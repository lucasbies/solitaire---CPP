#include "Game.h"

CGame::CGame()
{
    //creer tout ce qui est utile puis créer le plateau 
    std::vector<CCarte> pioche = creation_pioche();
    std::array < std::vector<CCarte>, 7> plateau = remplissage_plateau(pioche);
    _plateau = CPLateau(pioche, plateau);
}

void CGame::jouer()
{
    // Boucle principale du jeu

    //verif si on veut rester dans le jeu
    bool verif = true;
    char demande;
    while (verif)
    {
        std::cout << _plateau;
        if (_plateau.verif_victoire())
        {
            break;
        }

        std::cout << "\n Que souhaiter vous faire : \n"
            " P : Découvrir la pioche \n"
            " M : Monter une carte sur les piles\n"
            " D : Déplacer une carte du jeu vers le jeu\n"
            " E : Déplacer une carte de la pioche sur le jeu\n"
            " Q : quitter le jeu \n";
        std::cin >> demande;
        switch (demande)
        {
        case 'P':
        case 'p':
            _plateau.decouverte_pioche();
            break;
        case 'M':
        case 'm':
        {
            int cols;
            std::cout << "Quel est la colonne de la carte que vous vouler monter ?";
            std::cin >> cols;
            _plateau.Monter_carte(cols);
            break;
        }
        case 'd':
        case 'D':
        {
            int base, fin, ligne;
            std::cout << "Donne la colone de la carte à déplacer : ";
            std::cin >> base;
            std::cout << "Donne la ligne de la carte à déplacer : ";
            std::cin >> ligne;
            std::cout << "Donne la colone ou la carte doit être déplacé déplacer : ";
            std::cin >> fin;
            _plateau.deplacer_carte(base, ligne, fin);
            break;
        }
        case 'E':
        case 'e':
        {
            int fin;
            std::cout << "Vers quel colonne souhaiter vous mettre la carte qui est dans la pioche : ";
            std::cin >> fin;
            _plateau.pioche_vers_jeu(fin);
            break;
        }
        case 'q':
        case 'Q':
            verif = false;
        }

        
    }
}
