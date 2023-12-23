/*
Ronald Forte
Ronald.Fortejr63@myhunter.cuny.edu
10/11/23
PROJECT 4
This is the Tavern implementation for term project
Tavern.cpp declares the Tavern class along with its private and public members
*/
#include "Tavern.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/* Parameterized Constructor */
/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
1. Name: An uppercase string
2. Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
3. Subclass: An uppercase string [BARBARIAN, MAGE, SCOUNDREL, RANGER]
4. Level/Vitality/Armor: A positive integer
5. Enemy: 0 (False) or 1 (True)
6. Main: Uppercase string or strings representing the main weapon (Barbarian and Mage), Dagger type (Scoundrel), or arrows (Ranger). A ranger's arrows are of the form [TYPE] [QUANTITY];[TYPE] [QUANTITY], where each arrow type is separated by a semicolon, and the type and its quantity are separated with a space.
7. Offhand: An uppercase string that is only applicable to Barbarians, and may be NONE if the Barbarian does not have an offhand weapon, or if the character is of a different subclass.
8. School/Faction: Uppercase strings that represent a Mage's school of magic: [ELEMENTAL, NECROMANCY, ILLUSION] or a Scoundrel's faction: [CUTPURSE, SHADOWBLADE, SILVERTONGUE], and NONE where not applicable
9. Summoning: 0 (False) or 1 (True), only applicable to Mages (summoning an Incarnate) and Rangers (Having an Animal Companion)
10. Affinity: Only applicable to Rangers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Ranger with no affinities, or characters of other subclasses.
11. Disguise: 0 (False) or 1 (True), only applicable to Scoundrels, representing if they have a disguise.
12. Enraged: 0 (False) or 1 (True), only applicable to Barbarians, representing if they are enraged.
    @post: Each line of the input file corresponds to a Character subclass and dynamically allocates Character derived objects, adding them to the Tavern.
*/
Tavern::Tavern(const std::string& file_name) {
  std::ifstream read(file_name);
  if (!read.is_open()) {
    std::cout << "ERROR: File Open" << "\n";
  }

  std::string str;
  std::getline(read, str); //Holds the first line we want to ignore (just column names)

  std::string name, race, subclass, main, offhand, school_faction, affinity; //all variables where we're holding the values from csv
  int level, vitality, armor;
  bool enemy, summoning, disguise, enraged;
  Character* player = nullptr; //we need a character pointer :)

  std::string line = "";
  while (std::getline(read, line)) { //while getting each line after line
    std::istringstream inputString(line); 

    getline(inputString, name, ','); //stores in name
    getline(inputString, race, ',');  //stores in race
    getline(inputString, subclass, ','); //stores in subclasses

    std::string temp2; //for the strings to convert them into integers/bools

    getline(inputString, temp2, ','); //stores in level
    level = stoi(temp2);

    getline(inputString, temp2, ','); //stores in vitality
    vitality = stoi(temp2);

    getline(inputString, temp2, ','); //stores in armor
    armor = stoi(temp2);

    getline(inputString, temp2, ','); //stores in if theyre an enemy or not
    enemy = stoi(temp2);

    getline(inputString, main, ',');  //stores in the main weapon
    std::istringstream weap(main);
    
    std::vector <Arrows> arow; //temp empty vector (useful to print out the arrows :))
    while (std::getline(weap, temp2, ';')) {
      std::istringstream new_var(temp2);
      std::string new_arrow_type;
      int new_arrow_quantity;
      
      new_var >> new_arrow_type >> new_arrow_quantity;
      Arrows new_arrow;
      new_arrow.type_ = new_arrow_type;
      new_arrow.quantity_ = new_arrow_quantity;

      arow.push_back(new_arrow);
    }
  

    getline(inputString, offhand, ','); //stores in secondary weapon

    getline(inputString, school_faction, ',');  //stores in school of magic / faction
    
    getline(inputString, temp2, ','); //stores in if they can summon incarnate
    summoning = stoi(temp2);

    getline(inputString, affinity, ','); //stores in affinity
    std::string taffinitz = "";

    std::vector <std::string> tvect; //temp vect helps print out affinities
    std::string affini = "";
    if (subclass == "RANGER") {
      std::istringstream affini_parse(affinity);
      while(getline(affini_parse, affini, ';')) { 
        tvect.push_back(affini);  
      }
    }

    // disguise
    getline(inputString, temp2, ','); //stores in disguise
    disguise = stoi(temp2);

    // enraged
    getline(inputString, temp2, ','); //stores in enraged
    enraged = stoi(temp2);
    
    if (subclass == "MAGE") {
    player = new Mage(name, race, vitality, armor, level, enemy, school_faction, main, summoning);
  } else if (subclass == "BARBARIAN") {
    player = new Barbarian(name, race, vitality, armor, level, enemy, main, offhand, enraged);
  } else if (subclass == "SCOUNDREL") {
    player = new Scoundrel(name, race, vitality, armor, level, enemy, main, school_faction, disguise);
  } else if (subclass == "RANGER") {
    player = new Ranger(name, race, vitality, armor, level, enemy, arow, tvect, summoning);
  }
  enterTavern(player);
}

}

/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}



/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}

/**
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters() {
  for (int i = 0; i < getCurrentSize(); i++) {
    items_[i] -> display();
  }
}

/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race (only exact matches to the input string), displays each character's information

*/
void Tavern::displayRace(const std::string &race) {
  for (int i = 0; i < getCurrentSize(); i++) {
    if (items_[i] -> getRace() == race) {
      items_[i] -> display();
    }
  }

}

/**
    @post: Every character in the tavern eats a tainted stew.
*/
void Tavern::taintedStew() {
  for (int i = 0; i < getCurrentSize(); i++) {
    items_[i] -> eatTaintedStew();
  }
}
