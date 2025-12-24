#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32
#include "fonction.h"
#include "Carte.h"
#include <iostream>
#include "Plateau.h"
#include "Game.h"


//Programme principal à compléter

int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    ::SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32
    
    
    CGame game;
	game.jouer();
}
