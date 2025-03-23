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

private:
	char m_board[9];
	int CurrentPlayer;
	bool CheckWinner() const;
	bool isBoardFull() const;
	bool isValidMove(int position) const;
	void InitializeBoard();
};
