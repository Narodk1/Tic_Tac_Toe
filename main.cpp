/*Simple Project C++ From NARO*/
#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
//Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;
void display_board() {
	//Rander Game Board Layout 
	cout << "PLAYER - 1 [X]\t PLAYER - 2[O] \n";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] <<endl;
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] <<endl;
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] <<endl;
	cout << "\t     |     |     \n";

}
void player_turn() {
	if (turn == 'X') {
		cout << "\n\tPlayer - 1 [X] turn : ";
	}
	else if (turn == 'O') {
		cout << "\n\t Player - 2 [O] turn : ";
	}
	cin >> choice;
	//Switch case to get wich row and column will be update
	switch (choice)
	{
	case 1:
		row = 0; column = 0; break;
	case 2:
		row = 0; column = 1; break;
	case 3:
		row = 0; column = 2; break;
	case 4:
		row = 1; column = 0; break;
	case 5:
		row = 1; column = 1; break;
	case 6:
		row = 1; column = 2; break;
	case 7:
		row = 2; column = 0; break;
	case 8:
		row = 2; column = 1; break;
	case 9:
		row = 2; column = 2; break;
	default:
		cout << "Invalid Move";
	}
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
		//Updating The Position For 'X' Symbol if
		//Positio Is Not AlReady Occupied
		board[row][column] = 'X';
	    turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		//Updating The Position For 'O' Symbol if
		//Positio Is Not AlReady Occupied
		board[row][column] = 'O';
		turn = 'X';
	}
	else {
		cout << "Box Is AlReady Is Filled \n Please Choose Another Choice  " << endl;
		player_turn();
	}
	/*Display board for show Result*/
	display_board();
}
//Function to get Game Status 
bool gameover() {
	for (int i = 0; i < 3; i++) 
		//checking the win for both diagnol /row and column
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[i][0] == board[1][i] && board[0][i] == board[2][i])
			return false;
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
			return false;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] != 'X' && board[i][j] != 'O')
					return true;
				    draw = true;
			}
		}
		return false;
}
/*main*/
int main() {
	cout << "TIC TAC TOE GAME FROM N-A-R-O" << endl;
	cout << "For Two Players "<<endl;
	while (gameover())
	{
		display_board();
		player_turn();
		gameover();
	}
	if (turn == 'X' && draw == false) {
		cout << "\n Congratulation ! Player With 'X' has won the game";
	}
	else if (turn == 'O' && draw == false) {
		cout<<"\n Congratulation ! Player With 'O' has won the game";
	}
	else {
		cout << "\n GAME DRAW!!!\n";
	}
}