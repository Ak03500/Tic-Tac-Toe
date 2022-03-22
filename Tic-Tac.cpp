#include<iostream>
#include<iomanip>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
//Tic-Tac-Toe Game


void displayBoard(char board[])
{
	cout << "     |     |     " << endl;
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

	cout << "     |     |     " << endl << endl;
}

bool isWinner(char board1[])
{
	if (board1[0] == board1[1] && board1[1] == board1[2] && board1[0] == 'X')
	{
		return true;
	}
	else if (board1[3] == board1[4] && board1[4] == board1[5] && board1[3] == 'X')
	{
		return true;
	}
	else if (board1[6] == board1[7] && board1[7] == board1[7] && board1[6] == 'X')
	{
		return true;
	}
	else if (board1[0] == board1[3] && board1[3] == board1[6] && board1[0] == 'X')
	{
		return true;
	}
	else if (board1[1] == board1[4] && board1[4] == board1[7] && board1[1] == 'X')
	{
		return true;
	}
	else if (board1[2] == board1[5] && board1[5] == board1[8] && board1[2] == 'X')
	{
		return true;
	}
	else if (board1[0] == board1[3] && board1[3] == board1[8] && board1[0] == 'X')
	{
		return true;
	}
	else if (board1[2] == board1[4] && board1[4] == board1[6] && board1[2] == 'X')
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isCompWin(char board1[])
{
	if (board1[0] == board1[1] && board1[1] == board1[2] && board1[0] == 'O')
	{
		return true;
	}
	else if (board1[3] == board1[4] && board1[4] == board1[5] && board1[3] == 'O')
	{
		return true;
	}
	else if (board1[6] == board1[7] && board1[7] == board1[7] && board1[6] == 'O')
	{
		return true;
	}
	else if (board1[0] == board1[3] && board1[3] == board1[6] && board1[0] == 'O')
	{
		return true;
	}
	else if (board1[1] == board1[4] && board1[4] == board1[7] && board1[1] == 'O')
	{
		return true;
	}
	else if (board1[2] == board1[5] && board1[5] == board1[8] && board1[2] == 'O')
	{
		return true;
	}
	else if (board1[0] == board1[3] && board1[3] == board1[8] && board1[0] == 'O')
	{
		return true;
	}
	else if (board1[2] == board1[4] && board1[4] == board1[6] && board1[2] == 'O')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isValid(int user, int comp)
{
	if (user != comp)
	{
		return true;
	}
	else
		return false;
}

bool isDraw(char board[])
{
	if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cout << "Welcome to this Tic-Tac-Toe game against the computer!" << endl;
	cout << "You are 'X' and the computer is 'O'" << endl;
	char board[] = { '0','1','2','3','4','5','6','7','8' };
	int user;
	displayBoard(board);
	do
	{
		char user1 = 'X';
		char comp = 'O';
		int redo = 0;
		srand(time(0));
		cout << "Please select a digit between 0 & 8 to make your move: ";
		cin >> user;
		board[user] = 'X';
		displayBoard(board);
		int compMove =  rand() % user;
		while (compMove == user)
		{
			compMove = rand() % user;

		}
		cout << "The computer's move is: " << compMove << endl;
		board[compMove] = 'O';

		if (user == compMove)
		{

			while (redo == compMove)
			{
				cout << "Please re-select your move: ";
				cin >> redo;

			}

		}

		displayBoard(board);
	} while (!isWinner(board) && !isCompWin(board) && !isDraw(board) );


	if (isWinner(board))
	{
		cout << "You Won!!!" << endl;
	}
	else if(isCompWin(board))
	{
		cout << "The Computer Won" << endl;
	}
	else if (isDraw(board))
	{
		cout << "Its a Tie" << endl;
	}

	return 0;
}




