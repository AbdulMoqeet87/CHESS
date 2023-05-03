#include "Piece.h"


Piece::Piece(int _r, int _c, Color _Cr, Board* _b, int Dclr)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _Cr;
	this->B = _b;
	this->disClr = Dclr;
}
void Piece::MovePiece(int _r, int _c)
{

	this->ri = _r;
	this->ci = _c;
}
Color Piece::GetColor()
{
	if (this == nullptr)
		return NullClr;
	return this->C;
}
bool Piece::IsHorizontalMOve(int sri, int sci, int dri, int dci)
{

	return (sri == dri);
}
bool Piece::IsVerticalMOve(int sri, int sci, int dri, int dci)
{
	return (sci == dci);
}
bool Piece::IsForwardDigMove(int sri, int sci, int dri, int dci)
{

	return((dri < sri&& dri < sri) || (dri<sri&& dri>sri));


}
bool Piece::IsBackwardDigMove(int sri, int sci, int dri, int dci)
{

	return((dri > sri && dri < sri) || (dri > sri && dri > sri));


}
bool Piece::IsDiagonalMove(int sri, int sci, int dri, int dci)
{
	int delta_R = abs(sri - dri);
	int  delta_C = abs(sci - dci);

	return (delta_R == delta_C);
}
bool Piece::IsHorzPathClear(int sri, int sci, int dri, int dci, char** A)
{
	int sp = 0, ep = 0;

	if (sci < dci)
	{
		sp = sci + 1;	ep = dci - 1;
	}

	if (sci > dci)
	{
		sp = dci + 1;	ep = sci - 1;
	}

	for (int c = sp; c <= ep; c++)
	{

		//(B->IsApiece(sri, c))

		if (A[sri][c] != '-')
			return false;
	}
	return true;

}
bool Piece::IsVertPathClear(int sri, int sci, int dri, int dci, char** A)
{
	int sp = 0, ep = 0;

	if (sri < dri)
	{
		sp = sri + 1;	ep = dri - 1;
	}

	if (sri > dri)
	{
		sp = dri + 1;	ep = sri - 1;
	}

	for (int r = sp; r <= ep; r++)
	{

		if (A[r][sci] != '-')
			return false;

	}
	return true;

}
bool Piece::IsDiagonal1_Pathclear(int sri, int sci, int dri, int dci, char** A)
{

	int Delta_r, sp, ep;


	Delta_r = abs(sri - dri);


	if (sri < dri)
	{

		for (int i = 1; i < Delta_r; i++)
		{

			if (A[sri + i][sci + i] != '-')
				return false;
		}
		return true;

	}
	else
	{
		for (int i = 1; i < Delta_r; i++)
		{

			if (A[sri - i][sci - i] != '-')
				return false;
		}
		return true;
	}
}
bool Piece::IsDiagonal2_Pathclear(int sri, int sci, int dri, int dci, char** A)
{

	int Delta_r, sp, ep;


	Delta_r = abs(sri - dri);


	if (sri < dri)
	{

		for (int i = 1; i < Delta_r; i++)
		{

			if (A[sri + i][sci - i] != '-')
				return false;
		}
		return true;

	}
	else
	{
		for (int i = 1; i < Delta_r; i++)
		{

			if (A[sri - i][sci + i] != '-')
				return false;
		}
		return true;
	}
}
bool Piece::BishopLegalty(int sri, int sci, int dri, int dci, char** A)
{
	if ((sri > dri && dci > sci) || sri<dri && sci>dci)
		return IsDiagonalMove(sri, sci, dri, dci) && IsDiagonal2_Pathclear(sri, sci, dri, dci, A);
	else if (((sri > dri && dci < sci) || sri < dri && sci < dci))
		return IsDiagonalMove(sri, sci, dri, dci) && IsDiagonal1_Pathclear(sri, sci, dri, dci, A);
	return false;
}
bool Piece::RookLegalty(int sri, int sci, int dri, int dci, char** A)
{

	return (IsVerticalMOve(sri, sci, dri, dci) && IsVertPathClear(sri, sci, dri, dci, A)) || (IsHorizontalMOve(sri, sci, dri, dci) && IsHorzPathClear(sri, sci, dri, dci, A));

}
Piece::Piece(const Piece& P2)
{
	this->ri=P2.ri, this->ci=P2.ci;
	int disClr;
this->B=P2.B;
	this->IsFirstMove=P2.IsFirstMove ;
this->C = P2.C;


}