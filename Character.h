#pragma once
#include <iostream>

extern unsigned font;

class Character
{
private:
	int m_health;
	int m_mana;
	int m_power;

public:
	Character();
	int attack(int power);
	void takeDamage();
};

Character::Character() {}