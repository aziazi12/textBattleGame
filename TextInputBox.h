#pragma once
#include "sfwdraw.h"
#include <string>
#define ATTACK input = "ATTACK"
#define SPECIAL1 input = "SPECIAL 1"
#define SPECIAL2 input = "SPECIAL 2"
#define SPECIAL3 input = "SPECIAL 3"

class TextInputBox
{
public:
	bool keyStates[350];
	std::string input;
	std::string intro;
	float x, y, w, h;
	unsigned handle;
	unsigned introS;

	TextInputBox();
	void update();
	void draw();
	void drawIntro();
	std::string getString();
	std::string introString();

	// x,y,font,w,h and a string
	bool enterPressed = false;
};
void TextInputBox::update()
{
	for (unsigned i = 0; i < 350; ++i)
	{
		bool currentState = sfw::getKey(i);

		if (currentState && !keyStates[i])// on press, add a character to the string (if it's alphanumeric)
		{
			switch (i)
			{
			case KEY_BACKSPACE: if (input.length() > 0) input = input.substr(0, input.length() - 1); break;
			case KEY_ENTER: enterPressed = true; break;
			case !KEY_ENTER: drawIntro(); break;
			default:
				input += i;
			}


		}

		if (!currentState && keyStates[i]); // release
		keyStates[i] = currentState;
	}
}

TextInputBox::TextInputBox(){}

void TextInputBox::draw()
{
	sfw::drawString(handle, input.c_str(), 300, y, w, h);

}

void TextInputBox::drawIntro()
{
		sfw::drawString(font, intro.c_str(), 400, 300, 60, 60);
}

// "" means enter hasn't been pressed or there is no input
std::string TextInputBox::getString()
{
	std::string ret = "";
	if (enterPressed)
	{
		ret = input;
		input = "";
		enterPressed = false;
	}
	return ret;
}

std::string TextInputBox::introString()
{
	std::string intro = "Press enter to start";
	if (enterPressed)
	{
		intro = "";
	}

	return intro;
}

