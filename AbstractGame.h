#pragma once
#include <assert.h>
#include <vector>
#include "AbstractState.h"
#include "AbstractMove.h"
class AbstractGame {
private:
	AbstractState * currState;
public:
	virtual AbstractState * GetNextState(AbstractMove * move, AbstractState * currState) = 0;
	virtual int EvaluateState(AbstractState * state) = 0;
	virtual bool GameIsOver(AbstractState * state) = 0;
	virtual std::vector<AbstractMove*> GenerateListOfMoves(AbstractState * state) = 0;

	~AbstractGame() { delete currState; }
	int MiniMaxScore(AbstractState * state, int (*evalFunction)(AbstractState*), int depth=-1);
	AbstractMove * MaxMove(AbstractState * state, int(*evalFunction)(AbstractState*), int depth = -1);
	AbstractMove * MinMove(AbstractState * state, int(*evalFunction)(AbstractState*), int depth = -1);
	AbstractMove * BestMove(AbstractState * state, int depth, int (*evalFunction)(AbstractState*));
	void PerformMove(AbstractMove * move);
	AbstractState * GetCurrentState() { return currState; }
protected:
	void SetInitialState(AbstractState * initState) { currState = initState; }
};