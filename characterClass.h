//
// Created by hugo
//

#ifndef MINIPROJECT_CHARACTERCLASS_H
#define MINIPROJECT_CHARACTERCLASS_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <istream>
#include <fstream>

/**
 * Emulate what the real parser will return
 * all method returns maps for now, the data struct will be decided once we create the real parser
 */
class Parser{
    std::string filePath;
public:
    static std::vector<std::string> parseClan(); // return vector fill with clan name
    static std::vector<std::string> parseNature();
    static std::vector<std::string> parseTalents();
    static std::vector<std::string> parseSkills();
    static std::vector<std::string> parseDisciplines();
    static std::vector<std::string> parseBackgrounds();

    static auto parseAttributes();
    static auto parseAbilities();
    static std::vector<std::string> parseKnowledges();
    static auto parseAllies();
    static auto parseVirtues();
    static auto parseComplexesDisciplines();
};


/**
 * CharacterBackground holds all the background of the Vampire.
 * Everything in here will not change once created
 */
class CharacterBackground{
    std::string Name;
    std::string Player;
    std::string Chronicle;
    std::string nature;
    std::string demeanor;
    std::string Concept;
    std::string clan;
    std::string Generation;
    std::string Sire;
public:
    // Setters
    void setName(std::string name);
    void setPlayer(std::string name);
    void setChronicle(std::string name);
    void setGeneration(std::string name);
    void setSire(std::string name);
    void setConcept(std::string concept);
    void setClan(std::string choice);
    void setNature(std::string choice);
    void setDeamenor(std::string choice);
    // Getters
    std::string getName();
    std::string getPlayer();
    std::string getGeneration();
    std::string getChronicle();
    std::string getSire();
    std::string getConcept();
    std::string getClan();


    void presentBackground(); // cout text description of the Vampire background

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
    void setStrength(int value);
    int getStrength();
    void setDexterity(int value);
    int getDexterity();
    void setStamina(int value);
    int getStamina();
    void setCharisma(int value);
    int getCharisma();
    void setManipulation(int value);
    int getManipulation();
    void setAppearance(int value);
    int getAppearance();
    void setPerception(int value);
    int getPerception();
    void setIntelligence(int value);
    int getIntelligence();
    void setWits(int value);
    int getWits();

    //used only during character creation
    void setPhysical(int strength, int dexterity, int stamina);

    void setSocial(int charisma, int manip, int appear);

    void setMental(int percep, int intell, int wits);

    void summary() const; // cout text description of the attributes
};


/**
 *  Parsing will return 3 maps of all abilities (talents, skills, knowledges) associated with 0
 *  set them with a map. input <"Brawl":1> will increase brawl inside talents by 1
 */

class Abilities{
    std::map<std::string, int> talents;
    std::vector<std::string> skills;
    std::vector<std::string> knowledges;
public:
    Abilities(); // fill talents, skills and knowledges from the parser with all the available choices
    bool setTalents(std::map<std::string, int> mapTalents); // increase talents if it exist
    bool setSkills(std::map<std::string, int> mapSkills); // increase skill if it exist
    bool setKnowledges(std::map<std::string, int> mapKnowledges); // increase knowledges if it exist
    void speak(); // cout text description of the chosen abilities
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
    Advantages(); // fill AvailableDisciplines and AvailableBackgrounds from the parser

    void increaseVirtue(int conscience, int instinct, int courage); // set virtue

    void increaseDiscipline(std::map<std::string, int> disciplineToAdd); // add discipline with points if in AvailableDisciplines

    void increaseBackgrounds(std::map<std::string, int> backgroundToAdd);

    int getConscience();

    int getInstinct();

    int getCourage();

    std::map<std::string, std::string> getAvailableDisciplines();

    std::map<std::string, int> getDisciplines();

    std::map<std::string, std::string> getAvailableBackgrounds();

    std::map<std::string, int> getBackgrounds();

    void talk(); // cout text description of the chosen disciplines and backgrounds
};

/**
 *  Blood pool
 */
class BloodPool{
    int maxBloodPool;
    int currentBloodPool;
public:
    void setMaxBloodPool(std::string generation); // set max blood pool according to Vampire generation
    int getMaxBloodPool();
    void setCurrentBloodPool(int blood);
    int getCurrentBloodPool();
    void talk();
};

/**
 * Humanity and Willpower
 */

class HumanityWill{
    int humanityPoints;
    int willpowerPoints;
public:
    HumanityWill(); // so the object can be constructed without conscience, etc
    HumanityWill(int conscience, int instinct, int courage);
    int getHumanity();
    int getWillpower();
    void talk() const;
};


/**
 *  Health status of the player
 */

class Health{
    bool isBruised = false;
    bool isHurt = false;
    bool isInjured =false;
    bool isWounded =false;
    bool isMauled =false;
    bool isCrippled = false;
    bool isIncapacitaded = false;
    bool torpor = false;
public:
    //setters
    void setBruised(bool);
    void setHurt(bool);
    void setInjured(bool);
    void setWounded(bool);
    void setMauled(bool);
    void setCrippled(bool);
    void setIncapacitaded(bool);
    void setTorpor(bool);
    //getters
    bool getBruised();
    bool getHurt();
    bool getInjured();
    bool getWounded();
    bool getMauled();
    bool getCrippled();
    bool getIncapacitated();
    bool getTorpor();
    void talk();
};


/**
 * Experience
 */




/**
 * Hold all the informations about the character
 */
class Character{
    Attributes attrib;
    Abilities abil;
    Advantages advan;
    CharacterBackground background;
    BloodPool bloodPool;
    HumanityWill humanityWill;
    Health health;
    int AvailableExperiencePoint;
public:
    void setAttributes(Attributes);

    void setAbilities(Abilities);

    void setAdvantages(Advantages);

    void setBloodPool(BloodPool);

    void setHumanityWill(HumanityWill);

    Attributes getAttributes();

    CharacterBackground& getBackground();

    Advantages getAdvantages();

    BloodPool getBloodPool();

    HumanityWill getHumanityWill();

    Health getHealth();

    int getExperience();

    void setExperience(int);

    void talk();

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
    void StepZero(std::string name, std::string player,std::string chronicle,std::string generation,std::string sire);
    void StepOne(std::string concept, std::string clan, std::string nature, std::string demeanor);
    void StepTwo(Attributes);
    void StepThree(Abilities);
    void StepFour(Advantages);
    void StepFive(BloodPool, HumanityWill);
    Character getCharacter();
};

#endif //MINIPROJECT_CHARACTERCLASS_H
