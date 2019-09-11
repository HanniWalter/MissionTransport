#pragma once
#include "GameObject.h"
#include <string>
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Enums.h"
#include "Intersection.h"

std::string inputString(std::string out);

int inputInt(std::string out);

void println(std::string out);

void println(int out);

void print(std::string out);

void print(int out);

int d(int x1,int x2,int y1,int y2);

std::vector<GameObject*> getInRange(int range, GameObject center, std::vector<GameObject> input);

StockTyp GoodToStockTyp(Good g);

int min(int a, int b);

int max(int a, int b);

std::string enumToSting(Good g);
std::string enumToSting(StockTyp g);
