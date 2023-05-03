#include "Knight.h"
#include"Utility.h"

Knight::Knight(int _r, int c_, Color _Cl, Board* _b, int Dclr)
	:Piece(_r, c_, _Cl, _b, Dclr)
{
}
void Knight::Draw(int Dp_r, int Dp_c, sf::RenderWindow& window)
{
	sf::Texture BN;
if(disClr==1)	
BN.loadFromFile(("BrownKnight.png"));
else 
BN.loadFromFile(("BlackKnight.png"));

	sf::Sprite BKnight(BN);

	BKnight.setPosition(sf::Vector2f(Dp_c + 23, Dp_r + 5));
	window.draw(BKnight);
	//window.display();
}
bool Knight::Legalty(int sri, int sci, int dri, int dci, char** A, Color DP,char T)
{
	int Delta_r = abs(sri - dri);
	int Delta_c = abs(sci - dci);
	return(Delta_c == 2 && Delta_r == 1) || (Delta_r == 2 && Delta_c == 1);

}
bool Knight::GetIsFirstMove()
{
	return IsFirstMove;
}