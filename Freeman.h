#pragma once
#include <iostream>
#include "Character.h"
#include <fstream>

class Freeman : Character
{
private:
	int m_health;
	int m_mana;
	int m_power;
public:
	Freeman();
	int getHealth();
	void setHealth(int newHealth);
	void showHealth();
	int getMana();
	void setMana(int newMana);
	void showMana();
	void isDead();
	void clearStrings();
	void moveSet();

	unsigned handle;
	float xpos = 600;
	float ypos = 300;
	float xposHealth = xpos - 30;
	float yposHealth = ypos + 90;
	float xposMana = xpos - 30;
	float yposMana = ypos + 60;
	int hpPrint;
	std::string hp;
	std::string mana;
	std::string lost;
	std::string lost2;

	int attack();
	int special1();
	int special2();
	int special3();

};

Freeman::Freeman()
{
	m_health = 150;
	m_mana = 100;
	m_power = 10;
	hp = "HEALTH:" + std::to_string(m_health);
	mana = "MANA:" + std::to_string(m_mana);
}

int Freeman::getHealth()
{
	return m_health;
}

void Freeman::setHealth(int newHealth)
{
	m_health = newHealth;
	hp = "HEALTH:" + std::to_string(m_health);
}

void Freeman::showHealth()
{
	sfw::drawString(font, hp.c_str(), xposHealth, yposHealth, 20, 20);
}

int Freeman::getMana()
{
	return m_mana;
}

void Freeman::setMana(int newMana)
{
	m_mana = newMana;
	mana = "MANA:" + std::to_string(m_mana);
}

void Freeman::showMana()
{
	sfw::drawString(font, mana.c_str(), xposMana, yposMana, 20, 20);
}

void Freeman::isDead()
{
		std::string lost = "PLAYER 2 LOSES!";
		std::string lost2 = "PLAYER 1 WINS!";
		sfw::drawString(font, lost.c_str(), 300, 300, 20, 20);
		sfw::drawString(font, lost2.c_str(), 300, 250, 20, 20);
		clearStrings();
}

void Freeman::clearStrings()
{
	lost = "";
	lost2 = "";
}

void Freeman::moveSet()
{
	std::string move1 = "'ATTACK' FOR A NORMAL ATTACK";
	std::string move2 = "'SPECIAL 1' 50% MORE:30 MANA";
	std::string move3 = "'SPECIAL 2' FOR 100HP HEAL:60 MANA";
	std::string move4 = "'SPECIAL 3' FOR DOUBLE:50 MANA";

	sfw::drawString(font, move1.c_str(), xposHealth - 100, 150, 15, 15);
	sfw::drawString(font, move2.c_str(), xposHealth - 100, 125, 15, 15);
	sfw::drawString(font, move3.c_str(), xposHealth - 100, 100, 15, 15);
	sfw::drawString(font, move4.c_str(), xposHealth - 100, 75, 15, 15);
}

int Freeman::attack()
{
	return m_power;
}

int Freeman::special1()
{
	return m_power * 1.5;
}

int Freeman::special2()
{
	return m_health + 100;
}

int Freeman::special3()
{
	return m_power * 2;
}