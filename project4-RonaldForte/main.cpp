#include <iostream>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Ranger.hpp"
#include "Scoundrel.hpp"
#include "Tavern.hpp"
using namespace std;

int main()
{
    Tavern bar("characterstest.csv");
    bar.displayCharacters();
}