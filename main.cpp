#include <SFML/Graphics.hpp>

sf::Vector2f playerPos;
sf::Vector2f blockPos;

sf::Vector2f mv;

int blocksizex = 20;
int blocksizey = 20;
int playersizex = 20;
int playersizey = 20;

int xdiff = (blocksizex / 2) + (playersizex / 2);
int ydiff = (blocksizey / 2) + (playersizey / 2);

float mvspeed = 10.0;

int main() {
//    sf::RenderWindow window(sf::VideoMode(1360, 768), "My window", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(600, 600), "my game");
	window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("/home/kip/CLionProjects/sfml-app/textures.png");

	sf::Sprite player;
	player.setTexture(texture);
	player.setTextureRect(sf::IntRect(0, 0, 20, 20));
	player.setOrigin(10.f, 10.f);

	sf::Sprite block;
	block.setTexture(texture);
	block.setTextureRect(sf::IntRect(20, 0, 20, 20));
//	block.scale((blocksizex / 20), (blocksizey / 20));
	block.setOrigin((blocksizex / 2), (blocksizey / 2));
	block.move(sf::Vector2f(100.f, 100.f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		mv.x = 0.f;
		mv.y = 0.f;

		if (event.type == sf::Event::TextEntered){
			if (event.text.unicode < 128){
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
					player.move(sf::Vector2f(0.f, -mvspeed));
					mv.y = -mvspeed;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
					player.move(sf::Vector2f(-mvspeed, 0.f));
					mv.x = -mvspeed;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
					player.move(sf::Vector2f(0.f, mvspeed));
					mv.y = mvspeed;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
					player.move(sf::Vector2f(mvspeed, 0.f));
					mv.x = mvspeed;
				}
			}
		}

		playerPos.x = player.getPosition().x;
		playerPos.y = player.getPosition().y;
		blockPos.x = block.getPosition().x;
		blockPos.y = block.getPosition().y;

		if((playerPos.x > (blockPos.x - xdiff)) && (playerPos.x < (blockPos.x + xdiff)) && (playerPos.y > (blockPos.y - ydiff)) && (playerPos.y < (blockPos.y + ydiff))){

			mv.x = mv.x * -1.f;
			mv.y = mv.y * -1.f;

			player.move(mv);
		}

		window.draw(player);
		window.draw(block);
		window.display();
	}

	return 0;
}