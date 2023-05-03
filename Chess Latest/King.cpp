#include "King.h"
#include"Utility.h"
#include<SFML/Graphics.hpp>

King::King(int _r, int c_, Color _Cl, Board* _b, int Dclr)
	:Piece(_r, c_, _Cl, _b, Dclr)
{
	this->isFirst = true;
}
void King::Draw(int Dp_r, int Dp_c, sf::RenderWindow & window)
{

	//SetClr(disClr);
	//int size = 6;
	//int P_r = Dp_r + 2;
	//int P_c = Dp_c + 4;
	////cout << ((C == WHITE) ? 'P' : 'p');
	//gotoRowCol(P_r, P_c - 2);
	//cout << char(-37);
	//gotoRowCol(P_r, P_c);
	//cout << char(-37);
	//gotoRowCol(P_r, P_c + 2);
	//cout << char(-37);

	//for (int c = P_c - 1; c < P_c + 2; c++)
	//{
	//	gotoRowCol(P_r + 1, c);
	//	cout << char(-37);
	//}

	//for (int r = P_r; r < P_r + 4; r++)//r=row,r<row+5
	//{
	//	gotoRowCol(r, P_c);
	//	cout << char(-37);
	//}
	//for (int c = P_c - 1; c < P_c + 2; c++)
	//{
	//	gotoRowCol(P_r + 3, c);
	//	cout << char(-37);
	//}

	//for (int c = P_c - 2; c < P_c + 3; c++)
	//{
	//	gotoRowCol(P_r + 4, c);
	//	cout << char(-37);
	//}

	sf::Texture Bk;
			if (disClr == 1)
			{
				Bk.loadFromFile(("brown_king.png"));
		
				sf::Sprite Bking(Bk);
				Bking.setPosition(sf::Vector2f(Dp_c + 16, Dp_r + 5));
				window.draw(Bking);
			}

	else 
			{
				Bk.loadFromFile(("BlackKing.png"));
				sf::Sprite Bking(Bk);
				Bking.setPosition(sf::Vector2f(Dp_c + 16, Dp_r -3));
				window.draw(Bking);
			}



}
bool King::Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)
{
	int Delta_r = abs(sri - dri);
	int Delta_c = abs(sci - dci);
	if (Delta_c <= 1 && Delta_r <= 1)
	{
		if (BishopLegalty(sri, sci, dri, dci, A) || RookLegalty(sri, sci, dri, dci, A));
		{
			if (T == '-')
			this->isFirst = false;
			return true;
		}
	}
	return false;
}
bool King::GetIsFirstMove()
{
	return this->isFirst;
}