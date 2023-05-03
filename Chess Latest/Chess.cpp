#include "Chess.h"
#include<iostream>
#include<fstream>
#include"Board.h"
#include"Player.h"
#include"Piece.h"
#include<time.h>
#include"Utility.h"
#include<string>
#include<SFML/Graphics.hpp>
//#include<SFML/Graphics.hpp>
using namespace std;
//using namespace sf;

Chess::Chess(const char* filename)
{
	ifstream Rdr(filename);
	B = new Board(Rdr);
	//int Time = 180;
	Rdr >> Turn;// = B->ReadTurn(Rdr);
	Rdr >> P1_Time;
	Rdr >> P2_Time;
	Ps[0] = new Player("Moqeet", WHITE,P1_Time);
	Ps[1] = new Player("Abdullah", BLACK,P2_Time);
	sri = 0, sci = 0, dri = 0, dci = 0;
	Un_d.push_back(*B);
}
void static getRowColbyLeftClickSf(int& rpos, int& cpos, sf::RenderWindow& window)
{
	while (true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i p = sf::Mouse::getPosition(window);

			cpos = p.y;
			rpos = p.x;
			break;
		}
	}
}
void Chess::SelectPosition(int& ri, int& ci,sf::RenderWindow & window)
{
	//gotoRowCol(13, 5);
	//cout << "Row :";
	//cin >> ri;
	//gotoRowCol(14, 5);
	//cout << "Col :";
	//cin >> ci;

	//if (dri == -1 && dci == -1 && (Vb.size() > 0))
	//{
	//	if (Undo(sri, sci))
	//		return true;
	//}
	//else if (dri == -1 && dci == -1 && (Vb.size() > 0))
	//{
	//	if (Redo(sri, sci))
	//		return true;
	//}

	////bool buttonClicked = false;

	////while (!buttonClicked) {
	////	// Check the state of the left mouse button
	////	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) 
	////	{
	////		buttonClicked = true;
	////		getRowColbyLeftClick(ri, ci);
	////	}
	////	else {
	////		// Increment A while the button is not clicked
	////		; t++;
	////		
	////	}
	////}
	//if (G_type == 2)
	//{
	//	if (!MygetRowColbyLeftClick2(ri, ci, t, t_Allowed, Org_t))
	//	{
	////		Uindx = 1;
	//		return false;

	//	}
	//}
	//else
	//	
	//{

	//	getRowColbyLeftClick(ri, ci);
	//}
	//if(dri==-1&&dci==-1 && (Vb.size()>0))
	//{
	//	if (Undo(sri, sci))
	//		return true;
	//}
	//else if (dri == -1 && dci == -1 && (Vb.size() > 0))
	//{
	//	if (Redo(sri, sci))
	//		return true;
	//}






	int Cellsize = 80;
	int ColMargin = 350;
	int RowMargin = 40;

	getRowColbyLeftClickSf(ci, ri, window);
	if (ci >= ColMargin && ri >= RowMargin)
	{
		ri = ri - RowMargin;
		ci = ci - ColMargin;

		ri = (ri / Cellsize);//div by no.of rows
		ci = (ci / Cellsize);//div by no. of cols
	}
}
bool Chess::IsvalidSource()
{
	if ((sri < 0 || sri >= 8) || (sci < 0 || sci >= 8))
		return false;
	if (!IsMyPiece(sri, sci))
		return false;
	
	return true;
}
bool Chess::IsvalidDestination()
{
	if ((dri < 0 || dri >= 8) || (dci < 0 || dci >= 8))
		return false;
	if (IsMyPiece(dri, dci))
		return false;
	return true;
}
bool Chess::IsMyPiece(int ri, int ci)
{
	return (B->PieceColor(ri, ci) == Ps[Turn - 1]->GetColor());
}
void Chess::TurnChange()
{
	Turn = Turn % 2 + 1;
}
void Chess::DsiplayName()
{
	if (Turn == 1)
		SetClr(1); else SetClr(5);
	gotoRowCol(10, 5);
	std::cout << Ps[Turn - 1]->GetName() << "'s Turn \n\n";
}
//void Chess::Play(int G_type)
//{
//	int indx = 1;
//	int t = 0;
//	dri = -1, dci = -1; int iv = 0;
//
//	Vb.push_back(*B);
//	B->DisplayBoard();
//	while (true)
//	{
//		//if (Undo(sri, sci) && (iv >= 0))
//
//Box(60, 130, 7, 10, 4);
//		SetClr(79);
//		gotoRowCol(63, 133);
//		cout << "UNDO";
//	Box(60, 20, 7, 10, 4);
//		SetClr(79);
//		gotoRowCol(63, 23);
//		cout << "REDO";
//		int Ptime = Ps[Turn - 1]->GetTime();
//		int _r = 0, _c = 0;
//		this->DsiplayName();
//		do
//		{
//			do {
//				do
//
//				{
//					dri = -1, dci = -1;
//					do
//					{
//						sri = -1, sci = -1;
//						cout << "Select Source Co-Ordinates:";
//						t++;
//						int  Pt = Ps[Turn - 1]->GetTime();
//						if (!SelectPosition(sri, sci, t, Ptime,G_type,Pt))
//						{
//							SetClr(2);
//							gotoRowCol(17, 4);
//							cout<<Ps[Turn-1]->GetName() << " RAN OUT OF TIME\n\n";
//							gotoRowCol(20, 7);
//							cout<<Ps[Turn % 2]->GetName() << " Wins";
//						
//							exit(0);
//						}
//					} while (!IsvalidSource() && !Undo(sri, sci) && !Redo(sri, sci));
//					if (!Undo(sri, sci) && !Redo(sri, sci))
//					{
//						B->HighlightCell(sri, sci, Ps[Turn - 1]->GetColor());
//					}	//cout << "Select Dest Co-Ordinates:";
//						int  Pt = Ps[Turn - 1]->GetTime();
//					
//					if (!SelectPosition(dri, dci, t, Ptime, G_type,Pt))
//					{
//						SetClr(2);
//						gotoRowCol(17, 4);
//						cout << Ps[Turn - 1]->GetName() << " RAN OUT OF TIME\n\n";
//						gotoRowCol(20, 7);
//						cout << Ps[Turn % 2]->GetName() << " Wins";
//						//_getch();
//						exit(0);
//					}
//					
//				if(!Undo(sri, sci) && !Redo(sri, sci))	B->UnHighlightCell(sri, sci, Ps[Turn - 1]->GetColor());
//				} while ( !Undo(sri, sci) && !Redo(sri, sci) &&!B->Castling(sri, sci, dri, dci, _r, _c) &&!IsvalidDestination() );
//
//				t++;
//
//			} while (!Undo(sri, sci) && !Redo(sri, sci) &&!B->Castling(sri, sci, dri, dci, _r, _c)&&!B->IslegalMove(sri, sci, dri, dci,'-') );
//
//			t++;
//		} while (!Undo(sri, sci) && !Redo(sri, sci) &&!B->Selfcheck(sri, sci, dri, dci, Ps[Turn - 1]->GetColor()) &&!B->Castling(sri, sci, dri, dci, _r, _c));
//
//		
//		 iv = Vb.size() - Uindx - 1;
//		t = 0;
//		int timme = Ps[Turn - 1]->GetTime() - Ptime;
//		Ps[Turn - 1]->SetTime(Ps[Turn - 1]->GetTime() -timme);
//		//system("cls");
//		if (!Undo(sri, sci) && !Redo(sri, sci))
//		{
//			B->DisplayBoard();
//			TurnChange();
//			
//			B->Update(sri, sci, dri, dci, Turn, Vb);
//			iv = Vb.size() - Uindx - 1;
//		
//		
//		
//			B->DispRowDest(sri, sci, dri, dci);
//			if (B->checkMate(Ps[Turn - 1]->GetColor()))
//			{
//				SetClr(4); gotoRowCol(20, 5); cout << "CHECK_Mate";
//				; SetClr(0); gotoRowCol(20, 5); cout << "     ";
//				exit(0);
//			}
//			else if (B->Check(Ps[Turn - 1]->GetColor()))
//			{
//				SetClr(4); gotoRowCol(20, 5); cout << "CHECK";
//				; SetClr(0); gotoRowCol(20, 5); cout << "     ";
//			}
//			else if (B->stalemate(Ps[Turn - 1]->GetColor()))
//			{
//				SetClr(4); gotoRowCol(20, 5); cout << "Stalemate";
//				; SetClr(0); gotoRowCol(20, 5); cout << "     ";
//			}
//
//		}
//		else if (Undo(sri, sci) && (iv >= 0))
//		{
//			delete B;
//			B = nullptr;
//			B = new Board(Vb[Vb.size() - Uindx-1]);
//			Turn = Turn%2 + 1;
//			B->DisplayBoard();
//			Uindx++;
//		
//		
//		
//		}
//		else if(Redo(sri, sci) && Uindx>1)
//		{
//			delete B;
//			B = nullptr;
//			B = new Board(Vb[Vb.size() - Uindx+1]);
//			Turn = (Turn % 2) + 1;
//			B->DisplayBoard();
//			Uindx--;
//
//		}
//	}
//}
void Chess::Play(int& choice,sf::RenderWindow& window)
{
	int Cellsize = 80;
	int ColMargin = 350;
	int RowMargin = 40;
	int cast_r=-1, cast_c=-1;
	int t = 0; int min = 0, sec = 0;
	int RemTime = 0;
	//-------------------
	RemTime = Ps[Turn - 1]->GetTime();
	min = RemTime / 60;
	sec = RemTime % 60;
	//-----------------------
	//----------------
	bool IsDestination = false;
	bool IsSource = true;
	bool LegalMove = false;
	bool selfcheck = false;
	bool Okhayboss = false;
	bool Checkm = false;
	bool Chk = false;
	bool StaleM = false;
	bool IsUndo = false;
	bool IsRedo = false;

	//-------------------
	sf::Color lightBrown(200, 160, 100);
	sf::Font Lato;
	Lato.loadFromFile("Lato.ttf");
//-------------------------------------------
	sf::Text CMate("CHECK MATE", Lato, 90);
	CMate.setPosition(375, 250);
	CMate.setFillColor(sf::Color::Red);
	CMate.setOutlineThickness(15);
	CMate.setOutlineColor(sf::Color::White);
//----------------------------------------------
	sf::Text CHeck("CHECK", Lato, 50);
	CHeck.setPosition(1120, 350);
	CHeck.setFillColor(sf::Color::Red);
	CHeck.setOutlineColor(sf::Color::Black);
	CHeck.setOutlineThickness(3);
	//--------------------------------------
	sf::Text SMate("STALE MATE", Lato, 90);
	SMate.setPosition(375, 250);
	SMate.setFillColor(sf::Color::Red);
	SMate.setOutlineThickness(15);
	SMate.setOutlineColor(sf::Color::White);
	//--------------------------------------
	sf::Text T_Up("TIME'S UP", Lato, 90);
	T_Up.setPosition(450, 250);
	T_Up.setFillColor(sf::Color::Red);
	T_Up.setOutlineThickness(15);
	T_Up.setOutlineColor(sf::Color::White);
	//--------------------------------------
	sf::Text P1("PLAYER 1", Lato, 30);
	P1.setPosition(50, 90);
	P1.setFillColor(sf::Color::White);
	P1.setOutlineThickness(5);
	P1.setOutlineColor(sf::Color::Black);
	//-------------------------------------
	sf::Text P2("PLAYER 2", Lato, 30);
	P2.setPosition(1120, 90);
	P2.setFillColor(sf::Color::Black);
	P2.setOutlineThickness(2);
	P2.setOutlineColor(sf::Color::White);
	//-------------------------------------
	sf::Text Colon(" : ", Lato, 30);
	Colon.setPosition(1120, 130);
	Colon.setFillColor(sf::Color::Black);
	Colon.setOutlineThickness(2);
	Colon.setOutlineColor(sf::Color::White);
	//-------------------------------------

	sf::Texture Ud;
	Ud.loadFromFile("UndoLogo.png");
	sf::Sprite Undo(Ud);
	Undo.setPosition(sf::Vector2f(90, 550));
	Undo.setScale(1,1);
	
	//---------------------------------
	sf::Texture Rd;
	Rd.loadFromFile("RedoLogo.png");
	sf::Sprite Redo(Rd);
	Redo.setPosition(sf::Vector2f(1150, 550));
	Redo.setScale(1, 1);
	//----------------------------------------
	sf::Texture bg;
	bg.loadFromFile("backtableChess.png");

	sf::Sprite Backtable(bg);
	Backtable.setPosition(0, -180);
	Backtable.setScale(0.8, 0.8);
	//----------------------------
	


	while (window.isOpen())
	{
		t++;
		sf::Event evnt;
		
		while (window.pollEvent(evnt))
		{
			
			
			if (evnt.type == sf::Event::Closed)
				window.close();
		
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i p = sf::Mouse::getPosition(window);
				if(IsSource)
				{
					t++;
					sri = p.y;
					sci = p.x;
					if (p.x >= ColMargin && p.y >= RowMargin)
					{
						sri = sri - RowMargin;
						sci = sci - ColMargin;

						sri = (sri / Cellsize);//div by no.of rows
						sci = (sci / Cellsize);//div by no. of cols					
					}

					LegalMove = false;
					selfcheck = false;
					Okhayboss = false;
					Checkm = false;				
					StaleM = false;

					if (IsvalidSource())
					{
						B->HighlightCell(sri, sci, Ps[Turn - 1]->GetColor(), window);						
						IsSource = false;
						IsDestination = true;
						IsUndo = false;
						IsRedo = false;
						
					}
					else if ((p.x > 80 && p.x <= 190)&&(p.y > 540 && p.y <= 650))
					{
						if (Un_d.size()>1)
						{
							IsSource = false;
							IsUndo = true;
						}
					}
					else if ((p.x > 1140 && p.x <= 1260) && (p.y > 540 && p.y <= 650))
					{
						if (!Re_d.empty())
						{
							IsSource = false;
							IsRedo = true;
						}
					}

				}
				else if (IsDestination)
				{
					//t++;
					B->UnHighlightCell(sri, sci, Ps[Turn - 1]->GetColor(), window);
						dri = p.y;
						dci = p.x;
					if (p.x >= ColMargin && p.y >= RowMargin)
					{
						
						dri = dri - RowMargin;
						dci = dci - ColMargin;

						dri = (dri / Cellsize);//div by no.of rows
						dci = (dci / Cellsize);//div by no. of cols
					}

					if (IsvalidDestination() || B->Castling(sri, sci, dri, dci, cast_r, cast_c))
					{
						
						IsSource = false;
						LegalMove = true;

					}
					else 
						IsSource = true;
						
					IsDestination = false;
				}
				 if (LegalMove)
				{
					// t++;

					if (B->IslegalMove(sri, sci, dri, dci, '-')||B->Castling(sri,sci,dri,dci,cast_r,cast_c))
					{
						
						selfcheck = true;
					}
					else
					{
						IsSource = true;
					}
						LegalMove = false;
				}
				 if (selfcheck)
				{
					// t++;

					if (!B->Selfcheck(sri, sci, dri, dci, Ps[Turn - 1]->GetColor()))
					{
						IsSource = true;
						
					}
					else
						Okhayboss = true;
					 selfcheck = false;

						
				 }
				 if (IsUndo)
				 {
					 if (Un_d.size()>=2)
					 {
						 delete B;
						 B = nullptr;
						 B = new Board(Un_d[Un_d.size()-2]);
						 Turn = Turn%2 + 1;
						//Re_d.insert(Re_d.begin() + Uindx, Un_d.back());
						 Re_d.push_back(Un_d.back());
						 Un_d.pop_back();
						Uindx++;
						IsUndo= false;
						IsSource = true;
					 }

				}

				 else if (IsRedo)
				 {
					 if (!Re_d.empty())
					 {
						 delete B;
						 B = nullptr;
						 B = new Board(Re_d.back());
						 Turn = Turn % 2 + 1;
						 //Re_d.erase(Re_d.begin());
						 Un_d.push_back(Re_d.back());
						 Re_d.pop_back();
						 IsRedo = false;
						 IsSource = true;
					 }

				 }

				 else if (Okhayboss)
				{
					 
					 Ps[Turn - 1]->SetTime(RemTime);
					 TurnChange();			
					 B->Update(sri, sci, dri, dci, Turn,Ps[0]->GetTime(), Ps[1]->GetTime(), Un_d);
					 Chk = false;
					 Re_d.clear();
					 //----------------------------------
					 RemTime = Ps[Turn - 1]->GetTime();	
					 min = RemTime / 60;
					 sec = RemTime % 60;
					 //------------------
					 if (B->IsPromotion(dri, dci))
					 {
						 B->Promotion(dri, dci, window);
					 }
					 //t = 0;
					 
					 if (B->checkMate(Ps[Turn - 1]->GetColor()))
					{
						 Checkm = true;
					}
					 
					 else if (B->Check(Ps[Turn - 1]->GetColor()))
					{
						 Chk = true;		 
					}
					
					else if (B->stalemate(Ps[Turn - 1]->GetColor()))
					{					
						 StaleM = true;
					}
					 
					 Okhayboss = false;
					 IsSource = true;
				 
				 }

			}
		
		}
		window.clear();


	
		if (t >= 65)
		{
			sec--;
			t = 0;
			RemTime--;
		}

		if (sec <= -1)
		{
			sec = 59;
			min--;
		}



		string gmin = std::to_string(min);
		if (min < 10)gmin = "0" + gmin;

		sf::Text Min(gmin, Lato, 30);
		Min.setPosition(1100, 130);
		Min.setFillColor(sf::Color::Red);
		Min.setOutlineThickness(1);
		Min.setOutlineColor(sf::Color::Black);
		//-------------------------------------
		
		//-----------------------------------
		
		string gsec = std::to_string(sec);
		if (sec < 10)gsec = "0" + gsec;
		sf::Text sec(gsec, Lato, 30);
		sec.setPosition(1140, 130);
		sec.setFillColor(sf::Color::Red);
		sec.setOutlineThickness(1);
		sec.setOutlineColor(sf::Color::Black);

		//------------------------------
		int pm = Ps[0]->GetTime() / 60;
		string P1_m = std::to_string(Ps[0]->GetTime() / 60);
		if (pm < 10)P1_m = "0" + P1_m;
		
		sf::Text P1Min(P1_m, Lato, 30);
		P1Min.setPosition(70, 160);
		P1Min.setFillColor(sf::Color::White);
		P1Min.setOutlineThickness(2);
		P1Min.setOutlineColor(sf::Color::Black);
		//-------------------------------------
		//-----------------------------------
		int ps = Ps[0]->GetTime() % 60;
		string P1_s = std::to_string(Ps[0]->GetTime() % 60);
		if (ps < 10)P1_s = "0" + P1_s;
		
		sf::Text P1sec(P1_s, Lato, 30);
		P1sec.setPosition(130, 160);
		P1sec.setFillColor(sf::Color::White);
		P1sec.setOutlineThickness(2);
		P1sec.setOutlineColor(sf::Color::Black);
		//----------------------------------------
		int p2m = Ps[1]->GetTime() / 60;
		string P2_m = std::to_string(Ps[1]->GetTime() / 60);
		if (p2m < 10)P2_m = "0" + P2_m;
		
		sf::Text P2Min(P2_m, Lato, 30);
		P2Min.setPosition(1140, 160);
		P2Min.setFillColor(sf::Color::Black);
		P2Min.setOutlineThickness(2);
		P2Min.setOutlineColor(sf::Color::White);
		//-------------------------------------
		//-----------------------------------
		int p2s = Ps[1]->GetTime() % 60;
		string P2_s = std::to_string(Ps[1]->GetTime() % 60);
		if (p2s < 10)P2_s = "0" + P2_s;

		sf::Text P2sec(P2_s, Lato, 30);
		P2sec.setPosition(1200, 160);
		P2sec.setFillColor(sf::Color::Black);
		P2sec.setOutlineThickness(2);
		P2sec.setOutlineColor(sf::Color::White);


		window.draw(Backtable);

		if(Turn==2)
		{
			window.draw(P1Min);
			Colon.setPosition(110, 160);
			window.draw(Colon);
			window.draw(P1sec);
		}
		else 
		{
			window.draw(P2Min);
			Colon.setPosition(1180, 160);
			window.draw(Colon);
			window.draw(P2sec);

		}
		if (Turn == 1)
		{
			Min.setPosition(70, 160);
			sec.setPosition(130, 160);
			Colon.setPosition(110, 160);
		}
		else
		{
			Min.setPosition(1140, 160);
			sec.setPosition(1200, 160);
			Colon.setPosition(1180, 160);
		}

		window.draw(Min);
		window.draw(Colon);
		window.draw(sec);

		window.draw(Undo);
		window.draw(Redo);
		window.draw(P1);
		window.draw(P2);
			
			B->DisplayBoard(window);
			if(IsvalidSource())
			{
				B->DrawSouceCell(sri, sci, window);
			}
			if (Checkm)
				window.draw(CMate);

			else if (Chk)
			{
				if (Turn == 1)
					CHeck.setPosition(35, 300);
				else
					CHeck.setPosition(1105, 300);
				window.draw(CHeck);
			}
			else if (StaleM)
				window.draw(SMate);
			else if (RemTime == 0)
				window.draw(T_Up);

			window.display();
			
			if(Checkm)
			{
				sf::sleep(sf::seconds(5));
				choice = 0;
				break;
			}
			else if(StaleM)
			{
				sf::sleep(sf::seconds(5));
				choice = 0;
				break;
			}
			else if(RemTime<=0)
			{
				sf::sleep(sf::seconds(5));
				choice = 0;
				break;
			}


	}
	
}
bool Chess::Undo(int r,int c)
{
	if ((r >= 60 && r < 68) && (c >= 130 && c < 146))
		return true;

	return false;
}
bool Chess::Redo(int r, int c)

{
	(60, 20, 7, 10, 4);

	if ((r >= 60 && r < 68) && (c >= 20 && c < 31))
		return true;

	return false;

}

