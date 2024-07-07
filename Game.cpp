#include "Game.h"

Game::Game() {
}

Game::Game(int ancho,int alto, String nombre) {
    srand(time(NULL));
    fps = 60;
    window = new RenderWindow(VideoMode(ancho, alto), nombre);
    window->setFramerateLimit(fps);
    event = new Event;
    clock_game = new Clock();
    time_game = new Time();

    tx_background = new Texture;
    sp_background = new Sprite;
    tx_background->loadFromFile("assets/vias_tren.png");
    sp_background->setTexture(*tx_background);

    vagon_a = new Vagon(12,30,130);

    game_loop();
}

void Game::game_loop() {
    while (window->isOpen()) {
        game_draw();
    }
    
}

void Game::game_draw() {
    window->clear(Color(255, 255, 255, 255));
    window->draw(*sp_background);
    window->draw(vagon_a->get_sprite());
    window->draw(vagon_a->get_text());
    window->display();
}
