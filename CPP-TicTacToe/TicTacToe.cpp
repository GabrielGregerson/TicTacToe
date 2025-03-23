#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe() {
	InitializeBoard();
	CurrentPlayer = 0;
}

void TicTacToe::InitializeBoard() {
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = ' ';
	}
}

bool TicTacToe::IsGameOver() const {
	return CheckWinner() || isBoardFull();
}

void TicTacToe::Display() const {
	for (int i = 0; i < 9; i++)
	{
		cout << m_board[i] << " ";
		if (i == 2 || i == 5) {
			cout << "\n------------\n";
		}
		else if (i == 8) {
			cout << "\n";
		}
		else {
			cout << " | ";
		}
	}
	if (CheckWinner()) {
		cout << "Player " << (CurrentPlayer) << " WINS! \n";
	}
	else if (isBoardFull()) {
		cout << "IT'S A TIE!! \n";
	}
}

void TicTacToe::TakeTurn() {
	int position;
	cout << "Choose your position please (1-9): ";
	cin >> position;
	position--;

	while (!isValidMove(position)) {
		cout << "Position has already been chosen please choose again (1-9) ";
		cin >> position;
		position--;
	}

	m_board[position] = (CurrentPlayer == 0) ? 'X' : 'O';

	CurrentPlayer = 1 - CurrentPlayer;
}

bool TicTacToe::isValidMove(int position) const {
	return position >= 0 && position < 9 && m_board[position] == ' ';
}

bool TicTacToe::isBoardFull() const {
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] == ' ') {
			return false;
		};
	}
}

bool TicTacToe::CheckWinner() const {
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ') return true;
	if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ') return true;
	if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ') return true;

	if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ') return true;
	if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ') return true;
	if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ') return true;
	
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ') return true;
	if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' ') return true;
	return false;
}