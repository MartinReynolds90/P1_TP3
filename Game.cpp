#include "Game.h"

Game::Game() {
}

Game::Game(int ancho,int alto, String nombre) {
    srand(time(NULL));
    fps = 15;
    window = new RenderWindow(VideoMode(ancho, alto), nombre);
    window->setFramerateLimit(fps);
    event = new Event;
    clock_game = new Clock();
    time_game = new Time();
    

    n_uno = 5;
    n_dos = 6;
    n_tres = 0;

    respuesta = 0;
    
    

    tx_background = new Texture;
    sp_background = new Sprite;
    tx_background->loadFromFile("assets/vias_tren.png");
    sp_background->setTexture(*tx_background);
    tx_locomotora = new Texture;
    sp_locomotora = new Sprite;
    tx_locomotora->loadFromFile("assets/locomotora.png");
    sp_locomotora->setTexture(*tx_locomotora);
    sp_locomotora->setPosition(20, 160);
    sp_locomotora->setScale(sp_locomotora->getScale().x / 2, sp_locomotora->getScale().y / 2);
    vel_tren = 2;



    locomotoraRect = new FloatRect;
    vagonRect = new FloatRect;

  

    arreglo_vias[0] = 160;
    arreglo_vias[1] = 230;
    arreglo_vias[2] = 320;
    arreglo_vias[3] = 418;
    arreglo_vias[4] = 545;
    indice_vias = 0;
    colision = false;
    estacion_final.x = window->getSize().x - 50;
    estacion_final.y = 545;


    vagon_a = new Vagon(rand() % 10, 290, arreglo_vias[0]);
    vagon_b = new Vagon(rand() % 10, 190, arreglo_vias[1]);
    vagon_c = new Vagon(rand() % 10, 460, arreglo_vias[2]);
    vagon_d = new Vagon(rand() % 10, 355, arreglo_vias[3]);
    vagon_e = new Vagon(rand() % 10, 550, arreglo_vias[3]);
    vagon_f = new Vagon(rand() % 10, 560, arreglo_vias[4]);
    vagon_g = new Vagon(rand() % 10, 60, arreglo_vias[0]);

    arreglo_vagones[0] = vagon_a;
    arreglo_vagones[1] = vagon_b;
    arreglo_vagones[2] = vagon_c;
    arreglo_vagones[3] = vagon_d;
    arreglo_vagones[4] = vagon_e;
    arreglo_vagones[5] = vagon_f;
    arreglo_vagones[6] = vagon_g;

    tren = new Lista;
    primer_v = new Nodo;
    ultimo_v = new Nodo;

    tren->agregar_nodo(vagon_a);
    tren->agregar_nodo(vagon_b);

   

    game_loop();
}

void Game::game_loop() {
    while (window->isOpen()) {
        while (window->pollEvent(*event)) {
            if (event->type == Event::Closed) {
                window->close();
            }

            /*if (event->type == Event::TextEntered) {
                if (respuesta != 0) {
                    if (event->text.unicode < 128) {
                        //cout << "Se tipeo un caracter ASCII: " << static_cast<char>(event->text.unicode) << endl;

                        font_respuesta.loadFromFile("assets/Square.ttf");
                        text_respuesta.setFont(font_respuesta);
                        string_respuesta = " correcto = " + to_string(static_cast<int>(respuesta));
                        text_respuesta.setString(string_respuesta);
                        text_respuesta.setPosition(140, 100);
                    }
                }

            }*/

            *locomotoraRect = sp_locomotora->getGlobalBounds();
            *time_game = clock_game->getElapsedTime();
            cout << "tiempo: " << time_game->asSeconds() << endl;

            font_tiempo.loadFromFile("assets/Square.ttf");
            text_tiempo.setFont(font_tiempo);
            string_tiempo = "Tiempo " + to_string(static_cast<int>(time_game->asSeconds()));
            text_tiempo.setString(string_tiempo);
            text_tiempo.setFillColor(Color::Blue);
            text_tiempo.setPosition(200, 70);



            if (locomotoraRect->contains(estacion_final.x, estacion_final.y)) {
                vel_tren = 0;
                cout << "fin del juego" << endl;

            }

            if (sp_locomotora->getPosition().x <= window->getSize().x) {
                sp_locomotora->setPosition(sp_locomotora->getPosition().x + vel_tren, sp_locomotora->getPosition().y);
                tren->recorrer_lista(sp_locomotora->getPosition().x - 75 + vel_tren, sp_locomotora->getPosition().y);
                //RECORRO LA LISTA PARA HACER QUE LOS VAGONES SIGAN A LA LOCOMOTORA
            }
            else {
                indice_vias++;
                sp_locomotora->setPosition(50 + vel_tren, arreglo_vias[indice_vias]);
            }

            for (int i = 0; i < 7; i++) {//COLISION CON VAGONES
                *vagonRect = arreglo_vagones[i]->get_sprite().getGlobalBounds();


                if (vagonRect->intersects(*locomotoraRect)) {

                    cout << "tiempo colision000000000000000000000000000: " << time_game->asSeconds() << endl;

                    vel_tren = 0;
                    colision = true;
                    n_uno = rand() % 10;
                    n_dos = rand() % 10;
                    n_tres = rand() % 10;



                    cout << "resuelva la operacion " << endl;
                    cout << n_uno << " + " << n_dos << " + " << n_tres << ": " << endl;



                    font_uno.loadFromFile("assets/Square.ttf");
                    text_uno.setFont(font_uno);

                    font_dos.loadFromFile("assets/Square.ttf");
                    text_dos.setFont(font_dos);

                    font_tres.loadFromFile("assets/Square.ttf");
                    text_tres.setFont(font_tres);



                    string_uno = " " + to_string(static_cast<int>(n_uno));
                    text_uno.setString(string_uno);
                    text_uno.setFillColor(Color::Black);
                    text_uno.setPosition(200, 40);

                    string_dos = "+ " + to_string(static_cast<int>(n_dos));
                    text_dos.setString(string_dos);
                    text_dos.setFillColor(Color::Black);
                    text_dos.setPosition(240, 40);

                    string_tres = " + " + to_string(static_cast<int>(n_tres));
                    text_tres.setString(string_tres);
                    text_tres.setFillColor(Color::Black);
                    text_tres.setPosition(280, 40);



                    game_draw();
                    cin >> respuesta;



                    if (respuesta == n_uno + n_dos + n_tres /* && time_game->asSeconds() <= 5.0*/) {//SI RESPONDE BIEN y en el tiempo establecido

                        vel_tren = 2;
                        string_uno = "  ";
                        text_uno.setString(string_uno);


                        string_dos = "  ";
                        text_dos.setString(string_dos);


                        string_tres = "  ";
                        text_tres.setString(string_tres);


                        font_respuesta.loadFromFile("assets/Square.ttf");
                        text_respuesta.setFont(font_respuesta);
                        string_respuesta = " correcto = " + to_string(static_cast<int>(respuesta));
                        text_respuesta.setString(string_respuesta);
                        text_respuesta.setPosition(sp_locomotora->getPosition().x - 140, sp_locomotora->getPosition().y - 40);

                        tren->agregar_nodo(arreglo_vagones[i]);//SI RESPONDE BIEN SE AGREGA EL VAGON COLISIONADO

                    }
                    else {
                        cout << "respuesta incorrecta  " << endl;
                        //ELIMINO EL ULTIMO NODO SI RESPONDE MAL
                        tren->quitar_nodo();
                    }
                }
            }
            //vagon_a->set_position(sp_locomotora->getPosition().x - 65, sp_locomotora->getPosition().y);//el vagon sigue a la locomotora siempre
            game_draw();
        }
    }
    
}

void Game::game_draw() {
    window->clear(Color(255, 255, 255, 255));
    window->draw(*sp_background);
    window->draw(*sp_locomotora);

    for (int i = 0; i < 7; i++) {
        window->draw(arreglo_vagones[i]->get_sprite());
        window->draw(arreglo_vagones[i]->get_text());
    }

    window->draw(text_uno);
    window->draw(text_dos);
    window->draw(text_tres);
    window->draw(text_respuesta);
    window->draw(text_tiempo);
    
    window->display();
}

