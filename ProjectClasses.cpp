//
// Created by hugo.
//


#include "characterClass.h"



std::vector<std::string> Parser::parseClan() {
    /**
     * Read vampire file and return all clans
     * @return std::vector of all clan
     */
    std::vector<std::string> allClan;
    std::string filepath = "VampireV5.txt";
    std::string line;
    std::ifstream infile(filepath);

    while(std::getline(infile, line)){
        if (!line.rfind("--", 0)){ //if line starts with "--"
            line.erase(0,2);
            allClan.push_back(line);
        }
        if (!line.rfind("Noiad", 0)){ // stop at the last clan
            break;
        }
    }
    return allClan;
}

std::vector<std::string> Parser::parseNature() {
    /**
     * read vampire file and return all Natures
     * @return std::vector of all natures
     */
    std::vector<std::string> all;
    std::string filepath = "VampireV5.txt";
    std::string line;
    int lineNumber=0;
    std::ifstream infile(filepath);

    while(std::getline(infile, line)){
        lineNumber++;
        if (lineNumber >= 365){
            if (!line.rfind("--", 0)){ //if line starts with "--"
                line.erase(0,2);
                all.push_back(line);
            }
            if (!line.rfind("Visionary", 0)){ // stop at the last nature
                break;
            }
        }

    }
    return all;
}



 std::vector<std::string> Parser::parseDisciplines() {
     /**
  * read vampire file and return all Natures
  * @return std::vector of all disciplines
  */
    std::vector<std::string> AvailableDisciplines; // map all disciplined to description, set by the parser
     std::string filepath = "VampireV5.txt";
     std::string line;
     int lineNumber=0;
     std::ifstream infile(filepath);

     while(std::getline(infile, line)){
         lineNumber++;
         if (lineNumber >= 365){
             if (!line.rfind("--", 0)){ //if line starts with "--"
                 line.erase(0,2);
                 AvailableDisciplines.push_back(line);
             }
             if (!line.rfind("Visceratika", 0)){ // stop at the last nature
                 break;
             }
         }

     }
    return AvailableDisciplines;
}

std::vector<std::string> Parser::parseBackgrounds() {
    /**
 * read vampire file and return all backgrounds
 * @return std::vector of all backgrounds
 */
    std::vector<std::string> AvailableBackgrounds;
    std::string filepath = "VampireV5.txt";
    std::string line;
    int lineNumber=0;
    std::ifstream infile(filepath);

    while(std::getline(infile, line)){
        lineNumber++;
        if (lineNumber >= 930){
            if (!line.rfind("--", 0)){ //if line starts with "--"
                line.erase(0,2);
                AvailableBackgrounds.push_back(line);
            }
            if (!line.rfind("Status", 0)){ // stop at the last nature
                break;
            }
        }

    }
    return AvailableBackgrounds;
}


std::vector<std::string> Parser::parseKnowledges(){
    /**
 * read vampire file and return all knowledges
 * @return std::vector of all knowledges
 */
    std::vector<std::string> allKnowledges;
    std::string filepath = "VampireV5.txt";
    std::string line;
    int lineNumber=0;
    std::ifstream infile(filepath);

    while(std::getline(infile, line)){
        lineNumber++;
        if (lineNumber >= 818){
            if (!line.rfind("--", 0)){ //if line starts with "--"
                line.erase(0,2);
                allKnowledges.push_back(line);
            }
            if (!line.rfind("Expert Knowledge", 0)){ // stop at the last nature
                break;
            }
        }

    }
    return allKnowledges;
}

std::vector<std::string> Parser::parseTalents() {
    /**
 * read vampire file and return all talents
 * @return std::vector of all talents
 */
    std::vector<std::string> allTalents;
    std::string filepath = "VampireV5.txt";
    std::string line;
    int lineNumber=0;
    std::ifstream infile(filepath);

    while(std::getline(infile, line)){
        lineNumber++;
        if (lineNumber >= 592){
            if (!line.rfind("--", 0)){ //if line starts with "--"
                line.erase(0,2);
                allTalents.push_back(line);
            }
            if (!line.rfind("Hobby Talent", 0)){ // stop at the last nature
                break;
            }
        }

    }
    return allTalents;
}

std::vector<std::string> Parser::parseSkills() {
    /**
 * read vampire file and return all skills
 * @return std::vector of all skills
 */
    std::vector<std::string> allSkills;
    std::string filepath = "VampireV5.txt";
    std::string line;
    int lineNumber=0;
    std::ifstream infile(filepath);

    while(std::getline(infile, line)){
        lineNumber++;
        if (lineNumber >= 705){
            if (!line.rfind("--", 0)){ //if line starts with "--"
                line.erase(0,2);
                allSkills.push_back(line);
            }
            if (!line.rfind("Professional Skill", 0)){ // stop at the last nature
                break;
            }
        }

    }
    return allSkills;
}

std::vector<std::string> Parser::getClanDiscipline(std::string clan) {
    /**
 * select clan discipline
     * @param Name of the clan selected by the user
 * @return std::vector of available discipline
 */
    std::vector<std::string> clanDiscipline;
    if(clan=="Assamite"){
        clanDiscipline.push_back("Celerity");clanDiscipline.push_back("Obfuscate");clanDiscipline.push_back("Quietus");
    }else if (clan=="Brujah"){
        clanDiscipline.push_back("Celerity");clanDiscipline.push_back("Potence");clanDiscipline.push_back("Presence");
    }else if (clan=="Followers of Set"){
        clanDiscipline.push_back("Obfuscate");clanDiscipline.push_back("Presence");clanDiscipline.push_back("Serpentis");
    }else if (clan=="Gangrel"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Protean");
    }else if (clan=="Giovanni"){
        clanDiscipline.push_back("Dominate");clanDiscipline.push_back("Necromancy");clanDiscipline.push_back("Potence");
    }else if (clan=="Lasombra"){
        clanDiscipline.push_back("Dominate");clanDiscipline.push_back("Obtenebration");clanDiscipline.push_back("Potence");
    }else if (clan=="Malkavian"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Dementation");clanDiscipline.push_back("Obfuscate");
    }else if (clan=="Nosferatu"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Obfuscate");clanDiscipline.push_back("Potence");
    }else if (clan=="Ravnos"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Chimerstry");clanDiscipline.push_back("Fortitude");
    }else if (clan=="Toreador"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Celerity");clanDiscipline.push_back("Presence");
    }else if (clan=="Tremere"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Dominate");clanDiscipline.push_back("Thaumaturgy");
    }else if (clan=="Tzimisce"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Vicissitude");
    }else if (clan=="Ventrue"){
        clanDiscipline.push_back("Presence");clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Dominate");
    }else if (clan=="Baali"){
        clanDiscipline.push_back("Daimoinon");clanDiscipline.push_back("Presence");clanDiscipline.push_back("Obfuscate");
    }else if (clan=="Blood Brothers"){
        clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Potence");clanDiscipline.push_back("Sanguinus");
    }else if (clan=="Daughters of Cacophony"){
        clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Melpominee");clanDiscipline.push_back("Presence");
    }else if (clan=="Gargoyles"){
        clanDiscipline.push_back("Flight");clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Potence");clanDiscipline.push_back("Visceratika");
    }else if (clan=="Harbingers of Skulls"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Necromancy");
    }else if (clan=="Kiasyd"){
        clanDiscipline.push_back("Dominate");clanDiscipline.push_back("Mytherceria");
        clanDiscipline.push_back("Obtenebration");
    }else if (clan=="Nagaraja"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Necromancy");
        clanDiscipline.push_back("Dominate");
    }else if (clan=="Salubri"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Fortitude");
        clanDiscipline.push_back("Obeah");
    }else if (clan=="Samedi"){
        clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Obfuscate");
        clanDiscipline.push_back("Thanatosis");
    }else if (clan=="True Brujah"){
        clanDiscipline.push_back("Potence");clanDiscipline.push_back("Presence");
        clanDiscipline.push_back("Temporis");
    }else if (clan=="Ahrimanes"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Presence");
        clanDiscipline.push_back("Spiritus");
    }else if (clan=="Anda"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Fortitude");
        clanDiscipline.push_back("Protean");
    }else if (clan=="Cappadocians"){
        clanDiscipline.push_back("Auspex");clanDiscipline.push_back("Fortitude");
        clanDiscipline.push_back("Necromancy");
    }else if (clan=="Children of Osiris"){
        clanDiscipline = Parser::parseDisciplines();
    }else if (clan=="Lamia"){
        clanDiscipline.push_back("Fortitude");clanDiscipline.push_back("Necromancy");
        clanDiscipline.push_back("Potence");
    }else if (clan=="Lhiannan"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Ogham");
        clanDiscipline.push_back("Presence");
    }else if (clan=="Noiad"){
        clanDiscipline.push_back("Animalism");clanDiscipline.push_back("Auspex");
        clanDiscipline.push_back("Protean");
    }else if (clan=="Caitiff"){
        clanDiscipline = Parser::parseDisciplines();
    }

    return clanDiscipline;
}


/**
 * CharacterBackground declaration
 */

void CharacterBackground::setName(std::string name) {Name=name;}

void CharacterBackground::setPlayer(std::string name) {Player=name;}

void CharacterBackground::setChronicle(std::string name) {Chronicle=name;}

void CharacterBackground::setGeneration(std::string name) {Generation=name;}

void CharacterBackground::setConcept(std::string concept) {Concept=concept;}

void CharacterBackground::setSire(std::string name) {Sire=name;}

void CharacterBackground::setClan(std::string choice) {clan=choice;}

void CharacterBackground::setNature(std::string choice) {nature=choice;}

void CharacterBackground::setDeamenor(std::string choice) {demeanor=choice;}

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
    std::cout << "Let me tell you about my clan :" << clan <<  std::endl;

    std::cout << "I say i'm a " << nature << std::endl;
    std::cout << "But truth is, i'm really more a "<< demeanor << std::endl;
    std::cout << "####################################" << std::endl;

}

std::string CharacterBackground::getGeneration() {
    return Generation;
}

std::string CharacterBackground::getChronicle() {
    return Chronicle;
}

std::string CharacterBackground::getSire() {
    return Sire;
}

std::string CharacterBackground::getConcept() {
    return Concept;
}

std::string CharacterBackground::getClan() {
    return clan;
}

std::string CharacterBackground::getNature() {
    return nature;
}

std::string CharacterBackground::getDemeanor() {
    return demeanor;
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
    Strength = strength;
    Dexterity = dexterity;
    Stamina = stamina;
}

void Attributes::setSocial(int charisma, int manip, int appear) {
    Charisma = charisma;
    Manipulation = manip;
    Appearance = appear;
}

void Attributes::setMental(int percep, int intell, int wits) {
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
    talents = Parser::parseTalents();
    skills = Parser::parseSkills();
    knowledges = Parser::parseKnowledges();
}

void Abilities::setTalents(std::vector<int> v) {
    chosenTalents = v;
}

void Abilities::setSkills(std::vector<int> v) {
    chosenSkills=v;
}

void Abilities::setKnowledges(std::vector<int> v) {
    chosenKnowledges=v;
}

void Abilities::setValueTalents(std::vector<int> v) {
    valueTalents = v;
}

void Abilities::setValueSkills(std::vector<int> v) {
    valueSkills = v;
}

void Abilities::setValueKnowledges(std::vector<int> v) {
    valueKnowledges =v;
}

std::vector<int> Abilities::getTalents() {
    return chosenTalents;
}

std::vector<int> Abilities::getValueTalents() {
    return valueTalents;
}

std::vector<int> Abilities::getSkills() {
    return chosenSkills;
}

std::vector<int> Abilities::getValueSkills() {
    return valueSkills;
}

std::vector<int> Abilities::getKnowledge() {
    return chosenKnowledges;
}

std::vector<int> Abilities::getValueKnowledge() {
    return valueKnowledges;
}


/**
 * Advantage declarations
 */


Advantages::Advantages(){}

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

void Advantages::setDisciplines(std::vector<std::string>v1, std::vector<int>v2) {
    std::map<std::string, int> disciplines;
    for (int i = 0; i < v1.size(); ++i) {
        disciplines[v1[i]] = v2[i];
    }
    Disciplines = disciplines;
}

void Advantages::setBackgrounds(std::vector<std::string> v1, std::vector<int> v2) {
    std::map<std::string, int> background;
    for (int i = 0; i < v1.size(); ++i) {
        background[v1[i]] = v2[i];
    }
    backgrounds = background;
}

void Advantages::setVirtue(int conscience, int instinct, int courage) {
    this->VirtueConscience = conscience;
    this->VirtueInstinct = instinct;
    this->VirtueCourage = courage;
}


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
    std::cout << "########## Advantages #######" << std::endl;
    advan.talk();
    std::cout << "########## Etc #######" << std::endl;
    bloodPool.talk();
    humanityWill.talk();
    health.talk();
    std::cout << "###### Experience #######" << std::endl << getExperience() << " points" << std::endl;
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

Abilities Character::getAbilities() {
    return abil;
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

void CharacterCreation::StepOne(std::string concept, std::string clan, std::string nature, std::string demeanor) {
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
void BloodPool::setMaxBloodPool() {
//    std::map<std::string, int> generationToBlood;
//    generationToBlood.insert(std::pair<std::string, int>("Third",100));
//    generationToBlood.insert(std::pair<std::string, int>("Fourth",50));
//    generationToBlood.insert(std::pair<std::string, int>("Fifth",40));
//    generationToBlood.insert(std::pair<std::string, int>("Sixth",30));
//    generationToBlood.insert(std::pair<std::string, int>("Seventh",20));
//    generationToBlood.insert(std::pair<std::string, int>("Eighth",15));
//    generationToBlood.insert(std::pair<std::string, int>("Ninth",14));
//    generationToBlood.insert(std::pair<std::string, int>("Tenth",13));
//    generationToBlood.insert(std::pair<std::string, int>("Eleventh",12));
//    generationToBlood.insert(std::pair<std::string, int>("Twelfth",11));
//    generationToBlood.insert(std::pair<std::string, int>("Thirteenth+",10));
//    maxBloodPool = generationToBlood[generation];
//    std::cout << maxBloodPool;
    maxBloodPool = rand() % 10 +1;
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
    humanityPoints = conscience;
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





