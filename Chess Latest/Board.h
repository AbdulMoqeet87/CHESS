#pragma once
#include<fstream>
#include<vector>
using namespace std;
#include"Utility.h"
#include<SFML/Graphics.hpp>
class Piece;
class Cell;
class Board
{
protected:
	//Piece*** P;
	Cell*** C;
	char** A;

public:
	Board(ifstream& rdr);
	Board(const Board& B);
	void DisplayBoard(sf::RenderWindow &window);
	void DispRowDest(int sri, int sci, int dri, int dci);
	void Save(int turn, int P1_Time, int P2_Time);
	Color PieceColor(int ri, int ci);
	void Update(int sr, int sc, int dr, int dc, int turn,int P1_Time,int P2_Time,vector<Board>& vb);
	bool IsApiece(int ri, int ci);
	void LoadChar(ifstream& rdr);
	bool IslegalMove(int sri, int sci, int dri, int dci,char T);
	void HighlightCell(int sri, int sci, Color, sf::RenderWindow& window);
	bool FindKIng(int dri, int dci, Color PC);
	void UnHighlightCell(int sri, int sci, Color, sf::RenderWindow& window);
	bool Check(Color PC);
	bool Selfcheck(int sri, int sci, int dri, int dci, Color PC);
	bool isMyPiece(int ri, int ci, Color Pc);
	bool IsvalidDestination(int, int, Color);
	bool checkMate(Color Pc);
	void Promotion(int dri, int dci,sf::RenderWindow& window);
	bool stalemate(Color Pc);
	bool Castling(int sri, int sci, int dri, int dci,int &_dr,int &_dc);
	void DrawSouceCell(int sri, int sci, sf::RenderWindow& window);
	bool IsPromotion(int dri, int dci);
};

