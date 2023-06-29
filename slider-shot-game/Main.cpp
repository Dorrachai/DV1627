#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "Meteor.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game!");
    Slider slider(0.f, 300.f);
    std::vector<Meteor> meteors;
    float maxRange = window.getSize().x * 0.8f;

    sf::Font font;
    if (!font.loadFromFile("Comic_Neue"))
    {
        // Handle error...
    }

    sf::Text healthText;
    healthText.setFont(font);
    healthText.setCharacterSize(24);
    healthText.setFillColor(sf::Color::White);
    healthText.setPosition(10.f, 10.f);

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    gameOverText.setString("GAME OVER");

    sf::Clock clock;
    sf::Clock meteorClock;
    float meteorSpawnInterval = 2.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && slider.shape.getPosition().y > 0)
            slider.MoveUp();
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && slider.shape.getPosition().y < window.getSize().y - slider.shape.getSize().y)
            slider.MoveDown();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && slider.shootCooldown <= 0.f)
        {
            slider.Shoot(maxRange);
            slider.shootCooldown = 1.f;
        }

        slider.shootCooldown -= clock.restart().asSeconds();

        if (slider.shootCooldown < 0)
        {
            slider.shootCooldown = 0.f;
        }

        slider.UpdateReadyBullet();

        for (int i = 0; i < slider.bullets.size(); i++)
        {
            slider.bullets[i].Move();

            if (slider.bullets[i].shape.getPosition().x > window.getSize().x)
            {
                slider.bullets.erase(slider.bullets.begin() + i);
                i--;
            }
            else
            {
                for (int j = 0; j < meteors.size(); j++)
                {
                    if (slider.bullets[i].shape.getGlobalBounds().intersects(meteors[j].shape.getGlobalBounds()))
                    {
                        meteors.erase(meteors.begin() + j);
                        slider.bullets.erase(slider.bullets.begin() + i); // erase bullet
                        slider.shootCooldown = 0.f; // reset the bullet cooldown
                        i--;
                        break;
                    }
                }
            }
        }

        if (meteorClock.getElapsedTime().asSeconds() >= meteorSpawnInterval)
        {
            for (int i = 0; i < 3; ++i) { // spawn 3 meteors
                meteors.push_back(Meteor(800, rand() % (600 - 20) + 10));
            }
            meteorClock.restart(); // reset the meteor clock
        }

        for (int i = 0; i < meteors.size(); i++)
        {
            meteors[i].Move();

            if (meteors[i].shape.getPosition().x < 0.f - meteors[i].shape.getRadius())
            {
                meteors.erase(meteors.begin() + i);
                slider.playerHealth--;
                i--;
            }
        }

        window.clear();

        if (slider.playerHealth > 0)
        {
            slider.Draw(window);

            for (auto& bullet : slider.bullets)
                bullet.Draw(window);

            for (auto& meteor : meteors)
                meteor.Draw(window);
        }

        std::string healthString;
        for (int i = 0; i < slider.playerHealth; i++)
            healthString += "* ";
        healthText.setString(healthString);

        window.draw(healthText);

        if (slider.playerHealth <= 0)
        {
            window.draw(gameOverText);
        }

        window.display();
    }

    return 0;
}
