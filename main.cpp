/*Simple Project C++ From NARO with two Methods*/
#include <iostream >
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void display_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int board_count(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

void display_board()
{
	cout << "Tic Tac Toe From NaroDK";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
	cout << "\t     |     |     \n";
}
void get_computer_choice()
{
	srand(time(0));
	int choice;
	do
	{
		choice = rand() % 10; /*0-9*/
	} while (board[choice] != ' ');
	board[choice] = 'O';
}
void get_x_player_choice()
{
	while (true)
	{
		cout << "select your position (1-9): ";
		int choice;
		cin >> choice;
		choice--; /*the game will be started in 0 that why we need to put -- */
		if (choice < 0 || choice > 8)
		{
			cout << "select your choice from position (1-9):" << endl;
		}
		else if (board[choice] != ' ')
		{
			cout << "select empty position !" << endl;
		}
		else
		{
			board[choice] = 'X';
			break;
		}
	}
}
void get_o_player_choice()
{
	while (true)
	{
		cout << "select your position (1-9): ";
		int choice;
		cin >> choice;
		choice--; /*the game will be started in  0 that why we need to put -- */
		if (choice < 0 || choice > 8)
		{
			cout << "select your choice from position (1-9):" << endl;
		}
		else if (board[choice] != ' ')
		{
			cout << "select empty position !" << endl;
		}
		else
		{
			board[choice] = 'O';
			break;
		}
	}
}

int board_count(char symbol)
{
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		if(board[i] == symbol)
			total += 1;
	}
	return total;
}
char check_winner()
{
	// horizental*******************************************************
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
		return board[2];
	if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
		return board[4];
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
		return board[7];
	// vertical***************************************************
	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
		return board[0];
	if (board[1] == board[5] && board[5] == board[7] && board[1] != ' ')
		return board[1];
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
		return board[2];
	//\/**************************************************************
	if (board[0] == board[4] && board[4] == board[4] == board[8] && board[0] != ' ')
		return board[0];
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
		return board[2];
	if (board_count('X') + board_count('O'))
		return 'c';
	else
		return 'd';
}
void computer_vs_player()
{
	string playerN;
	cout << "entrer Votre nom : ";
	cin >> playerN;
	while (true)
	{
		system("cls");
		display_board();
		if (board_count('X') == board_count('O'))
		{
			cout << "c'est le tour de : " << playerN << endl;
			get_x_player_choice();
		}
		else
		{
			get_computer_choice();
		}
		char winner = check_winner();
		if (winner == 'X')
		{
			system("cls");
			display_board();
			cout << playerN << " a gagner cette partie!!" << endl;
			break;
		}
		else if (winner == 'O')
		{
			system("cls");
			display_board();
			cout << " J'ai gagner cette partie!!" << endl;
			break;
		}
		else if (winner == 'd')
		{
			cout << "la partire est terminer!!" << endl;
			break;
		}
	}
}
void player_vs_player()
{
	string playerX, playerO;
	cout << "entrer le nom de joueur X: ";
	cin >> playerX;
	cout << "entrer le nom de joueur Y: ";
	cin >> playerO;
	while (true)
	{
		system("cls");
		display_board();
		if (board_count('X') == board_count('O'))
		{
			cout << "c'est le tour de : " << playerX << endl;
			get_x_player_choice();
		}
		else
		{
			cout << "c'est le tour de : " << playerO << endl;
			get_o_player_choice();
		}
		char winner = check_winner();
		if (winner == 'X')
		{
			system("cls");
			display_board();
			cout << playerX << " a gagner cette partie!!" << endl;
			break;
		}
		else if (winner == 'O')
		{
			system("cls");
			display_board();
			cout << playerO << " a gagner cette partie!!" << endl;
			break;
		}
		else if (winner == 'd')
		{
			cout << "la partie est terminer!!" << endl;
			break;
		}
	}
}

int main()
{
	int mode;
	cout << "1- Computer VS Player." << endl;
	cout << "2- Player VS Player." << endl;
	cout << "selectionner le mode de jeux: ";
	cin >> mode;
	switch (mode)
	{
	case 1:
		computer_vs_player();
		break;
	case 2:
		player_vs_player();
		break;
	default:
		cout << "SVP Choisi les options disponible dans le menu!!" << endl;
		cout << "choisi encore le mode de jeux: ";
	   cin >> mode;
	break;
	}
	return 0;
}
