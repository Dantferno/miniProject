#include <iostream>
#include <string>
#include <map>
#include <vector>

class Parser{
    std::string filePath;
public:
    auto parseClan(){};
    auto parseNature(){};
    auto parseAttributes(){};
    auto parseAbilities(){};
    auto parseSkills(){};
    auto parseKnowledges(){};
    auto parseAllies(){};
    auto parseVirtues(){};
    auto parseDisciplines(){};
    auto parseComplexesDisciplines(){};
};

/**
 * Clan will display the available Clan/description
 * Clan can be set/get from here
 * A deeper parser is available to show on the GUI the nickname/sect/etc properly
 */
class Clan{
    std::string chosenClanName;
    std::string chosenClanDescription;
    std::map<std::string, std::string> allClan; // map clan name to clan description
public:
    void parseClan(){}; // set the allClan map after parsing
    std::map<std::string, std::string> getAvailableClan(){return allClan;}; //return the map allClan;
    void setClan(std::string choiceClan){}; // Will set the desired Clan and description
    std::string getClan(){return chosenClanName;};
    std::string getClanDescription(){return chosenClanDescription;};
    auto deeperParser(std::string askedClan){}; // will return (probably) a map with the nickname/sect/etc for a Clan to
                                                // be displayed in a new window
};

/**
 * Hold the available Nature/Demeanor
 * Set and get Nature name and description
 */
class Nature{
    std::string chosenNature;
    std::string chosenDescription;
    std::map<std::string, std::string> all; // map name to description
public:
    void parseClan(){}; // set the allClan map after parsing
    void getAvailable(){}; //return the map all;
    void setChoice(std::string choice){}; // Will set the desired choice and description
    std::string getChoice(){return chosenNature;};
    std::string getChoiceDescription(){return chosenDescription;};
};



/**
 * CharacterBackground will hold all the story of the Vampire.
 *
 */
class CharacterBackground{
    std::string Name;
    std::string Player;
    std::string Chronicle;
    Nature nature;
    Nature demeanor;
    std::string Concept;
    Clan clan;
    std::string Generation;
    std::string Sire;
public:
    // Setters
    void setName(std::string name){Name=name;};
    void setPlayer(std::string name){Player=name;};
    void setChronicle(std::string name){Chronicle=name;};
    void setGeneration(std::string name){Generation=name;};
    void setSire(std::string name){Sire=name;};
    void setClan(Clan choice){clan=choice;};
    void setNature(Nature choice){nature=choice;};
    void setDeamenor(Nature choice){demeanor=choice;};
    // Getters
    std::string getName(){return Name;};
    std::string getPlayer(){return Player;};

};

/**
 * class holding all the attributes, get and set them
 */
class Attributes{
    int Strength =1;
    int Dexterity=1;
    int Stamina=1;
    int Charisma=1;
    int Manipulation=1;
    int Appearance=1;
    int Perception=1;
    int Intelligence=1;
    int Wits=1;
public:
    void setStrength(int value){Strength=value;};
    int getStrength(){return Strength;}
    void setDexterity(int value){Dexterity=value;};
    int getDexterity(){return Dexterity;}
    void setStamina(int value){Stamina=value;};
    int getStamina(){return Stamina;}
    void setCharisma(int value){Charisma=value;};
    int getCharisma(){return Charisma;}
    void setManipulation(int value){Manipulation=value;};
    int getManipulation(){return Manipulation;}
    void setAppearance(int value){Appearance=value;};
    int getAppearance(){return Appearance;}
    void setPerception(int value){Perception=value;};
    int getPerception(){return Perception;}
    void setIntelligence(int value){Intelligence=value;};
    int getIntelligence(){return Intelligence;};
    void setWits(int value){Wits=value;};
    int getWits(){return Wits;};
    //used only during character creation
    void setPhysical(int strength, int dexterity, int stamina){

        if(strength+dexterity+stamina>7){
            throw std::invalid_argument( "Too much points" );
        }
        Strength = strength;
        Dexterity = dexterity;
        Stamina = stamina;
    }

    void setSocial(int charisma, int manip, int appear){
        if(charisma+manip+appear>5){
            throw std::invalid_argument( "Too much points" );
        }
        Charisma = charisma;
        Manipulation = manip;
        Appearance = appear;
    }

    void setMental(int percep, int intell, int wits){
        if(percep+intell+wits>3){
            throw std::invalid_argument( "Too much points" );
        }
        Perception=percep;
        Intelligence=intell;
        Wits=wits;
    }
};

/**
 *  Parsing will return 3 maps of all abilities (talents, skills, knowledges) associated with 0
 *  set them with a map. input <"Brawl":1> will increase brawl inside talents by 1
 */

class Abilities{
    std::map<std::string, int> talents;
    std::map<std::string, int> skills;
    std::map<std::string, int> knowledges;
public:
    Abilities(){
    // just for testing the class, the parser will initialize the maps
        talents.insert(std::pair<std::string, int>("Alertness", 0));
        talents.insert(std::pair<std::string, int>("Awareness", 0));
        talents.insert(std::pair<std::string, int>("Leadership", 0));
    }
    bool setTalents(std::map<std::string, int> mapTalents){
        std::map<std::string, int>::iterator itrmapTalents;
        // use key to upgrade associated value by int
        for(itrmapTalents = mapTalents.begin(); itrmapTalents != mapTalents.end(); itrmapTalents++){
            std::string talent(itrmapTalents->first);
            if (talents.count(talent)==0){
                //if one of the talent doesn't exist return false
                return false;
            }
            talents[talent] += itrmapTalents->second;
        }
        return true;
    }
    void speak() {
        std::map<std::string, int>::iterator itrmapTalents;
        // use key to upgrade associated value by int
        for (itrmapTalents = talents.begin(); itrmapTalents != talents.end(); itrmapTalents++) {
            std::cout << itrmapTalents->first << " " << itrmapTalents->second<<std::endl;
        }
    }
    bool setSkills(std::map<std::string, int> mapSkills){
        std::map<std::string, int>::iterator itrmap;
        // use key to upgrade associated value by int
        for(itrmap = mapSkills.begin(); itrmap != mapSkills.end(); itrmap++){
            std::string skill(itrmap->first);
            if (talents.count(skill)==0){
                //if one of the talent doesn't exist return false
                return false;
            }
            talents[skill] += itrmap->second;
        }
        return true;
    }
    bool setKnowledges(std::map<std::string, int> mapKnowledges){
        std::map<std::string, int>::iterator itrmap;
        // use key to upgrade associated value by int
        for(itrmap = mapKnowledges.begin(); itrmap != mapKnowledges.end(); itrmap++){
            std::string skill(itrmap->first);
            if (talents.count(skill)==0){
                //if one of the talent doesn't exist return false
                return false;
            }
            talents[skill] += itrmap->second;
        }
        return true;
    }
};

/**
 * Same as abilities except the maps are empty and the key will be checked against the
 * available disciplines/backgrounds
 * example : setDiscipline(<"Thaumaturgie": 2> will add thaumaturgie to the Discipline map
 * after checking that it is a valid discipline, if the key is already in Discipline,
 * it will just increase the value by 2.
 */
class Advantages{
    std::map<std::string, int> Disciplines; // map selected discipline to points
    std::map<std::string, int> backgrounds;
    std::map<std::string, std::string> AvailableDisciplines; // map all disciplined to description, set by the parser
    std::map<std::string, std::string> AvailableBackgrounds;
    int VirtueConscience=1;
    int VirtueInstinct=1;
    int VirtueCourage=1;
public:
    void increaseVirtue(int conscience, int instinct, int courage){
        VirtueConscience += conscience;
        VirtueInstinct += instinct;
        VirtueCourage += courage;
    };

};

/**
 * Hold all the informations about the character
 */
class Character{
public:
    Attributes attrib;
    Abilities abil;
    Advantages advan;
    CharacterBackground background;
    void setAttributes(Attributes attri){
        attrib = attri;
    }

    void setAbilities(Abilities abilities) {
        abil = abilities;
    }

    void setAdvantages(Advantages advantages) {
        advan = advantages;
    }

    void talk(){
        std::cout << background.getName();
    }

};


/**
 * Will be used by the GUI to create the character
 * each step will be a window and the arguments passed to the step will be the form to complete
 * For now serve as a proof of concept
 */
class CharacterCreation{
    Character ch;
public:
    void StepZero(std::string name, std::string player,std::string chronicle,std::string generation,std::string sire){
        ch.background.setName(name);
        ch.background.setName(player);
        ch.background.setChronicle(chronicle);
        ch.background.setGeneration(generation);
        ch.background.setSire(sire);
    };
    void StepOne(std::string concept, Clan clan, Nature nature, Nature demeanor){
        ch.background.setClan(clan);
        ch.background.setNature(nature);
        ch.background.setDeamenor(demeanor);
    };
    void StepTwo(Attributes attri){
        ch.setAttributes(attri);
    };
    void StepThree(Abilities ability){
        ch.setAbilities(ability);
    };
    void StepFour(Advantages advantages) {
        ch.setAdvantages(advantages);
    };
    void StepFive(){};
    Character getCharacter(){return ch;};
};




int main() {
    CharacterCreation cr;
    cr.StepZero("Hugo", "Hugo", "Chroniques de test", "Premiere generation", "Moi meme");
    // we create a clan/Nature/Demeanor for testing
    Clan bestClan;
    bestClan.setClan("Clan des meilleurs");
    // we create a nature architect and a demeanor trickster for testing
    Nature architect, trickster;
    architect.setChoice("Architect");
    trickster.setChoice("Trickster");
    cr.StepOne("student", bestClan, architect, trickster); // We have everything to complete the first step
    // second step, set attributes
    Attributes attri;
    attri.setPhysical(3,3,1);
    attri.setSocial(2,2,1);
    attri.setMental(1,1,1);
    cr.StepTwo(attri);


    // third step, select abilities
    Abilities abilities;
    std::map<std::string, int>newAbilities;
    // lets try to add a fake ability
    newAbilities.insert(std::pair<std::string, int>("Coucou", 2));
    bool abilitiesAdded = abilities.setTalents(newAbilities);
    std::cout << "Did it work ? " << abilitiesAdded << std::endl; // return false
    // Now let's add a real ability
    std::map<std::string, int>newRealAbilities;
    newRealAbilities.insert(std::pair<std::string, int>("Alertness", 2));
    abilitiesAdded = abilities.setTalents(newRealAbilities);
    std::cout << "Did it work ? " << abilitiesAdded << std::endl; // return true
    // It worked
    // lets add two at the time
    abilities.speak();
    newRealAbilities.insert(std::pair<std::string, int>("Awareness", 2));
    newRealAbilities.insert(std::pair<std::string, int>("Leadership", 2));
    abilitiesAdded = abilities.setTalents(newRealAbilities);
    std::cout << "Did it work ? " << abilitiesAdded << std::endl; // return true
    abilities.speak();
    cr.StepThree(abilities);


    // fourth step, select advantages
    Advantages advantages;
    cr.StepFour(advantages);
    // fifth step,
    cr.StepFive();
    Character myCharacter = cr.getCharacter();
    myCharacter.talk();
    return 0;
}
