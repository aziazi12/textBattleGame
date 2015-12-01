#pragma once
#include "Character.h"
#include "Araragi.h"
#include "Freeman.h"
#include "sfwdraw.h"

class Player1
{
private:
	int m_health;
	int m_mana;
	int m_power;

public:
	Player1();
	int getHealth();
	void setHealth(int newHealth);
	void showHealth();
	int attack();
	int special1();
	int special2();
	int special3();

	unsigned handle;
	float xpos = 100;
	float ypos = 300;
	float xposHealth = xpos;
	float yposHealth = ypos + 75;
	int hpPrint;
	std::string hp;

};

Player1::Player1() {}

void Player1::showHealth()
{
	sfw::drawString(font, hp.c_str(), xposHealth, yposHealth, 50, 50);
}

int Player1::getHealth()
{
	return m_health;
}

void Player1::setHealth(int newHealth)
{
	m_health = newHealth;
}

int Player1::attack()
{
	return m_power;
}

int Player1::special1()
{
	
}

int Player1::special2()
{

}

int Player1::special3()
{

}