#pragma once
#include<string>
#include <iostream>
#include "Utility.h"
using namespace std;

class Player
{
protected:
	string name;
	Color C;
	int TimeAllowed;
public:
	Player(string N, Color _C,int t);
	Color GetColor();
	string GetName();
	int GetTime();
	void SetTime(int t);
};

