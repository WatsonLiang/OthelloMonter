#pragma once

#include<iostream>
#include<vector>
#include<set>
#include<time.h>

using namespace std;

// class that record a possibile playing position 
// along with the number of chesses that should be reversed in each direction if the position is played
class PlayRev {
public:
	int pos;
	int revset[8] = {};
	PlayRev();
};

class Othello {
public:
	Othello();
	
	// parameters that record the state of a position on the board 
	// or the state of the game
	static const int BLACK;
	static const int WHITE;
	static const int EMPTY;
	static const int DRAW;
	static const int PLAYING;
	static const int DIRSET[8][2];
	
	// the player of the current game
	int turn;
	
	// state of each position
	// BLACK / WHITE / EMPTY
	int _board[64] = {};
	
	// print out the board as a graphic-like formate
	int showboard();
	
	// get the reference of a specific position 
	inline int &board(int pos) {
		return _board[pos];
	}
	inline int &board(int x, int y) {
		return _board[to1d(x, y)];
	}
	
	static inline int to1d(int x, int y) {
		return x * 8 + y;
	}
	static inline int to2dx(int pos) {
		return pos >> 3;
	}

	static inline int to2dy(int pos) {
		return pos % 8;
	}

	void updateplayset();

	int play(int pos);
	int play(PlayRev playrev);

	// play the board randomly
	int randomplay();

	vector<PlayRev> playset;

	// state of the board
	// BLACK / WHITE / PLAYING / DRAW
	// BLACK or WHITE means the game is over and the winner is BLACK or WHITE
	int boardstate;

};
