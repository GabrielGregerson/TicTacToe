#pragma once
#include "Game.h"
#include <iostream>

class TicTacToe : public Game
{
public:
	TicTacToe();
	void Display() const;
	bool IsGameOver() const;
	void TakeTurn();
	char m_board[9];
private:
	int CurrentPlayer;
	// either true or false if the winner is decided
	bool CheckWinner() const;
	// If the board iis full it also sends back true or false
	bool isBoardFull() const;
	// Checks and see if the current move they are making is valid or not
	bool isValidMove(int position) const;
};
