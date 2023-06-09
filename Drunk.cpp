﻿#include <SFML/Graphics.hpp>

int main()
{
    const int sizeX = 500; const int sizeY = 500;
    sf::RenderWindow window(sf::VideoMode(sizeX, sizeY), "Circle");

    double dx = 0.01; double dy = 0.01;
    double x = sizeX / 2; double y = sizeY / 2;
    float radius = 50; int dr = 5;

    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
                window.close();

            switch (event.key.code)      // change the color: R - red; B - blue; G - green
            {
            case sf::Keyboard::G:
                circle.setFillColor(sf::Color::Green);
                break;

            case sf::Keyboard::B:
                circle.setFillColor(sf::Color::Blue);
                break;

            case sf::Keyboard::R:
                circle.setFillColor(sf::Color::Red);
                break;

            case sf::Keyboard::Up:       // increase the size
                
                if ((x + radius + dr   < sizeX && x - radius + dr > 0
                    && y + radius + dr < sizeY && y - radius + dr > 0))
                {
                    radius += 5;
                    circle.setRadius(radius);
                }

                break;

            case sf::Keyboard::Down:     // decrease the size
                if (radius >= 10)
                {
                    radius -= dr;
                    circle.setRadius(radius);
                }
                break;

            case sf::Keyboard::Numpad6:  // increase X-axis speed 

                dx += 0.01;
                break;

            case sf::Keyboard::Numpad4:  // decrease X-axis speed

                dx -= 0.01;
                break;

            case sf::Keyboard::Numpad8:  // increase Y-axis speed

                dy -= 0.01;
                break;

            case sf::Keyboard::Numpad2:  // decrease Y-axis speed

                dy += 0.01;
                break;

            case sf::Keyboard::Space:    // stop the circle
                dx = 0;
                dy = 0;
                break;
            }
        }

        if (x + radius >= sizeX || x - radius  <= 0)
            dx = -dx;
        if (y + radius >= sizeY || y - radius  <= 0)
            dy = -dy;

        x += dx;
        y += dy;

        window.clear();

        circle.setOrigin(radius, radius);
        circle.setPosition(x, y);

        window.draw(circle);
        window.display();



    }

    return 0;
}
