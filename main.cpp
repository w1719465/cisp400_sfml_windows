// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace sf;
using namespace std;
int main()
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;
	View mainView(FloatRect(0.0f,0.0f,width, height));
	//width = 800; height = 600;
	// Create a video mode object
	VideoMode vm(width, height);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	vector<Vector2f> vertices;
	vector<Vector2f> points;
	int click=0;

	Font f;
	if (!f.loadFromFile("./fonts/KOMIKAP_.ttf")) cout << "failed to load font..." << endl;
	Text instructions;
	instructions.setFont(f);
	instructions.setCharacterSize(24);
	instructions.setFillColor(Color::Green);

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
				if ((event.mouseButton.button == sf::Mouse::Left) && (click <= 4)) 
				{
				    click++;
				    //if (click == 4) { click = 1; }

					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					// get the current mouse position in the window
					sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

					// convert it to world coordinates
					sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos, mainView);
					vertices.push_back(worldPos);					
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

		if (click <= 4)
		{
		    ostringstream oss;
		    oss << "Click " << click;
		    instructions.setString(oss.str());

		    FloatRect textRect = instructions.getLocalBounds();
		    instructions.setOrigin(textRect.left +
			   textRect.width / 2.0f,
			   textRect.top +
			   textRect.height / 2.0f);

		    instructions.setPosition(width / 2, 50);
		}
		/*
		****************************************
		Draw the scene
		****************************************
		*/
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		//RectangleShape r{ Vector2f{4,4} }; ///width, height.  Center uninitialized
		window.setView(mainView);
		CircleShape r(6);
		r.setFillColor(Color::Magenta);
		
		if (click < 4)
		{
		    for (int i = 0; i < vertices.size(); i++)
		    {
			   r.setPosition(Vector2f{ vertices.at(i).x, vertices.at(i).y });
			   window.draw(r);
		    }		   
		}
		else
		{
		    bool done = false;
		    int ii = 0;
		    while (!done)
		    {
			   r.setPosition(Vector2f{ vertices.at(ii).x, vertices.at(ii).y });
			   window.draw(r);
			   ii++;

			   //************************		   			   
			   int sz = vertices.size() - 1;
			   float x1 = vertices.at(sz).x;
			   float y1 = vertices.at(sz).y;

			   srand(ii);
			   int rnd = (rand() % 3) + 0;
			   float x2 = vertices.at(rnd).x;
			   float y2 = vertices.at(rnd).y;

			   cout << "rnd = " << rnd << endl;
			   cout << "x1 = " << x1 << ", y1 = " << y1 << endl;
			   cout << "x2 = " << x2 << ", y2 = " << y2 << endl;

			   float dx = x2 - x1;
			   float dy = y2 - y1;
			   dx = sqrt(dx * dx) / 2.0;
			   dy = sqrt(dy * dy) / 2.0;

			   if (x2 > x1)
				  dx += x1;
			   else
				  dx += x2;

			   if (y2 > y1)
				  dy += y1;
			   else
				  dy += y2;

			   vertices.push_back(Vector2f{dx,dy});

			   //***************
			   if (ii > 100) {
				  done = true;
				  click = 0;	
				  //vertices.clear();
			   }
		    }		    
		}

		int xx = event.mouseButton.x;
		int yy = event.mouseButton.y;
		instructions.setPosition(xx, yy);
		window.draw(instructions);

		// Show everything we just drew
		window.display();		
	}

	return 0;
}
