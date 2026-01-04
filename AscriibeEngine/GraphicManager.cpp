#include "GraphicManager.h"


GraphicManager::GraphicManager()
{
	// init SDL
	fontManager = new FontManager;

 


	//Création fenêtre SDL     
	win = SDL_CreateWindow("Test SDL2 + PDCurses", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (!win)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
	}


	//Création du renderer
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");


	//chargement du font
	fontManager->LoadFont("E:/Programation/Projet/Ascriibe_Engine-SDL2/asset/font/dejavu/ttf/DejaVuSansMono.ttf", 20, { 255, 255, 255, 255 });  //E:/Programation/Projet/Ascriibe_Engine-SDL2/asset/font/dejavu/ttf/DejaVuSans.ttf
}

GraphicManager::~GraphicManager()
{
	fontManager->~FontManager();
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
}



void GraphicManager::DrawScene(Scene* scene)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	CharSize charSize = fontManager->getCharacterSize();


	for (int y = 0; y < scene->maxPos.y; y++)
	{
		for (int x = 0; x < scene->maxPos.x  ; x++)
		{
			chtype ch = mvinch(y, x) & A_CHARTEXT;
			wchar_t wch = ch & A_CHARTEXT;

			std::wstring ws(1, wch);
			std::string utf8 = wchar_to_utf8(ws);

			if (ch == ' ') continue;
			//char chChar = (char)ch;
			SDL_Texture* tex = CreateCharTexture(utf8.c_str());
			
			SDL_Rect rect = { x * charSize.w, y * charSize.h, charSize.w, charSize.h};
			
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			if (ch == '@') SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			if (ch == '#') SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			
			SDL_RenderCopy(renderer, tex, NULL, &rect);
			

			SDL_DestroyTexture(tex); 
		}
	}

	SDL_RenderPresent(renderer);

	//SDL_Delay(2);
}

SDL_Texture* GraphicManager::CreateCharTexture(const char* character)
{
	SDL_Surface* surface = fontManager->getTextSurface(character);//"@╔═╗ UTF-8 █▓▒");
	if (!surface) {
		printf("Render error: %s\n", TTF_GetError());
	}
 
	SDL_Texture* preTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return preTexture;
}




// Convert wchar_t -> UTF-8
std::string GraphicManager::wchar_to_utf8(const std::wstring& wstr) {
	if (wstr.empty()) return {};

	int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), nullptr, 0, nullptr, nullptr);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), strTo.data(), size_needed, nullptr, nullptr);

	return strTo;
}

// Convert UTF-8 -> wchar_t
std::wstring GraphicManager::utf8_to_wchar(const std::string& str) {
	if (str.empty()) return {};

	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), nullptr, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), wstrTo.data(), size_needed);

	return wstrTo;
}
