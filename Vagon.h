#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Vagon
{
private:
	int numero;
	Sprite sp_texto;
	Sprite* sp_vagon;
	Texture* tx_vagon;
	Font font_vagon;
	Text text_vagon;
	String string_vagon;

public:
	Vagon(int,int,int);
	Sprite get_sprite();
	Text get_text();


};

