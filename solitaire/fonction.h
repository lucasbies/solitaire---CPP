#pragma once
#include <random>
#include "Carte.h"
#include<array>
#include <vector>

//donne un nombre aléatoire
int carte_hasard(int max);

std::array<std::vector<CCarte>, 7> remplissage_plateau(std::vector <CCarte>& pioche);

void melange_pioche(std::vector <CCarte>& pioche);

std::vector <CCarte> creation_pioche();