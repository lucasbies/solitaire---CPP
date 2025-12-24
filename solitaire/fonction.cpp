#include "fonction.h"
#include <iostream>


int carte_hasard(int max)
{
    int res;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>dis(0, max);
    res = dis(gen);//retient un nombre au hasard dans res
    return res;
}

std::array<std::vector<CCarte>, 7> remplissage_plateau(std::vector<CCarte>& pioche)
{
    std::array<std::vector<CCarte>, 7> plateau;
    for (size_t i = 0; i < 7; i++) {
        for (size_t j = 0; j < i + 1; j++) 
        {
            plateau[i].push_back(pioche[pioche.size()-1]);
            pioche.pop_back();
            if (i == j)
                plateau[i][j].setVisible();
        }
    }
    return plateau;
}

std::vector<CCarte> creation_pioche()
{
    CCarte P1(1, 1);
    CCarte P2(2, 1);
    CCarte P3(3, 1);
    CCarte P4(4, 1);
    CCarte P5(5, 1);
    CCarte P6(6, 1);
    CCarte P7(7, 1);
    CCarte P8(8, 1);
    CCarte P9(9, 1);
    CCarte P10(10, 1);
    CCarte P11(11, 1);
    CCarte P12(12, 1);
    CCarte P13(13, 1);
    CCarte CO1(1, 2);
    CCarte CO2(2, 2);
    CCarte CO3(3, 2);
    CCarte CO4(4, 2);
    CCarte CO5(5, 2);
    CCarte CO6(6, 2);
    CCarte CO7(7, 2);
    CCarte CO8(8, 2);
    CCarte CO9(9, 2);
    CCarte CO10(10, 2);
    CCarte CO11(11, 2);
    CCarte CO12(12, 2);
    CCarte CO13(13, 2);
    CCarte T1(1, 3);
    CCarte T2(2, 3);
    CCarte T3(3, 3);
    CCarte T4(4, 3);
    CCarte T5(5, 3);
    CCarte T6(6, 3);
    CCarte T7(7, 3);
    CCarte T8(8, 3);
    CCarte T9(9, 3);
    CCarte T10(10, 3);
    CCarte T11(11, 3);
    CCarte T12(12, 3);
    CCarte T13(13, 3);
    CCarte CA1(1, 4);
    CCarte CA2(2, 4);
    CCarte CA3(3, 4);
    CCarte CA4(4, 4);
    CCarte CA5(5, 4);
    CCarte CA6(6, 4);
    CCarte CA7(7, 4);
    CCarte CA8(8, 4);
    CCarte CA9(9, 4);
    CCarte CA10(10, 4);
    CCarte CA11(11, 4);
    CCarte CA12(12, 4);
    CCarte CA13(13, 4);
    //crer un tableau qui est la pioche qui contient toutes les cartes
    std::vector<CCarte> pioche = { P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13,
                                   CO1, CO2, CO3, CO4, CO5, CO6, CO7, CO8, CO9, CO10, CO11, CO12, CO13,
                                   T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
                                   CA1, CA2, CA3, CA4, CA5, CA6, CA7, CA8, CA9, CA10, CA11, CA12, CA13 };
    melange_pioche(pioche);
    return pioche;
}

void melange_pioche(std::vector<CCarte>& pioche)
{
    for (size_t i = 0; i < pioche.size(); i++)
    {
        std::swap(pioche[i], pioche[carte_hasard(pioche.size()-1)]);
    }
}


