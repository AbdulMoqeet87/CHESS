#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"King.h"
#include"Queen.h"
#include"Cell.h"
#include <iostream>
#include <fstream>

using namespace std;
Board::Board(ifstream& Rdr)
{

	this->LoadChar(Rdr);

	int Cellsize = 80;
	int ColMargin = 350;
	int RowMargin = 40;
	C = new Cell * *[8];

	for (int r = 0, Disp_r = RowMargin; r < 8; r++, Disp_r += Cellsize)
	{
		C[r] = new Cell * [8];
		for (int c = 0, Disp_c = ColMargin; c < 8; c++, Disp_c += Cellsize)
		{
			C[r][c] = new Cell(Disp_r, Disp_c, r, c, A[r][c], Cellsize, this);
		}
	}

}
void Board::DisplayBoard(sf::RenderWindow & window)
{

	
	
		for (int ri = 0; ri < 8; ri++)
		{
			for (int ci = 0; ci < 8; ci++)
			{
				C[ri][ci]->Draw(window);
			}
			//cout << endl;
		}

	

}
Color Board::PieceColor(int ri, int ci)
{
	if (A[ri][ci] == '-')
		return NullClr;
	return C[ri][ci]->GetPieceColor();

}
void Board::Update(int sr, int sc, int dr, int dc, int turn,int P1_Time,int P2_Time,vector<Board>&Ud)
{
	int _dr = 0, _dc = 0;
	

	{
		if (Castling(sr, sc, dr, dc, _dr, _dc))
		{
			if (sc < dc)
			{
				C[dr][dc]->SetPiece(C[sr][sc]->GetPiece());
				C[sr][sc]->SetPiece(nullptr);
				C[dr][dc]->setName(C[sr][sc]->GetName());
				C[sr][sc]->setName('.');

				A[dr][dc] = A[sr][sc];
				A[sr][sc] = '-';

				C[dr][dc - 1]->SetPiece(C[_dr][_dc]->GetPiece());
				C[_dr][_dc]->SetPiece(nullptr);
				C[dr][dc - 1]->setName(C[_dr][_dc]->GetName());
				C[_dr][_dc]->setName('.');
				
				A[dr][dc - 1] = A[_dr][_dc];
				A[_dr][_dc] = '-';
				DispRowDest(_dr, _dc, dr, dc - 1);
				DispRowDest(sr, sc, dr, dc);


			}
			if (sc > dc)
			{
				C[dr][dc]->SetPiece(C[sr][sc]->GetPiece());
				C[sr][sc]->SetPiece(nullptr);
				C[dr][dc]->setName(C[sr][sc]->GetName());
				C[sr][sc]->setName('.');

				A[dr][dc] = A[sr][sc];
				A[sr][sc] = '-';

				C[dr][dc + 1]->SetPiece(C[_dr][_dc]->GetPiece());
				C[_dr][_dc]->SetPiece(nullptr);
				C[dr][dc + 1]->setName(C[_dr][_dc]->GetName());
				C[_dr][_dc]->setName('.');
				
				
				A[dr][dc + 1] = A[_dr][_dc];
				A[_dr][_dc] = '-';
				DispRowDest(_dr, _dc, dr, dc + 1);
				DispRowDest(sr, sc, dr, dc);


			}
		}

		else
		{
			C[dr][dc]->SetPiece(C[sr][sc]->GetPiece());
			C[sr][sc]->SetPiece(nullptr);
			C[dr][dc]->setName(C[sr][sc]->GetName());
			C[sr][sc]->setName('.');
			A[dr][dc] = A[sr][sc];
			A[sr][sc] = '-';
		}
	}
	
	Save(turn,  P1_Time,P2_Time);

	Ud.push_back(*this);
}
void Board::Save(int turn,int P1_Time,int P2_Time)
{
	ofstream Wtr("output.txt");

	for (int r = 0; r < 8; r++)
	{

		for (int c = 0; c < 8; c++)
		{
			Wtr << A[r][c];
		}
		Wtr << "\n";
	}
	Wtr << turn<<"\n";
	Wtr << P1_Time << "\n" <<P2_Time;

}
bool Board::IsApiece(int ri, int ci)
{
	if (C[ri][ci]->GetPiece() != nullptr)
		return true;
	return false;
}
void Board::LoadChar(ifstream& Rdr)
{

	A = new char* [8];
	for (int r = 0; r < 8; r++)
	{
		A[r] = new char[8];
		for (int c = 0; c < 8; c++)
		{
			Rdr >> A[r][c];
		}
	}

}
void Board::DispRowDest(int sri, int sci, int dri, int dci)
{
	//C[sri][sci]->Draw();
	//C[dri][dci]->Draw();
}
bool Board::IslegalMove(int sri, int sci, int dri, int dci,char T)
{
	Color DP = C[dri][dci]->GetPieceColor();
	return(C[sri][sci]->LegalMove(sri, sci, dri, dci, A, DP,T));
}
void Board::HighlightCell(int sri, int sci, Color PC, sf::RenderWindow& window)
{
	C[sri][sci]->Highlight(window, sri, sci,sf::Color::Blue);
	for (int _ri = 0; _ri < 8; _ri++)
	{
		for (int _ci = 0; _ci < 8; _ci++)
		{
			if ((C[sri][sci]->GetPieceColor() != C[_ri][_ci]->GetPieceColor()))
			{
				if ((C[sri][sci]->LegalMove(sri, sci, _ri, _ci, A, C[_ri][_ci]->GetPieceColor(),'h')) && (Selfcheck(sri, sci, _ri, _ci, PC)))
				{
				
					if(C[_ri][_ci]->GetPieceColor()!=NullClr)
					C[_ri][_ci]->Highlight(window, sri, sci, sf::Color::Red);
					else 
						C[_ri][_ci]->Highlight(window, sri, sci, (sf::Color(0, 255, 0, 200)));
				}
			}
		}
	}

}
void Board::UnHighlightCell(int sri, int sci, Color PC, sf::RenderWindow& window)
{
	C[sri][sci]->UnHighlight(window, sri, sci);
	for (int _ri = 0; _ri < 8; _ri++)
	{
		for (int _ci = 0; _ci < 8; _ci++)
		{
			if ((C[sri][sci]->GetPieceColor() != C[_ri][_ci]->GetPieceColor()))
			{
				if (C[sri][sci]->LegalMove(sri, sci, _ri, _ci, A, C[_ri][_ci]->GetPieceColor(),'h') && (Selfcheck(sri, sci, _ri, _ci, PC)))
					C[_ri][_ci]->UnHighlight(window,sri,sci);
			}
		}
	}

}
bool Board::FindKIng(int dri, int dci, Color PC)
{
	if (PC == WHITE)
	{
		if (A[dri][dci] == 'k')
			return true;

	}
	else if (PC == BLACK)
	{
		if (A[dri][dci] == 'K')
			return true;
	}
	return false;

}
bool Board::Check(Color PC)
{
	if (PC == WHITE)PC = BLACK;
	else if (PC == BLACK)PC = WHITE; else PC + NullClr;

	for (int _sr = 0; _sr < 8; _sr++)
	{
		for (int _sc = 0; _sc < 8; _sc++)
		{
			for (int _dr = 0; _dr < 8; _dr++)
			{
				for (int _dc = 0; _dc < 8; _dc++)
				{
					if ((C[_sr][_sc]->GetPieceColor() != C[_dr][_dc]->GetPieceColor()) && PC != C[_dr][_dc]->GetPieceColor())
					{
						if (C[_sr][_sc]->GetPieceColor() != NullClr && C[_dr][_dc]->GetPieceColor() != NullClr)
						{

							if (FindKIng(_dr, _dc, PC))
							{
								if (C[_sr][_sc]->LegalMove(_sr, _sc, _dr, _dc, A, C[_dr][_dc]->GetPieceColor(),'h'))
									return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool Board::Selfcheck(int sri, int sci, int dri, int dci, Color PC)
{
	//Cell Temp= new Cell();
	int Cellsize = 9;
	int ColMargin = 45;
	int RowMargin = 5;

	Cell* H = new Cell();
	char T = '-';

	H->SetPiece((C[dri][dci]->GetPiece()));
	T = A[dri][dci];

	C[dri][dci]->SetPiece(C[sri][sci]->GetPiece());
	C[sri][sci]->SetPiece(nullptr);
	A[dri][dci] = A[sri][sci];
	A[sri][sci] = '-';

	if (Check(PC))
	{
		C[sri][sci]->SetPiece(C[dri][dci]->GetPiece());
		C[dri][dci]->SetPiece(H->GetPiece());
		A[sri][sci] = A[dri][dci];
		A[dri][dci] = T;
		delete H;
		return false;
	}
	else
	{
		C[sri][sci]->SetPiece(C[dri][dci]->GetPiece());
		C[dri][dci]->SetPiece(H->GetPiece());
		A[sri][sci] = A[dri][dci];
		A[dri][dci] = T;
		delete H;
		return true;
	}
}
bool Board::IsvalidDestination(int dri, int dci, Color Pc)
{
	if ((dri < 0 || dri >= 8) || (dci < 0 || dci >= 8))
		return false;
	if (isMyPiece(dri, dci, Pc))
		return false;
	return true;
}
bool Board::isMyPiece(int ri, int ci, Color PC)
{
	return PieceColor(ri, ci) == PC;
}
bool Board::checkMate(Color Pc)
{
	if (Check(Pc))
	{
		for (int _sr = 0; _sr < 8; _sr++)
		{
			for (int _sc = 0; _sc < 8; _sc++)
			{
				for (int _dr = 0; _dr < 8; _dr++)
				{
					for (int _dc = 0; _dc < 8; _dc++)
					{
						if ((C[_sr][_sc]->GetPieceColor() != C[_dr][_dc]->GetPieceColor()) && C[_sr][_sc]->GetPieceColor() == Pc)
						{
							if (IslegalMove(_sr, _sc, _dr, _dc,'h') && (Selfcheck(_sr, _sc, _dr, _dc, Pc)))
							{
								
								return false;
							}
						}

					}

				}

			}

		}

		return true;

	}
	return false;
}
void Board::Promotion(int dri, int dci,sf::RenderWindow &window)
{


	sf::Texture B;
	B.loadFromFile("pawnPromote.png");

	sf::Sprite Promt(B);
	Promt.setPosition(0, -180);
	Promt.setScale(0.3, 0.3);
	//window.setPosition(sf::Vector2i(0, 0));

	//-----------------------------------
	sf::RectangleShape Queen;
	Queen.setFillColor(sf::Color::White);
	Queen.setSize(sf::Vector2f(80, 80));
	Queen.setPosition(450, 250);
	
	sf::Texture BQ;
	BQ.loadFromFile(("BlackQueen.png"));

	sf::Sprite BQueen(BQ);

	BQueen.setPosition(sf::Vector2f(450 + 23, 250 + 5));

	
	//----------------------
	sf::RectangleShape Rook;
	Rook.setFillColor(sf::Color::White);
	Rook.setSize(sf::Vector2f(80, 80));
	Rook.setPosition(600, 250);

	sf::Texture BR;
	BR.loadFromFile(("BlackRook.png"));
	sf::Sprite BRook(BR);

	BRook.setPosition(sf::Vector2f(600 + 23, 250+ 5));
	
	//----------------------
	sf::RectangleShape Bishop;
	Bishop.setFillColor(sf::Color::White);
	Bishop.setSize(sf::Vector2f(80, 80));
	Bishop.setPosition(750, 250);
	sf::Texture BB;
	
	BB.loadFromFile(("BlackBishop.png"));

	sf::Sprite BBishop(BB);

	BBishop.setPosition(sf::Vector2f(750+ 23, 250+ 5));
	


	//----------------------
	sf::RectangleShape Knight;
	Knight.setFillColor(sf::Color::White);
	Knight.setSize(sf::Vector2f(80, 80));
	Knight.setPosition(900, 250);
	sf::Texture BN;
	
	BN.loadFromFile(("BlackKnight.png"));

	sf::Sprite BKnight(BN);

	BKnight.setPosition(sf::Vector2f(900 + 23, 250+ 5));
	
	//-------------------------


	sf::Color normalColor = sf::Color::White;
	sf::Color hoverColor = sf::Color::Green;
	//------------------------------
	sf::Font Lato;
	Lato.loadFromFile("Lato.ttf");

	sf::Text NG("PROMOTION", Lato, 70);
	NG.setPosition(500, 50);
	NG.setFillColor(sf::Color::White);
	NG.setOutlineColor(sf::Color::Black);
	NG.setOutlineThickness(3);
	//----------------------------
	bool GoBack = false;
	int choice = 0;
	//-------------------

	while (window.isOpen())
	{

		sf::Event evnt;
		
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
			if (evnt.type == sf::Event::MouseMoved )
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (Queen.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
				
					Queen.setOutlineColor(hoverColor);
					Queen.setOutlineThickness(7);
					
				}
				else
				{
					Queen.setOutlineColor(normalColor);
					Queen.setOutlineThickness(1);

				}

				
					
				if (Rook.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					Rook.setOutlineColor(hoverColor);
					Rook.setOutlineThickness(7);

				}
				
				else
				{
					Rook.setOutlineColor(normalColor);
					Rook.setOutlineThickness(1);
				};

			
				 if (Bishop.getGlobalBounds().contains(mousePos.x, mousePos.y))

				 {
					 Bishop.setOutlineColor(hoverColor);
					 Bishop.setOutlineThickness(7);
				 }
				 else
				 {
					 Bishop.setOutlineColor(normalColor);
					 Bishop.setOutlineThickness(1);
				 }

				 
				 if (Knight.getGlobalBounds().contains(mousePos.x, mousePos.y))

				 {
					 Knight.setOutlineColor(hoverColor);
					 Knight.setOutlineThickness(7);
				 }

				else
				 {
					 Knight.setOutlineColor(normalColor);
					 Knight.setOutlineThickness(1);
				 }
				

			}


			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (Queen.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{

					choice = 1;
					GoBack = true;
				}
			
				else if (Rook.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					choice = 2;
					GoBack = true;
				}
				else if(Bishop.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					choice = 3;
					GoBack = true;
				}
				if (Knight.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					choice = 4;
					GoBack = true;
				}



			}

		}
		if (GoBack)
			break;
		window.clear();
		window.draw(Promt);
		window.draw(NG);
		window.draw(Queen);
		window.draw(BQueen);
		window.draw(Rook);
		window.draw(BRook);
		window.draw(Bishop);
		window.draw(BBishop);
		window.draw(Knight);
		window.draw(BKnight);

		window.display();


	}
if(dri==7)
{
	switch (choice)
	{
	case 1:
		C[dri][dci]->Promotion(dri, dci, 'Q', this);
		A[dri][dci] = 'Q';
		break;
	case 2:
		C[dri][dci]->Promotion(dri, dci, 'R', this);
		A[dri][dci] = 'R';
		break;
	case 3:
		C[dri][dci]->Promotion(dri, dci, 'B', this);
		A[dri][dci] = 'B';
		break;
	case 4:
		C[dri][dci]->Promotion(dri, dci, 'N', this);
		A[dri][dci] = 'N';
		break;

	}

}
if(dri==0)
{
	switch (choice)
	{
	case 1:
		C[dri][dci]->Promotion(dri, dci, 'q', this);
		A[dri][dci] = 'q';
		break;
	case 2:
		C[dri][dci]->Promotion(dri, dci, 'r', this);
		A[dri][dci] = 'r';
		break;
	case 3:
		C[dri][dci]->Promotion(dri, dci, 'b', this);
		A[dri][dci] = 'b';
		break;
	case 4:
		C[dri][dci]->Promotion(dri, dci, 'n', this);
		A[dri][dci] = 'n';
		break;

	}

}
	

}

bool Board::stalemate(Color Pc)
{
	if (!Check(Pc))
	{
		for (int _sr = 0; _sr < 8; _sr++)
		{
			for (int _sc = 0; _sc < 8; _sc++)
			{
				for (int _dr = 0; _dr < 8; _dr++)
				{
					for (int _dc = 0; _dc < 8; _dc++)
					{
						if ((C[_sr][_sc]->GetPieceColor() != C[_dr][_dc]->GetPieceColor()) && C[_sr][_sc]->GetPieceColor() == Pc)
						{
							if (IslegalMove(_sr, _sc, _dr, _dc,'h') && (Selfcheck(_sr, _sc, _dr, _dc, Pc)))
							{

								return false;
							}
						}

					}

				}

			}

		}

		return true;

	}
	return false;

}
bool Board::Castling(int sri, int sci, int dri, int dci,int &_dr,int &_dc)
{
	 _dr = sri;
	 if (dci > sci)
		 _dc = sci + 1;
	 if (dci < sci)
		 _dc = sci - 1;
	 int Delta_c = abs(dci - sci);
	 if (C[sri][sci]->GetPieceColor() == WHITE)
	{
		if (A[sri][sci] == 'K' && sri == 0)
		{
			
			while (_dc < 8 && _dc >= 0)
			{
				if ((A[_dr][_dc] != '-'))
					break;
				

				if (dci > sci)
				_dc++;
				if (dci < sci)
					_dc--;
			}
			if (A[_dr][_dc] == 'R')
			{
				if (C[sri][sci]->GetFirstMove()==true && C[_dr][_dc]->GetFirstMove() == true)
				{
					if (Delta_c == 2 && sri == dri)
					{
						if(Selfcheck(sri,sci,dri,dci,WHITE) && !Check(WHITE))
						{
							return true;
						}
					}
				}
			}

		}
	}

	 if (C[sri][sci]->GetPieceColor() == BLACK)
	{
		if (A[sri][sci] == 'k' && sri == 7)
		{
			
			while (_dr < 8 && _dc >= 0)
			{
				if ((A[_dr][_dc] != '-'))
					break;
				if (dci > sci)
				_dc++;
				if (dci < sci)
					_dc--;
			}
			if (A[_dr][_dc] == 'r')
			{
				if (C[sri][sci]->GetFirstMove()==true && C[_dr][_dc]->GetFirstMove()==true)
				{
					if (Delta_c==2&& sri == dri)
					{
						if (Selfcheck(sri, sci, dri, dci, BLACK)&&!Check(BLACK))
						return true;
					}
				}
			}

		}
	}

	return false;

}
Board::Board(const Board& B2)
{
	this->A = new char*[8];
	for (int i = 0; i < 8; i++)
		this->A[i] = new char[8];

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			this->A[r][c] = B2.A[r][c];
		}
	}

	int Cellsize = 9;
	int ColMargin = 45;
	int RowMargin = 5;
	C = new Cell * *[8];


	for (int r = 0, Disp_r = RowMargin; r < 8; r++, Disp_r += Cellsize)
	{

		C[r] = new Cell * [8];
		for (int c = 0, Disp_c = ColMargin; c < 8; c++, Disp_c += Cellsize)
		{
			C[r][c] = new Cell(*B2.C[r][c]);
		}
	}


}

void Board :: DrawSouceCell(int sri, int sci, sf::RenderWindow& window)
{

	C[sri][sci]->Draw(window);

}
bool Board::IsPromotion(int dri, int dci)
{
	return  (((A[dri][dci] == 'p') && dri == 0) || ((A[dri][dci] == 'P') && dri == 7));

}