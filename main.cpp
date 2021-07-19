#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include "Othello.h"

int randomEvaluation(AbstractState * state);
int simpleSum(AbstractState * state);
int simpleSumBlack(AbstractState * state);
int simpleSumWithCorners2(AbstractState * state);
int simpleSumWithCorners2Black(AbstractState * state);
int simpleSumWithCorners4(AbstractState * state);
int simpleSumWithCorners4Black(AbstractState * state);

int main() {
	srand(time(NULL));
	OthelloMove * move;
	std::stringstream fileString;
	int secondPlayerWinsCount = 0;
	for (int i = 0; i < 8; i++) {
		fileString << "depth " << i << " " << "random v random.txt";
		std::ofstream out(fileString.str());
		for (int j = 0; j < 100; j++) {
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "simpleSum v random.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSum));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "random v simpleSum.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumBlack));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "cornersWorth2 v random.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners2));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "random v cornersWorth2.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners2Black));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "simpleSum v cornersWorth2.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSum));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners2Black));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "cornersWorth2 v simpleSum.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners2));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumBlack));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "cornersWorth4 v simpleSum.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners4));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumBlack));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "simpleSum v cornersWorth4.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSum));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners4Black));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "cornersWorth2 v cornersWorth4.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners2));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners4Black));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "cornersWorth4 v cornersWorth2.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners4));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners2Black));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "cornersWorth4 v random.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners4));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		fileString << "depth " << i << " " << "random v cornersWorth4.txt";
		out.open(fileString.str());
		for (int j = 0; j < 100; j++) {
			std::stringstream fileString;
			OthelloGame g;
			int turnCount = 0;
			while (!g.GameIsOver(g.GetCurrentState()) && turnCount < 50) {
				turnCount++;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, randomEvaluation));
				g.PerformMove(move);
				delete move;
				move = static_cast<OthelloMove*>(g.BestMove(g.GetCurrentState(), i, simpleSumWithCorners4Black));
				g.PerformMove(move);
				delete move;
			}
			secondPlayerWinsCount += g.PrintResults(out, "", "");
		}
		out << "First player won: " << 100 - secondPlayerWinsCount << " matches.";
		secondPlayerWinsCount = 0;
		out.close();
		fileString.str("");
		secondPlayerWinsCount = 0;
	}
	return 0;
}

int randomEvaluation(AbstractState * state) {
	return rand();
}

int simpleSum(AbstractState * state) {
	auto s = static_cast<OthelloState*>(state);
	int count = 0;
	OthelloState::TileType color = OthelloState::TileType::WHITE;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == color)
				count++;
		}
	}
	return count + rand() % 5 - 2;
}

int simpleSumBlack(AbstractState * state) {
	auto s = static_cast<OthelloState*>(state);
	int count = 0;
	OthelloState::TileType color = OthelloState::TileType::BLACK;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == color)
				count++;
		}
	}
	return count + rand() % 5 - 2;
}

int simpleSumWithCorners2(AbstractState * state) {
	auto s = static_cast<OthelloState*>(state);
	OthelloState::TileType color = OthelloState::TileType::WHITE;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == color)
				count++;
		}
	}
	if (s->board[0][0] == color) {
		count += 1;
	}
	if (s->board[7][0] == color) {
		count += 1;
	}
	if (s->board[0][7] == color) {
		count += 1;
	}
	if (s->board[7][7] == color) {
		count += 1;
	}
	return count + rand() % 5 - 2;
}

int simpleSumWithCorners2Black(AbstractState * state) {
	auto s = static_cast<OthelloState*>(state);
	OthelloState::TileType color = OthelloState::TileType::BLACK;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == color)
				count++;
		}
	}
	if (s->board[0][0] == color) {
		count += 1;
	}
	if (s->board[7][0] == color) {
		count += 1;
	}
	if (s->board[0][7] == color) {
		count += 1;
	}
	if (s->board[7][7] == color) {
		count += 1;
	}
	return count + rand() % 5 - 2;
}

int simpleSumWithCorners4(AbstractState * state) {
	auto s = static_cast<OthelloState*>(state);
	OthelloState::TileType color = OthelloState::TileType::WHITE;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == color)
				count++;
		}
	}
	if (s->board[0][0] == color) {
		count += 3;
	}
	if (s->board[7][0] == color) {
		count += 3;
	}
	if (s->board[0][7] == color) {
		count += 3;
	}
	if (s->board[7][7] == color) {
		count += 3;
	}
	return count + rand() % 5 - 2;
}

int simpleSumWithCorners4Black(AbstractState * state) {
	auto s = static_cast<OthelloState*>(state);
	OthelloState::TileType color = OthelloState::TileType::BLACK;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s->board[i][j] == color)
				count++;
		}
	}
	if (s->board[0][0] == color) {
		count += 3;
	}
	if (s->board[7][0] == color) {
		count += 3;
	}
	if (s->board[0][7] == color) {
		count += 3;
	}
	if (s->board[7][7] == color) {
		count += 3;
	}
	return count + rand() % 5 - 2;
}