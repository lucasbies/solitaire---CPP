#pragma once
#include <sstream>

class CCarte {
	int _valeur;
	int _couleur;
	bool _visible;

public: 
	CCarte(int _valeur, int _couleur,bool _visible=false);
	int getValeur() const;
	int getCouleur() const;
	bool getVisible() const;
	void setVisible();
	std::string affiche_carte()const;


};
