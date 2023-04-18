// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
int main()
{
	sf::View view(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Fullscreen);
	vector<Vector2f> vertices;
	vector<Vector2f> points;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					vertices.push_back({(float)event.mouseButton.x, (float)event.mouseButton.y});
				}
			}

		}
		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*****************************************
			Update the scene
		*****************************************/
		//generate interior points
		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(view);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		//RectangleShape r{ Vector2f{4,4} }; ///width, height.  Center uninitialized
		CircleShape r(2);
		r.setFillColor(Color::Magenta);
		for (size_t i = 0; i < vertices.size(); i++)
		{
			r.setPosition(Vector2f{ vertices.at(i).x, vertices.at(i).y });
			window.draw(r);
		}

		// Show everything we just drew
		window.display();
	}

	return 0;
}
