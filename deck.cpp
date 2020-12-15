#include "deck.h"
#include <chrono>
#include <thread>


deck::deck()
{
srand(time(0));
}

//std::vector<std::vector<int>> newdeck(){
//    std::vector<std::vector<int>> vect = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
//                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
//                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
//                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}};
//    return vect;
//}

std::string deck::card()
{
    std::vector<std::vector<int>> vect = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                             {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                             {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                             {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}};
    int typeofcard = rand() % 4;
    int numofcard = rand() % vect[typeofcard].size();
    vect[typeofcard].erase(vect[typeofcard].begin()+numofcard);
    numofcard+=1;
    typeofcard+=1;
//    while(numofcard!=vect[typeofcard][numofcard]){
//
//    }
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
