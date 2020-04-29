#pragma once
#include "GPRO-FW-TicTacToe.h"

int turns = 0;
//-----------------------------------------------------------------------------
// DEFINITIONS

void displayGameBoard(gs_tictactoe game) {
	cout << endl << "-----------" << endl;
	for (int xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos){
		for (int ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos){
			string display = "ERROR";
			if (game[xpos][ypos] == gs_tictactoe_space_open) {
				display = OPEN_DISPLAY;
			}
			else if (game[xpos][ypos] == gs_tictactoe_space_x) {
				display = X_DISPLAY;
			}
			else if (game[xpos][ypos] == gs_tictactoe_space_o) {
				display = O_DISPLAY;
			}
			 cout << display << "|";
		}
		cout << endl << "-----------" << endl;
	}
}

gs_tictactoe_space_state gameLoop(gs_tictactoe_space_state plr, gs_tictactoe game) {
	if (plr == gs_tictactoe_space_x) {
		cout << "It is X's turn." << endl;
		if (playItem(plr, game))
			plr = gs_tictactoe_space_o;
		else
			cout << endl << "ERROR: That Cell is full for doesn't egsit please try another." << endl;
	}
	else if (plr == gs_tictactoe_space_o) {
		cout << "it is O's Turn." << endl;
		if (playItem(plr, game))
			plr = gs_tictactoe_space_x;
		else
			cout << "That Cell is full for doesn't egsit please try another." << endl;
	}
	turns++;
	return plr;
}

bool checkForWin(gs_tictactoe game, gs_tictactoe_space_state player) {
	if (checkHorizontal(game, player) || checkVectical(game, player) || checkDiagonal(game, player)) {
		return true;
	}
	return false;
}

bool input(gs_tictactoe_space_state turnState, gs_tictactoe game)
{
	int row = -1;
	int col = -1;
	do {
		cout << "Enter a Coloum to play" << endl;
		 col = getInput();
		cout << "Enter a Row to play" << endl;
		 row = getInput();
	} while (!validInput(col, GS_TICTACTOE_BOARD_HEIGHT) && !validInput(row, GS_TICTACTOE_BOARD_HEIGHT));'
	
	if (game[row][col] == gs_tictactoe_space_open && validInput(col, GS_TICTACTOE_BOARD_HEIGHT) && validInput(row, GS_TICTACTOE_BOARD_HEIGHT)) {
		game[row][col] = turnState;
		return true;
	}
	return false;

}

bool checkHorizontal(gs_tictactoe game, gs_tictactoe_space_state player)
{
	for (int xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos) {
		int winPoints = 0;
		for (int ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos) {
			if (game[xpos][ypos] == player) {
				winPoints++;
			}
		}
		if (winPoints == POINTS_TO_WIN) {
			winOutput(player);
			return true;
		}
	}
	return false;
}

bool checkVectical(gs_tictactoe game, gs_tictactoe_space_state player)
{
	for (int ypos = 0; ypos < GS_TICTACTOE_BOARD_WIDTH; ++ypos) {
		int winPoints = 0;
		for (int xpos = 0; xpos < GS_TICTACTOE_BOARD_HEIGHT; ++xpos) {
			if (game[xpos][ypos] == player) {
				winPoints++;
			}
		}
		if (winPoints == POINTS_TO_WIN) {
			winOutput(player);
			return true;
		}
	}
	return false;
	return false;
}

bool checkDiagonal(gs_tictactoe game, gs_tictactoe_space_state player)
{
	if (game[0][0] == player && game[1][1] == player && game[2][2] == player) {
		winOutput(player);
		return true;
	}
	else if (game[0][2] == player && game[1][1] == player && game[2][0] == player) {
		winOutput(player);
		return true;
	}
	return false;
}

bool checkTie()
{
	if (turns >= MAX_TURNS) {
		cout << "Cats Game!" << endl;
		return true;
	}
	return false;
}

void winOutput(gs_tictactoe_space_state player)
{
	cout << "Winner Winner!!!" << endl;
}

void input()
{
}

int launchTicTacToe()
{
	gs_tictactoe game;

	gs_tictactoe_reset(game);

	cout << "Tic Tac Toe has been launched" << endl;
	bool active = true;
	gs_tictactoe_space_state player = gs_tictactoe_space_x;
	
	while (active) {
		if (checkForWin(game, gs_tictactoe_space_x) || checkForWin(game, gs_tictactoe_space_o) || checkTie()) {
			active = false;
			break;
		}
		displayGameBoard(game);
		player = gameLoop(player, game);

	}
	displayGameBoard(game);

	return 0;
}



//-----------------------------------------------------------------------------
