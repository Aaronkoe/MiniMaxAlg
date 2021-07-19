#pragma once
#include <iostream>
#include "AbstractGame.h"
#include "AbstractState.h"
#include "AbstractMove.h"

class OthelloMove : public AbstractMove {
public:
	int row, col;
	OthelloMove(int r, int c) : row(r), col(c) { }
};

class OthelloState : public AbstractState {
public:
	enum TileType {
		WHITE,
		BLACK,
		EMPTY
	};
	TileType board[8][8];
	OthelloState() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = EMPTY;
			}
		}
		board[3][3] = WHITE;
		board[4][4] = WHITE;
		board[4][3] = BLACK;
		board[3][4] = BLACK;
	}
	OthelloState(TileType b[8][8]) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = b[i][j];
			}
		}
	}
	enum CheckDirection {
		UP,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		UP_LEFT
	};
	int GetNextOfSameColor(TileType color, int row, int col, CheckDirection dir) {
		switch (dir) {
		case UP:
			return GetNextOfSameColor(color, row, col, 0, 1);
		case UP_RIGHT:
			return GetNextOfSameColor(color, row, col, 1, 1);
		case RIGHT:
			return GetNextOfSameColor(color, row, col, 1, 0);
		case DOWN_RIGHT:
			return GetNextOfSameColor(color, row, col, 1, -1);
		case DOWN:
			return GetNextOfSameColor(color, row, col, 0, -1);
		case DOWN_LEFT:
			return GetNextOfSameColor(color, row, col, -1, -1);
		case LEFT:
			return GetNextOfSameColor(color, row, col, -1, 0);
		case UP_LEFT:
			return GetNextOfSameColor(color, row, col, -1, 1);
		}
	}
	int GetNextOfSameColor(TileType color, int row, int col, int dr, int dc) {
		for (int i = row + dr, j = col + dc, count = 1; i >= 0 && j >= 0 && i < 8 && j < 8; i += dr, j += dc, count++) {
			if (board[i][j] == EMPTY) {
				return -1;
			}
			if (board[i][j] == color) {
				return count;
			}
		}
		return -1;
	}
	void FlipTilesInDirection(TileType color, int row, int col, CheckDirection dir, int num) {
		switch (dir) {
		case UP:
			return FlipTilesInDirection(color, row, col, 0, 1, num);
		case UP_RIGHT:
			return FlipTilesInDirection(color, row, col, 1, 1, num);
		case RIGHT:
			return FlipTilesInDirection(color, row, col, 1, 0, num);
		case DOWN_RIGHT:
			return FlipTilesInDirection(color, row, col, 1, -1, num);
		case DOWN:
			return FlipTilesInDirection(color, row, col, 0, -1, num);
		case DOWN_LEFT:
			return FlipTilesInDirection(color, row, col, -1, -1, num);
		case LEFT:
			return FlipTilesInDirection(color, row, col, -1, 0, num);
		case UP_LEFT:
			return FlipTilesInDirection(color, row, col, -1, 1, num);
		}
	}
	void FlipTilesInDirection(TileType color, int row, int col, int dr, int dc, int num) {
		for (int i = row, j = col; num > 0; i += dr, j += dc, num--) {
			board[i][j] = color;
		}
	}
	bool MoveFlipsTile(OthelloMove move) {
		for (int i = 0; i < 8; i++) {
			int num = GetNextOfSameColor((TileType)(int)whoseTurn, move.row, move.col, (OthelloState::CheckDirection)i);
			if (num > 1)
				return true;
		}
		return false;

	}
	std::vector<AbstractMove*> GetOpenMoves() {
		std::vector<AbstractMove*> moves;
		OthelloState* state = static_cast<OthelloState*>(this);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (state->board[i][j] == EMPTY && state->HasAdjacentTile(i, j) && MoveFlipsTile({ i, j })) {
					moves.push_back(new OthelloMove(i, j));
				}
			}
		}
		return moves;
	}
private:
	bool HasAdjacentTile(int row, int col) {
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if ((row + i >= 0) && col + j >= 0 && row + i < 8 && col + j < 8 && (board[row + i][col + j] == BLACK || board[row + i][col + j] == WHITE)) {
					return true;
				}
			}
		}
		return false;
	}
};

class OthelloGame : public AbstractGame {
public:
	OthelloGame();
	OthelloGame(OthelloState * initState);

	AbstractState * GetNextState(AbstractMove * move, AbstractState * state) override;
	int EvaluateState(AbstractState * state) override;
	bool GameIsOver(AbstractState * state) override;
	std::vector<AbstractMove*> GenerateListOfMoves(AbstractState * state) override;

	void Print(AbstractState * s=NULL);
	int PrintResults(std::ostream & out, std::string evalFunc1, std::string evalFunc2);
private:
	void FlipTiles(OthelloState * state, OthelloMove * move, OthelloState::TileType color);
};