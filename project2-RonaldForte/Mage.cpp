#include "Mage.hpp"

/**
  Default constructor.
  Default-initializes all private members. 
  Default character name: "NAMELESS". Booleans are default-initialized to False. 
  Default school of magic and weapon: "NONE". 
*/
Mage::Mage(){
    Character();
    school_of_magic_= "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

/**
  Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's school of magic (a const string reference). Valid schools: 
                    [ELEMENTAL, NECROMANCY, ILLUSION]. 
                    String inputs can be in lowercase, but must be converted to 
                    uppercase when setting the variable. Default to "NONE".
    @param      : The character's choice of weapon (a const string reference). 
                    Valid weapons: [WAND, STAFF]
                    String inputs can be in lowercase, but must be converted to 
                    uppercase when setting the variable. Default to "NONE".
    @param      : A flag indicating whether the character is able to summon an 
                    incarnate. Default to false.
    @post       : The private members are set to the values of the corresponding 
                    parameters.
                    REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                    variables should be set to "NONE". 
*/

Mage::Mage(std::string name, std::string race, int vitality, int armor, int level, bool enemy, std::string school_of_magic, std::string weapon, bool can_summon_incarnate):
    Character(name, race, vitality, armor, level, enemy), weapon_{weapon}, can_summon_incarnate_{can_summon_incarnate}
{
    if(!setSchool(school_of_magic)){
        school_of_magic_ = "NONE";
    }
    if(!setCastingWeapon(weapon)){
        weapon_ = "NONE";
    }
}

/**
 * 
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setSchool(const std::string& school_of_magic){
    std::string alpha = "";
    for(int i = 0; i < school_of_magic.length(); i++){
        if(isalpha(school_of_magic[i])){
            alpha += char(toupper(school_of_magic[i]));
        }
    }
    if(alpha == "ELEMENTAL" ||alpha ==  "NECROMANCY" ||alpha ==  "ILLUSION"){
        school_of_magic_ = alpha;
        return true;
    }
    return false;
}

/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string& weapon){
    std::string alphawep = "";
    for(int i = 0; i < weapon.length(); i++){
        if(isalpha(weapon[i])){
            alphawep += char(toupper(weapon[i]));
        }
    }
    if(alphawep == "STAFF" || alphawep ==  "WAND"){
        weapon_ = alphawep;
        return true;
    }
    return false;
}

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
void Mage::setIncarnateSummon(const bool& can_summon_incarnate){
    can_summon_incarnate_ = can_summon_incarnate;
}

/**
  @return  : the string indicating the character's school of magic
**/
std::string Mage::getSchool() const{
    return school_of_magic_;
}

/**
  @return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const{
    return weapon_;
}

/**
  @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const{
    return can_summon_incarnate_;
}