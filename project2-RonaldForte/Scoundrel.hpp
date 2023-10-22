#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP
#include <iostream>
#include <string>
#include <cctype>
#include "Character.hpp"

/*an enum Dagger with the values {WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE}*/
enum Dagger
{
    WOOD,
    BRONZE,
    IRON,
    STEEL,
    MITHRIL,
    ADAMANT,
    RUNE
};
class Scoundrel : public Character
{
private:
    Dagger dagger_;
    std::string faction_;
    bool has_disguise_;

public:
    Scoundrel();
    Scoundrel(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, std::string dagger = "WOOD", std::string faction = "NONE", bool disguise = false);
    void setDagger(const std::string& dagger);
    std::string getDagger() const;
    bool setFaction(const std::string& faction);
    std::string getFaction() const;
    void setDisguise(const bool& disguise);
    bool hasDisguise() const;
};
#endif