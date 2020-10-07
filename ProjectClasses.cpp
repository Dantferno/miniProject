//
// Created by hugo.
//

#include "characterClass.h"

/*
 * Parser declaration
 * just some dummy value to test the rest of the code
 */

auto Parser::parseClan() {
    std::map<std::string, std::string> allClan;
    allClan.insert(std::pair<std::string, std::string>("DLAD", "The Best of the best."));
    return allClan;
}

auto Parser::parseNature() {
    std::map<std::string, std::string> all;
    all.insert(std::pair<std::string, std::string>("Bon Vivant", "Unlife is for pleasure."));
    all.insert(std::pair<std::string, std::string>("Capitalist", "Why give it away for free when you can sell it"));
    return all;
}

auto Parser::parseAbilities() {
    // just for testing the class, the parser will initialize the maps
    std::map<std::string, int> talents;
    talents.insert(std::pair<std::string, int>("Alertness", 0));
    talents.insert(std::pair<std::string, int>("Awareness", 0));
    talents.insert(std::pair<std::string, int>("Leadership", 0));
    return talents;
}

auto Parser::parseDisciplines() {
    std::map<std::string, std::string> AvailableDisciplines; // map all disciplined to description, set by the parser
    AvailableDisciplines.insert(std::pair<std::string, std::string>("Thaumaturgy", "description"));
    AvailableDisciplines.insert(std::pair<std::string, std::string>("Fortitude", "description"));
    return AvailableDisciplines;
}

auto Parser::parseBackgrounds() {
    std::map<std::string, std::string> AvailableBackgrounds;
    AvailableBackgrounds.insert(std::pair<std::string, std::string>("Mentor", "description"));
    AvailableBackgrounds.insert(std::pair<std::string, std::string>("Herd", "description"));
    return AvailableBackgrounds;
}

auto Parser::parseSkills() {
    std::map<std::string, int> skills;
    skills.insert(std::pair<std::string, int>("Etiquette", 0));
    skills.insert(std::pair<std::string, int>("Firearms", 0));
    skills.insert(std::pair<std::string, int>("Melee", 0));
    return skills;
}

auto Parser::parseKnowledges(){
    std::map<std::string, int> knowledges;
    knowledges.insert(std::pair<std::string, int>("Academics", 0));
    knowledges.insert(std::pair<std::string, int>("Computer", 0));
    knowledges.insert(std::pair<std::string, int>("Finance", 0));
    return knowledges;
}

/**
 * Clan class declarations
 */

Clan::Clan() {
    allClan = Parser::parseClan(); // set available clan from the parser
}

std::map<std::string, std::string> Clan::getAvailableClan() {return allClan;}

bool Clan::setClan(std::string choiceClan) {
    //return false if clan doesn't exist, else set him
    if (allClan.count(choiceClan)==0){return false;}
    chosenClanName = choiceClan;
    chosenClanDescription = allClan[chosenClanName];
    return true;
}

std::string Clan::getClan() {return chosenClanName;}

std::string Clan::getClanDescription() {return chosenClanDescription;}

auto Clan::deeperParser(std::string askedClan) {}

void Clan::talk() {
    std::cout << "My clan's name is " << chosenClanName << std::endl;
    std::cout << "Its " << chosenClanDescription << std::endl;
}

/**
 * Nature declaration
 */


Nature::Nature() {all = Parser::parseNature();} // set available Nature from the parser


bool Nature::setChoice(std::string choice) {
    //return false if clan doesn't exist, else set him
    if (all.count(choice)==0){return false;}
    chosenNature=choice;
    chosenDescription = all[chosenNature];
    return true;
}

std::string Nature::getChoice() {return chosenNature;}

std::string Nature::getChoiceDescription() {return chosenDescription;}

/**
 * CharacterBackground declaration
 */

void CharacterBackground::setName(std::string name) {Name=name;}

void CharacterBackground::setPlayer(std::string name) {Player=name;}

void CharacterBackground::setChronicle(std::string name) {Chronicle=name;}

void CharacterBackground::setGeneration(std::string name) {Generation=name;}

void CharacterBackground::setConcept(std::string concept) {Concept=concept;}

void CharacterBackground::setSire(std::string name) {Sire=name;}

void CharacterBackground::setClan(Clan choice) {clan=choice;}

void CharacterBackground::setNature(Nature choice) {nature=choice;}

void CharacterBackground::setDeamenor(Nature choice) {demeanor=choice;}

std::string CharacterBackground::getName() {return Name;}

std::string CharacterBackground::getPlayer() {return Player;}

void CharacterBackground::presentBackground() {
    std::cout << "#############BACKGROUND#############" << std::endl;
    std::cout << "My name is " << Name << std::endl;
    std::cout << "I'm the player : " << Player << std::endl;
    std::cout << "We're playing the chronicle :" << Chronicle << std::endl;
    std::cout << "My concept is :" << Concept << std::endl;
    std::cout << "I'm a vampire of the " << Generation << " generation" << std::endl;
    std::cout << "My Sire was " << Sire << std::endl;
    std::cout << "Let me tell you about my clan :" << std::endl;
    clan.talk();
    std::cout << "I say i'm a " << nature.getChoice() << std::endl;
    std::cout << "But truth is, i'm really more a "<< demeanor.getChoice() << std::endl;
    std::cout << "####################################" << std::endl;

}

std::string CharacterBackground::getGeneration() {
    return Generation;
}

/**
 * Attributes declarations
 */



void Attributes::setStrength(int value) {Strength=value;}

int Attributes::getStrength() {return Strength;}

void Attributes::setDexterity(int value) {Dexterity=value;}

int Attributes::getDexterity() {return Dexterity;}

void Attributes::setStamina(int value) {Stamina=value;}

int Attributes::getStamina() {return Stamina;}

void Attributes::setCharisma(int value) {Charisma=value;}

int Attributes::getCharisma() {return Charisma;}

void Attributes::setManipulation(int value) {Manipulation=value;}

int Attributes::getManipulation() {return Manipulation;}

int Attributes::getAppearance() {return Appearance;}

void Attributes::setAppearance(int value){Appearance=value;};

void Attributes::setPerception(int value) {Perception=value;}

int Attributes::getPerception() {return Perception;}

void Attributes::setIntelligence(int value) {Intelligence=value;}

int Attributes::getIntelligence() {return Intelligence;}

void Attributes::setWits(int value) {Wits=value;}

int Attributes::getWits() {return Wits;}

void Attributes::setPhysical(int strength, int dexterity, int stamina) {

    if(strength+dexterity+stamina>7){
        throw std::invalid_argument( "Too much points" );
    }
    Strength = strength;
    Dexterity = dexterity;
    Stamina = stamina;
}

void Attributes::setSocial(int charisma, int manip, int appear) {
    if(charisma+manip+appear>5){
        throw std::invalid_argument( "Too much points" );
    }
    Charisma = charisma;
    Manipulation = manip;
    Appearance = appear;
}

void Attributes::setMental(int percep, int intell, int wits) {
    if(percep+intell+wits>3){
        throw std::invalid_argument( "Too much points" );
    }
    Perception=percep;
    Intelligence=intell;
    Wits=wits;
}

void Attributes::summary() const {
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

/**
 * Abilities declarations
 */


Abilities::Abilities()
{
    talents = Parser::parseAbilities();
    skills = Parser::parseSkills();
    knowledges = Parser::parseKnowledges();
}

bool Abilities::setTalents(std::map<std::string, int> mapTalents)
{
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

bool Abilities::setSkills(std::map<std::string, int> mapSkills)
{
    std::map<std::string, int>::iterator itrmap;
    // use key to upgrade associated value by int
    for(itrmap = mapSkills.begin(); itrmap != mapSkills.end(); itrmap++){
        std::string skill(itrmap->first);
        if (skills.count(skill)==0){
            //if one of the talent doesn't exist return false
            return false;
        }
        skills[skill] += itrmap->second;
    }
    return true;
}

bool Abilities::setKnowledges(std::map<std::string, int> mapKnowledges)
{
    std::map<std::string, int>::iterator itrmap;
    // use key to upgrade associated value by int
    for(itrmap = mapKnowledges.begin(); itrmap != mapKnowledges.end(); itrmap++){
        std::string knowledge(itrmap->first);
        if (knowledges.count(knowledge)==0){
            //if one of the talent doesn't exist return false
            return false;
        }
        knowledges[knowledge] += itrmap->second;
    }
    return true;
}

void Abilities::speak()
{
    std::cout << "#Talents :" << std::endl;
    std::map<std::string, int>::iterator itrmapTalents;
    for (itrmapTalents = talents.begin(); itrmapTalents != talents.end(); itrmapTalents++) {
        std::cout << itrmapTalents->first << " " << itrmapTalents->second<<std::endl;
    }
    std::cout << "#Skills :" << std::endl;
    for (itrmapTalents = skills.begin(); itrmapTalents != skills.end(); itrmapTalents++) {
        std::cout << itrmapTalents->first << " " << itrmapTalents->second<<std::endl;
    }
    std::cout << "#Knowledges :" << std::endl;
    for (itrmapTalents = knowledges.begin(); itrmapTalents != knowledges.end(); itrmapTalents++) {
        std::cout << itrmapTalents->first << " " << itrmapTalents->second<<std::endl;
    }
}



/**
 * Advantage declarations
 */


Advantages::Advantages()
{
    // parser will initialize AvailableDisciplines and AvailableBackgrounds
    // lets just put dummy value for now
    AvailableDisciplines = Parser::parseDisciplines();
    AvailableBackgrounds = Parser::parseBackgrounds();

}

void Advantages::increaseVirtue(int conscience, int instinct, int courage)
{
    VirtueConscience += conscience;
    VirtueInstinct += instinct;
    VirtueCourage += courage;
}

void Advantages::increaseDiscipline(std::map<std::string, int> disciplineToAdd)
{
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
}

void Advantages::increaseBackgrounds(std::map<std::string, int> backgroundToAdd)
{
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
}

std::map<std::string, std::string> Advantages::getAvailableDisciplines()
{
    return AvailableDisciplines;
}

std::map<std::string, int> Advantages::getDisciplines() {return Disciplines;}

std::map<std::string, std::string> Advantages::getAvailableBackgrounds()
{
    return AvailableBackgrounds;
}

std::map<std::string, int> Advantages::getBackgrounds() {return backgrounds;}

void Advantages::talk()
{
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
}

int Advantages::getConscience(){return VirtueConscience;}

int Advantages::getInstinct(){return VirtueInstinct;}

int Advantages::getCourage(){return VirtueCourage;}

/**
 * Character declarations
 */


void Character::setAttributes(Attributes attri) {
    attrib = attri;
}

void Character::setAbilities(Abilities abilities) {
    abil = abilities;
}

void Character::setAdvantages(Advantages advantages) {
    advan = advantages;
}

CharacterBackground &Character::getBackground() {
    return background;
}

void Character::talk() {
    background.presentBackground();
    std::cout << "########## Attributes #######" << std::endl;
    attrib.summary();
    std::cout << "########## Abilities #######" << std::endl;
    abil.speak();
    std::cout << "########## Advantages #######" << std::endl;
    advan.talk();
    std::cout << "########## Etc #######" << std::endl;
    bloodPool.talk();
    humanityWill.talk();
    health.talk();
}

void Character::setBloodPool(BloodPool bloodPool1) {
    bloodPool = bloodPool1;
}

void Character::setHumanityWill(HumanityWill hw) {
    humanityWill = hw;
}

BloodPool Character::getBloodPool() {
    return bloodPool;
}

Advantages Character::getAdvantages() {
    return advan;
}

Health Character::getHealth() {
    return health;
}

int Character::getExperience() {
    return AvailableExperiencePoint;
}

HumanityWill Character::getHumanityWill() {
    return humanityWill;
}

Attributes Character::getAttributes() {
    return attrib;
}

void Character::setExperience(int points) {
    AvailableExperiencePoint += points;
}


/**
 * Character creation declaration
 */


void CharacterCreation::StepZero(std::string name, std::string player, std::string chronicle,
                                 std::string generation, std::string sire) {

    background.setName(name);
    background.setPlayer(player);
    background.setChronicle(chronicle);
    background.setGeneration(generation);
    background.setSire(sire);
}

void CharacterCreation::StepOne(std::string concept, Clan clan, Nature nature, Nature demeanor) {
background.setClan(clan);
background.setConcept(concept);
background.setNature(nature);
background.setDeamenor(demeanor);
}

void CharacterCreation::StepTwo(Attributes attri) {
    ch.setAttributes(attri);
}

void CharacterCreation::StepThree(Abilities ability) {
    ch.setAbilities(ability);
}

void CharacterCreation::StepFour(Advantages advantages) {
    ch.setAdvantages(advantages);
}


void CharacterCreation::StepFive(BloodPool bloodPool, HumanityWill humanityWill) {
    ch.setHumanityWill(humanityWill);
    ch.setBloodPool(bloodPool);
}

Character CharacterCreation::getCharacter() {return ch;}

/**
 * Bloodpool declaration
 */

// Set maxBloodPool according to character Generation
void BloodPool::setMaxBloodPool(std::string generation) {
    std::map<std::string, int> generationToBlood;
    generationToBlood.insert(std::pair<std::string, int>("Third",100));
    generationToBlood.insert(std::pair<std::string, int>("Fourth",50));
    generationToBlood.insert(std::pair<std::string, int>("Fifth",40));
    generationToBlood.insert(std::pair<std::string, int>("Sixth",30));
    generationToBlood.insert(std::pair<std::string, int>("Seventh",20));
    generationToBlood.insert(std::pair<std::string, int>("Eighth",15));
    generationToBlood.insert(std::pair<std::string, int>("Ninth",14));
    generationToBlood.insert(std::pair<std::string, int>("Tenth",13));
    generationToBlood.insert(std::pair<std::string, int>("Eleventh",12));
    generationToBlood.insert(std::pair<std::string, int>("Twelfth",11));
    generationToBlood.insert(std::pair<std::string, int>("Thirteenth+",10));
    maxBloodPool = generationToBlood[generation];
    std::cout << maxBloodPool;
    setCurrentBloodPool(maxBloodPool);
}

int BloodPool::getMaxBloodPool() {
    return maxBloodPool;
}

void BloodPool::setCurrentBloodPool(int blood) {
    currentBloodPool = blood;
}

int BloodPool::getCurrentBloodPool() {
    return currentBloodPool;
}

void BloodPool::talk() {
    std::cout << "Blood Pool : " << currentBloodPool << "/" << maxBloodPool << std::endl;
}

/**
 * Humanity
 *
 */


int HumanityWill::getHumanity() {
    return humanityPoints;
}

int HumanityWill::getWillpower() {
    return willpowerPoints;
}

HumanityWill::HumanityWill(int conscience, int instinct, int courage) {
    humanityPoints = courage + conscience;
    willpowerPoints = courage;
}

HumanityWill::HumanityWill() {}

void HumanityWill::talk() const {
    std::cout << "Humanity points : " << humanityPoints << std::endl;
    std::cout << "Willpower points : "<< willpowerPoints << std::endl;
}


/**
 * Health declaration
 *
 */

void Health::setHurt(bool hurt) {isHurt = hurt;}

void Health::setBruised(bool bruise) {isBruised = bruise;}

void Health::setInjured(bool injured) {isInjured = injured;}

void Health::setWounded(bool wound) {isWounded = wound;}

void Health::setMauled(bool mauled) {isMauled = mauled;}

void Health::setCrippled(bool cripple) {isCrippled = cripple;}

void Health::setIncapacitaded(bool inc) {isIncapacitaded = inc;}

void Health::setTorpor(bool t) {torpor = t;}

bool Health::getBruised() {return isBruised;}

bool Health::getHurt() {return isHurt;}

bool Health::getInjured() {return isInjured;}

bool Health::getWounded() {return isWounded;}

bool Health::getMauled() {return isMauled;}

bool Health::getCrippled() {return isCrippled;}

bool Health::getIncapacitated() {return isIncapacitaded;}

bool Health::getTorpor() {return torpor;}

void Health::talk() {
    std::cout << "######### Health status ##########" << std::endl;
    if(isBruised){std::cout<<"I'm bruised" << std::endl;}else{std::cout<<"I'm not bruised" << std::endl;}
    if(isHurt){std::cout<<"I'm hurt" << std::endl;}else{std::cout<<"I'm not Hurt" << std::endl;}
    if(isInjured){std::cout<<"I'm injured" << std::endl;}else{std::cout<<"I'm not injured" << std::endl;}
    if(isWounded){std::cout<<"I'm wounded" << std::endl;}else{std::cout<<"I'm not wounded" << std::endl;}
    if(isMauled){std::cout<<"I'm mauled" << std::endl;}else{std::cout<<"I'm not mauled" << std::endl;}
    if(isCrippled){std::cout<<"I'm crippled" << std::endl;}else{std::cout<<"I'm not crippled" << std::endl;}
    if(isIncapacitaded){std::cout<<"I'm incapacitated" << std::endl;}else{std::cout<<"I'm not incapacitated" << std::endl;}
    if(torpor){std::cout<<"I'm in torpor" << std::endl;}else{std::cout<<"I'm not in torpor" << std::endl;}
}





