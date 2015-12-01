#pragma once
#include <iostream>


enum TYPE { None, Player, Enemy, Bullet };

class GameObject
{
	TYPE type;
	float xPos, yPos, width, height, radius, angle;
	unsigned textureHandle;
	bool isActive;

	virtual void draw();
	virtual void update();
	virtual void onCollision(GameObject &o);
};

class Dinosaur : GameObject
{
	void draw();

	
};

class Player : GameObject
{

};