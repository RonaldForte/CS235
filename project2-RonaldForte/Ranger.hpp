#ifndef RANGER_HPP_
#define RANGER_HPP_
#include "Character.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

struct Arrows
{
    std::string type_;
    int quantity_;
};
// Valid Arrows are [WOOD, FIRE, WATER, POISON, BLOOD]
// Valid Affinities are [FIRE, WATER, POISON, BLOOD]
class Ranger : public Character
{
private:
    std::vector<Arrows> arrows_;
    std::vector<std::string> affinities_;
    bool has_companion_;

public:
    Ranger();
    Ranger(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::vector<Arrows>& arrow = {}, const std::vector<std::string>& affinity = {}, bool companion = false); 
    void setCompanion(const bool& companion);
    std::vector<Arrows> getArrows() const;
    std::vector<std::string> getAffinities() const;
    bool getCompanion() const;


    bool addArrows(const std::string& arrow_type, int quantity);
    bool fireArrow(const std::string& arrows);
    bool addAffinity(const std::string& affinity);
};
#endif