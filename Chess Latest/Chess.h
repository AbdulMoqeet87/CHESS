#pragma once
#include<fstream>
#include<vector>
#include"Board.h"

class Board;
class Player;
using namespace std;
class Chess
{
	int sri, sci, dri, dci;
	int Turn;
	int P1_Time;
	int P2_Time;
	Player* Ps[2];
	Board* B;
	vector<Board> Un_d;
	vector<Board>Re_d;
	int Uindx = 0;

public:

	Chess(const char* filename);
	void Play(int &choice,sf::RenderWindow & window);
	void SelectPosition(int& ri, int& ci, sf::RenderWindow& window);
	bool IsvalidSource();
	bool IsvalidDestination();
	bool IsMyPiece(int ri, int ci);
	void DsiplayName();
	void TurnChange();
	bool Undo(int r,int c);
	bool Redo(int r, int c);

};

