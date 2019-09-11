#include <optional>+
#include <SDL.h>
#include "Display.h"
#pragma once
//singleton
class EventHandler
{
private:
	static EventHandler* instancePtr;
	EventHandler();
	void HandleEvent(SDL_Event event);
	void HandleKeyUpEvents(SDL_KeyboardEvent event);
	void HandleTextInputEvents(SDL_Event event);
public:
	static EventHandler* getInstancePtr();
	~EventHandler();
	
	void HandleEventStack();
};

