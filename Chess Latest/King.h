#pragma once
#include"Piece.h"
class King :public Piece
{
	bool isFirst;
public:
	King(int _r, int c_, Color _Cl, Board* _b, int Dclr);
	virtual void Draw(int Dp_r, int Dp_c, sf::RenderWindow& window) override;
	virtual bool Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)override;
	void SetIsfirstMove(bool Y);
	//bool GetIsFirstMove();
	virtual bool GetIsFirstMove()override;
}
;

