#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <iostream>


enum race {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};
//Every Character has a Name, Race, Health, Armor, Level, and a boolean if the character is an enemy.
class Character{
    private:
        std::string name_;
        race race_;
        int vitality_;
        int armor_;
        int level_;
        bool enemy_;
    public:
        /*default constructor:
        Default constructor.
        Default-initializes all private members. 
        Default character name: "NAMELESS". 
        Booleans are default-initialized to False. 
        Default enum value: NONE. 
        Default Vitality, Max Armor, and Level: 0.
        */
        Character();

        /*param constructor:
        Parameterized constructor.
            @param      : The name of the character (a string in UPPERCASE)
            @param      : The race of the character (a string)
            @param      : The character's vitality (a non-negative integer) , with default  
                            value 0
            @param      : The character's max armor level (a non-negative integer), with 
                            default value 0
            @param      : The character's level (non-negative integer), with default value 0
            @param      : A flag indicating whether the character is an enemy, with default 
                            value false
            @post       : The private members are set to the values of the corresponding 
                            parameters.
        */

        Character(std::string name, std::string Race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);
        //setters:
        /**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
        */
        void setName(const std::string& name);

        /**
            @param  : the race of the Character (a string)
            @post   : sets the Character's race to the value of the parameter.
            If the given race was invalid, set race_ to NONE.
        */
        void setRace(const std::string& race);

        /**
            @param  : an integer vitality
            @pre    : vitality >= 0 : Characters cannot have negative health
            @post   : sets the vitality private member to the value of the parameter
                    if vitality is negative, do nothing.
        */
        void setVitality(const int& vitality);

        /**
            @param  : an integer armor level
            @pre    : armor >= 0 : Characters cannot have negative armor
            @post   : sets the armor private member to the value of the parameter
                    if armor is negative, do nothing.
        */
        void setArmor(const int& armor);

        /**
            @param  : an integer level
            @pre    : level >= 0 : Characters cannot have a negative
            @post   : sets the level private member to the value of the parameter
                    if level is negative, do nothing.
        */
        void setLevel(const int& level);

        /**
            @post   : sets the enemy flag to true
        */
        void setEnemy();   

        //getters:
        /**
            @return : the name of the Character
        */
        std::string getName()const;

        /**
            @return : the race of the Character (a string)
        */
        std::string getRace()const;

        /**
            @return : the value stored in vitality_
        */
        int getVitality()const;

        /**
            @return : the value stored in armor_
        */
        int getArmor()const;

        /**
            @return : the value stored in level_
        */
        int getLevel()const;

        /**
            @return true if the character is an enemy, false otherwise

        Note: this is an accessor function and must follow the same convention as all accessor  
        functions even if it is not called getEnemy
        */
        bool isEnemy()const;


};
#endif
