#include "sfwdraw.h"
#include "AssetLibrary.h"
#include "Player.h"
#include <vector>
#include "collisiontests.h"

void main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	sfw::setBackgroundColor(BLACK);	


	// Now I'm using the loadTexture from AssetLibrary! Notice how I Get to name it now.
	// The name lets me easily refer to it later!
	loadTexture("Explosion", "../res/explosion.png", 5, 3); // so this is an explosion sprite sheet. TLDR WE WILL MAKE DINOSAURS EXPLODE!
	addAnimation("Explosion", "BOOM", {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14});

	unsigned f = sfw::loadTextureMap("./res/chiefitty.png", 1, 1);
	unsigned u = sfw::loadTextureMap("./res/sanic2.png");
	unsigned b = sfw::loadTextureMap("./res/atlantis.jpg");

	addAnimation("Explosion", "NOTVERYBOOM", { 0,1 });

	// Since I know the name, I can reuse it anywhere!
	Player dinosaur;
	GameObject barricade;
	barricade.x = 80;
	barricade.y = 80;
	barricade.textureName = "Explosion";
	barricade.animationName = "NOTVERYBOOM";

	while (sfw::stepContext())
	{
		barricade.draw();
		dinosaur.draw();	// Draw uses gameObject's draw, which just checks what the asset name is
							// and then fetches the appropriate handle for the draw.
		barricade.update();
		dinosaur.update(); 


		doCollision(barricade, dinosaur);

		unsigned frame = 0;

		sfw::drawTexture(b, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		sfw::drawTexture(f, 250, 400, 250, 150, 0, true, frame);
		frame;

		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 10, sfw::getTextureHeight(u) / 10, 180, true, 0, 0x88ffffff);
		else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 10, sfw::getTextureHeight(u) / 10);
		}
	}

	sfw::termContext();
}