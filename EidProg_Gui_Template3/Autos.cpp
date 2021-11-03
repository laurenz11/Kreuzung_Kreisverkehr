#include "Autos.h"
#include "CarProp.h"

void Autos::initTexture(Color c)
{
    switch (c) {
    case Color::BLUE: this->texture.loadFromFile("images/BlueCar.png"); break;
    case Color::YELLOW: this->texture.loadFromFile("images/YellowCar.png"); break;
    case Color::RED: this->texture.loadFromFile("images/RedCar.png"); break;
    }
}

void Autos::initSprite()
{
    this->sprite.setTexture(this->texture);
    //sprite skalieren
    this->sprite.scale(0.075f, 0.075f);
    this->sprite.setOrigin(320, 640);
}

void Autos::beschleunigung()
{
    this->speedp = speedp + 0.005;
    this->speedm = speedm - 0.005;
}

void Autos::bremsung()
{
    if (speedm < 0)
    {
        this->speedm + 0.01;
    }
    else this->speedm = 0;

    if (speedp > 0)
    {
        this->speedp - 0.01;
    }
    else this->speedp = 0;
}

Autos::Autos(Direction spawn, Color color, Direction direction)
{
    this->originalDirection = direction;
    switch (spawn) {
    case Direction::WEST: this->sprite.setPosition(20.f, 550.f); direction = Direction::EAST; break;
    case Direction::NORTH: this->sprite.setPosition(450.f, 30.f); direction = Direction::SOUTH; break;
    case Direction::EAST: this->sprite.setPosition(990.f, 450.f); direction = Direction::WEST; break;
    case Direction::SOUTH: this->sprite.setPosition(550.f, 970.f); direction = Direction::NORTH; break;
    }

    this->initTexture(color);
    this->initSprite();
    this->currentDirection = direction;
    switch (direction) {
    case Direction::NORTH: this->sprite.setRotation(0.f); break;
    case Direction::EAST: this->sprite.setRotation(90.f); break;
    case Direction::SOUTH: this->sprite.setRotation(180.f); break;
    case Direction::WEST: this->sprite.setRotation(270.f); break;
    }
}

Autos::~Autos()
{
}

int Autos::stopNS()
{
    return 0;
}

const sf::Vector2f Autos::getPos() const
{
    return this->sprite.getPosition();
}


const Direction Autos::getOriginalDir() const
{
    return this->originalDirection;
}

const Direction Autos::getCurrentDir() const
{
    return this->currentDirection;
}


void Autos::update()
{

    switch (this->currentDirection)
    {

    case Direction::SOUTH: {
        this->beschleunigung();
        //this->bremsung();
        if (sprite.getPosition().y >= 450 && sprite.getPosition().y <= 560)
        {
            
            if (rndValue < 4)
                {
                this->sprite.move(speedm, 0.f); //richtung westen
                this->sprite.setRotation(-90.f);

            }
            else if (rndValue >= 4 && rndValue < 8)
            {
                if (sprite.getPosition().y >= 550)
                {
                    this->sprite.move(speedp, 0.f);
                    this->sprite.setRotation(90.f);
                }
                else this->sprite.move(0.f, speedp);
            }
            else
            {
                this->sprite.move(0.f, speedp);
            }

        }
        else if (sprite.getPosition().y >= 440 && sprite.getPosition().y > 450)
        {
            this->sprite.move(0.f, 0.f);
        }
        else this->sprite.move(0.f, speedp);
        break;
   
    }

    case Direction::EAST: {
        this->beschleunigung();
        if (sprite.getPosition().x >= 460 && sprite.getPosition().x <= 560)
        {

            if (rndValue < 8)
            {
                
                if (sprite.getPosition().x >= 550) 
                {
                    this->sprite.move(0.f, speedm); //richtung Norden
                    this->sprite.setRotation(0.f);
                }
                else this->sprite.move(speedp, 0.f);
            }
            else if (rndValue > 8)
            {
                this->sprite.move(0.f, speedp); //richtung süden
                this->sprite.setRotation(180.f);
            }
            else
            {
                this->sprite.move(speedp, 0.f);
            }
        }
        else this->sprite.move(speedp, 0.f);
        break;
    }
     
    case Direction::WEST: {
        this->beschleunigung();
        if (sprite.getPosition().x <= 550 && sprite.getPosition().x >= 440)
        {

            if (rndValue < 9)
            {
                this->sprite.move(0.f, speedm); //richtung Norden
                this->sprite.setRotation(0.f);
            }
            else if (rndValue > 8)
            {
                if (sprite.getPosition().x <= 450)
                {
                    this->sprite.move(0.f, speedp); //richtung süden
                    this->sprite.setRotation(-180.f);
                }
                else this->sprite.move(speedm, 0.f);
            }
            else
            {
                this->sprite.move(speedm, 0.f);
            }
        }
        else this->sprite.move(speedm, 0.f);
        break;
    }
    case Direction::NORTH: {
        this->beschleunigung();
        if (sprite.getPosition().y <= 550)
        {

            if (rndValue < 4)
            {
                if (sprite.getPosition().y <= 450)
                {
                    this->sprite.move(speedm, 0.f); //richtung westen
                    this->sprite.setRotation(-90.f);
                }
                else this->sprite.move(0.f, speedm);
            }
            else if (rndValue >= 4 && rndValue < 8)
            {
                this->sprite.move(speedp, 0.f); //richtung osten
                this->sprite.setRotation(90.f);
            }
            else
            {
                this->sprite.move(0.f, speedm);
            }
        }
        else this->sprite.move(0.f, speedm);
        break;
    }
    }

}

void Autos::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
