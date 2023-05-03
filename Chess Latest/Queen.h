#pragma once
#include"Piece.h"
class Queen :public Piece
{
public:
	Queen(int _r, int c_, Color _Cl, Board* _b, int dclr);
	virtual void Draw(int Dp_r, int Dp_c, sf::RenderWindow& window) override;
	virtual bool Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)override;

	virtual bool GetIsFirstMove()override;

};

