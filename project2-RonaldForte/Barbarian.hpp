#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include <string>
#include <cctype>
#include "Character.hpp"

class Barbarian : public Character
{
private:
    std::string main_weapon_;
    std::string secondary_weapon_;
    bool enraged_;

public:
    Barbarian();
    Barbarian(std::string name, std::string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, std::string main_weapon = "NONE", std::string secondary_weapon = "NONE", bool enraged = false);
    bool setMainWeapon(const std::string& main_weapon);
    std::string getMainWeapon() const;
    bool setSecondaryWeapon(const std::string& secondary_weapon);
    std::string getSecondaryWeapon() const;
    void setEnrage(const bool& enraged);
    bool getEnrage() const;
    void toggleEnrage();
};
#endif 