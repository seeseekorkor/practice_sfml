#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>

int main(void) {
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
    sf::Texture texture;

    if (!texture.loadFromFile("examples/02-sprite/assets/character.png", false)) {
        std::cout << "Failed to load texture.\n";
    }
    texture.setSmooth(false);
    
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect({0, 64*10}, {64, 64})); // Walk Texture Position
    sprite.setScale({3, 3});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sprite.setTextureRect(
            sf::IntRect(
                {
                    (sprite.getTextureRect().position.x + 64) % (64 * 9), // 64x64 9개 걷기 동작 순환
                    sprite.getTextureRect().position.y
                }, 
                sprite.getTextureRect().size
            )
        );

        window.clear();
        window.draw(sprite);
        window.display();
        
        sleep(1);
    }
}