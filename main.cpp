#include "characterClass.h"

int main() {
    /********** character init **********/
    CharacterCreation cr; // the cr object will handle the character generation step by step
    cr.StepZero("Hugdrula", "Hugo", "Chroniques de test",
                "Fourth", "Sr. Tempel");

    /********* first step ************/
    // we create a clan/Nature/Demeanor
    Clan bestClan;
    bestClan.setClan("DLAD"); // if clan doesn't exist, return false so we can check it in the GUI
    // we create a nature "Bon Vivant" and a demeanor "Capitalist" for testing
    Nature nature, demeanor;
    nature.setChoice("Bon Vivant");
    demeanor.setChoice("Capitalist");
    std::string concept("student"); // choose concept
    cr.StepOne(concept, bestClan, nature, demeanor); // We have everything to complete the first step, character is updated

    /********* second step, set attributes *************/
    Attributes attri;
    attri.setPhysical(3,3,1);
    attri.setSocial(2,2,1);
    attri.setMental(1,1,1);
    cr.StepTwo(attri); // complete the second step, push the changes to the character

    /********* third step, select abilities *************/
    Abilities abilities;
    // lets try to add a fake ability
    std::map<std::string, int>newAbilities;
    newAbilities.insert(std::pair<std::string, int>("Coucou", 2)); // coucou is not an ability returned by the parser
    bool abilitiesAdded = abilities.setTalents(newAbilities); // return false, do nothing
    // Now let's add a real ability
    std::map<std::string, int>newRealAbilities;
    newRealAbilities.insert(std::pair<std::string, int>("Alertness", 2));
    abilities.setTalents(newRealAbilities); // return true, ability has been added
    // It worked
    // lets add two at the time
    newRealAbilities.clear();
    newRealAbilities.insert(std::pair<std::string, int>("Awareness", 2));
    newRealAbilities.insert(std::pair<std::string, int>("Leadership", 2));
    abilitiesAdded = abilities.setTalents(newRealAbilities); // return true, Awareness and Leadership have been added
    // lets quickly add skills and knowledges
    newRealAbilities.clear();
    newRealAbilities.insert(std::pair<std::string, int>("Firearms", 2));
    newRealAbilities.insert(std::pair<std::string, int>("Melee", 2));
    abilities.setSkills(newRealAbilities); // add Firearms and Melee skills
    newRealAbilities.clear();
    newRealAbilities.insert(std::pair<std::string, int>("Academics", 2));
    newRealAbilities.insert(std::pair<std::string, int>("Computer", 2));
    abilities.setKnowledges(newRealAbilities); // add knowledges
    cr.StepThree(abilities); // push step 3

    /********* fourth step, select advantages and virtues *************/
    // lets create an advantage obj
    Advantages advantages;
    // We will set the virtue
    advantages.increaseVirtue(3,3,1);
    // Now let's add a discipline
    std::map<std::string, int>discipline;
    discipline.insert(std::pair<std::string, int>("Thaumaturgy", 2));
    advantages.increaseDiscipline(discipline); // Thaumaturgy is added with value 2 to the discipline
    advantages.increaseDiscipline(discipline); // thaumaturgy already exist so its just increased by 2
    // we can add N disciplines at the same time, without affecting those already present
    discipline.clear();
    discipline.insert(std::pair<std::string, int>("Fortitude", 3));
    discipline.insert(std::pair<std::string, int>("Animalism", 1));
    advantages.increaseDiscipline(discipline);
    // let's add a background
    std::map<std::string, int>backg;
    backg.insert(std::pair<std::string, int>("Mentor", 2));
    advantages.increaseBackgrounds(backg);
    // We push the step four
    cr.StepFour(advantages);

    /*********  fifth step *************/
    // create blood pool
    BloodPool bloodPool{};
    // set the max blood pool using the character generation
    std::string generation = cr.getCharacter().getBackground().getGeneration();
    bloodPool.setMaxBloodPool(generation);
    // create humanity and willpower
    int conscience = cr.getCharacter().getAdvantages().getConscience();
    int instinct= cr.getCharacter().getAdvantages().getInstinct();
    int courage= cr.getCharacter().getAdvantages().getCourage();
    HumanityWill hw(conscience, instinct, courage);
    cr.StepFive(bloodPool, hw); // assign blood pool and humanity/willpower to character
    // return the character
    Character myCharacter = cr.getCharacter();
    std::cout << "@@@@@@@@@@@ Fiche Personnage @@@@@@@@@@@@@" << std::endl;
    myCharacter.talk(); // Let's see what we have at the end
    return 0;
}

