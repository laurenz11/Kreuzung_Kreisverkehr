#pragma once
#include"Autos.h"
#include "Functions.h"
#include "Ampel.h"
#include "GUI.h"
#include "Time.h"

class Simulation
{
private:
	sf::RenderWindow* window;
	sf::RenderStates* blendmode;

	GUI* gui;

	sf::Clock clock;
	//Autos

	//Auto rot
	int spawnTimer;
	int spawnTimerMax;
	std::vector<Autos*> autos;
	std::vector<Ampel*> ampeln;

	//Hintergrund
	sf::Texture KreuzverkehrTex;
	sf::Sprite Kreuzverkehr;

	
	//bool checkDistance(Autos obj_1, Autos obj_2);
	void initWindow();
	void initAuto();
	void initKreuzverkehr();
	void renderWorld();

	//GUI-Sachen erstellen
	void initGUI();




public:
	bool startIsAllowed;
	Simulation();
	virtual ~Simulation();
	Autos stopNS();
	//funktionen
	void run();
  void updateAllAmpel();
  void deleteAutos();
	void updateAuto();
	void updateAmpel(int index);
	void update();
	void updateAfterStart();
	void render();
	void createAmpel();

	void backToGUI(); //ermöglich es Zeit, Anzahl Fahrzeuge an das GUI zu übergeben und zu rendern

};
