#include "Character.hpp"

Character::Character(){
    name_ = "NAMELESS";
    race_ = NONE;
    vitality_ = 0;
    armor_ = 0;
    level_ = 0;
    enemy_ = false;
}

Character::Character(std::string name, std::string race, int vitality, int armor, int level, bool enemy){
    setName(name);
    setRace(race);

    if(armor >= 0){
       armor_ = armor;
    }else{
       armor_ = 0;
    }

    if(vitality >= 0){
       vitality_ = vitality;
    }else{
       vitality_ = 0;
    }
   
    if(level >= 0){
       level_ = level;
    }else{
       level_ = 0;
    }

    enemy_ = enemy;
}

void Character::setName(const std::string& name){
    std::string refrencelol = "";
    for(int i = 0; i < name.length(); i++){
        if (isalpha(name[i])){
            refrencelol = refrencelol + char(toupper(name[i]));
        }
    }
    if(refrencelol == ""){
        name_ = "NAMELESS";
    }else{
        name_ = refrencelol;
    }
}

void Character::setRace(const std::string& race){
    if (race == "HUMAN"){
        race_ = HUMAN;
    } else if (race == "ELF"){
        race_ = ELF;
    } else if (race == "DWARF"){
        race_ = DWARF;
    } else if (race == "LIZARD"){
        race_ = LIZARD;
    } else if (race == "UNDEAD"){
        race_ = UNDEAD;
    } else{
        race_ = NONE;
    }
}

void Character::setVitality(const int& vitality){
    if (vitality >= 0){
        vitality_ = vitality;
    }
}

void Character::setArmor(const int& armor){
    if (armor >= 0){
            armor_ = armor;
    }
}

void Character::setLevel(const int& level){
    if (level >= 0) {
        level_ = level;
    }
}

void Character::setEnemy(){
    enemy_ = true;
}

std::string Character::getName()const{
    return name_;
}

std::string Character::getRace()const{
    if (race_ == HUMAN){
        return "HUMAN";
    } else if (race_ == ELF){
        return "ELF";
    } else if (race_ == DWARF){
        return "DWARF";
    } else if (race_ == LIZARD){
        return "LIZARD";
    } else if (race_ == UNDEAD){
        return "UNDEAD"; 
    }
    return "NONE";
}

int Character::getVitality()const{
    return vitality_;
}
int Character::getArmor()const{
    return armor_;
}
int Character::getLevel()const{
    return level_;
}
bool Character::isEnemy()const{
    return enemy_;
}