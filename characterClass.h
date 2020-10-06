//
// Created by hugo
//

#ifndef MINIPROJECT_CHARACTERCLASS_H
#define MINIPROJECT_CHARACTERCLASS_H

#include <iostream>
#include <string>
#include <map>
#include <vector>


class Parser{
    std::string filePath;
public:
    static auto parseClan();;
    static auto parseNature();;
    static auto parseAttributes(){};
    static auto parseAbilities();;
    static auto parseSkills(){};
    static auto parseKnowledges(){};
    static auto parseAllies(){};
    static auto parseVirtues(){};
    static auto parseDisciplines(){};
    static auto parseComplexesDisciplines(){};
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
    Clan();;
    std::map<std::string, std::string> getAvailableClan();; //return the map allClan;
    bool setClan(std::string choiceClan);; // Will set the desired Clan and description using the map, check if Clan exist, else return false
    std::string getClan();;
    std::string getClanDescription();;
    auto deeperParser(std::string askedClan);; // will return (probably) a multimap with the nickname/sect/etc for a Clan to
    // be displayed in a new window
    void talk();;
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
    Nature();;
    void getAvailable();; //return the map all;
    bool setChoice(std::string choice);; // Will set the desired choice and description
    std::string getChoice();;
    std::string getChoiceDescription();;

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
    void setName(std::string name);;
    void setPlayer(std::string name);;
    void setChronicle(std::string name);;
    void setGeneration(std::string name);;
    void setSire(std::string name);;
    void setConcept(std::string concept);
    void setClan(Clan choice);;
    void setNature(Nature choice);;
    void setDeamenor(Nature choice);;
    // Getters
    std::string getName();;
    std::string getPlayer();;

    void presentBackground();;
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
    void setStrength(int value);;
    int getStrength();
    void setDexterity(int value);;
    int getDexterity();
    void setStamina(int value);;
    int getStamina();
    void setCharisma(int value);;
    int getCharisma();
    void setManipulation(int value);;
    int getManipulation();
    void setAppearance(int value);
    int getAppearance();
    void setPerception(int value);;
    int getPerception();
    void setIntelligence(int value);;
    int getIntelligence();;
    void setWits(int value);;
    int getWits();;
    //used only during character creation
    void setPhysical(int strength, int dexterity, int stamina);

    void setSocial(int charisma, int manip, int appear);

    void setMental(int percep, int intell, int wits);
    void summary() const;
};
#endif //MINIPROJECT_CHARACTERCLASS_H
