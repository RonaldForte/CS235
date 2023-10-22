// Ronald A Forte Jr.
// Ronald.ForteJr63@myhunter.cuny.edu
// Due: 10/6/2023
// PROJECT 3
// This is the Tavern implementation for term project
#include "Tavern.hpp"


/**
    Default constructor.
    Default-initializes all private members. 
*/
Tavern::Tavern():level_sum_{0}, enemy_count_{0} 
{}

/**
@param:   A const reference to a Character entering the Tavern
@return:  returns true if a Character was successfully added to the tavern (i.e. items_),
false otherwise
@post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(const Character& Ronald){
    if (add(Ronald)) {
        level_sum_ += Ronald.getLevel();
        if (Ronald.isEnemy()) {
            enemy_count_ ++;
        }
        return true;
    }
    return false;
}

/** @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),
    false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(const Character& Ronald){
    if (remove(Ronald)) {
        level_sum_ -= Ronald.getLevel();
        if (Ronald.isEnemy()) {
            enemy_count_ --;
        }
        return true;
    }
    return false;
}

/** 
    @return:  The integer level count of all the characters currently in the Tavern
**/
int Tavern::getLevelSum()const{
    return level_sum_;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
**/
int Tavern::calculateAvgLevel() const{
    double level_sum_dec = level_sum_;
    return std::round(level_sum_dec/item_count_);

}

/** 
    @return:  The integer enemy count of the Tavern
**/
int Tavern::getEnemyCount()const{
    return enemy_count_;
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
**/
double Tavern::calculateEnemyPercentage()const{
    double enemy_count_dec = enemy_count_;
    double enemy_percent = std::round((enemy_count_dec/item_count_)*10000)/100.0;
    return enemy_percent;
}

/**
    @param:   A const reference to a string representing a character Race with value in 
            ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
            If the argument string does not match one of the expected race values, 
            the tally is zero. NOTE: no pre-processing of the input string necessary, only uppercase input will match.
**/
int Tavern::tallyRace(const std::string& race)const{
    if(race != "NONE" && race != "HUMAN" && race != "ELF" && race != "DWARF" && race != "LIZARD" && race != "UNDEAD"){
        return 0;
    }
    int index = 0;
    std::string temp_race;
    int none_tal = 0;
    int human_tal = 0;
    int elf_tal = 0;
    int dwarf_tal = 0;
    int lizard_tal = 0;
    int undead_tal = 0;

    while(index < item_count_){
        temp_race = items_[index].getRace();
        if(temp_race == "NONE") {       
            none_tal++;
        }
        else if(temp_race == "HUMAN") {
            human_tal++;
        }
        else if(temp_race == "ELF") {
            elf_tal++;
        }
        else if(temp_race == "DWARF") {
            dwarf_tal++;
        }
        else if(temp_race == "LIZARD") {
            lizard_tal++;
        }
        else if(temp_race == "UNDEAD") {
            undead_tal++;
        }
        index++;
    }

    if(race == "NONE"){
        return none_tal;
    }
    else if(race == "HUMAN"){
        return human_tal;
    }
    else if(race == "ELF"){
        return elf_tal;
    }
    else if(race == "DWARF"){
        return dwarf_tal;
    }
    else if(race == "LIZARD"){
        return lizard_tal;
    }
    else if(race == "UNDEAD"){
        return undead_tal;
    }

    return 0;

}

/**
@post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n
            \nThe average level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy percentage should be rounded to 2 decimal places.
            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0
            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport() const {

    std::cout << "Humans: " << tallyRace("HUMAN") << "\n" << "Elves: "\
    << tallyRace("ELF") << "\n" << "Dwarves: " << tallyRace("DWARF") << "\n"\
    << "Lizards: " << tallyRace("LIZARD") << "\n" << "Undead: "\
    << tallyRace("UNDEAD") << "\n\n" << "The average level is: "\
    << calculateAvgLevel() << "\n" << calculateEnemyPercentage() << "% are enemies.\n\n";

}