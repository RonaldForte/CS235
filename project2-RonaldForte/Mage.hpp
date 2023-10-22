#ifndef MAGE_HPP_
#define MAGE_HPP_
#include <iostream>
#include <string>
#include <cctype>
#include "Character.hpp"

// Valid magic types {ELEMENTAL, NECROMANCY, ILLUSION}
// Valid weapons are {WAND, STAFF}

class Mage: public Character{
private:
    std::string school_of_magic_;
    std::string weapon_;
    bool can_summon_incarnate_;

public:
    Mage();
    Mage(std::string name, std::string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, std::string school_of_magic = "NONE", std::string weapon = "NONE", bool can_summon_incarnate = false);
    bool setSchool(const std::string& school_of_magic);
    std::string getSchool() const;
    bool setCastingWeapon(const std::string& weapon);
    std::string getCastingWeapon() const;
    void setIncarnateSummon(const bool& can_summon_incarnate);
    bool hasIncarnateSummon() const;
};
#endif