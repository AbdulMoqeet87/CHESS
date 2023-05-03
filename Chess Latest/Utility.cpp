#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Utility.h"


//#include<conio.h>
#include<iomanip>
using namespace std;
void Box(int dr, int dc, int rsize, int csize, int clr)
{
	SetClr(clr);
	gotoRowCol(dr, dc);
	for (int r = 0; r < rsize; r++)
	{
		for (int c = 0; c < csize; c++)
		{
			gotoRowCol(dr + r, dc + c);
			cout << char(-37);
		}
		cout << endl;
	}

}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
bool MygetRowColbyLeftClick2(int& rpos, int& cpos,int &t,int &player_time,int ptimeOrg)
{
	//MSG msg{};
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord{};
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	SetClr(4); gotoRowCol(32, 3); cout << "YOUR REMAINING TIME ";
	Box(34, 8, 3, 9, 15);
	
	int min = player_time / 60;	
	int s = player_time %60;
	
	do
	{
		t++;
		if (t == 6000)
		{
			player_time -= 1;
			t = 0;
			s--;
			if (player_time == 0)
			{
				gotoRowCol(35, 9);
				cout << setw(2) << setfill('0') << 0 << " : " << setw(2) << setfill('0') << 0;
				return false;
			}
		}
	/*	SetClr(2);
		gotoRowCol(35, 10); 
		cout << "   ";
		gotoRowCol(35, 10);
		cout << player_time;
	*/	//if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		bool buttonClicked = false;
		bool first = true;
		while (!buttonClicked) {
			t++;
			if (t ==6000)
			{
				player_time -= 1;
				t = 0;
				s--;
		
				
				if (player_time == 0)
					
				{
					gotoRowCol(35, 9);
					cout << setw(2) << setfill('0') << 0 << " : " << setw(2) << setfill('0') << 0;
					return false;
				}
				
			}

			if (s==-1)
			{
				min--;
				s = 59;
				first = true;
			}
			
			{

				SetClr(244);
				gotoRowCol(35, 9);
				cout << setw(2) << setfill('0') << min << " : " << setw(2) << setfill('0') << s;

			}
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{

				ReadConsoleInput(hInput, &InputRecord, 1, &Events);
				buttonClicked = true;
			}
		
		}
	if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			
			return true;
		}
	} while (true);

}

