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
    Clan(){
        //All clan will be filled by the parser, this is just a test
        allClan.insert(std::pair<std::string, std::string>("DLAD", "The Best of the best."));
    };
    std::map<std::string, std::string> getAvailableClan(){return allClan;}; //return the map allClan;
    bool setClan(std::string choiceClan){
        //return false if clan doesn't exist, else set him
        if (allClan.count(choiceClan)==0){return false;}
        chosenClanName = choiceClan;
        chosenClanDescription = allClan[chosenClanName];
        return true;
    }; // Will set the desired Clan and description using the map, check if Clan exist, else return false
    std::string getClan(){return chosenClanName;};
    std::string getClanDescription(){return chosenClanDescription;};
    auto deeperParser(std::string askedClan){}; // will return (probably) a map with the nickname/sect/etc for a Clan to
                                                // be displayed in a new window
    void talk(){
      std::cout << "My clan's name is " << chosenClanName << std::endl;
      std::cout << "Its " << chosenClanDescription << std::endl;
    };
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
    Nature(){
        // This is just dummy values, the map all will be filled by the parser
        all.insert(std::pair<std::string, std::string>("Bon Vivant", "Unlife is for pleasure."));
        all.insert(std::pair<std::string, std::string>("Capitalist", "Why give it away for free when you can sell it"));
    };
    void getAvailable(){}; //return the map all;
    bool setChoice(std::string choice){
        //return false if clan doesn't exist, else set him
        if (all.count(choice)==0){return false;}
        chosenNature=choice;
        chosenDescription = all[chosenNature];
        return true;
        }; // Will set the desired choice and description
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
    void setConcept(std::string concept){Concept=concept;}
    void setClan(Clan choice){clan=choice;};
    void setNature(Nature choice){nature=choice;};
    void setDeamenor(Nature choice){demeanor=choice;};
    // Getters
    std::string getName(){return Name;};
    std::string getPlayer(){return Player;};

    void presentBackground(){
      std::cout << "#############BACKGROUND#############" << std::endl;
      std::cout << "My name is " << Name << std::endl;
      std::cout << "I'm the player : " << Player << std::endl;
      std::cout << "We're playing the chronicle :" << Chronicle << std::endl;
      std::cout << "My concept is :" << Concept << std::endl;
      std::cout << "I'm a vampire of the " << Generation << std::endl;
      std::cout << "My Sire was " << Sire << std::endl;
      std::cout << "Let me tell you about my clan :" << std::endl;
      clan.talk();
      std::cout << "I say i'm a " << nature.getChoice() << std::endl;
      std::cout << "But truth is, i'm really more a "<< demeanor.getChoice() << std::endl;
      std::cout << "####################################" << std::endl;

    };

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
    void summary(){
        std::cout << "#Physical " << std::endl;
        std::cout << "Strength : " << Strength<< std::endl;
        std::cout << "Dexterity : " << Dexterity << std::endl;
        std::cout << "Stamina : " << Stamina << std::endl;
        std::cout << "#Social" << std::endl;
        std::cout << "Charisma : " << Charisma << std::endl;
        std::cout << "Manipulation : " << Manipulation << std::endl;
        std::cout << "Appearance : " << Appearance << std::endl;
        std::cout << "#Mental "<< std::endl;
        std::cout << "Perception : " << Perception << std::endl;
        std::cout << "Intelligence : " << Intelligence << std::endl;
        std::cout << "Wits : " << Wits << std::endl;

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
        std::cout << "#Talents :" << std::endl;
        std::map<std::string, int>::iterator itrmapTalents;
        // use key to upgrade associated value by int
        for (itrmapTalents = talents.begin(); itrmapTalents != talents.end(); itrmapTalents++) {
            std::cout << itrmapTalents->first << " " << itrmapTalents->second<<std::endl;
        }
        std::cout << "#Skills :" << std::endl;
        std::cout << "#Knowledges :" << std::endl;
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
 * example : setDiscipline(<"Thaumaturgy": 2> will add thaumaturgie to the Discipline map
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
    Advantages(){
        // parser will initialize AvailableDisciplines and AvailableBackgrounds
        // lets just put dummy value for now
        AvailableDisciplines.insert(std::pair<std::string, std::string>("Thaumaturgy", "description"));
        AvailableDisciplines.insert(std::pair<std::string, std::string>("Fortitude", "description"));
        AvailableBackgrounds.insert(std::pair<std::string, std::string>("Mentor", "description"));
        AvailableBackgrounds.insert(std::pair<std::string, std::string>("Herd", "description"));

    };

    void increaseVirtue(int conscience, int instinct, int courage){
        VirtueConscience += conscience;
        VirtueInstinct += instinct;
        VirtueCourage += courage;
    };

    void increaseDiscipline(std::map<std::string, int> disciplineToAdd){
        std::map<std::string, int>::iterator itr;
        // use key to upgrade associated value by int
        for(itr = disciplineToAdd.begin(); itr != disciplineToAdd.end(); itr++){
            std::string discipline(itr->first); // get the key
            if (Disciplines.count(discipline)==0){
                //if one of the discipline doesn't exist add it with value
                Disciplines[discipline] = itr->second;
            }else {
                Disciplines[discipline] += itr->second;
            }
        }
    };

    void increaseBackgrounds(std::map<std::string, int> backgroundToAdd){
        std::map<std::string, int>::iterator itr;
        // use key to upgrade associated value by int
        for(itr = backgroundToAdd.begin(); itr != backgroundToAdd.end(); itr++){
            std::string background(itr->first); // get the key
            if (backgrounds.count(background)==0){
                //if one of the discipline doesn't exist add it with value
                backgrounds[background] = itr->second;
            }else {
                backgrounds[background] += itr->second;
            }
        }
    };

    std::map<std::string, std::string> getAvailableDisciplines(){
        return AvailableDisciplines;
    }

    std::map<std::string, int> getDisciplines(){
        return Disciplines;
    }

    std::map<std::string, std::string> getAvailableBackgrounds(){
        return AvailableBackgrounds;
    }

    std::map<std::string, int> getBackgrounds(){
        return backgrounds;
    }

    void talk(){
        std::cout << "#Disciplines" << std::endl;
        std::map<std::string, int>::iterator itr;
        for(itr = Disciplines.begin(); itr != Disciplines.end(); itr++) {
            std::cout << itr->first << " : " << itr->second << std::endl;
        }
        std::cout << "#Backgrounds" << std::endl;
        for(itr = backgrounds.begin(); itr != backgrounds.end(); itr++) {
            std::cout << itr->first << " : " << itr->second << std::endl;
        }
        std::cout << "#Virtues" << std::endl;
        std::cout << "Conscience : " <<VirtueConscience << std::endl;
        std::cout << "Instinct : " <<VirtueInstinct << std::endl;
        std::cout << "Courage : " <<VirtueCourage << std::endl;

    };
};

/**
 * Hold all the informations about the character
 */
class Character{
    Attributes attrib;
    Abilities abil;
    Advantages advan;
    CharacterBackground background;
public:
    void setAttributes(Attributes attri){
        attrib = attri;
    }

    void setAbilities(Abilities abilities) {
        abil = abilities;
    }

    void setAdvantages(Advantages advantages) {
        advan = advantages;
    }

    CharacterBackground& getBackground(){
        return background;
    }

    void talk(){
        background.presentBackground();
        std::cout << "########## Attributes #######" << std::endl;
        attrib.summary();
        std::cout << "########## Abilities #######" << std::endl;
        abil.speak();
        std::cout << "########## Advantages #######" << std::endl;
        advan.talk();
        std::cout << "########## Etc #######" << std::endl;
    }

};


/**
 * Will be used by the GUI to create the character
 * each step will be a window and the arguments passed to the step will be the form to complete
 * For now serve as a proof of concept
 */
class CharacterCreation{
    Character ch;
    CharacterBackground &background = ch.getBackground();
public:
    void StepZero(std::string name, std::string player,std::string chronicle,std::string generation,std::string sire){

        background.setName(name);
        background.setPlayer(player);
        background.setChronicle(chronicle);
        background.setGeneration(generation);
        background.setSire(sire);
    };
    void StepOne(std::string concept, Clan clan, Nature nature, Nature demeanor){
        background.setClan(clan);
        background.setConcept(concept);
        background.setNature(nature);
        background.setDeamenor(demeanor);
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
    cr.StepZero("Hugdrula", "Hugo", "Chroniques de test", "Premiere generation", "Moi meme");


    // we create a clan/Nature/Demeanor for testing
    Clan bestClan;
    bestClan.setClan("DLAD"); // if clan doesn't exist, return false so we can check it in the GUI
    // we create a nature architect and a demeanor trickster for testing
    Nature architect, trickster;
    architect.setChoice("Bon Vivant");
    trickster.setChoice("Capitalist");
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


    // fourth step, select advantages and virtues
    // lets create an advantage obj
    Advantages advantages;
    // We will set the virtue
    advantages.increaseVirtue(3,3,1);
    // Now let's add a discipline
    std::map<std::string, int>discipline;
    discipline.insert(std::pair<std::string, int>("Thaumaturgy", 2));
    advantages.increaseDiscipline(discipline); // Thaumaturgy is added with value 2 to the discipline
    advantages.increaseDiscipline(discipline); // thaumaturgy already exist so its just increased by 2
    // Lets see what discipline we have
    std::cout << "Our disciplines : " << std::endl;
    advantages.talk();
    // we can add N disciplines at the same time, without affecting those already present
    discipline.clear();
    discipline.insert(std::pair<std::string, int>("Fortitude", 3));
    discipline.insert(std::pair<std::string, int>("Animalism", 1));
    advantages.increaseDiscipline(discipline);
    // Lets see what discipline we have
    std::cout << "Our disciplines : " << std::endl;
    advantages.talk();
    // let's add a background
    std::map<std::string, int>backg;
    backg.insert(std::pair<std::string, int>("Mentor", 2));
    advantages.increaseBackgrounds(backg);
    // We add the advantages to our character using the character creation object
    cr.StepFour(advantages); // nb: backgrounds works the same as disciplines


    // fifth step,
    cr.StepFive();
    Character myCharacter = cr.getCharacter();
    std::cout << "@@@@@@@@@@@ Fiche Personnage @@@@@@@@@@@@@" << std::endl;
    myCharacter.talk(); // Let's see what we have at the end
    return 0;
}

