#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "CarProp.h"
class Ampel
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	void initTexture(Ampel_Farbe f);
	void initSprite();


public:
	Ampel(Ampel_Seite seite, Ampel_Farbe ampel_farbe);
	virtual ~Ampel();
  Ampel_Farbe color;
  bool ampel_up;
	void render(sf::RenderTarget& target);
  void cycle();
};
