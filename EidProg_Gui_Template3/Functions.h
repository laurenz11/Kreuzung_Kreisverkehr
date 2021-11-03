#pragma once
#include "Autos.h"
#include "GUI.h"

class Functions
{

public:

    //Überprüft, ob ein Auto gespawnt werden darf, oder ob die Stelle beretis belegt ist. Eine Funktion für jede Himmelsrichtung (checkSpawnNorth, checkSpawnSouth, checkSpawnWest, checkSpawnEast)
    static  bool checkSpawnNorth(std::vector<Autos*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        //std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //std::cout << "Schleife beginnt\n";
                //std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::SOUTH:
                    if (cars[i]->getPos().y < 150) {
                        return blocked = 1;
                        //std::cout << "blocked" << std::endl;
                    }

                    else {  blocked = 0;  }

                    break;
                    break;

                default:blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnSouth(std::vector<Autos*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
        //std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
           // std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
                //std::cout << "Schleife beginnt\n";
                //std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::NORTH:
                    if (cars[i]->getPos().y > 850) {
                        return blocked = 1;
                       // std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0;  }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return 0;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnEast(std::vector<Autos*> cars)
    {
       // std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
       // std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
          //  std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
              //  std::cout << "Schleife beginnt\n";
               // std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::WEST:
                    if (cars[i]->getPos().x > 850) {
                        return blocked = 1;
                      //  std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0;  }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
            //std::cout << "blocked returned" << std::endl;
        }

    }

    static  bool checkSpawnWest(std::vector<Autos*> cars)
    {
        //std::cout << "checkSpawn aufgerufen" << std::endl;
        bool blocked;
       // std::cout << "blocked erstellt\n";

        if (cars.empty()) {
            blocked = 0;
            //std::cout << "cars noch empty\n";
            return blocked;
        }

        else {
            for (int i = 0; i < cars.size(); i++)
            {
              //  std::cout << "Schleife beginnt\n";
              //  std::cout << i << std::endl;
                switch (cars[i]->getCurrentDir()) {

                case Direction::EAST:
                    if (cars[i]->getPos().x < 150) {
                        return blocked = 1;
                   //     std::cout << "blocked" << std::endl;
                    }

                    else { blocked = 0;  }

                    break;
                    break;

                default: blocked = 0;
                    break;

                }

            }
            return blocked;
           // std::cout << "blocked returned" << std::endl;
        }

    }

    static float distance(Autos obj_1, Autos obj_2) {
        float dist_x = obj_1.getPos().x - obj_2.getPos().x;
        float dist_y = obj_1.getPos().x - obj_2.getPos().y;

        float distance = sqrt((dist_x*dist_x) + (dist_y*dist_y));
        return distance;
    }

    static bool checkDistance(Autos obj_1, Autos obj_2) {

        if (distance(obj_1, obj_2) < 20) {
            return true;
        }
        else return false;
    }

    static bool checkIfSameDirection(Autos focusedCar, Autos CarToCheck) {
        if (focusedCar.getOriginalDir() == CarToCheck.getOriginalDir()) {
            return true;

        }
        else return false;
    }

    static bool checkIfTooClose(Autos focusedCar, Autos CarToCheck) {
        return checkDistance(focusedCar, CarToCheck);

    }

    static bool checkForEquality(Autos obj_1, Autos obj_2) {
        if (obj_1.getPos() == obj_2.getPos()) {
            return true;
        }

        else return false;
    }

    static bool allowMovement(Autos focusedCar, std::vector<Autos*> autos) {
        for (auto* CarToCheck : autos) {
            if (checkForEquality(focusedCar, *CarToCheck))
            {
                return true;
            }

            else if (checkIfTooClose(focusedCar, *CarToCheck) && checkIfSameDirection(focusedCar, *CarToCheck)) {
                return false;
                break;
            }

            else return true;
        }
    }

    static void deleteCars(std::vector<Autos*> autos) { //Soll Objekte aus dem Vektor autos löschen, wenn diese den Bildschirm verlassen
        for (int i = 0; i < autos.size(); i++) {
            if (autos[i]->getPos().x < 0) {
                autos.erase(autos.begin() + i);
                //counterWest ++;
            }

            else if (autos[i]->getPos().x > 1000) {
                autos.erase(autos.begin() + i);
                //counterEast ++;
            }

            else if (autos[i]->getPos().y > 1000) {
                autos.erase(autos.begin() + i);
                //counterSouth ++;
            }
            else if (autos[i]->getPos().y < 0) {
                autos.erase(autos.begin() + i);
                //counterNorth ++;
            }
            else break;
        }
    }


    static unsigned int backToGUI(unsigned int, unsigned int) {

    }
};

