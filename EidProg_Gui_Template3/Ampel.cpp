#include "Ampel.h"
#include "CarProp.h"

void Ampel::initTexture(Ampel_Farbe f)
{
  switch (f) {
  case Ampel_Farbe::GREEN: this->texture.loadFromFile("images/GRUEN1.png"); break;
  case Ampel_Farbe::YELLOW: this->texture.loadFromFile("images/GELB1.png"); break;
  case Ampel_Farbe::RED: this->texture.loadFromFile("images/ROT1.png"); break;
  case Ampel_Farbe::REDYELLOW: this->texture.loadFromFile("images/GELBROT1.png"); break;
  }
}

void Ampel::initSprite()
{
  this->sprite.setTexture(this->texture);
  //sprite skalieren
  this->sprite.scale(0.4f, 0.4f);
}

// ein Schritt im Ampelzyklus. ampel_up gibt die Zyklusrichtung an. color die aktuelle Ampelfarbe
void Ampel::cycle() {
  
  switch(color) {
  case Ampel_Farbe::GREEN:
    this->texture.loadFromFile("images/GELB1.png");color=Ampel_Farbe::YELLOW;this->ampel_up=true; break;
  case Ampel_Farbe::YELLOW:
    if (this->ampel_up){
      this->texture.loadFromFile("images/ROT1.png");color=Ampel_Farbe::RED; break;
    } else {
      this->texture.loadFromFile("images/GRUEN1.png");color=Ampel_Farbe::GREEN; break;
    }
  case Ampel_Farbe::RED: this->texture.loadFromFile("images/GELBROT1.png");color=Ampel_Farbe::REDYELLOW;this->ampel_up=false; break;
  case Ampel_Farbe::REDYELLOW: this->texture.loadFromFile("images/GRUEN1.png");color=Ampel_Farbe::GREEN; break;
  }
  this->sprite.setTexture(this->texture,true);
}

Ampel::Ampel(Ampel_Seite seite, Ampel_Farbe farbe)
{
  //spawn: start direction, setposition: start coordinates, Direction: end direction
  switch (seite) {
  case Ampel_Seite::OBEN:   this->sprite.setPosition(430.f, 410.f); break;
  case Ampel_Seite::UNTEN: this->sprite.setPosition(570.f, 620.f); break;
  case Ampel_Seite::RECHTS: this->sprite.setPosition(570.f, 410.f); break;
  case Ampel_Seite::LINKS:  this->sprite.setPosition(430.f, 625.f); break;
  }
  this->color = farbe;
  this->ampel_up = true;
  this->initTexture(farbe);
  this->initSprite();


  switch (seite) {
  case Ampel_Seite::OBEN: this->sprite.setRotation(180.f); break;
  case Ampel_Seite::UNTEN: this->sprite.setRotation(0.f); break;
  case Ampel_Seite::RECHTS: this->sprite.setRotation(270.f); break;
  case Ampel_Seite::LINKS: this->sprite.setRotation(90.f); break;
  }
}

Ampel::~Ampel()
{
}
void Ampel::render(sf::RenderTarget& target)
{
  target.draw(this->sprite);
}
