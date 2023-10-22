#include <cmath>
#include <iostream>
#include "Tavern.hpp"
#include "Character.hpp"

int main() {
    Character boba;
    boba.setName("Eva");
    boba.setRace("ELF");
    boba.setLevel(31);

    Character angryTA;
    angryTA.setName("Anonym");
    angryTA.setRace("DWARF");
    angryTA.setEnemy();
    angryTA.setLevel(10000);

    Tavern huntercollege;
    huntercollege.enterTavern(boba);
    huntercollege.enterTavern(angryTA);
    huntercollege.tavernReport();

    Character twin;
    twin.setName("Kevin");
    twin.setRace("UNDEAD");
    twin.setLevel(32);
    huntercollege.enterTavern(twin);
    huntercollege.tavernReport();


    Character bonk;
    bonk.setName("Kobin");
    bonk.setRace("DWARF");
    bonk.setLevel(13);
    bonk.setEnemy();
    huntercollege.enterTavern(bonk);
    huntercollege.tavernReport();


    Character mwin;
    mwin.setName("Cable");
    mwin.setRace("HUMAN");
    mwin.setLevel(8);
    mwin.setEnemy();
    huntercollege.enterTavern(mwin);
    huntercollege.tavernReport();


    Character bleen;
    bleen.setName("Kevin");
    bleen.setRace("NONE");
    bleen.setLevel(9);
    huntercollege.enterTavern(bleen);
    huntercollege.tavernReport();

    huntercollege.exitTavern(angryTA);
    huntercollege.tavernReport();
    huntercollege.exitTavern(bleen);
    huntercollege.tavernReport();

    return 0;

}