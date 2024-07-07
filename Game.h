#pragma once
#include <SFML/Graphics.hpp>
#include "Vagon.h"

using namespace sf;

class Game
{
private:
	RenderWindow* window;
	Event* event;
	int fps;

	Clock* clock_game;
	Time* time_game;

	Sprite* sp_background;
	Texture* tx_background;

	Vagon* vagon_a;

public:
	Game();
	Game(int,int,String);
	void game_loop();
	void game_draw();

};

