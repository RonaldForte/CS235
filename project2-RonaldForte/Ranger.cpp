#include "Ranger.hpp"
#include <cctype>
#include <iostream>
#include <vector>

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/
Ranger::Ranger(){
    Character();
    arrows_ = {};
    affinities_ = {};
    has_companion_ = false;
}

/**
   Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false
    @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                    Lowercase valid arrow types are retained but converted to uppercase.
                    Invalid arrows are those with non-positive quantities or invalid types.
                    If the vector contains invalid arrows, those arrows are discarded. 
                    Default to empty vector
    @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                    String inputs can be in lowercase, but must be converted to uppercase.
                    If the vector contains invalid affinities, those affinities are discarded.
                    Default to empty vector
    @param      : A flag indicating whether the character is able to recruit an animal companion. 
                    Default to false
    @post       : The private members are set to the values of the corresponding parameters
*/
Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::vector<Arrows>& arrow, const std::vector<std::string>& affinity, bool companion): 
Character(name, race, vitality, armor, level), has_companion_{companion}
{
    for (int i = 0; i < arrow.size(); i++) { 
        addArrows(arrow[i].type_, arrow[i].quantity_);
    }

    for (int i = 0; i < affinity.size(); i++) {
        addAffinity(affinity[i]);
    }
}

/**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
**/
void Ranger::setCompanion(const bool& has_companion){
    has_companion_ = has_companion;
}

/**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
**/
bool Ranger::addArrows(const std::string& arrow_type, int quantity) {  // 
    std::string new_arrow = "";  // empty string
    for (int i = 0; i < arrow_type.length(); i++) {  // loops through the string
        if (!isalpha(arrow_type[i])) {  // if it's not in the alphabet
            return false;  // return false
        } else {
            new_arrow += char(toupper(arrow_type[i]));  // if it is in the alphabet, convert it to uppercase
        }
    }

    if ((new_arrow != "WOOD" && new_arrow != "FIRE" && new_arrow != "WATER" && new_arrow != "POISON" && new_arrow != "BLOOD") || quantity <= 0) {  // if the user's input is not equal to either "WOOD", "FIRE", "WATER", "POISON", or "BLOOD" or if the quantity is less than or equal to 0 
        return false;  // return false
    }

    for (int i = 0; i < arrows_.size(); i ++ ) {  // loops through the arrows_ vector
        if (new_arrow == arrows_[i].type_) {  // if the user's input is equal to the type of the arrow
            arrows_[i].quantity_ += quantity;  // update the quantity to the user's input
            return true;  // return true
        }
    }

    Arrows ar1;
    ar1.quantity_ = quantity;
    ar1.type_ = new_arrow;
    arrows_.push_back(ar1);
    return true; 
}

/**
    @param    : a reference to string representing the arrow type
    @post     : If the character has the listed arrow AND enough arrows to fire one, 
                the quantity of remaining arrows in the vector is updated.
                Lowercase valid arrow types are accepted but converted to uppercase.
                If firing the last arrow, simply decrement the quantity to 0.
    @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
**/
bool Ranger::fireArrow(const std::string& arrow){
    std::string empty_arrow = "";
    for (int i = 0; i < arrow.length(); i++) {
        if(isalpha(arrow[i])){
            empty_arrow += char(toupper(arrow[i]));
        }
    }

    for(int i = 0; i < arrows_.size(); i++){
        if(arrows_[i].type_ == empty_arrow && arrows_[i].quantity_ > 0){
            arrows_[i].quantity_--;
            return true;
        }
    }
    return false;
}

/**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
              String inputs can be in lowercase, but must be converted to uppercase when 
              setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
**/
bool Ranger::addAffinity(const std::string& affinity) {
    std::string new_affinity = "";  // empty string
    for (int i = 0; i < affinity.length(); i++) {  // loops through the string 
        if (!isalpha(affinity[i])) {  // if it's not in the alphabet
            return false;  // return false
        } else {
            new_affinity += char(toupper(affinity[i]));  // if it is in the alphabet, convert it to uppercase
        }
    }
    
    if (new_affinity == "FIRE" || new_affinity == "WATER" || new_affinity == "POISON" || new_affinity == "BLOOD") {  // checks if the user's input is equal to either "FIRE", "WATER", "POISON" or "BLOOD"
        for (int i = 0; i < affinities_.size(); i++) { // loops through the entire vector
            if (affinities_[i] == new_affinity) { // checks if the first element in the vector is equal to the parameter, if it is then exit the for loop
                return false;
            }
        } 
        affinities_.push_back(new_affinity); // after looping through the entire vector and there is no existing affinity, add it to the vector
        return true;
    } else {
        return false;
    }
}

/**
  @return     : a vector of the Character's arrows
**/
std::vector<Arrows> Ranger::getArrows() const {
    return arrows_;
}

/**
  @return     : a vector of the Character's affinities
**/
std::vector <std::string> Ranger::getAffinities() const {
    return affinities_;
}

/**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
**/
bool Ranger::getCompanion() const {
    return has_companion_;
}
