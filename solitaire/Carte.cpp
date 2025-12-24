#include "Carte.h"

CCarte::CCarte(int valeur, int couleur, bool visible)
{
	_valeur = valeur;
	_couleur = couleur;
	_visible = visible;
}

int CCarte::getValeur() const
{
	return _valeur;
}

int CCarte::getCouleur() const
{
	return _couleur;
}

bool CCarte::getVisible() const
{
	return _visible;
}

void CCarte::setVisible()
{
	_visible = true;
}

std::string CCarte::affiche_carte() const
{
	std::string res = "";
	if (getVisible())
	{
		switch (getValeur())
		{
		case 13:
			res += " K";
			break;
		case 12:
			res += " Q";
			break;
		case 11:
			res += " J";
			break;
		case 10:
			res += "10";
			break;
		case 0:
			res += "  ";
			break;
		default:
			res += " " + std::to_string(getValeur());
		}
		switch (getCouleur())
		{
		case 1:
			res += "\x1B[1;30m♠️\x1B[0m";
			break;
		case 2:
			res += "\x1B[1;31m♥️\x1B[0m";
			break;
		case 3:
			res += "\x1B[1;30m♣️\x1B[0m";
			break;
		case 4:
			res += "\x1B[1;31m♦️\x1B[0m";
			break;
		}
	}
	else
		res = "  ? ";

	return res;
}

