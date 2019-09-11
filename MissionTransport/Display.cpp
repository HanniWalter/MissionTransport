#include "Display.h"

std::shared_ptr <Display>  Display::instanceptr(new Display());

void Display::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::string("SDL could not Initialize!");
	}
	window = SDL_CreateWindow("MissionTransport", 50, 50, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);//TODO Fullscreen or so
	if (window == NULL) {
		throw std::string("Window could not be created!");
	}
	//int imgFlags = IMG_INIT_PNG;
	//if (!(IMG_Init(imgFlags) & imgFlags)) {
	//	throw std::string("SDL_image could not initialize!");
	//}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		throw std::string("SDL_surface could not created!");
	}
	TTF_Init();

	surface = SDL_GetWindowSurface(window);
	

}

void Display::EventLoop()
{

	for (;;) {
		break;

	}
}

Display::Display()
{
	try
	{
		initSDL();
		displayCreationFLAG = true;
	}
	catch (std::string ex)
	{
		std::cout << ex;
	}
}

std::shared_ptr <Display>  Display::getInstancePtr()
{
	return instanceptr;
}

void Display::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0xE0, 0xE0, 0xE0, 0xFF);
	SDL_RenderClear(renderer);
	if (this->ConsoleFLAG) {
		renderConsole();
	}
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

void Display::renderConsole()
{
	int FontHeigth = 16;	
	int Btl =0;
	TTF_Font* ConsoleFont = TTF_OpenFont("arial.ttf", FontHeigth);
	int maxLines = HEIGHT / (FontHeigth+Btl);
	std::vector<std::string> Lines;
	std::shared_ptr<Console> console = Console::getInstancePtr();
	int firstElement = 0;
	int compvalue = console->getLog().size() - maxLines;
	if (compvalue > 0){
		firstElement = compvalue;
	}
	for (int i = firstElement; i < console->getLog().size(); i++) {
		Lines.push_back(console->getLog()[i]);
	}

	SDL_Rect Message_Line; //create a rect
	SDL_Color textColor = { 0, 0, 0, 0 };

	for( int i = 0;i< Lines.size();i++)
	{
		if (Lines[i].size() > 0) {
			SDL_Surface* textSurface = TTF_RenderText_Solid(ConsoleFont, Lines[i].c_str(), textColor);
			SDL_Texture* Consoletexture = SDL_CreateTextureFromSurface(renderer, textSurface);
			Message_Line.x = 0;
			Message_Line.y = i * (FontHeigth + Btl);
			Message_Line.w = textSurface->w;
			Message_Line.h = textSurface->h;
			SDL_RenderCopy(renderer, Consoletexture, NULL, &Message_Line);
			SDL_DestroyTexture(Consoletexture);
			SDL_FreeSurface(textSurface);
		} 
	}
	TTF_CloseFont(ConsoleFont);
}



/*
int Display::paintObjects()
{
	for (int i = 0; i < GlobalWorld->getTracks().size(); i++)
	{
		paintTrack(GlobalWorld->getTracks().at(i));
	}
	for (int i = 0; i < GlobalWorld->getIntersections().size(); i++)
	{
		paintObject(GlobalWorld->getIntersections().at(i));
	}
	return 0;
}

int Display::paintObject(GameObject object)
{
	if (object.getpicture() == std::string("STATION"))
	{
		filledCircleColor(renderer, object.getX(), object.getY(), 10, 0xff0000ff);
		filledCircleColor(renderer, object.getX(), object.getY(), 8, BACKGROUND);
	}
	return 0;
}

int Display::paintTrack(Track t)
{
	for (int i = 0; i < t.getPoints().size()-1; i++)
	{
		thickLineColor(renderer, 
			t.getPoints().at(i).at(0), 
			t.getPoints().at(i).at(1), 
			t.getPoints().at(i + 1).at(0), 
			t.getPoints().at(i + 1).at(1), 
			4, 
			0xff0000ff);
	}
	return 0;
}





Display::~Display()
{
	//Destroy window 
	SDL_DestroyWindow(window); 
	//Quit SDL subsystems 
	SDL_Quit(); 
}

int Display::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0xE0, 0xE0, 0xE0, 0xFF);
	SDL_RenderClear(renderer);
	paintObjects();
	SDL_RenderPresent(renderer);	
	return 0;
}

*/

;