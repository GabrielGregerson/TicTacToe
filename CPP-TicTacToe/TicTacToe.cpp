#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe() {
	// loops to empty out the spaces in the array and resets the player
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = ' ';
	}
	CurrentPlayer = 0;
}
bool TicTacToe::IsGameOver() const {
	return CheckWinner() || isBoardFull();
}

void TicTacToe::Display() const {
	// Used to display the board and initialize the board
	for (int i = 0; i < 9; i++) {
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

	// after the board is displayed again it will verify if there is a winner or not
	if (CheckWinner()) {
		cout << "Player " << ((CurrentPlayer == 0) ? "2" : "1") << " WINS! \n";
	}
	// if the Board is full it ends the game and says it's a TIE
	else if (isBoardFull()) {
		cout << "IT'S A TIE!! \n";
	}
}


void TicTacToe::TakeTurn() {
	int position;
	cout << "Choose your position please (1-9): ";
	cin >> position;
	position--;

	// If the move is valid It will add which position to add it to
	while (!isValidMove(position)) {
		cout << "Position has already been chosen please choose again (1-9) ";
		cin >> position;
		position--;
	}
	// Depending on the currentt player it will add to the array
	m_board[position] = (CurrentPlayer == 0) ? 'X' : 'O';

	CurrentPlayer = 1 - CurrentPlayer;
}

bool TicTacToe::isValidMove(int position) const {
	// if the position in the array is within 0-9 and is empty it will return fine but if its already full it will tell them to pick another
	return position >= 0 && position < 9 && m_board[position] == ' ';
}

bool TicTacToe::isBoardFull() const {
	// loops to verify if the board is full or not
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] == ' ') {
			return false;
		};
	}
}

bool TicTacToe::CheckWinner() const {
	// if any of these combinations contain any form of X or O's it will return true and we will have a winner
	//
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