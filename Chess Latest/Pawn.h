#pragma once
#include"Piece.h"
class Pawn :public Piece
{
	bool isFirstMove = true;

public:
	Pawn(int _r, int c_, Color _Cl, Board* _b, int Dclr);
	virtual void Draw(int Dp_r, int Dp_c, sf::RenderWindow& window) override;
	virtual bool Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)override;
	virtual bool GetIsFirstMove()override;
};

