#pragma once
#include"Utility.h"
#include<SFML/Graphics.hpp>

class Board;
class Piece;
class Cell
{
	int Clclr;
	char name;
	int size;
	int ri, ci, DispLr, DispLc;
	Board* B;
	Piece* P;
	int p1_clr = 1;
	int p2_clr = 5;
	sf::RectangleShape Rec;
public:
	Cell();
	Cell(const Cell& C2);
	Cell(int Disp_r, int Disp_c, int r, int c, char n, int size, Board*);
	void Draw(sf::RenderWindow & Window);
	Color GetPieceColor();
	void SetPiece(Piece*);
	Piece* GetPiece();
	bool LegalMove(int sri, int sci, int dri, int dci, char** A, Color DP, char T);
	void Highlight( sf::RenderWindow& window,int sri,int sci, sf::Color C);
	void UnHighlight(sf::RenderWindow& window,  int sri, int sci);
	void Promotion(int dri, int dci, char nam, Board* b);
	//void Castling();
	bool GetFirstMove();
	void setName(char c);
	char GetName();
};

