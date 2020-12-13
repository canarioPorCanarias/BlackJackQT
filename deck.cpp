#include "deck.h"



deck::deck()
{
    srand(time(NULL));
}


std::string deck::card(){
    int num = rand() % 13 + 1;
    int form=rand()%4+1;
    std::string type;
    if(num <= 10){
    switch (form) {
    case 1:
        type="C";
        break;
    case 2:
        type="D";
        break;
    case 3:
        type="H";
        break;
    case 4:
       type="S";
        break;
    }
    std::string final =  std::to_string(num) + type;
    }else{
        int form=rand()%3+1;
        switch (form) {
        case 1:
            type="J";
            break;
        case 2:
            type="Q";
            break;
        case 3:
            type="K";
            break;
        }
    }

    return "";
}
