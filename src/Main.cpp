#include <SFML/Graphics.hpp>

#include "Engine.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Scene *main_scene;
    main_scene = new GamePlay();

    main_scene->Init();

    window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        main_scene->Update();

        // clear the window with black color
        window.clear(sf::Color::Black);

        main_scene->Draw(&window);

        // end the current frame
        window.display();
    }

    delete main_scene;

    return 0;
}