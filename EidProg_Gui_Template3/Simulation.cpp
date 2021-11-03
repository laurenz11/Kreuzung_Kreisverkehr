#include "Simulation.h"
#include "CarProp.h"

void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 1000), "Simulation", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(165);
	this->window->setVerticalSyncEnabled(false);

	this->blendmode = new sf::RenderStates();
}

void Simulation::initAuto()
{
	this->spawnTimerMax = 20.f;
}

void Simulation::initKreuzverkehr()
{
	if (!this->KreuzverkehrTex.loadFromFile("images/Kreuzverkehr.png"));
	{
		//std::cout << "kein hintergrund\n";
	}
	this->Kreuzverkehr.setTexture(this->KreuzverkehrTex);
}

void Simulation::renderWorld()
{
	this->window->draw(this->Kreuzverkehr);
}

void Simulation::initGUI()
{
	gui = new GUI(this->window);
}



Simulation::Simulation()
{
	this->initWindow();
	this->initAuto();
	this->initKreuzverkehr();
	this->initGUI();
}



Simulation::~Simulation()
{
	delete this->window;
	for (auto* i : this->autos)
	{
		delete i;
	}

}
//funktionen
void Simulation::run()
{
	this->startIsAllowed = false;
	this->createAmpel();
	std::cout << "create ampel" << std::endl;
	while (this->window->isOpen())
	{
		//Wie kannst du die Minutenvorgabe ins programm einbinden? + mache aus Stopp ein anhalten + z�hle/l�sche autos, die das Feld verlassen
		this->update();
		this->render();

		if (startIsAllowed) {
			this->updateAfterStart();
		}
		
	}
}

void Simulation::updateAuto()
{

	int rndValue = rand() % 10;
	//std::cout << rndValue << std::endl;
	int rndAnfahrt = rand() % 100;
	Direction spawn;
	if (rndAnfahrt < 15) {
		if (Functions::checkSpawnNorth(autos) == 0) {
			spawn = Direction::NORTH;
			//std::cout << "spawn auf nord" << std::endl;
		}
		else { spawn = Direction::NOWHERE;  }
	}
	else if (rndAnfahrt < 50) {
		if (Functions::checkSpawnEast(autos) == 0) {
			spawn = Direction::EAST;
			//std::cout << "spawn auf ost" << std::endl;
		}
		else { spawn = Direction::NOWHERE;  }
	}
	else if (rndAnfahrt < 65) {
		if (Functions::checkSpawnSouth(autos) == 0) {
			spawn = Direction::SOUTH;
			//std::cout << "spawn auf sued" << std::endl;
		}
		else { spawn = Direction::NOWHERE;  }
	}
	else {
		if (Functions::checkSpawnWest(autos) == 0) {
			spawn = Direction::WEST;
			//std::cout << "spawn auf west" << std::endl;
		}
		else { spawn = Direction::NOWHERE;  }
	}

	if (spawn != Direction::NOWHERE) {
		//rotes auto generieren
		if (rndValue < 2) // rotes Auto 20 %
		{
			this->autos.push_back(new Autos(spawn, Color::RED, Direction::EAST));
			//std::cout << "pushed back" << std::endl;
		}
		//Gelbes Auto generieren
		if (rndValue >= 2 && rndValue < 9) // gelbes Auto 70%
		{
			this->autos.push_back(new Autos(spawn, Color::YELLOW, Direction::WEST));
			//std::cout << "pushed back" << std::endl;
		}
		//Blaues Auto generieren
		if (rndValue == 9) // blaues Auto 10 %
		{
			this->autos.push_back(new Autos(spawn, Color::BLUE, Direction::EAST));
			//std::cout << "pushed back" << std::endl;
		}
	}
}

void Simulation::update()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
		this->gui->ClickedOnClose(window, e);
		this->gui->ClickedOnStart(e, &startIsAllowed);
		this->gui->ClickedOnStop(e, &startIsAllowed);
		this->gui->handleEvent(e);
	}
}

void Simulation::updateAfterStart() {

	for (auto* car : this->autos)
	{
		//if (Functions::allowMovement(*car, autos) == true) {
		car->update();

	}

	this->spawnTimer++;
	//Auto bewegen
	if (this->spawnTimer % 100 == 0) {
		this->updateAuto();
		//std::cout << "updateAuto\n";
	}

	if (this->spawnTimer % 1000 == 0 ) {
	  this->updateAllAmpel();
	}

	
	// if (this->spawnTimer == 500 || this->spawnTimer == 1500) {
	// 	this->updateAmpel1();
	// }
	// if (this->spawnTimer == 530 || this->spawnTimer == 1530) {
	// 	this->updateAmpel2();
	// }
	// if (this->spawnTimer == 540 || this->spawnTimer == 1540) {
	// 	this->updateAmpel3();
	// }
	// if (this->spawnTimer == 570 || this->spawnTimer == 1570) {
	// 	this->updateAmpel4();
	// }
	// if (this->spawnTimer == 930 || this->spawnTimer == 1930) {
	// 	this->updateAmpel5();
	// }
	// if (this->spawnTimer == 960 || this->spawnTimer == 1960) {
	// 	this->updateAmpel6();
	// }
	// if (this->spawnTimer == 970 || this->spawnTimer == 1970) {
	// 	this->updateAmpel7();
	// }
	// if (this->spawnTimer == 1000 || this->spawnTimer == 2000) {
	// 	this->updateAmpel8();
	// }
}

void Simulation::render() {
	this->window->clear(sf::Color(200, 200, 200));

	this->gui->render(this->window);

	this->renderWorld();
	for (Ampel* far : this->ampeln)
	{
		far->render(*this->window);
	}

	for (auto* car : this->autos)
	{
		car->render(*this->window);
	}
	this->window->display();
	
}
void Simulation::createAmpel()
{
	this->ampeln.push_back(new Ampel(Ampel_Seite::OBEN, Ampel_Farbe::RED));
	this->ampeln.push_back(new Ampel(Ampel_Seite::UNTEN, Ampel_Farbe::RED));
	this->ampeln.push_back(new Ampel(Ampel_Seite::RECHTS, Ampel_Farbe::GREEN));
	this->ampeln.push_back(new Ampel(Ampel_Seite::LINKS, Ampel_Farbe::GREEN));

}

// schaltet alle Ampeln einen Zyklus weiter
void Simulation::updateAllAmpel() {
  std::cout << "update all traffic lights" << std::endl;
  for(int i = 0; i < this->ampeln.size();i++) {
    this->updateAmpel(i);
  }
}

// schaltet die Ampel mit dem Index 'index' einen Zyklus weiter
void Simulation::updateAmpel(int index) {
  this->ampeln[index]->cycle();
}


