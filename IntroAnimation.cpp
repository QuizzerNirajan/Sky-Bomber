#include "../IntroAnimation.h"

using std::vector;
using std::stringstream;
using std::string;

void Animation::start() {

	vector <sf::Sprite>sprites(120);
	vector <sf::Texture>textures(120);
	vector <string> names(120);

	sf::Music bgmu;
	if (!bgmu.openFromFile("resources/planesound.wav"))
		std::cout << "sound couldn't be stream";


	for (int i = 1; i < 120; i++)
	{
		stringstream aname;
		aname << i;
		string aName = aname.str();
		if (aName.size() < 4)
		{
			string extras(4 - aName.size(), '0');
			aName = extras + aName;
		}
		string root = "intro/";
		aName = root + aName;
		aName = aName + ".png";
		names[i - 1] = aName;

	}

	for (int i = 0; i < 120; i++)
	{

		if (!textures[i].loadFromFile(names[i]))
		{
			//error
		}
		sprites[i].setTexture(textures[i]);
	}

	bgmu.play();
	sf::RenderWindow app(sf::VideoMode(1366, 766), "High Score");
	int i = 0;
	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				app.close();
			}

		}
		app.clear();

		if (i < 120)
		{
			app.draw(sprites[i]);
			i++;
			Sleep(100);

		}

		else
		{
			break;
		}
		app.display();

	}
	bgmu.pause();
	app.close();
	Splash::start();

}