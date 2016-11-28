#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../State.h"

class Engine;

class MainMenuState : public State
{
public:
	MainMenuState(Engine* engine) : State(engine, "MainMenuState") { };

	void update();
	void render();
	void handleEvent(SDL_Event* event);

private:
	void load();
	void unload();

	void loadAssets();
	void prepareButtons();
	void prepare();

private:
};

#endif