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

}
enGameChoice ReadPlayerChoice(){

}
enGameChoice GetComputerChoice() {

}
stGameResults playGame(short Rounds) {

}
string Tabs(short numOfTabs) {

}
void showGameOverScrean() {

}
void ShowFinalGameResults(stGameResults GameResults) {

}
short ReadHowManyRounds() {
	do
};
void ResetScrean() {

}
void startGame() {

}
int main()
{
	srand((unsigned)time(NULL));
}
