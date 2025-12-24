#pragma once
#include "fonction.h"
#include <vector>
#include "Carte.h"
#include <array>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>

class CPLateau
{
	std::vector<CCarte> _pioche;
	std::array < std::vector<CCarte>, 7> _jeu;
	std::array<std::vector<CCarte>, 4> _deck;
	std::vector<CCarte> _defausse;

public:
	CPLateau()=default;
	CPLateau(std::vector<CCarte> _pioche, std::array < std::vector<CCarte>, 7> _jeu);
	std::string Affiche() const;
	void decouverte_pioche();
	void Monter_carte(int);
	void deplacer_carte(int,int, int);
	void pioche_vers_jeu(int);

	bool verif_victoire() const;

};
std::ostream& operator <<(std::ostream& out, CPLateau& plateau);
