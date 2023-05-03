#include<iostream>
#include"Utility.h"
#include"Cell.h"
#include "Piece.h"
#include "Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"King.h"
#include"Queen.h"
#include <iostream>
#include <fstream>

using namespace std;

Cell::Cell()
{
	Clclr = 0;
	name = '.';
	size = 0;
	ri = 0, ci = 0, DispLr = 0, DispLc = 0;
	B = nullptr;
	P = nullptr;
}
void Cell::setName(char c)
{
	name = c;
 }
char Cell::GetName()
{
	return name;;
 }
Cell::Cell(const Cell &C2)
{

	this->Clclr=C2.Clclr;
	this->name=C2.name;

	this->ri=C2.ri, this->ci=C2.ci, this->DispLr=C2.DispLr, this->DispLc=C2.DispLc;
	this->B=C2.B;
	this->p1_clr=C2.p1_clr;
	this->p2_clr =C2.p2_clr ;

	this->size = C2.size;

	if (name == 'P')
	{
		this->P = new Pawn(ri, ci, WHITE, B, p1_clr);

	}
	else if (name == 'p')
	{
		this->P = new Pawn(ri, ci, BLACK, B, p2_clr);

	}

	else if (name == 'R')
	{

		this->P = new Rook(ri, ci, WHITE, B, p1_clr);
	}
	else if (name == 'r')

	{
		this->P = new Rook(ri, ci, BLACK, B, p2_clr);
	}

	else if (name == 'N')

	{
		this->P = new Knight(ri, ci, WHITE, B, p1_clr);
	}
	else if (name == 'n')
	{

		this->P = new Knight(ri, ci, BLACK, B, p2_clr);
	}

	else if (name == 'B')

	{
		this->P = new Bishop(ri, ci, WHITE, B, p1_clr);
	}
	else if (name == 'b')

	{
		this->P = new Bishop(ri, ci, BLACK, B, p2_clr);
	}

	else if (name == 'K')

	{
		this->P = new King(ri, ci, WHITE, B, p1_clr);
	}
	else if (name == 'k')

	{
		this->P = new King(ri, ci, BLACK, B, p2_clr);
	}

	else if (name == 'Q')

	{
		this->P = new Queen(ri, ci, WHITE, B, p1_clr);
	}
	else if (name == 'q')
	{
		this->P = new Queen(ri, ci, BLACK, B, p2_clr);
	}
	else this->P = nullptr;

	this->Rec = C2.Rec;
	this->Rec.setSize(C2.Rec.getSize());
	this->Rec.setPosition(C2.Rec.getPosition());
	this->Rec.setOutlineThickness(C2.Rec.getOutlineThickness());
	this->Rec.setOutlineColor(C2.Rec.getOutlineColor());


}
Cell::Cell(int Disp_r, int Disp_c, int r, int c, char n, int _size, Board* b)
{


	if (n == 'P')
	{
		P = new Pawn(r, c, WHITE, b, p1_clr);

	}
	else if (n == 'p')
	{
		P = new Pawn(r, c, BLACK, b, p2_clr);

	}

	else if (n == 'R')
	{

		P = new Rook(r, c, WHITE, b, p1_clr);
	}
	else if (n == 'r')

	{
		P = new Rook(r, c, BLACK, b, p2_clr);
	}

	else if (n == 'N')

	{
		P = new Knight(r, c, WHITE, b, p1_clr);
	}
	else if (n == 'n')
	{

		P = new Knight(r, c, BLACK, b, p2_clr);
	}

	else if (n == 'B')

	{
		P = new Bishop(r, c, WHITE, b, p1_clr);
	}
	else if (n == 'b')

	{
		P = new Bishop(r, c, BLACK, b, p2_clr);
	}

	else if (n == 'K')

	{
		P = new King(r, c, WHITE, b, p1_clr);
	}
	else if (n == 'k')

	{
		P = new King(r, c, BLACK, b, p2_clr);
	}

	else if (n == 'Q')

	{
		P = new Queen(r, c, WHITE, b, p1_clr);
	}
	else if (n == 'q')
	{
		P = new Queen(r, c, BLACK, b, p2_clr);
	}
	else P = nullptr;

	if (((r + c) % 2 == 0))
		Clclr = 15;
	else Clclr = 0;

	sf::Color lightBrown(200, 160, 100);
	sf::Color aqua(0, 255, 255);
	//
    sf::Color gray(128, 128, 128);
	name = n;
	size = _size;
	B = b;
	ri = r; ci = c;
	DispLr = Disp_r;
	DispLc = Disp_c;
	Rec.setSize(sf::Vector2f(80, 80));
	if (Clclr == 0)
		Rec.setFillColor(sf::Color::Black);
	else
		Rec.setFillColor(sf::Color::White);

	Rec.setPosition(DispLc, DispLr);
	Rec.setOutlineThickness(1);
	Rec.setOutlineColor(sf::Color::White);
}
void Cell::Draw(sf::RenderWindow& Window)
{
	/*for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			SetClr(Clclr);
			gotoRowCol(DispLr + r, DispLc + c);
			cout << char(-37);

		}
		cout << endl;
	}*/

	
	 
	Window.draw(Rec);
	


	if (P != nullptr)
		P->Draw(DispLr, DispLc,Window);
}
Color Cell::GetPieceColor()
{
	return P->GetColor();
}
void Cell::SetPiece(Piece* n)
{
	this->P = n;
}
Piece* Cell::GetPiece()
{
	return this->P;
}
bool Cell::LegalMove(int sri, int sci, int dri, int dci, char** A, Color DP,char T)
{
	if (P != nullptr)
		return P->Legalty(sri, sci, dri, dci, A, DP,T);
	return false;
}
void Cell::Highlight( sf::RenderWindow& window, int sri, int sci,sf::Color C)
{/*
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			SetClr(2);
			if (r == 0 || r == size - 1 || c == 0 || c == size - 1)
			{
				gotoRowCol(DispLr + r, DispLc + c);
				cout << char(-37);
			}

		}
		cout << endl;
	}*/
	
	if (this->ri == sri && this->ci == sci)
	{
		Rec.setOutlineThickness(5);
		Rec.setOutlineColor(sf::Color::Blue);
	}
	else
	Rec.setFillColor(C);
	
	
	
	this->Draw(window);

}
void Cell::UnHighlight(sf::RenderWindow& window, int sri, int sci)
{
	
	if (this->ri == sri && this->ci == sci)
	{

		Rec.setOutlineColor(sf::Color::White);


		Rec.setOutlineThickness(1);
	}
	else 
	{
		if (Clclr == 0)
			Rec.setFillColor(sf::Color::Black);
		else
			Rec.setFillColor(sf::Color::White);

	}
	this->Draw(window);
	
}
void Cell::Promotion(int dri, int dci, char nam, Board* b)
{
	if (nam == 'Q')
		this->P = new Queen(dri, dci, WHITE, b, p1_clr);
	else if (nam == 'q')
		this->P = new Queen(dri, dci, BLACK, b, p2_clr);

	else if (nam == 'N')
		this->P = new Knight(dri, dci, WHITE, b, p1_clr);
	else if (nam == 'n')
		this->P = new Knight(dri, dci, BLACK, b, p2_clr);

	else if (nam == 'B')
		this->P = new Bishop(dri, dci, WHITE, b, p1_clr);
	else if (nam == 'b')
		this->P = new Bishop(dri, dci, BLACK, b, p2_clr);

	else if (nam == 'R')
		this->P = new Rook(dri, dci, WHITE, b, p1_clr);
	else if (nam == 'r')
		this->P = new Rook(dri, dci, BLACK, b, p2_clr);

}
bool Cell::GetFirstMove()
{
	return this->P->GetIsFirstMove();
}
