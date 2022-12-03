#include<iostream>
using namespace std;
void print_board(char** board, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
bool valid_position(char** board, int n, int row, int column)
{
	return row > -1 && row<n&& column >-1 && column < n&& board[row][column] == '.';
}
int main()
{
	cout << "Please ; Enter the size of the board: ";
	int n;
	cin >> n;

	char** board;
	board = new char* [n];

	for (int i = 0; i < n; i++)
	{
		board[i] = new char[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = '.';
		}

	}
	print_board(board, n);

	//--------------------------------------------------------------------------
	//counting Number of x's , y's in each row , column and diagonal
	int* rowx = new int[n];
	int* rowy = new int[n];
	int* columnx = new int[n];
	int* columny = new int[n];
	for (int i = 0; i < n; i++)
	{
		rowx[i] = 0; rowy[i] = 0; columnx[i] = 0; columny[i] = 0;
	}
	int right_diagonal_x = 0, right_diagonal_y = 0, left_diagonal_x = 0, left_diagonal_y = 0;

	//-------------------------------------------------------------------------
	int steps = 0;
	bool first_player_mode = true;
	while (steps <= n * n)
	{
		cout << "\n****************\n";
		cout << "Player ";
		if (first_player_mode)
		{
			cout << "x ";
		}
		else
		{
			cout << "y ";
		}
		cout << "mode\n";

		cout << "Enter Empty location for r , c: ";
		int r, c;
		cin >> r >> c;
		r--; c--;

		if (!valid_position(board, n, r, c))
		{
			cout << "Please ; Enter a valid position \n";
			continue;
		}
		if (first_player_mode)
		{
			board[r][c] = 'x';
		}
		else
		{
			board[r][c] = 'o';
		}
		print_board(board, n);
		if (first_player_mode)
		{
			rowx[r]++;
			columnx[c]++;
			right_diagonal_x += (r == c);
			left_diagonal_x += (r + c == n - 1);

			// if any of them is equal to n then the player is win
			if (rowx[r] == n || columnx[c] == n || right_diagonal_x == n || left_diagonal_x == n)
			{
				cout << "congratulations for first player ; You are the winner of the Game\n";
				break;
			}

		}
		else
		{
			rowy[r]++;
			columny[c]++;
			right_diagonal_y += (r == c);
			left_diagonal_y += (r + c == n - 1);

			// if any of them is equal to n then the player is win
			if (rowy[r] == n || columny[c] == n || right_diagonal_y == n || left_diagonal_y == n)
			{
				cout << "congratulations for second player ; You are the winner of the Game\n";
				break;
			}
		}
		steps++;
		first_player_mode = !first_player_mode;

	}
	cout << "Game over\n";
	return 0;
}