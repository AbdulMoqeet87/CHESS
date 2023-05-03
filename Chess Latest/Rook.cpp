#include "Rook.h"
#include"Utility.h"
using namespace std;

Rook::Rook(int _r, int c_, Color _Cl, Board* _b, int dclr)
	:Piece(_r, c_, _Cl, _b, dclr)
{
	this->isFirst = true;
}
void Rook::Draw(int Dp_r, int Dp_c, sf::RenderWindow& window)
{

	sf::Texture BR;
	if(disClr==1)
	BR.loadFromFile(("BrownRook.png"));
	else 
		BR.loadFromFile(("BlackRook.png"));
	sf::Sprite BRook(BR);

	BRook.setPosition(sf::Vector2f(Dp_c + 23, Dp_r + 5));
	window.draw(BRook);

}
bool Rook::Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)
{
	if (RookLegalty(sri, sci, dri, dci, A))
	{
		if(T=='-')
		this->isFirst = false;
		return true;
	}
}
bool Rook::GetIsFirstMove()
{
return this->isFirst;
}