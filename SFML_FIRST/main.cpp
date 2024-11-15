#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {

    float WIDTH = 1920;
    float HEIGHT = 1080;
    float baseSpeed = 200.f;
    float scaleSpeed = 0.5f;

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SpaceWar");


    Texture playerTexture;
    Texture enemyTexture;
    Texture playerBulletTexture;
    Texture enemyBulletTexture;
    Texture backgroundTexture;

    if (!playerTexture.loadFromFile("images/playerTexture.png") ||
        !enemyTexture.loadFromFile("images/enemyTexture.png") ||
        !playerBulletTexture.loadFromFile("images/playerBulletTexture.png") ||
        !enemyBulletTexture.loadFromFile("images/enemyBulletTexture.png") ||
        !backgroundTexture.loadFromFile("images/backGround.png")) {
        return -1; 
    }

 
    Sprite player;
    player.setTexture(playerTexture);
    player.setScale(2.f, 2.f);
    player.setPosition(WIDTH / 2, HEIGHT - 200);


    Sprite enemy;
    enemy.setTexture(enemyTexture);
    enemy.setScale(1.f, 1.f);
    enemy.setPosition(WIDTH / 2, 50);  


    Sprite playerBullet;
    playerBullet.setTexture(playerBulletTexture);
    playerBullet.setScale(1.f, 1.f);
    playerBullet.setPosition(WIDTH / 2, HEIGHT - 200);  


    Sprite enemyBullet;
    enemyBullet.setTexture(enemyBulletTexture);
    enemyBullet.setScale(1.f, 1.f);
    enemyBullet.setPosition(WIDTH / 2, 100);  


    Sprite background;
    background.setTexture(backgroundTexture);
    background.setScale(1.f, 1.f);
    background.setPosition(0, 0);



    Clock clock;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }


        float deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f) deltaTime = 1.0f;


        float speed = baseSpeed;
        if (Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift)) {
            speed *= 2.0f;
        }
        if (Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl)) {
            speed *= 0.5f;
        }

        if (Keyboard::isKeyPressed(Keyboard::C)) {
            player.scale(1 + scaleSpeed * deltaTime, 1 + scaleSpeed * deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::V)) {
            player.scale(1 - scaleSpeed * deltaTime, 1 - scaleSpeed * deltaTime);
        }


        FloatRect bounds = player.getGlobalBounds();
        if (Keyboard::isKeyPressed(Keyboard::W) && bounds.top > 0) {
            player.move(0.f, -speed * deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && bounds.top + bounds.height < window.getSize().y) {
            player.move(0.f, speed * deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && bounds.left > 0) {
            player.move(-speed * deltaTime, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && bounds.left + bounds.width < window.getSize().x) {
            player.move(speed * deltaTime, 0.f);
        }


        window.clear(Color::Transparent);
        window.draw(background); 
        window.draw(player);
        window.display(); 
    }

    return 0;
}
