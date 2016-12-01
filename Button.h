#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"
#include "Sprite.h"
#include <functional>
#include "LimitedText.h"

class Button : public Sprite
{
public:
	Button(SDL_Surface* surface, SDL_Renderer* renderer);

	void update();
	void render();
	void onClick();

public: 
	LimitedText text;
	std::function<void()> click;

private:
	std::string mActualText;
};

#endif