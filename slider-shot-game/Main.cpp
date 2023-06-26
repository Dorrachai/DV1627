#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "Meteor.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game!");
    Slider slider(0.f, 300.f);
    std::vector<Meteor> meteors;
    int meteorTimer = 0;
    float maxRange = window.getSize().x * 0.8f; // max range is 80% of the window width

    sf::Clock clock;  // to track time for bullet shooting delay

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
            slider.shootCooldown = 1.f; // Set the cooldown to 1 second
        }

        slider.shootCooldown -= clock.restart().asSeconds(); // Decrease the shoot cooldown based on elapsed time

        if (slider.shootCooldown < 0)
        {
            slider.shootCooldown = 0.f; // Don't let the cooldown go below 0
        }

        slider.UpdateReadyBullet(); // Update the ready bullet's position

        // Check bullet movement
        for (int i = 0; i < slider.bullets.size(); i++)
        {
            slider.bullets[i].Move();

            // If the bullet is off the right edge of the screen
            if (slider.bullets[i].shape.getPosition().x > window.getSize().x)
            {
                slider.bullets.erase(slider.bullets.begin() + i);
                i--;  // Decrease index to prevent skipping a bullet due to erasure
            }
            else  // If the bullet is still on the screen, check collision with meteors
            {
                for (int j = 0; j < meteors.size(); j++)
                {
                    if (slider.bullets[i].shape.getGlobalBounds().intersects(meteors[j].shape.getGlobalBounds()))
                    {
                        // Collision detected, erase bullet and meteor
                        slider.bullets.erase(slider.bullets.begin() + i);
                        meteors.erase(meteors.begin() + j);
                        i--;  // Decrease index to prevent skipping a bullet due to erasure
                        break;  // Exit inner loop to prevent undefined behavior due to erasure
                    }
                }
            }
        }

        if (meteorTimer <= 0)
        {
            meteors.push_back(Meteor(800, rand() % (600 - 20) + 10)); // 10 is the radius of the meteor, 20 is twice the radius
            meteorTimer = 5000; // adding a delay between meteor spawns (in frames)
        }

        // Check meteor movement
        for (int i = 0; i < meteors.size(); i++)
        {
            meteors[i].Move();

            // If the meteor is off the left edge of the screen
            if (meteors[i].shape.getPosition().x < 0)
            {
                meteors.erase(meteors.begin() + i);
                i--;  // Decrease index to prevent skipping a meteor due to erasure
            }
        }

        window.clear();

        slider.Draw(window);
        for (Meteor& meteor : meteors)
        {
            meteor.Draw(window);
        }

        window.display();

        if (meteorTimer > 0) meteorTimer--;
    }

    return 0;
}
