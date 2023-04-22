#include "bets.h"

bets::bets()
{
}

void bets::setBet(int value)
{
   int newbet = value;
   emit updateBet(newbet);
}
