#include "Pawn.h"
#include"Utility.h"
Pawn::Pawn(int _r, int c_, Color _Cl, Board* _b, int dclr)
	:Piece(_r, c_, _Cl, _b, dclr)
{
}
void Pawn::Draw(int Dp_r, int Dp_c, sf::RenderWindow& window)
{
	sf::Texture BP;
	if(disClr==1)
	BP.loadFromFile(("BrownPawn.png"));
	else 
	BP.loadFromFile(("BlackPawn.png"));
	sf::Sprite BPawn(BP);

	BPawn.setPosition(sf::Vector2f(Dp_c + 23, Dp_r + 5));
	window.draw(BPawn);


}
bool Pawn::Legalty(int sri, int sci, int dri, int dci, char** A, Color DP, char T)
{
	int Delta_r = abs(sri - dri);
	int Delta_c = abs(sci - dci);
	if ((C == WHITE && sri > 1) || (C == BLACK && sri < 6))	
		isFirstMove = false;

	if (isFirstMove == true)
	{
		if (A[dri][dci] == '-')
		{
			if (Delta_r == 2 || Delta_r == 1)
			{
				if ((C == WHITE) && (sri < dri))
					return((IsVerticalMOve(sri, sci, dri, dci) && IsVertPathClear(sri, sci, dri, dci, A)));

				if ((C == BLACK) && (sri > dri))
					return ((IsVerticalMOve(sri, sci, dri, dci) && IsVertPathClear(sri, sci, dri, dci, A)));
			}
		}
		if ((C != DP) && DP != NullClr)
		{
			if (C == WHITE && (dri - sri == 1))
			{
				return IsDiagonalMove(sri, sci, dri, dci) && (IsDiagonal1_Pathclear(sri, sci, dri, dci, A) || IsDiagonal2_Pathclear(sri, sci, dri, dci, A));
			}
			if (C == BLACK && (sri - dri == 1))
			{
				return IsDiagonalMove(sri, sci, dri, dci) && (IsDiagonal1_Pathclear(sri, sci, dri, dci, A) || IsDiagonal2_Pathclear(sri, sci, dri, dci, A));
			}
		}
	}

	else
	{
		if (A[dri][dci] == '-')
		{
			if (Delta_r == 1)
			{
				if ((C == WHITE) && (sri < dri))
					return((IsVerticalMOve(sri, sci, dri, dci) && IsVertPathClear(sri, sci, dri, dci, A)));

				if ((C == BLACK) && (sri > dri))
					return ((IsVerticalMOve(sri, sci, dri, dci) && IsVertPathClear(sri, sci, dri, dci, A)));
			}
		}
		if ((C != DP) && DP != NullClr)
		{
			if (C == WHITE && (dri - sri == 1))
			{
				return IsDiagonalMove(sri, sci, dri, dci) && (IsDiagonal1_Pathclear(sri, sci, dri, dci, A) || IsDiagonal2_Pathclear(sri, sci, dri, dci, A));
			}
			if (C == BLACK && (sri - dri == 1))
			{
				return IsDiagonalMove(sri, sci, dri, dci) && (IsDiagonal1_Pathclear(sri, sci, dri, dci, A) || IsDiagonal2_Pathclear(sri, sci, dri, dci, A));
			}
		}
	}

	return false;
}
bool Pawn::GetIsFirstMove()
{
	return IsFirstMove;
}