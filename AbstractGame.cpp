#include "AbstractGame.h"

int AbstractGame::MiniMaxScore(AbstractState * state, int (*evalFunction)(AbstractState*), int depth)
{
	if (GameIsOver(state) || depth <= 0) {
		return evalFunction(state);
	}
	depth--;
	if (state->whoseTurn == AbstractState::MAX) {
		AbstractMove * tempMove = MaxMove(state, evalFunction, depth);
		AbstractState * tempState = GetNextState(tempMove, state);
		int toReturn = MiniMaxScore(tempState, evalFunction, depth);
		delete tempState;
		delete tempMove;
		return toReturn;
	}
	else {
		AbstractMove * tempMove = MinMove(state, evalFunction, depth);
		AbstractState * tempState = GetNextState(tempMove, state);
		int toReturn = MiniMaxScore(tempState, evalFunction, depth);
		delete tempState;
		delete tempMove;
		return toReturn;
	}
}

AbstractMove * AbstractGame::MaxMove(AbstractState * state, int (*evalFunction)(AbstractState*), int depth)
{
	std::vector<AbstractMove*> moves = GenerateListOfMoves(state);
	int currentBest = -99999999;
	AbstractMove * best = nullptr;
	for (auto * move : moves) {
		AbstractState * tempState = GetNextState(move, state);
		int temp = MiniMaxScore(tempState, evalFunction, depth);
		delete tempState;
		if (temp > currentBest) {
			if (best)
				delete best;
			currentBest = temp;
			best = move;
		}
		else {
			delete move;
		}
	}
	assert(best);
	return best;
}

AbstractMove * AbstractGame::MinMove(AbstractState * state, int(*evalFunction)(AbstractState*), int depth)
{
	std::vector<AbstractMove*> moves = GenerateListOfMoves(state);
	int currentBest = 999999999;
	AbstractMove * best = nullptr;
	for (auto * move : moves) {
		AbstractState * tempState = GetNextState(move, state);
		int temp = MiniMaxScore(tempState, evalFunction, depth);
		delete tempState;
		if (temp < currentBest) {
			if (best) {
				delete best;
			}
			currentBest = temp;
			best = move;
		}
		else {
			delete move;
		}
	}
	assert(best);
	return best;
}

AbstractMove * AbstractGame::BestMove(AbstractState * state, int depth, int (*evalFunction)(AbstractState *))
{
	if (state->whoseTurn == AbstractState::MAX) {
		return MaxMove(state, evalFunction, depth);
	}
	return MinMove(state, evalFunction, depth);
}

void AbstractGame::PerformMove(AbstractMove * move)
{
	AbstractState * temp = GetNextState(move, currState);
	delete currState;
	currState = temp;
}