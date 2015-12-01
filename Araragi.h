#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Character.h"
#include <fstream>


class Araragi : Character
{
private:
	int m_health;
	int m_mana;
	int m_power;

public:
	Araragi();
	int getHealth();
	void setHealth(int newHealth);
	void showHealth();
	int getMana();
	void setMana(int newMana);
	void showMana();
	void moveSet();
	void isDead();
	void clearStrings();
	int attack();
	int special1();
	int special2();
	int special3();

	unsigned handle;
	float xpos = 100;
	float ypos = 300;
	float xposHealth = xpos - 20;
	float yposHealth = ypos + 90;
	float xposMana = xpos - 20;
	float yposMana = ypos + 60;
	int hpPrint;
	std::string hp;
	std::string mana;
	std::string lost;
	std::string lost2;
	std::string play;
	std::string yesNo;

};

Araragi::Araragi()
{
	m_health = 100;
	m_mana = 100;
	m_power = 15;
	hp = "HEALTH:" + std::to_string(m_health);
	mana = "MANA:" + std::to_string(m_mana);

	

}

void Araragi::setHealth(int newHealth)
{
	m_health = newHealth;
	hp = "HEALTH:" + std::to_string(m_health);
}

int Araragi::getHealth()
{
	return m_health;
}

void Araragi::showHealth()
{
	sfw::drawString(font, hp.c_str(), xposHealth, yposHealth, 20, 20);
}

void Araragi::setMana(int newMana)
{
	m_mana = newMana;
	mana = "MANA:" + std::to_string(m_mana);
}

int Araragi::getMana()
{
	return m_mana;
}

void Araragi::showMana()
{
	sfw::drawString(font, mana.c_str(), xposMana, yposMana, 20, 20);
}

void Araragi::isDead()
{
	
		std::string lost = "PLAYER 1 LOSES!";
		std::string lost2 = "PLAYER 2 WINS!";
		sfw::drawString(font, lost.c_str(), 300, 300, 20, 20);
		sfw::drawString(font, lost2.c_str(), 300, 250, 20, 20);

}

void Araragi::clearStrings()
{
	lost = "";
	lost2 = "";
}

void Araragi::moveSet()
{
	std::string move1 = "'ATTACK' FOR A NORMAL ATTACK";
	std::string move2 = "'SPECIAL 1' 50% MORE:20 MANA";
	std::string move3 = "'SPECIAL 2' FOR 50HP HEAL:40 MANA";
	std::string move4 = "'SPECIAL 3' FOR DOUBLE:50 MANA";

	sfw::drawString(font, move1.c_str(), xposHealth - 70, 150, 15, 15);
	sfw::drawString(font, move2.c_str(), xposHealth - 70, 125, 15, 15);
	sfw::drawString(font, move3.c_str(), xposHealth - 70, 100, 15, 15);
	sfw::drawString(font, move4.c_str(), xposHealth - 70, 75, 15, 15);
}

int Araragi::attack()
{
	return m_power;
}

int Araragi::special1()
{
	return m_power * 1.5;
}

int Araragi::special2()
{
	return m_health + 50;
}

int Araragi::special3()
{
	return m_power * 2;
}

