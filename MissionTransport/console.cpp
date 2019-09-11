#include "console.h"
#include <iostream>
#include <memory>

std::optional<std::shared_ptr<Console>> Console::instancePtr = {};

//call as threat
int Console::inputReader()
{
	while(seperatedConsoleActiv)
	{
		this->consoleInput();
	}
	return 0;
}


void Console::consoleInput()
{
	std::string  str;
	std::cin >> str;
//	if(str !="") this->insert(str);

}

void Console::processInput(std::string)
{

}

Console::~Console()
{
}

Console::Console()
{
	log = {};
	inputLine = std::string("");
}


std::shared_ptr<Console> Console::getInstancePtr()
{
	if (!instancePtr.has_value()) {
		std::shared_ptr<Console> ptr(new Console());
		instancePtr = ptr;
	}
	return instancePtr.value();
}

void Console::clear()
{
	log.clear();
}

std::vector<std::string> Console::getLog()
{
	std::vector<std::string> returner(log);
	if (inputLine != "") {
		returner.push_back(inputLine);
	}
	return returner;
}

void Console::print(std::string str)
{
	this->log.push_back(str);
}

void Console::insert(std::string str)
{
	this->print(str);
	this->processInput(str);
}

void Console::activateSeperatedConsole()
{
	std::thread seperatedConsoleThread(&Console::inputReader, this);
	seperatedConsoleActiv = true;
	seperatedConsoleThread.detach();
}

void Console::deactivateSeperatedConsole()
{
	seperatedConsoleActiv = false;
}

void Console::inputLineFinishLine()
{
	this->insert(inputLine);
	this->inputLineDeleteLine();
}

void Console::inputLineDeleteLine()
{
	inputLine = "";
}

void Console::inputLineDeleteCharacter()
{
	if (inputLine != "") {
		inputLine.pop_back();
	}
}

void Console::inputLineAddCharacter(std::string s)
{
	inputLine.append(s);
}