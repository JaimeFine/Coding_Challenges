#ifndef __GAME__
#define __GAME__

#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<ctime>
using namespace std;

typedef enum {
	ROCK, SCISSOR, PAPER, SHOW, HELP, EXIT
} SelectObject;

typedef enum {
	WIN, LOSE, TIE
} Result

class Rashambo {
private:
	int win_num;
	int lose_num;
	int draw_num;

	Result Compare(SelectObject player_choice, SelectObject computer_choice);

	void FinalStatus();
	void GameStatus();
	void Help();
	void Report(Result result);
	SelectObject machine;
	SelectObject player;

public:
	RashamboStart();
	virtual ~Rashambo() {};
	void Run();
};

Rashambo::RashamboStart() {
	win_num = 0;
	lose_num = 0;
	draw_num = 0;
}

Result Rashambo::Compare(SelectObject machine, SelectObject player) {
	Result result;

	if (machine == player) {
		return DRAW;
	}

	switch(player) {
	case ROCK:
		result = (machine == PAPER) ? LOSE : WIN;

		break;
	case SCISSOR:
		result = (machine == ROCK) ? LOSE : WIN;

		break;
	case PAPER:
		result = (machine == SCISSOR) ? WIN : LOSE;

		break;
	}

	return result;
}

void Rashambo::GameStatus() {
	cout << "Current status:" << endl;
	cout << "Victory number: " << win_num << endl;
	cout << "Lose number: " << lose_num << endl;
	cout << "Draw number: " << draw_num << endl;
}

void Rashambo::Help() {

}


