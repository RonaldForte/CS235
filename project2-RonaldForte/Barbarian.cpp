#include "Barbarian.hpp"

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian(){
    Character();
    main_weapon_ = "NONE";
    secondary_weapon_="NONE";
    enraged_ = false;
}

/**
    Parameterized constructor.
        @param      : The name of the character (a const string reference)
        @param      : The race of the character (a const string reference)
        @param      : The character's vitality (an integer). Default to 0
        @param      : The character's max armor level (an integer). Default to 0
        @param      : The character's level (an integer). Default to 0
        @param      : A flag indicating whether the character is an enemy. Default to false
        @param      : The character's main weapon (a const string reference). 
                    String inputs can be in lowercase, but must be converted to uppercase 
                    when setting the variable. Only alphabetical characters are allowed.
                    Default to "NONE"
        @param      : The character's offhand weapon (a const string reference). 
                    String inputs can be in lowercase, but must be converted to uppercase 
                    when setting the variable. Only alphabetical characters are allowed.
                    Default to "NONE"
        @param      : A flag indicating whether the character is enraged. Default to false
        @post       : The private members are set to the values of the corresponding parameters. 
                    : If the main and secondary weapons are not provided or invalid, the variables                    are set to "NONE".
*/
Barbarian::Barbarian(std::string name, std::string race, int vitality, int armor, int level, bool enemy, std::string main_weapon, std::string secondary_weapon, bool enraged):
Character(name, race, vitality, armor, level, enemy), main_weapon_{main_weapon}, secondary_weapon_{secondary_weapon}, enraged_{enraged}
{
    setMainWeapon(main_weapon);
    setSecondaryWeapon(secondary_weapon);
}

/**
    @param    : a reference to a string representing the Character's main weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
                If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string& main_weapon){
    std::string alpha = "";
    for (int i = 0; i < main_weapon.length(); i++) {
        if (isalpha(main_weapon[i])){
        alpha += char(toupper(main_weapon[i]));
        }
    }

    if (alpha != "") {
        main_weapon_ = alpha;
        return true;
    }
return false;

}

/**
    @param    : a reference to a string representing the Character's secondary weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
              : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon) {
    std::string alpha2 = "";
    for (int i = 0; i < secondary_weapon.length(); i++) {
        if (isalpha(secondary_weapon[i])) {
            alpha2 += char(toupper(secondary_weapon[i]));
        }
    }

    if (alpha2 != "") {
        secondary_weapon_ = alpha2;
        return true;
    } else {
        return false;
    }
}

/**
  @post   : sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage(){
    if(enraged_ == false){
        enraged_ = true;
    }
    else if (enraged_ == true){
        enraged_ = false;
    }
}

/**
  @param      : a reference to a bool
  @post       : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool& enraged){
    enraged_ = enraged;
}

/**
    @return   : a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const{
    return main_weapon_;
}

/**
   @return    : a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon()const{
    return secondary_weapon_;
}

/**
  @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage()const{
    return enraged_;
}
