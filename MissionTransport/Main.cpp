#include "Globals.h"
#include "Display.h"
#include "World.h"
#include <chrono>
#include "SDL.h" // don't delete
#include <string>
#include <vector>
#include "Util.h"


void initGlobalProduktion() {
	GlobalProduction = { Production(1), Production(2) };
}

/*

int programfunction() {
	//Messy Part
	GSTicking = true;
	GSRunning = true;
	World w(1);
	GlobalWorld = &w;

	/*
	if (GSDisplayMode == 2) {
		Display d;
		GlobalDisplay = &d;
	}
	*

	//Event handler for GameEvennts not implemtented maybe later if needed


	if (GSDisplayMode == 1) {
		while (GSRunning)
		{
			std::string command = inputString("Insert command");
			if (command == "stop") {
				break;
				GSRunning == false;
			}
			else if (command == "worldstate") {
				GlobalWorld->worldprint();
			}
			else if (command == "print") {
				std::string command2 = inputString("Insert List");
				if (command2 == "station") {
					for (int i = 0; i < GlobalWorld->getStations().size(); i++) {
						print(i);
						GlobalWorld->getStations().at(i).printStation();

					}
				}
				else if (command2 == "intersection") {
					for (int i = 0; i < GlobalWorld->getStations().size(); i++) {
						print(i);
						GlobalWorld->getStations().at(i).printIntersection();
					}
				}
				else if (command2 == "track") {
					for (int i = 0; i < GlobalWorld->getStations().size(); i++) {

					}
				}
			}
			else if (command == "add") {
				std::string command2 = inputString("Object");
				if (command2 == "station") {
					GlobalWorld->addStation(inputInt("Input X"), inputInt("Input Y"));
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
						list.push_back({ inputInt("X?"),inputInt("Y?") });
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
		//refferenzzeit m�glichst nah an der Gameloop
		std::chrono::high_resolution_clock::time_point Oldtime = std::chrono::high_resolution_clock::now();
		// gameloop
		while (GSRunning) {
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

*/
#include "Stock.h"
#include "Enums.h"
#include "Fabric.h"
#include "Production.h"
#include "console.h"
#include <Windows.h>
#include "EventHandler.h"


void GameLoop() {
	while(true){
		EventHandler* eventHandler = EventHandler::getInstancePtr();
		eventHandler->HandleEventStack();
		Display::getInstancePtr()->render();
	}
}

int main(int iHate, char* SDL[]) {
	std::shared_ptr<Console> console = Console::getInstancePtr();
	console->activateSeperatedConsole();
	static std::shared_ptr <Display> display = Display::getInstancePtr();
	World::createFormPreset(1);
	std::shared_ptr<World> world = World::getInstance().value();
	world->print();
	GameLoop();
	

	/*
	//	Stock a = Stock::fabricStock(42);
//	Stock b = Stock::fabricStock(42);
	initGlobalProduktion();
	Fabric f = Fabric(10, 10, 42, 42, { {1} });
	f.printFabric();
	f.load(20, Coal);
	f.update(6);
	f.update(6);
	f.update(6);z
	f.update(6);
	f.printFabric();

//	a.printStock();
//	b.printStock();



//	a.printStock();
//	b.printStock();

**/
}
