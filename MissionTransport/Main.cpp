#include "Globals.h"
#include "Display.h"
#include "World.h"
#include <chrono>
#include "SDL.h" // don't delete
#include <string>
#include <vector>
#include "Util.h"



int main(int iHate, char* SDL[]) {
	//Messy Part
	GSDisplayMode = 1;
	GSTicking = true;
	GSRunning = true;
	World w(1);
	GlobalWorld = &w;

	if (GSDisplayMode == 2) {
		Display d;
		GlobalDisplay = &d;
	}
	//Event handler for GameEvennts not implemtented mabey later if needed


	if (GSDisplayMode == 1) {
		while (GSRunning == true)
		{
			std::string command = inputString("Insert command");
			if (command == "stop") {
				break;
				GSRunning == false;
			}
			else if(command == "worldstate"){
				GlobalWorld->worldprint();
			}
			else if (command == "print") {
				std::string command2 = inputString("Insert List");
				if (command2 == "station") {
					for (int i = 0;i<GlobalWorld->getStations().size();i++) {
						print(i);
						GlobalWorld->getStations().at(i).printStation();
					
					}
				}else if (command2 == "intersection") {
					for (int i = 0; i < GlobalWorld->getStations().size(); i++) {
						print(i);
						GlobalWorld->getStations().at(i).printIntersection();
					}
				}else if (command2 == "track") {
					for (int i = 0; i < GlobalWorld->getStations().size(); i++) {

					}
				}
			}
			else if (command == "add") {
				std::string command2 = inputString("Object");
				if (command2 == "station") {
					GlobalWorld->addStation(inputInt("Input X"),inputInt("Input Y"));
				}
				else if (command2 == "intersection") {
					GlobalWorld->addIntersection(inputInt("Input X"), inputInt("Input Y"));
				}
				else if (command2 == "track") {
					int points = inputInt("number of points beetween start and end");
					int int1 = inputInt("Intersection A");
					int int2 = inputInt("Intersection B");
					std::vector<std::vector<int>> list = std::vector<std::vector<int>>();
					for (int i = 0; i < points; i++) {
						list.push_back({inputInt("X?"),inputInt("Y?")});
					}
					GlobalWorld->addTrack(GlobalWorld->getIntersections().at(int1), list, GlobalWorld->getIntersections().at(int2));
				}
			}
			else {
				println("Command not found");
			}
		}
	}

	if (GSDisplayMode == 2) {
		//refferenzzeit möglichst nah an der Gameloop
		std::chrono::high_resolution_clock::time_point Oldtime = std::chrono::high_resolution_clock::now();
		// gameloop
		while(GSRunning) {
			//Tick
			std::chrono::high_resolution_clock::duration ticktime = std::chrono::high_resolution_clock::now() - Oldtime;
			unsigned int tick = std::chrono::duration_cast<std::chrono::microseconds>(ticktime).count();
			Oldtime = std::chrono::high_resolution_clock::now();

			//update all objects
			GlobalWorld->update(tick);

			//render display
			GlobalDisplay->render();
		}
	}
	

	return 42;
}
