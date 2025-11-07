//#include "Game.h"
//
//Game::Game() {
//}
//
//Game::Game(int ancho,int alto, String nombre) {
//    srand(time(NULL));
//    fps = 60;
//    window = new RenderWindow(VideoMode(ancho, alto), nombre);
//    window->setFramerateLimit(fps);
//    event = new Event;
//    clock_game = new Clock();
//    time_game = new Time();
//    
//    tx_background = new Texture;//Sprite del fondo
//    sp_background = new Sprite;
//    tx_background->loadFromFile("assets/vias_tren.png");
//    sp_background->setTexture(*tx_background);
//
//    tx_locomotora = new Texture;//Sprite de locomotora
//    sp_locomotora = new Sprite;
//    tx_locomotora->loadFromFile("assets/locomotora.png");
//    sp_locomotora->setTexture(*tx_locomotora);
//    sp_locomotora->setPosition(20, 160);
//    sp_locomotora->setScale(sp_locomotora->getScale().x / 2, sp_locomotora->getScale().y / 2);
//    vel_tren = 2;//velocidad de la locomotora
//
//
//    font.loadFromFile("assets/Square.ttf");//Fuente para los textos
//
//    text_tiempo.setFont(font);//Texto del tiempo
//    string_tiempo = "Tiempo " + to_string(static_cast<int>(time_game->asSeconds()));
//    text_tiempo.setString(string_tiempo);
//    text_tiempo.setFillColor(Color::Blue);
//    text_tiempo.setPosition(200, 70);
//
//    rectangle = new RectangleShape(Vector2f(300,40));//Rectangulo donde aparece la respuesta del jugador
//    rectangle->setFillColor(Color(150, 150, 150, 255));
//    rectangle->setOutlineThickness(3.0);
//    rectangle->setFillColor(Color::Black);
//    rectangle->setPosition(Vector2f(350, 40));
//    
//    text_respuesta.setFont(font);//Texto de la respuesta del jugador///NO FUNCIONA ENTRE LA COLISION Y LA RESPUESTA
//    text_respuesta.setCharacterSize(30);
//    text_respuesta.setFillColor(Color::White);
//    text_respuesta.setPosition(Vector2f(350, 40));
//
//    text_victoria.setFont(font);//Texto de victoria/game over
//    string_victoria = " ";
//    text_victoria.setString(string_victoria);
//    text_victoria.setFillColor(Color::Black);
//    text_victoria.setPosition(Vector2f(200, 250));
//    text_victoria.setScale(text_victoria.getScale().x * 3, text_victoria.getScale().y * 3);
//
//    n_uno = 0;
//    n_dos = 0;
//    n_tres = 0;
//
//    respuesta = 0;//guarda la respuesta del jugador
//
//
//    locomotoraRect = new FloatRect;//para guardar el globalbound
//    vagonRect = new FloatRect; //para guardar el globalbound
//
//  
//
//    arreglo_vias[0] = 160;//creo un arreglo que tiene todas las posiciones en Y de las vias
//    arreglo_vias[1] = 230;
//    arreglo_vias[2] = 320;
//    arreglo_vias[3] = 418;
//    arreglo_vias[4] = 545;
//    indice_vias = 0;//Indice para recorrer el arreglo de vias
//
//    estacion_final.x = window->getSize().x - 50;//inicializo el Vector2f que representa la posicion de la estacion final
//    estacion_final.y = 545;
//
//
//    vagon_a = new Vagon(rand() % 10, 290, arreglo_vias[0]);//CREO LOS VAGONES, PASANDOLE UN NUMERO ALEATORIO, UNA POSICION EN X Y UNA EN Y(QUE COINCIDE CON UNA VIA)
//    vagon_b = new Vagon(rand() % 10, 190, arreglo_vias[1]);
//    vagon_c = new Vagon(rand() % 10, 460, arreglo_vias[2]);
//    vagon_d = new Vagon(rand() % 10, 355, arreglo_vias[3]);
//    vagon_e = new Vagon(rand() % 10, 550, arreglo_vias[3]);
//    vagon_f = new Vagon(rand() % 10, 560, arreglo_vias[4]);
//    vagon_g = new Vagon(rand() % 10, 460, arreglo_vias[0]);
//
//    arreglo_vagones[0] = vagon_a;//AGREGO LOS VAGONES A UN ARREGLO PARA FACILITAR LA MANIPULACION AL DIBUJARLOS Y OBTENER EL GLOBALBOUND
//    arreglo_vagones[1] = vagon_b;
//    arreglo_vagones[2] = vagon_c;
//    arreglo_vagones[3] = vagon_d;
//    arreglo_vagones[4] = vagon_e;
//    arreglo_vagones[5] = vagon_f;
//    arreglo_vagones[6] = vagon_g;
//
//    tren = new Lista;//CREO LA LISTA CON NOMBRE TREN
//    primer_v = new Nodo;//CREO EL PRIMER NODO
//
//    tren->agregar_nodo(vagon_a);//agrego los dos nodos iniciales
//    tren->agregar_nodo(vagon_b);
//
//
//
//    game_loop();//FUNCION GAME_LOOP
//}
//
//void Game::game_loop() {
//    while (window->isOpen()) {
//
//            
//            
//            *locomotoraRect = sp_locomotora->getGlobalBounds();//obtiene el globalBound de la locomotora en todo momento
//            
//            *time_game = clock_game->getElapsedTime();//actualiza el tiempo y se lo pasa al texto del tiempo
//             string_tiempo = "Tiempo " + to_string(static_cast<int>(time_game->asSeconds()));
//             text_tiempo.setString(string_tiempo);
//            
//
//            if (locomotoraRect->contains(estacion_final.x, estacion_final.y)) {//si la locomotora llega a la estacion final
//                vel_tren = 0;//le doy velocidad 0;
//                string_victoria = "GANASTE";//le paso el string de victoria al texto
//                text_victoria.setString(string_victoria);
//            }
//
//            if (sp_locomotora->getPosition().x <= window->getSize().x) {//si la locomotora no llego al final de la pantalla
//                sp_locomotora->setPosition(sp_locomotora->getPosition().x + vel_tren, sp_locomotora->getPosition().y);//se mueve
//                tren->recorrer_lista(sp_locomotora->getPosition().x - 75 + vel_tren, sp_locomotora->getPosition().y);//los vagones la siguen
//                //RECORRO LA LISTA PARA HACER QUE LOS VAGONES SIGAN A LA LOCOMOTORA
//            }
//            else {//si la locomotora llega al final de la pantalla la cambio a la siguiente via
//                indice_vias++;
//                sp_locomotora->setPosition(50 + vel_tren, arreglo_vias[indice_vias]);
//            }
//            for (int i = 0; i < 7; i++) {//OBTENGO LOS GLOBALBOUNDS DE LOS VAGONES
//                *vagonRect = arreglo_vagones[i]->get_sprite().getGlobalBounds();
//
//
//                if (vagonRect->intersects(*locomotoraRect)) {//SI LA LOCOMOTORA COLISIONA CON ALGUN VAGON
//
//                    vel_tren = 0;//LE DA VELOCIDAD CERO A LA LOCOMOTORA
//
//                    n_uno = rand() % 10;//GENERA TRES NUMEROS AL AZAR Y SE LOS PASA A LOS TEXTOS
//                    n_dos = rand() % 10;
//                    n_tres = rand() % 10;
//
//                    cout << "Resuelve la operación " << endl;
//                    cout << n_uno << " + " << n_dos << " + " << n_tres << ": " << endl;
//
//                    text_uno.setFont(font);//texto primero numero de la suma
//                    string_uno = " " + to_string(static_cast<int>(n_uno));
//                    text_uno.setString(string_uno);
//                    text_uno.setFillColor(Color::Black);
//                    text_uno.setPosition(200, 40);
//
//                    text_dos.setFont(font);//texto segundo numero de la suma
//                    string_dos = "+ " + to_string(static_cast<int>(n_dos));
//                    text_dos.setString(string_dos);
//                    text_dos.setFillColor(Color::Black);
//                    text_dos.setPosition(240, 40);
//
//                    text_tres.setFont(font);//texto del tercer numero de la suma
//                    string_tres = " + " + to_string(static_cast<int>(n_tres));
//                    text_tres.setString(string_tres);
//                    text_tres.setFillColor(Color::Black);
//                    text_tres.setPosition(280, 40);
//
//                    game_draw();//función dibujar
//                    
//                    cin >> respuesta;//LEE LA RESPUESTA>>>>>>MIENTRAS LEE LA RESPUESTA NO MUESTRA EL TEXTO DEL TIEMPO PERO SIGUE CONTANDOLO
//                    if ((respuesta == n_uno + n_dos + n_tres)&&(respuesta != 0)) {//SI RESPONDE BIEN///////////////////////
//
//                        vel_tren = 2;//LE DEVUELVO EL MOVIMIENTO AL TREN
//                        string_uno = "  ";//los textos no dibujan nada mientras el tren se mueve
//                        text_uno.setString(string_uno);
//                        string_dos = "  ";
//                        text_dos.setString(string_dos);
//                        string_tres = "  ";
//                        text_tres.setString(string_tres);
//
//
//                        tren->agregar_nodo(arreglo_vagones[i]);//SI RESPONDE BIEN SE AGREGA EL VAGON COLISIONADO (UN NODO A LA LISTA)
//               
//                    }
//                    else {//SI RESPONDE MAL///////////////////////
//                        if (tren->lista_vacia() == true) {//si la lista esta vacia y contesto mal, pierde porque se destruye la locomotora
//                            string_victoria = "GAME OVER";//le cambio el string al texto victoria
//                            text_victoria.setString(string_victoria);
//                        }
//                        else {
//                            tren->quitar_nodo();//ELIMINO EL ULTIMO NODO DE LA LISTA SI RESPONDE MAL
//                        }
//                    }
//                }
//            }
//            process_event();//funcion procesar eventos
//            game_draw();//funcion dibujar
//    }
//    
//}
//
//void Game::game_draw() {//FUNCION DIBUJAR
//    window->clear(Color(255, 255, 255, 255));
//    window->draw(*sp_background);//dibuja el fondo
//    window->draw(*sp_locomotora);//dibuja la locomotora
//
//    for (int i = 0; i < 7; i++) {//dibuja los vagones y los textos de cada vagon
//         window->draw(arreglo_vagones[i]->get_sprite());
//         window->draw(arreglo_vagones[i]->get_text());
//    }
//
//    window->draw(text_uno); //texto de los numeros de la operacion
//    window->draw(text_dos);
//    window->draw(text_tres);
//    window->draw(text_tiempo);//texto del tiempo
//
//    window->draw(*rectangle);
//    window->draw(text_respuesta);//texto de la respuesta del jugador//NO FUNCIONA ENTRE LA COLISION Y LA RESPUESTA, mientras espera el cin>>
//    window->draw(text_victoria);//muestra la condicion de victoria o derrota
//    
//    window->display();
//}
//
//
//
//void Game::process_event() {//FUNCION PROCESAR EVENTOS
//    while (window->pollEvent(*event)) {
//        if (event->type == Event::EventType::Closed) {
//            window->close();
//        }
//        if (event->type == Event::KeyPressed) {
//            if (event->key.code == Keyboard::Escape) {
//                window->close();
//            }
//        }
//        if (event->type == Event::TextEntered) {//lee el texto ingresado
//            if (event->text.unicode < 256) {//si esta dentro de la tabla ASCCI
//                if (event->text.unicode == 8 && string_respuesta.getSize() > 0) {//si presiona borrar y hay algo en el texto para borrar
//                    string_respuesta.erase(string_respuesta.getSize() - 1, 1);//borra
//                }
//                else {//sino es la tecla de borrar
//                    string_respuesta += (static_cast<char>(event->text.unicode));//lee, convierte a char y forma una string
//                }
//                text_respuesta.setString(string_respuesta);//le pasa el string al texto
//            }
//        }
//    }
//}
#include "Game.h"

Game::Game() {
}

Game::Game(int ancho, int alto, String nombre) {
    srand(time(NULL));
    fps = 60;
    window = new RenderWindow(VideoMode(ancho, alto), nombre);
    window->setFramerateLimit(fps);
    event = new Event;
    clock_game = new Clock();
    time_game = new Time();

    tx_background = new Texture;//Sprite del fondo
    sp_background = new Sprite;
    tx_background->loadFromFile("assets/vias_tren.png");
    sp_background->setTexture(*tx_background);

    tx_locomotora = new Texture;//Sprite de locomotora
    sp_locomotora = new Sprite;
    tx_locomotora->loadFromFile("assets/locomotora.png");
    sp_locomotora->setTexture(*tx_locomotora);
    sp_locomotora->setPosition(20, 160);
    sp_locomotora->setScale(sp_locomotora->getScale().x / 2, sp_locomotora->getScale().y / 2);
    vel_tren = 2;//velocidad de la locomotora

    font.loadFromFile("assets/Square.ttf");//Fuente para los textos

    text_tiempo.setFont(font);//Texto del tiempo
    string_tiempo = "Tiempo " + to_string(static_cast<int>(time_game->asSeconds()));
    text_tiempo.setString(string_tiempo);
    text_tiempo.setFillColor(Color::Blue);
    text_tiempo.setPosition(200, 70);

    rectangle = new RectangleShape(Vector2f(300, 40));//Rectangulo donde aparece la respuesta del jugador
    rectangle->setFillColor(Color(150, 150, 150, 255));
    rectangle->setOutlineThickness(3.0);
    rectangle->setFillColor(Color::Black);
    rectangle->setPosition(Vector2f(350, 40));

    text_respuesta.setFont(font);//Texto de la respuesta del jugador///NO FUNCIONA ENTRE LA COLISION Y LA RESPUESTA
    text_respuesta.setCharacterSize(30);
    text_respuesta.setFillColor(Color::White);
    text_respuesta.setPosition(Vector2f(350, 40));

    text_victoria.setFont(font);//Texto de victoria/game over
    string_victoria = " ";
    text_victoria.setString(string_victoria);
    text_victoria.setFillColor(Color::Black);
    text_victoria.setPosition(Vector2f(200, 250));
    text_victoria.setScale(text_victoria.getScale().x * 3, text_victoria.getScale().y * 3);

    respondiendo = false;//bool para el while de la respuesta

    resp_ingresada = 0;//la variable que guarda la respuesta 
    multiplo = 10;//multiplica el primer digito por 10 y el segundo por uno para formar la respuesta

    locomotoraRect = new FloatRect;//para guardar el globalbound
    vagonRect = new FloatRect; //para guardar el globalbound

    arreglo_vias[0] = 160;//creo un arreglo que tiene todas las posiciones en Y de las vias
    arreglo_vias[1] = 230;
    arreglo_vias[2] = 320;
    arreglo_vias[3] = 418;
    arreglo_vias[4] = 545;
    indice_vias = 0;//Indice para recorrer el arreglo de vias

    estacion_final.x = window->getSize().x - 50;//inicializo el Vector2f que representa la posicion de la estacion final
    estacion_final.y = 545;


    vagon_a = new Vagon(rand() % 10, 290, arreglo_vias[0]);//CREO LOS VAGONES, PASANDOLE UN NUMERO ALEATORIO, UNA POSICION EN X Y UNA EN Y(QUE COINCIDE CON UNA VIA)
    vagon_b = new Vagon(rand() % 10, 190, arreglo_vias[1]);
    vagon_c = new Vagon(rand() % 10, 460, arreglo_vias[2]);
    vagon_d = new Vagon(rand() % 10, 355, arreglo_vias[3]);
    vagon_e = new Vagon(rand() % 10, 550, arreglo_vias[3]);
    vagon_f = new Vagon(rand() % 10, 560, arreglo_vias[4]);
    vagon_g = new Vagon(rand() % 10, 460, arreglo_vias[0]);

    arreglo_vagones[0] = vagon_a;//AGREGO LOS VAGONES A UN ARREGLO PARA FACILITAR LA MANIPULACION AL DIBUJARLOS Y OBTENER EL GLOBALBOUND
    arreglo_vagones[1] = vagon_b;
    arreglo_vagones[2] = vagon_c;
    arreglo_vagones[3] = vagon_d;
    arreglo_vagones[4] = vagon_e;
    arreglo_vagones[5] = vagon_f;
    arreglo_vagones[6] = vagon_g;

    tren = new Lista;//CREO LA LISTA CON NOMBRE TREN
    primer_v = new Nodo;//CREO EL PRIMER NODO

    tren->agregar_nodo(vagon_a);//agrego los dos nodos iniciales
    tren->agregar_nodo(vagon_b);



    game_loop();//FUNCION GAME_LOOP
}

void Game::game_loop() {
    while (window->isOpen()) {

        *locomotoraRect = sp_locomotora->getGlobalBounds();//obtiene el globalBound de la locomotora en todo momento

        if (locomotoraRect->contains(estacion_final.x, estacion_final.y)) {//si la locomotora llega a la estacion final
            vel_tren = 0;//le doy velocidad 0;
            string_victoria = "GANASTE";//le paso el string de victoria al texto
            text_victoria.setString(string_victoria);
        }

        if (sp_locomotora->getPosition().x <= window->getSize().x) {//si la locomotora no llego al final de la pantalla
            sp_locomotora->setPosition(sp_locomotora->getPosition().x + vel_tren, sp_locomotora->getPosition().y);//se mueve
            tren->recorrer_lista(sp_locomotora->getPosition().x - 75 + vel_tren, sp_locomotora->getPosition().y);//los vagones la siguen
            //RECORRO LA LISTA PARA HACER QUE LOS VAGONES SIGAN A LA LOCOMOTORA
        }
        else {//si la locomotora llega al final de la pantalla la cambio a la siguiente via
            indice_vias++;
            sp_locomotora->setPosition(50 + vel_tren, arreglo_vias[indice_vias]);
        }

        for (int i = 0; i < 7; i++) {//OBTENGO LOS GLOBALBOUNDS DE LOS VAGONES
            *vagonRect = arreglo_vagones[i]->get_sprite().getGlobalBounds();

            if (vagonRect->intersects(*locomotoraRect)) {//SI LA LOCOMOTORA COLISIONA CON ALGUN VAGON
                n_uno = (rand() % 10);//numeros aleatorios de la suma
                n_dos = (rand() % 10);
                n_tres = (rand() % 10);
                resp_correcta = n_uno + n_dos + n_tres;//guarda la respuesta correcta para compararla con lo que ingresa el jugador
                cout << "int_correcta " << resp_correcta << endl;

                text_uno.setFont(font);//texto primero numero de la suma
                string_uno = " " + to_string(static_cast<int>(n_uno));
                text_uno.setString(string_uno);
                text_uno.setFillColor(Color::Black);
                text_uno.setPosition(200, 40);

                text_dos.setFont(font);//texto segundo numero de la suma
                string_dos = "+ " + to_string(static_cast<int>(n_dos));
                text_dos.setString(string_dos);
                text_dos.setFillColor(Color::Black);
                text_dos.setPosition(240, 40);

                text_tres.setFont(font);//texto del tercer numero de la suma
                string_tres = " + " + to_string(static_cast<int>(n_tres));
                text_tres.setString(string_tres);
                text_tres.setFillColor(Color::Black);
                text_tres.setPosition(280, 40);

                clock_game->restart();//si colisiona reinicia el contador en 5 seg
                respondiendo = true;//entra al while de respuesta
                while (respondiendo == true) {
                    *time_game = clock_game->getElapsedTime();//actualiza el tiempo y se lo pasa al texto del tiempo
                    string_tiempo = "Tiempo " + to_string(static_cast<int>(5 - time_game->asSeconds()));
                    text_tiempo.setString(string_tiempo);

                    vel_tren = 0;//LE DA VELOCIDAD CERO A LA LOCOMOTORA
                    process_event();
                    game_draw();


                    if (5 - time_game->asSeconds() >= 0) {//si esta dentro del tiempo establecido evalua las respuestas
                        if (multiplo <= 0) {//evalua las respuestas solo si ya se respondio
                            if (resp_correcta == resp_ingresada) {//si responde bien
                                cout << "Respondio bien" << endl;

                                tren->agregar_nodo(arreglo_vagones[i]);//SI RESPONDE BIEN SE AGREGA EL VAGON COLISIONADO (UN NODO A LA LISTA)
                                respondiendo = false;///SALE DEL WHILE DE RESPUESTA
                            }
                            else if (resp_correcta != resp_ingresada) {
                                cout << "Respondio mal" << endl;
                                if (tren->lista_vacia() == true) {//si la lista esta vacia y contesto mal, pierde porque se destruye la locomotora
                                    string_victoria = "GAME OVER";//le cambio el string al texto victoria
                                    text_victoria.setString(string_victoria);
                                    sp_locomotora->setPosition(190, 115);
                                }
                                else {
                                    tren->quitar_nodo();//ELIMINO EL ULTIMO NODO DE LA LISTA SI RESPONDE MAL

                                }
                                respondiendo = false;//SALE DEL WHILE DE RESPUESTA
                            }
                        }
                    }
                    else {//FUERA DE TIEMPO
                        cout << "se termino el tiempo" << endl;
                        if (tren->lista_vacia() == true) {//si la lista esta vacia y contesto mal, pierde porque se destruye la locomotora
                            string_victoria = "GAME OVER";//le cambio el string al texto victoria
                            text_victoria.setString(string_victoria);
                            sp_locomotora->setPosition(190, 115);
                        }
                        else {
                            tren->quitar_nodo();//ELIMINO EL ULTIMO NODO DE LA LISTA SI RESPONDE MAL
                        }
                        respondiendo = false;//SALE DEL WHILE DE RESPUESTA
                    }
                }
                //al salir de while de respuesta
                if (sp_locomotora->getPosition().y != 115) {//le devuelvo la velocidad al tren si no perdio
                    vel_tren = 2;//LE DEVUELVO EL MOVIMIENTO AL TREN
                }
                resp_ingresada = 0;//reinicio la respuesta ingresada a cero
                multiplo = 10;//el multiplo vuelve a ser 10 para formar la decena con el primer numero que ingrese
                string_tiempo = "";//"borro" el cartel de tiempo hasta la próxima colisión
                text_tiempo.setString(string_tiempo);

                string_uno = "  ";//los textos no dibujan nada mientras el tren se mueve
                text_uno.setString(string_uno);
                string_dos = "  ";
                text_dos.setString(string_dos);
                string_tres = "  ";
                text_tres.setString(string_tres);
            }
        }
        process_event();//mientras la ventana este abierta llama a la funcion procesar eventos
        game_draw();//mientras la ventana este abierta llama a la funcion dibujar
    }

}

void Game::game_draw() {//FUNCION DIBUJAR
    window->clear(Color(255, 255, 255, 255));
    window->draw(*sp_background);//dibuja el fondo
    window->draw(*sp_locomotora);//dibuja la locomotora

    for (int i = 0; i < 7; i++) {//dibuja los vagones y los textos de cada vagon
        window->draw(arreglo_vagones[i]->get_sprite());
        window->draw(arreglo_vagones[i]->get_text());
    }

    window->draw(text_uno); //texto de los numeros de la operacion
    window->draw(text_dos);
    window->draw(text_tres);
    window->draw(text_tiempo);//texto del tiempo

    window->draw(*rectangle);
    window->draw(text_respuesta);//texto de la respuesta del jugador//NO FUNCIONA ENTRE LA COLISION Y LA RESPUESTA, mientras espera el cin>>
    window->draw(text_victoria);//muestra la condicion de victoria o derrota

    window->display();
}



void Game::process_event() {//FUNCION PROCESAR EVENTOS
    while (window->pollEvent(*event)) {
        if (event->type == Event::EventType::Closed) {
            window->close();
        }
        if (event->type == Event::KeyPressed) {
            if (event->key.code == Keyboard::Escape) {
                window->close();
            }
        }
        if (event->type == Event::TextEntered) {//lee el texto ingresado
            if (event->text.unicode < 256) {//si esta dentro de la tabla ASCII
                if (event->text.unicode == 8 && string_respuesta.getSize() > 0) {//si presiona borrar y hay algo en el texto para borrar
                    string_respuesta.erase(string_respuesta.getSize() - 1, 1);//borra
                }
                else {//si no es la tecla de borrar
                    string_respuesta += (static_cast<char>(event->text.unicode));//lee, convierte a char y forma una string
                    int_respuesta = (static_cast<int>(event->text.unicode) - 48);//lee la tecla ingresada y lo convierte a su valor numérico en ASCII.

                    cout << "int_respuesta  " << int_respuesta << "  multiplo  " << multiplo << endl;

                    if (resp_correcta <= 9) {//si la respuesta correcta es 9 o menos solo admite la unidad como respuesta
                        multiplo = 1;
                    }
                    //int_total guarda el valor acumulado de los dos numeros que se ingresan, 
                    //el pirmero multiplicado por 10 para formar la decena y el segundo por 1 para la unidad
                    resp_ingresada = resp_ingresada + (int_respuesta * multiplo);//multiplica por 10 o 1 para formar la unidad y decena

                    //multiplo vale 10 cuando se ingresa el primer numero, luego cambia a 1 para el segundo
                    multiplo = multiplo / 10;//una vez que ingresa la decena divide el multiplo por 10 asi el proximo numero ingresado sera la unidad

                }
                text_respuesta.setString(string_respuesta);//le pasa el string al texto
            }
        }
    }
}
