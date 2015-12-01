#include "sfwdraw.h"
#include "Player.h"
#include <vector>
#include <string>
#include <sstream>
#include "collisiontests.h"
#include "AssetLibrary.h"
#include "Araragi.h"
#include "Character.h"
#include "Freeman.h"
#include "TextInputBox.h"

unsigned font;

void main()
{
	sfw::initContext(900, 600, "NSFW Draw");
	sfw::setBackgroundColor(BLACK);	


	// Now I'm using the loadTexture from AssetLibrary! Notice how I Get to name it now.
	// The name lets me easily refer to it later!
	//loadTexture("Explosion", "../res/explosion.png", 5, 3); // so this is an explosion sprite sheet. TLDR WE WILL MAKE DINOSAURS EXPLODE!
	//addAnimation("Explosion", "BOOM", {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14});

	unsigned f = sfw::loadTextureMap("./res/freemun.png");	
	unsigned a = sfw::loadTextureMap("./res/araragi.png");
	unsigned u = sfw::loadTextureMap("./res/sanic2.png");
	unsigned b = sfw::loadTextureMap("./res/arena.jpg");

	
	font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);


	//addAnimation("Explosion", "NOTVERYBOOM", { 0,1 });

	// Since I know the name, I can reuse it anywhere!
	Player dinosaur;
	GameObject barricade;
	barricade.x = 80;
	barricade.y = 80;
	//barricade.textureName = "Explosion";
	//barricade.animationName = "NOTVERYBOOM";

	TextInputBox introStringDraw;
	TextInputBox myTextBox;
	myTextBox.handle = font;
	myTextBox.x = 0;
	myTextBox.y = 600;
	myTextBox.w = 20;
	myTextBox.h = 20;

	Araragi araragi;
	Freeman freeman;

	bool playerTurn = true;
	int damageTaken;
	std::string turn;
	int newMana;

	while (sfw::stepContext())
	{
	
			myTextBox.update();
			myTextBox.draw();
			araragi.showHealth();
			araragi.showMana();
			araragi.moveSet();
			freeman.showHealth();
			freeman.showMana();
			freeman.moveSet();

			
		std::string input = myTextBox.getString();
		
		// if true player 1's turn, if false player 2's turn

		if (playerTurn == true)
		{
			turn = "Player 1's turn!";
			sfw::drawString(font, turn.c_str(), 250, 300, 20, 20);

			if (input == "ATTACK")
			{
				damageTaken = freeman.getHealth() - araragi.attack();
				freeman.setHealth(damageTaken);

				newMana = araragi.getMana() + 20;
				araragi.setMana(newMana);

				playerTurn = false;
			}
			if (araragi.getMana() > 0)
			{
				if (araragi.getMana() >= 20)
				{

					if (input == "SPECIAL 1")
					{
						damageTaken = freeman.getHealth() - araragi.special1();
						freeman.setHealth(damageTaken);

						newMana = araragi.getMana() - 20;
						araragi.setMana(newMana);

						playerTurn = false;
					}
				}

				if (araragi.getMana() >= 40)
				{

					if (input == "SPECIAL 2")
					{
						damageTaken = araragi.special2();
						araragi.setHealth(damageTaken);

						newMana = araragi.getMana() - 40;
						araragi.setMana(newMana);

						playerTurn = false;
					}
				}

				if (araragi.getMana() >= 50)
				{

					if (input == "SPECIAL 3")
					{
						damageTaken = freeman.getHealth() - araragi.special3();
						freeman.setHealth(damageTaken);

						newMana = araragi.getMana() - 50;
						araragi.setMana(newMana);

						playerTurn = false;
					}
				}
			}
		}

		else if (playerTurn == false)
		{
			turn = "Player 2's turn!";
			sfw::drawString(font, turn.c_str(), 250, 250, 20, 20);

			if (input == "ATTACK")
			{
				damageTaken = araragi.getHealth() - freeman.attack();
				araragi.setHealth(damageTaken);

				newMana = freeman.getMana() + 20;
				freeman.setMana(newMana);

				playerTurn = true;
			}
			if (freeman.getMana() > 0)
			{
				if (freeman.getMana() >= 30)
				{
					if (input == "SPECIAL 1")
					{
						damageTaken = araragi.getHealth() - freeman.special1();
						araragi.setHealth(damageTaken);

						newMana = freeman.getMana() - 30;
						freeman.setMana(newMana);

						playerTurn = true;
					}
				}

				if (freeman.getMana() >= 60)
				{

					if (input == "SPECIAL 2")
					{
						damageTaken = freeman.special2();
						freeman.setHealth(damageTaken);

						newMana = freeman.getMana() - 60;
						freeman.setMana(newMana);

						playerTurn = true;
					}
				}

				if (freeman.getMana() >= 50)
				{

					if (input == "SPECIAL 3")
					{
						damageTaken = araragi.getHealth() - freeman.special3();
						araragi.setHealth(damageTaken);

						newMana = freeman.getMana() - 50;
						freeman.setMana(newMana);

						playerTurn = true;
					}
				}
			}
		}

		if (araragi.getHealth() <= 0)
		{
			turn = "";
			araragi.isDead();
		}

		if (freeman.getHealth() <= 0)
		{
			turn = "";
			freeman.isDead();
		}


		sfw::drawTexture(b, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		sfw::drawTexture(f, 100, 300, 100, 100, 0, false, 0);
		sfw::drawTexture(a, 600, 300, 100, 100, 0, false, 0);

		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 10, sfw::getTextureHeight(u) / 10, 180, true, 0, 0x88ffffff);
		else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 10, sfw::getTextureHeight(u) / 10);
		}
	}


