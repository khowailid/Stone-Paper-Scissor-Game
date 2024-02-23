#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice {stone =1 , paper = 2 , scissors = 3};
enum enWinner {player =1 , computer = 2 , draw = 3};
struct stRoundInfo {
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice; 
	enWinner Winner; 
	string WinnerName;
};
struct stGameResults {
	short GameRounds = 0; short Player1WinTimes = 0; 
	short Computer2WinTimes = 0; 
	short DrawTimes = 0;
	enWinner GameWinner; string WinnerName = "";
};
int randomNumber(int from, int to) {
	int randNum = rand() % (to - from + 1) + from;
	return randNum;
}
string WinnerName(enWinner winner) {
	string arrWinnerName[3] = { "Player1", "Computer", "No Winner" };
	return arrWinnerName[winner - 1];
};

enWinner WhoWinTheRound(stRoundInfo roundInfo) {
	if (roundInfo.Player1Choice == roundInfo.ComputerChoice) {
		return enWinner::draw;
	}
	switch (roundInfo.Player1Choice)
	{
	case enGameChoice::stone:
		if (roundInfo.ComputerChoice == enGameChoice::paper)
		{
			return enWinner::computer;
		}
		break;
	case enGameChoice::paper:
		if (roundInfo.ComputerChoice == enGameChoice::scissors)
		{
			return enWinner::computer;
		}
		break;
	case enGameChoice::scissors:
		if (roundInfo.ComputerChoice == enGameChoice::stone)
		{
			return enWinner::computer;
		}
		break;
	}
	return enWinner::player;
}

string ChoiceName(enGameChoice choice) {
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[choice - 1];
};
void setWinnerScreenColor(enWinner winner) {
	switch (winner)
	{
	case enWinner::player:
		system("color 2F");
		break;
	case enWinner::computer:
		system("color 4F");
		break;
	case enWinner::draw:
		system("color 6F");
		break;
	}
}

void PrintRoundResults(stRoundInfo info) {
	cout << Tabs(2) << "Round [ " << info.RoundNumber << "] " << Tabs(2) << endl;
	cout << "Player Choice: " << ChoiceName(info.Player1Choice)<<endl;
	cout << "Computer Choice: " << ChoiceName(info.ComputerChoice)<<endl;
	cout << "Round Winner: " << info.Winner<<endl;
	cout << "-- " << Tabs(4) << " --";
	setWinnerScreenColor(info.Winner);
}


enWinner WhoWonTheGame(short plyer, short computer) {
	if (player > computer)
	{
		return enWinner::player;
	}
	else if (computer > player)
		return enWinner::computer;
	else
		return enWinner::draw;
}
stGameResults FillGameResults(int gameRounds, short player, short computer, short draw) {
	stGameResults GameResults;
	GameResults.GameRounds = gameRounds;
	GameResults.Player1WinTimes = player;  
	GameResults.Computer2WinTimes = computer;     
	GameResults.DrawTimes = draw;     
	GameResults.GameWinner = WhoWonTheGame(player, computer);    
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);
	return GameResults;
}
enGameChoice ReadPlayerChoice(){
	short Choice = 1;
	do{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";      
		cin >> Choice; 
	} 
	while (Choice < 1 || Choice >3); 
	return (enGameChoice)Choice;
}
enGameChoice GetComputerChoice() {
	return  (enGameChoice)randomNumber(1, 3);
}
stGameResults playGame(short Rounds) {
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= Rounds; GameRound++) {
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWinTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner); //Increase win/Draw counters
		if (RoundInfo.Winner == enWinner::player)             
				Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::computer)             
				ComputerWinTimes++; 
		else            
				DrawTimes++;
		PrintRoundResults(RoundInfo);    
	} 
		return FillGameResults(Rounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short numOfTabs) {
	string t = ""; 
	for (int i = 1; i < numOfTabs; i++){
			t = t + "\t";        
			cout << t;
	}
	return t;
}
void showGameOverScrean() {
	cout << Tabs(3) << "_____________________\n\n";
	cout << Tabs(5) << "+++ Game Over +++\n";
	cout << Tabs(3) << "_____________________\n\n";
}
void ShowFinalGameResults(stGameResults GameResults) {
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";     
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds<< endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl; 
	cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;     
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl; 
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;     
	cout << Tabs(2) << "___________________________________________________________\n";  
	setWinnerScreenColor(GameResults.GameWinner);
}
short ReadHowManyRounds() {
	short GameRounds = 1;
	do { 
		cout << "How Many Rounds 1 to 10 ? \n";  
	cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds >10);
	return GameRounds;
};
void ResetScrean() {
	system("cls");
	system("color 0F");
}
void startGame() {
	char playAgain = 'Y';
	do {
		ResetScrean();
		stGameResults GameResults = playGame(ReadHowManyRounds());
		showGameOverScrean();
		ShowFinalGameResults(GameResults);
		cout << endl << Tabs(3) << "Do you want to olay again? y/n";
		cin >> playAgain;
	} while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	startGame();
}
