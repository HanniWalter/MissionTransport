#include "EventHandler.h"
#include <iostream>

EventHandler* EventHandler::instancePtr = &EventHandler();

EventHandler::EventHandler()
{
}

void EventHandler::HandleEvent(SDL_Event event)
{
	switch (event.type)
	{
	case SDL_KEYUP:
		HandleKeyUpEvents(event.key);
		break;
	case SDL_TEXTINPUT:
		HandleTextInputEvents(event);
		break;

	
	default:
		break;
	}

}



void EventHandler::HandleKeyUpEvents(SDL_KeyboardEvent event)
{
	static std::shared_ptr <Display> display = Display::getInstancePtr();
	std::shared_ptr<Console> console = Console::getInstancePtr();
	if (display->ConsoleFLAG) {
		switch (event.keysym.sym)
		{
		case SDLK_CARET:
			display->ConsoleFLAG = false;
			break;
		case SDLK_RETURN:
			console->inputLineFinishLine();
			break;
		case SDLK_DELETE:
			console->inputLineDeleteLine();
			break;
		case SDLK_BACKSPACE:
			std::cout << (event.keysym.scancode);
			console->inputLineDeleteCharacter();
			break;
		default:

			break;
		}
	}
	else {
		if (event.keysym.sym == SDLK_CARET) {
			display->ConsoleFLAG = true;
			SDL_StartTextInput();
		}
		//std::cout << (event.keysym.scancode);
	}
	
}

void EventHandler::HandleTextInputEvents(SDL_Event event)
{
	if (event.text.text == "^") return;
	if (Display::getInstancePtr()->ConsoleFLAG){
		Console::getInstancePtr()->inputLineAddCharacter(event.text.text);
	}
}


EventHandler* EventHandler::getInstancePtr()
{
	return instancePtr;
}

EventHandler::~EventHandler()
{
}

void EventHandler::HandleEventStack()
{
	SDL_Event selectedEvent;
	while (SDL_PollEvent(&selectedEvent)) {
		this->HandleEvent(selectedEvent);
	}
}
