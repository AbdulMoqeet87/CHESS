#pragma once
#include"Utility.h"
#include<SFML/Graphics.hpp>

class Board;
class Piece
{
protected:
	int ri, ci;
	Color C;
	int disClr;
	Board* B;
	bool IsFirstMove = true;
public:
	Piece(int _r, int _c, Color _Cr, Board* _b, int Dclr);
	Piece(const Piece& P2);
	virtual void Draw(int Dp_r, int Dp_c,sf::RenderWindow & window) = 0;
	virtual bool Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T) = 0;
	void MovePiece(int _r, int _c);
	Color GetColor();
	bool IsHorizontalMOve(int sri, int sci, int dri, int dci);
	bool IsVerticalMOve(int sri, int sci, int dri, int dci);
	bool IsForwardDigMove(int sri, int sci, int dri, int dci);
	bool IsBackwardDigMove(int sri, int sci, int dri, int dci);
	bool IsDiagonalMove(int sri, int sci, int dri, int dci);
	bool IsHorzPathClear(int sri, int sci, int dri, int dci, char** A);
	bool IsVertPathClear(int sri, int sci, int dri, int dci, char** A);
	bool IsDiagonal1_Pathclear(int sri, int sci, int dri, int dci, char** A);
	bool IsDiagonal2_Pathclear(int sri, int sci, int dri, int dci, char** A);
	bool BishopLegalty(int sri, int sci, int dri, int dci, char** A);
	bool RookLegalty(int sri, int sci, int dri, int dci, char** A);
	virtual bool GetIsFirstMove()=0;

};

