#include "Vagon.h"
#include <iostream>

using namespace std;

Vagon::Vagon(int n,int x,int y){//recibe posicion en X e Y, y el numero de vagon
	numero = n;
	pos_x = x;
	pos_y = y;
	tx_vagon = new Texture;//Sprite del vagon
	sp_vagon = new Sprite;
	tx_vagon->loadFromFile("assets/vagon.png");
	sp_vagon->setTexture(*tx_vagon);
	sp_vagon->setPosition(x, y);
	sp_vagon->setScale(sp_vagon->getScale().x / 2, sp_vagon->getScale().y / 2);


	font_vagon.loadFromFile("assets/Square.ttf");//Texto del numero de vagon
	text_vagon.setFont(font_vagon);
	string_vagon = " " + to_string(static_cast<int>(numero));
	text_vagon.setString(string_vagon);
	text_vagon.setPosition(x+20, y);
	text_vagon.setFillColor(Color::Yellow);
}

Sprite Vagon::get_sprite() {//devuelve el sprite del vagon para dibujarlo
		return *sp_vagon;
}

Text Vagon::get_text() {//devuelve el testo del vagon para dibujarlo
		return text_vagon;
}

void Vagon::set_position(float new_x, float new_y) {//funcion para pasarle una posición nueva al vagon, recibe dos float
	sp_vagon->setPosition(new_x, new_y);
	text_vagon.setPosition(new_x, new_y);
}

Vector2f Vagon::get_position() {//devuelve la posición del vagon en un vector2f
	Vector2f pos_vagon;
	pos_vagon.x = pos_x;
	pos_vagon.y = pos_y;
	return pos_vagon;
}

int Vagon::get_num() {//devuelve el número del vagon
	return numero;
}

