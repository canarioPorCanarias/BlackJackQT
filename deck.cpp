#include "deck.h"



deck::deck()
{
    srand(time(NULL));
}

std::vector<std::vector<int>> vect = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}};
std::string deck::card()
{
    srand(time(NULL));
    int typeofcard = rand() % 4 + 1;
    int numofcard = rand() % 13 + 1;
    std::string tipo;
    std::string total;
    switch (typeofcard)
    {
    case 1:
        tipo = "C";
        break;
    case 2:
        tipo = "D";
        break;
    case 3:
        tipo = "H";
        break;
    case 4:
        tipo = "S";
        break;
    }
    //std::cout << vect[typeofcard][numofcard];
    if(numofcard>=11){
        std::string grande;
        switch (numofcard) {
        case 11:
            grande="J";
            break;
        case 12:
            grande="Q";
            break;
        case 13:
            grande="K";
            break;
        }

        return grande + tipo + ".png";
    }else{
    return std::to_string(numofcard) + tipo + ".png";
    }

};
