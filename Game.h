#pragma once
#include <SFML/Graphics.hpp>
#include "Vagon.h"
#include "Lista.h"

using namespace sf;

class Game
{
private:
	RenderWindow* window;
	Event* event;
	int fps;

	Clock* clock_game;
	Time* time_game;

	int n_uno;
	int n_dos;
	int n_tres;
	int respuesta;

	Sprite* sp_background;
	Texture* tx_background;
	Sprite* sp_locomotora;
	Texture* tx_locomotora;

	Font font_uno;
	Text text_uno;
	String string_uno;
	Font font_dos;
	Text text_dos;
	String string_dos;
	Font font_tres;
	Text text_tres;
	String string_tres;
	Font font_respuesta;
	Text text_respuesta;
	String string_respuesta;
	Font font_tiempo;
	Text text_tiempo;
	String string_tiempo;

	Lista* tren;
	Nodo* primer_v;
	Nodo* ultimo_v;
	


	int vel_tren;
	bool colision;
	Vector2f estacion_final;

	FloatRect* locomotoraRect;
	FloatRect* vagonRect;

	int arreglo_vias[5];
	int indice_vias;
	Vagon* arreglo_vagones[7];


	Vagon* vagon_a;
	Vagon* vagon_b;
	Vagon* vagon_c;
	Vagon* vagon_d;
	Vagon* vagon_e;
	Vagon* vagon_f;
	Vagon* vagon_g;
	

public:
	Game();
	Game(int,int,String);
	void game_loop();
	void game_draw();

};

