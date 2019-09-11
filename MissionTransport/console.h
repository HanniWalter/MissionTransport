#pragma once
#include <vector>
#include <string>
#include <thread>
#include <optional>


//singleton
class Console
{
private:
	Console();
	int inputReader();
	static std::optional<std::shared_ptr<Console>>  instancePtr;
	bool seperatedConsoleActiv = false;
	static std::thread seperatedConsoleThread;
	std::vector<std::string> log;
	std::string inputLine = std::string("");
	void consoleInput();
	void processInput(std::string);
public:
	~Console();
	static std::shared_ptr<Console> getInstancePtr();
	void clear();
	std::vector<std::string> getLog();
	void print(std::string);
	void insert(std::string);

	void activateSeperatedConsole();
	void deactivateSeperatedConsole();

	void inputLineFinishLine();
	void inputLineDeleteLine();
	void inputLineDeleteCharacter();
	//may change to character
	void inputLineAddCharacter(std::string);
};