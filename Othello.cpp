#include "Othello.h"

OthelloGame::OthelloGame()
{
	OthelloState * state = new OthelloState;
	SetInitialState(state);
}

OthelloGame::OthelloGame(OthelloState * initState)
{
	SetInitialState(initState);
}

AbstractState * OthelloGame::GetNextState(AbstractMove * move, AbstractState * state)
{
	OthelloState * oldState = static_cast<OthelloState*>(state);
	OthelloState * newState = new OthelloState(*oldState);
	OthelloMove * oMove = static_cast<OthelloMove*>(move);
	OthelloState::TileType color = (OthelloState::TileType)(int)oldState->whoseTurn;
	if (oMove->row != -1) {
		newState->board[oMove->row][oMove->col] = (OthelloState::TileType)(int)oldState->whoseTurn;
		FlipTiles(newState, oMove, (OthelloState::TileType)(int)newState->whoseTurn);
	}
	newState->whoseTurn = newState->whoseTurn == AbstractState::Player::MAX ? AbstractState::Player::MIN : AbstractState::Player::MAX;
	return newState;
}

int OthelloGame::EvaluateState(AbstractState * state)
{
	OthelloState * s = static_cast<OthelloState*>(state);
	int whiteCount = 0, blackCount = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == OthelloState::TileType::WHITE) {
				whiteCount++;
			}
		}
	}
	return whiteCount;
}

bool OthelloGame::GameIsOver(AbstractState * state)
{
	OthelloState * s = static_cast<OthelloState*>(state);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == OthelloState::TileType::EMPTY) {
				return false;
			}
		}
	}
	return true;
}

std::vector<AbstractMove*> OthelloGame::GenerateListOfMoves(AbstractState * state)
{
	auto s = static_cast<OthelloState*>(state);
	std::vector<AbstractMove*> moves = s->GetOpenMoves();
	if (moves.size() == 0) {
		moves.push_back(new OthelloMove(-1, -1));
	}
	return moves;
}

void OthelloGame::Print(AbstractState * s)
{
	OthelloState * state;
	if (s) {
		state = static_cast<OthelloState*>(s);
	}
	else {
		state = static_cast<OthelloState*>(GetCurrentState());
	}
	std::cout << "GAME STATE: " << std::endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << "|";
			switch (state->board[i][j]) {
				case OthelloState::EMPTY: std::cout << " "; break;
				case OthelloState::WHITE: std::cout << "O"; break;
				case OthelloState::BLACK: std::cout << "X"; break;
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

int OthelloGame::PrintResults(std::ostream & out, std::string evalFunction1, std::string evalFunction2)
{
	auto s = static_cast<OthelloState*>(GetCurrentState());
	int whiteCount = 0; int blackCount = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == OthelloState::TileType::BLACK) {
				blackCount++;
			}
			if (s->board[i][j] == OthelloState::TileType::WHITE) {
				whiteCount++;
			}
		}
	}
	int winner = blackCount > whiteCount ? 1 : 0;
	out << winner << "," << whiteCount << "," << blackCount << std::endl;
	return winner;
}

void OthelloGame::FlipTiles(OthelloState * state, OthelloMove * move, OthelloState::TileType color)
{
	for (int i = 0; i < 8; i++) {
		int num = state->GetNextOfSameColor(color, move->row, move->col, (OthelloState::CheckDirection)i);
		if (num <= 0) continue;
		state->FlipTilesInDirection(color, move->row, move->col, (OthelloState::CheckDirection)i, num);
	}
}
