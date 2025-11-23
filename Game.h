
#pragma once
#include <SFML/Graphics.hpp>
#include "Vagon.h"
#include "Lista.h"

using namespace sf;

class Game
{
private:
	RenderWindow window;
	Event event;
	int fps;

	Clock clock_game;
	Time time_game;

	int n_uno;
	int n_dos;
	int n_tres;
	int resp_correcta;
	int int_respuesta;//almacena cada tecla que el jugador ingresa para manipurarla y formar la resp_ingresada
	int resp_ingresada;
	int multiplo;
	bool respondiendo;

	Sprite sp_background, sp_locomotora;
	Texture tx_background, tx_locomotora;

	Font font;

	Text text_uno,text_dos,text_tres;
	String string_uno, string_dos,string_tres ;

	Text text_victoria, text_tiempo, text_respuesta,text_correcta;
	String string_victoria, string_tiempo, string_respuesta, string_correcta;

	RectangleShape rectangle;

	Lista* tren;
	Nodo* primer_v;

	int vel_tren;

	Vector2f estacion_final;

	FloatRect locomotoraRect, vagonRect;


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
	Game(int, int, String);
	void game_loop();
	void game_draw();
	void process_event();

};