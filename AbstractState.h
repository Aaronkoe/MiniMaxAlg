#pragma once
class AbstractState {
public:
	enum Player {
		MAX,
		MIN
	};
	Player whoseTurn;

	AbstractState() : whoseTurn(MAX) { }
	AbstractState(int i) { if (i == 0) whoseTurn = MAX; else whoseTurn = MIN; }
};