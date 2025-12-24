#include "Plateau.h"


CPLateau::CPLateau(std::vector<CCarte> pioche, std::array<std::vector<CCarte>, 7> jeu)
{
	_pioche = creation_pioche();
	_jeu = remplissage_plateau(_pioche);
	for (size_t i = 0; i < _pioche.size(); i++)
	{
		_pioche[i].setVisible();
	}
	for (size_t i = 0; i < 4; i++)
	{
		_deck[i].push_back(CCarte(0, i+1,true));
	}
	_defausse = {};
}

std::string CPLateau::Affiche() const
{

	if(verif_victoire())
	{
		return "Félicitation vous avez gagné !";
	}

	std::string res="╔══════════════════════════════════════════════════════╗\n"
					"║                                                0     ║\n║";
	for (size_t i = 0; i < 4; i++)
	{
		res+= _deck[i][_deck[i].size() - 1].affiche_carte()+"     ";
	}
	if (!std::empty(_pioche))
		res +="           "+ _pioche[_pioche.size() - 1].affiche_carte()+" ? ";
	else
		res += "           fin  ? ";

	res += "║\n"
		   "║                                                      ║\n"
		   "╠══════════════════════════════════════════════════════╣\n"
		   "║   1       2      3      4      5      6      7       ║\n"
		   "╠══════════════════════════════════════════════════════╣\n║  ";

	// garde la colonne la plus grande
	int max_taille = 0;
	for (size_t i = 0; i < 7; i++)
	{
		if (_jeu[i].size() > max_taille)
		{
			max_taille = _jeu[i].size();
		}
	}

	for (size_t i = 0; i < max_taille; i++) {
		for (size_t j = 0; j < 7; j++)
		{
			if (!std::empty(_jeu[j]) && _jeu[j].size() - 1 >= i)
			{
				res += _jeu[j][i].affiche_carte() + " | ";
			}
			else
				res += "     | ";
		}
		if (i + 1 < 10)
			res += std::to_string(i + 1) + "  ║\n║  ";
		else
			res += std::to_string(i + 1) + " ║\n║  ";
	}
	res += "                                                    ║\n"
		"║                                                      ║\n"
		"║                                                      ║\n"
		"║                                                      ║\n"
		"║                                                      ║\n"
		"║                                                      ║\n"
		"║                                                      ║\n"
		"╚══════════════════════════════════════════════════════╝\n";
	return res;

}

void CPLateau::decouverte_pioche()
{
	if (!std::empty(_pioche))
	{
		_defausse.push_back(_pioche[_pioche.size() - 1]);
		_pioche.pop_back();
	}
	else
	{
		for (size_t i = 0; i < _defausse.size(); i++)
		{
			_pioche.push_back(_defausse[_defausse.size() - 1 - i]);
		}
		_defausse = {};
	}

}

void CPLateau::Monter_carte(int cols)
{
	// Vérifier si on déplace depuis une colonne du jeu
	int colIndex = cols - 1;
	bool isValidColumn = (colIndex >= 0 && colIndex < 7);

	if (isValidColumn)
	{
		CCarte& derniereCarte = _jeu[colIndex][_jeu[colIndex].size() - 1];
		int couleurIndex = derniereCarte.getCouleur() - 1;
		int valeurDeck = _deck[couleurIndex][_deck[couleurIndex].size() - 1].getValeur();

		// La valeur de la dernière carte de la colonne doit être égale à la valeur de la dernière carte du deck de la bonne couleur + 1
		if (derniereCarte.getValeur() == valeurDeck + 1)
		{
			_deck[couleurIndex].push_back(derniereCarte);
			_jeu[colIndex].pop_back();

			if (!std::empty(_jeu[colIndex]))
				_jeu[colIndex][_jeu[colIndex].size() - 1].setVisible();
		}
	}
	else if (cols == 0) // Déplacer depuis la pioche
	{
		CCarte& cartepioche = _pioche[_pioche.size() - 1];
		int couleurIndex = cartepioche.getCouleur() - 1;
		int valeurDeck = _deck[couleurIndex][_deck[couleurIndex].size() - 1].getValeur();

		if (cartepioche.getValeur() == valeurDeck + 1)
		{
			_deck[couleurIndex].push_back(cartepioche);
			_pioche.pop_back();
		}
	}
		
}

void CPLateau::deplacer_carte(int base,int ligne, int fin)
{
	int baseIndex = base - 1;
	int finIndex = fin - 1;
	int ligneIndex = ligne - 1;

	// Vérification des indices
	bool indicesValides = (baseIndex < 7 && finIndex < 7 && ligne > 0 && ligne <= _jeu[baseIndex].size());

	if (!indicesValides)
		return;

	CCarte& carteADeplacer = _jeu[baseIndex][ligneIndex];
	bool colonneFinVide = std::empty(_jeu[finIndex]);

	// Vérifier si on peut placer un roi sur une colonne vide
	bool peutPlacerRoi = (carteADeplacer.getValeur() == 13 && colonneFinVide);

	bool peutDeplacer = false;
	if (!colonneFinVide)
	{
		CCarte& carteFin = _jeu[finIndex][_jeu[finIndex].size() - 1];
		bool valeurCorrecte = (carteADeplacer.getValeur() + 1 == carteFin.getValeur());
		bool couleurAlternee = (carteADeplacer.getCouleur() % 2 != carteFin.getCouleur() % 2);
		peutDeplacer = (valeurCorrecte && couleurAlternee);
	}

	if (peutDeplacer || peutPlacerRoi)
	{
		int taille = _jeu[baseIndex].size();

		// Déplacer les cartes
		for (size_t i = ligneIndex; i < taille; i++)
		{
			_jeu[finIndex].push_back(_jeu[baseIndex][i]);
		}

		// Supprimer les cartes de la colonne de base
		for (size_t i = ligneIndex; i < taille; i++)
		{
			_jeu[baseIndex].pop_back();
		}

		// Rendre visible la dernière carte de la colonne de base
		if (!std::empty(_jeu[baseIndex]))
		{
			_jeu[baseIndex][_jeu[baseIndex].size() - 1].setVisible();
		}
	}
}

void CPLateau::pioche_vers_jeu(int fin)
{
	int finIndex = fin - 1;
	bool indiceValide = (finIndex < 7 && fin > 0);

	if (!indiceValide)
		return;

	CCarte& cartePioche = _pioche[_pioche.size() - 1];
	bool colonneVide = std::empty(_jeu[finIndex]);

	// Placer un roi sur une colonne vide
	bool peutPlacerRoi = (cartePioche.getValeur() == 13 && colonneVide);

	if (peutPlacerRoi)
	{
		_jeu[finIndex].push_back(cartePioche);
		_pioche.pop_back();
		return;
	}

	//  Placer une carte sur une colonne non vide
	if (!colonneVide)
	{
		CCarte& carteFin = _jeu[finIndex][_jeu[finIndex].size() - 1];
		bool valeurCorrecte = (cartePioche.getValeur() + 1 == carteFin.getValeur());
		bool couleurAlternee = (cartePioche.getCouleur() % 2 != carteFin.getCouleur() % 2);

		if (valeurCorrecte && couleurAlternee)
		{
			_jeu[finIndex].push_back(cartePioche);
			_pioche.pop_back();
		}
	}
}


bool CPLateau::verif_victoire() const
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_deck[i].size() != 14)
			return false;
	}
	return true;
}


std::ostream& operator<<(std::ostream& out, CPLateau& plateau)
{
	//Reset la console pour eviter l'empilement des affichages
#ifdef _WIN32
	system("cls");
#endif
	out << plateau.Affiche() ;
	return out;
}


