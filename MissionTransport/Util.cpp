#include <string>
#include <iostream>


std::string inputString(std::string out) {
	std::cout << out << std::endl;
	std::string returner;
	std::cin >> returner;
	return returner;
}

int inputInt(std::string out) {
	std::cout << out << std::endl;
	int returner;
	std::cin >> returner;
	return returner;
}

void println(std::string out) {
	std::cout << out << std::endl;
}

void println(int out) {
	std::cout << out << std::endl;
}

void print(std::string out) {
	std::cout << out;
}

void print(int out) {
	std::cout << out;
}