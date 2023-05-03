#include "Queen.h"
#include"Utility.h"
Queen::Queen(int _r, int c_, Color _Cl, Board* _b, int dclr)
	:Piece(_r, c_, _Cl, _b, dclr)
{
}
void Queen::Draw(int Dp_r, int Dp_c, sf::RenderWindow& window)
{

	sf::Texture BQ;
	if(disClr==1)
	BQ.loadFromFile(("BrownQueen.png"));
	else
	BQ.loadFromFile(("BlackQueen.png"));

	sf::Sprite BQueen(BQ);

	BQueen.setPosition(sf::Vector2f(Dp_c + 23, Dp_r + 5));
	window.draw(BQueen);

}
bool Queen::Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)
{
	return BishopLegalty(sri, sci, dri, dci, A) || RookLegalty(sri, sci, dri, dci, A);

}
bool Queen::GetIsFirstMove()
{
	return IsFirstMove;
}