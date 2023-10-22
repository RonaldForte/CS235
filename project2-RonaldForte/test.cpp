#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include <iostream>
using namespace std;

int main(){
/*2.1.1 Instantiate a default Mage
- Sets its name, race, vitality, and armor levels using the appropriate setter functions
Name: defaultMage
Race: ELF
Vitality: 5
Armor: 3
Level: 2
Enemy: TRUE
- Print out information for default Mage 
*/
    Mage default_Mage; 

    default_Mage.setName("defaultMage");
    default_Mage.setRace("ELF");
    default_Mage.setVitality(5);
    default_Mage.setArmor(3);
    default_Mage.setLevel(2);
    default_Mage.setEnemy(); 

  cout << default_Mage.getName() << " is a Level " << default_Mage.getLevel() << " " << default_Mage.getRace() << "."
        << endl << "Vitality: " << default_Mage.getVitality()
        << endl << "Armor: " << default_Mage.getArmor()
        << endl << "They are " << (default_Mage.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "School of Magic: " << default_Mage.getSchool()
        << endl << "Weapon: " << default_Mage.getCastingWeapon()
        << endl << "Summon Incarnate: " << (default_Mage.hasIncarnateSummon() ? "TRUE" : "FALSE") << endl ;

/*2.1.2 Instantiate a Mage with the parameterized constructor with the following character details:
Name: SPYNACH
Race: ELF
Vitality: 6
Armor: 4
Level: 4
Enemy: FALSE
2.1.3 Set SPYNACH's unique private member variables to the following:
School of Magic: Illusion
Weapon: Wand
Summon Incarnate: TRUE
- Print out information for SPYNACH */
    Mage my_mage("SPYNACH", "ELF", 6, 4, 4, false);

    my_mage.setSchool("Illusion");
    my_mage.setCastingWeapon("Wand");
    my_mage.setIncarnateSummon(true);


    cout << my_mage.getName() << " is a Level " << my_mage.getLevel() << " " << my_mage.getRace() << "."
        << endl << "Armor: " << my_mage.getArmor()
        << endl << "They are " << (my_mage.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "School of Magic: " << my_mage.getSchool()
        << endl << "Weapon: " << my_mage.getCastingWeapon()
        << endl << "Summon Incarnate: " << (my_mage.hasIncarnateSummon() ? "TRUE" : "FALSE") << endl;


/*2.2.1 Instantiate a default Scoundrel
- Sets its name, race, vitality, and armor levels using the appropriate setter functions
Name: defaultScoundrel
Race: HUMAN
Vitality: 6
Armor: 4
Level: 3
Enemy: TRUE
- Print out information for default Scoundrel */
    Scoundrel default_Scoundrel; 

    default_Scoundrel.setName("defaultScoundrel");
    default_Scoundrel.setRace("HUMAN");
    default_Scoundrel.setVitality(6);
    default_Scoundrel.setArmor(4);
    default_Scoundrel.setLevel(3);
    default_Scoundrel.setEnemy();

    cout << default_Scoundrel.getName() << " is a Level " << default_Scoundrel.getLevel() << " " << default_Scoundrel.getRace() << "."
        << endl << "Vitality: " << default_Scoundrel.getVitality()
        << endl << "Armor: " << default_Scoundrel.getArmor()
        << endl << "They are " << (default_Scoundrel.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "Dagger: " << default_Scoundrel.getDagger()
        << endl << "Faction: " << default_Scoundrel.getFaction()
        << endl << "Disguise: " << (default_Scoundrel.hasDisguise() ? "TRUE" : "FALSE");



    Scoundrel my_scoundrel("FLEA", "DWARF", 12, 7, 5, false); 

    my_scoundrel.setDagger("Adamant");
    my_scoundrel.setFaction("Cutpurse");
    my_scoundrel.setDisguise(true);


    cout << my_scoundrel.getName() << " is a Level " << my_scoundrel.getLevel() << " " << my_scoundrel.getRace() << "."
        << endl << "Vitality: " << my_scoundrel.getVitality()
        << endl << "Armor: " << my_scoundrel.getArmor()
        << endl << "They are " << (my_scoundrel.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "Dagger: " << my_scoundrel.getDagger()
        << endl << "Faction: " << my_scoundrel.getFaction()
        << endl << "Disguise: " << (my_scoundrel.hasDisguise() ? "TRUE" : "FALSE");


    Ranger defaultRanger;

    defaultRanger.setName("defaultRanger");
    defaultRanger.setRace("UNDEAD");
    defaultRanger.setVitality(8);
    defaultRanger.setArmor(4);
    defaultRanger.setLevel(5);
    defaultRanger.setEnemy();

    cout << defaultRanger.getName() << " is a Level " << defaultRanger.getLevel() << " " << defaultRanger.getRace() << "."
        << endl << "Vitality: " << defaultRanger.getVitality()
        << endl << "Armor: " << defaultRanger.getArmor()
        << endl << "They are " << (defaultRanger.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "Vector of arrows: ";
            
        vector<Arrows> arrows = defaultRanger.getArrows();

        for (const Arrows& arrow : arrows){
            cout << arrow.type_ << ", " << arrow.quantity_ << ", ";
        }

        cout << endl << "Affinities: ";
              
        vector<string> affinities = defaultRanger.getAffinities();
        for (const string& affinity : affinities){
            cout << affinity << ", ";
        }

        cout << endl << "Animal Companion: " << (defaultRanger.getCompanion() ? "TRUE" : "FALSE") << endl;

    Ranger my_ranger("MARROW", "UNDEAD", 9, 6, 5, true); 
    my_ranger.addArrows("Wood", 30);
    my_ranger.addArrows("Fire", 5);
    my_ranger.addArrows("Water", 5);
    my_ranger.addArrows("Poison", 5);
    my_ranger.addAffinity("Fire");
    my_ranger.addAffinity("Poison");
    my_ranger.setCompanion(true);

    cout << my_ranger.getName() << " is a Level " << my_ranger.getLevel() << " " << my_ranger.getRace() << "."
        << endl << "Vitality: " << my_ranger.getVitality()
        << endl << "Armor: " << my_ranger.getArmor()
        << endl << "They are " << (my_ranger.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "Vector of arrows: ";

        vector<Arrows> my_rangerArrows = my_ranger.getArrows();

        for (const Arrows& arrow : my_rangerArrows){
            cout << arrow.type_ << ", " << arrow.quantity_ << ", ";
        }

        cout << endl << "Affinities: ";
              
        vector<string> my_rangerAffinities = my_ranger.getAffinities();
        for (const string& affinity : my_rangerAffinities){
            cout << affinity << ", ";
        }

        cout << endl << "Animal Companion: " << (defaultRanger.getCompanion() ? "TRUE" : "FALSE");
            
    
    //2.2.2 Instantiate a Ranger with the parameterized constructor with the following character details:
        Ranger MARROW("MARROW", "UNDEAD", 9, 6, 5, true);

 
        cout << MARROW.getName() << " is a Level " << MARROW.getLevel() << " " << MARROW.getRace() << "."
            << endl << "Vitality: " << MARROW.getVitality()
            << endl << "Armor: " << MARROW.getArmor()
            << endl << "They are " << (MARROW.isEnemy() ? "an enemy" : "not an enemy")
            << endl << "Arrows: ";
        
        vector<Arrows> arrows1 = MARROW.getArrows();
        for (const Arrows& arrow : arrows1) {
            cout << arrow.type_ << ": " << arrow.quantity_ << ", ";
        }
        
        cout << endl << "Affinities: ";
        vector<string> affinities1 = MARROW.getAffinities();
        for (const string& affinity : affinities1) {
            cout << affinity << ", ";
        }
        
        std::cout << endl << "Animal Companion: " << (MARROW.getCompanion() ? "TRUE" : "FALSE") << endl;
  
    // 2.4.1 Instantiate a default Barbarian
      Barbarian defaultBarbarian;
      defaultBarbarian.setName("defaultBarbarian");
      defaultBarbarian.setRace("HUMAN");
      defaultBarbarian.setVitality(10);
      defaultBarbarian.setArmor(5);
      defaultBarbarian.setLevel(5);
      defaultBarbarian.setEnemy();

    
    cout << defaultBarbarian.getName() << " is a Level " << defaultBarbarian.getLevel() << " " << defaultBarbarian.getRace() << "."
        << endl << "Vitality: " << defaultBarbarian.getVitality()
        << endl << "Armor: " << defaultBarbarian.getArmor()
        << endl << "They are " << (defaultBarbarian.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "Main Weapon: " << defaultBarbarian.getMainWeapon()
        << endl << "Secondary Weapon: " << defaultBarbarian.getSecondaryWeapon()
        << endl << "Enraged: " << (defaultBarbarian.getEnrage() ? "TRUE" : "FALSE") << endl;
    
    // 2.4.2 Instantiate a Barbarian with the parameterized constructor
    Barbarian BONK("BONK", "HUMAN", 11, 5, 5, true);
    BONK.setMainWeapon("MACE");
    BONK.setSecondaryWeapon("ANOTHERMACE");
    BONK.setEnrage(true);

    
    cout << BONK.getName() << " is a Level " << BONK.getLevel() << " " << BONK.getRace()
        << endl << "Vitality: " << BONK.getVitality()
        << endl << "Armor: " << BONK.getArmor()
        << endl << "They are " << (BONK.isEnemy() ? "an enemy" : "not an enemy")
        << endl << "Main Weapon: " << BONK.getMainWeapon()
        << endl << "Secondary Weapon: " << BONK.getSecondaryWeapon()
        << endl << "Enraged: " << (BONK.getEnrage() ? "TRUE" : "FALSE") << endl;

    return 0;
}
