#include "Vagon.h"
#include <iostream>

using namespace std;

Vagon::Vagon(int n,int x,int y){
	numero = n;
	tx_vagon = new Texture;
	sp_vagon = new Sprite;
	tx_vagon->loadFromFile("assets/vagon.png");
	sp_vagon->setTexture(*tx_vagon);
	sp_vagon->setPosition(x, y);

	font_vagon.loadFromFile("assets/Square.ttf");
	text_vagon.setFont(font_vagon);
	string_vagon = " " + to_string(static_cast<int>(numero));
	text_vagon.setString(string_vagon);
	text_vagon.setPosition(x+20, y+12);
	text_vagon.setFillColor(Color::Yellow);
}

Sprite Vagon::get_sprite() {
	return *sp_vagon;
}

Text Vagon::get_text() {
	return text_vagon;
}