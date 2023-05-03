#pragma once
#include<iostream>
//#include<SFML/Graphics.hpp>
//#include<windows.h>
//#include<conio.h>
using namespace std;
class Piece;
#define Screen_col 168
#define BROWN 6
#define GREEN 2
#define LBLUE 9
#define RED 4


//struct position { int ri, ci; };
enum Color { BLACK, WHITE = 15, NullClr = -20 };
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
void getRowColbyLeftClick(int& rpos, int& cpos);
bool MygetRowColbyLeftClick2(int& rpos, int& cpos, int& t, int& player_time, int ptimeOrg);
void Box(int dr, int dc, int rsize, int csize,int clr);
void MygetRowColbyLeftClick(int& rpos, int& cpos, int& t, int& player_time);