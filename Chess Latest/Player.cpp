#include "Player.h"
#include"Utility.h"
Player::Player(string N, Color _C,int t)
{
	name = N;
	C = _C;
	TimeAllowed = t;
}
Color Player::GetColor()
{
	return this->C;
}
string Player::GetName()
{
	return name;
}
int Player::GetTime()
{
	return TimeAllowed;
}
void Player::SetTime(int t)
{
	TimeAllowed = t;

}
