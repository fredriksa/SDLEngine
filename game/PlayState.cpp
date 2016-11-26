#include "PlayState.h"
#include "../AssetContainer.h"
#include "../Engine.h"
#include "../ImageLoader.h"
#include "../Sprite.h"
#include "Player.h"
#include "../SpriteCenterer.h"

PlayState::PlayState(Engine * engine)
	: State(engine, "PlayState") 
{
	load();
}


void PlayState::update()
{
	State::update();
}

void PlayState::render()
{
	State::render();
}

void PlayState::handleEvent(SDL_Event * event)
{
	State::handleEvent(event);
}

void PlayState::load()
{
	loadAssets();
	prepareEntities();
	bindHooks();
}

void PlayState::unload()
{

}

void PlayState::loadAssets()
{
	ImageLoader loader(mEngine->getRenderer());
	mAssets->addTexture("bgPurple", loader.loadPNG("..\\engine\\source\\assets\\bgpurple.png"));
	mAssets->addTexture("player", loader.loadPNG("..\\engine\\source\\assets\\player.png"));
}

void PlayState::prepareEntities()
{
	std::shared_ptr<Sprite> background(new Sprite(mAssets->getTexture("bgPurple")));
	background->getBody()->h = mEngine->getSize()->y;
	background->getBody()->w = mEngine->getSize()->x;

	std::shared_ptr<Player> player(new Player(mAssets->getTexture("player")));
	SpriteCenterer::centerHorizontal(player.get(), mEngine->getSize()->x);
	player.get()->getBody()->y = mEngine->getSize()->y - player.get()->getBody()->h - player.get()->getBody()->h * 0.1;
	std::shared_ptr<Vector4<int>> restriction(new Vector4<int>);
	restriction->x = 0;
	restriction->y = 0;
	restriction->z = mEngine->getSize()->x;
	restriction->o = mEngine->getSize()->y;
	player.get()->setMovementRestriction(restriction);
	mPlayer = player;

	addSprite(background);
	addSprite(mPlayer);
}

void PlayState::bindHooks()
{
	mKeyHooks.addHook(SDLK_a, std::bind(&Player::moveLeft, mPlayer.get()));
	mKeyHooks.addHook(SDLK_d, std::bind(&Player::moveRight, mPlayer.get()));
}