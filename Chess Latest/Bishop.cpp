#include "Bishop.h"
#include"Utility.h"

Bishop::Bishop(int _r, int c_, Color _Cl, Board* _b, int Dclr)
	:Piece(_r, c_, _Cl, _b, Dclr)
{
}
void Bishop::Draw(int Dp_r, int Dp_c, sf::RenderWindow& window)
{
	
	sf::Texture BB;
	if(disClr==1)
	BB.loadFromFile(("BrownBishop.png"));
	else 
	BB.loadFromFile(("BlackBishop.png"));
	
	sf::Sprite BBishop(BB);

	BBishop.setPosition(sf::Vector2f(Dp_c + 23, Dp_r + 5));
	window.draw(BBishop);

}
bool Bishop::Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)
{

	return BishopLegalty(sri, sci, dri, dci, A);
}
 bool Bishop::GetIsFirstMove()
{
	 return IsFirstMove;
}