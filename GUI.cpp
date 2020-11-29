//
// Created by hugo on 25/10/20.
//
#include <gdkmm.h>
#include "GUI.h"
#include "characterClass.h"





Fenetre::Fenetre()
{
    // Sets the border width of the window.
    set_border_width(10);
    this->add(welcome);
}

Fenetre::~Fenetre()
{

}

void Fenetre::welcomeView() {
    this->remove();
    this->add(welcome);
}



MyGrid::MyGrid() {
    myfont.set_size(16000);
    myfont.set_family("Arial");
    myfont2.set_size(13000);
    myfont2.set_family("Arial");
    this->set_row_spacing(10);
    nextButton.override_font(myfont);
    nextButton.set_label("Create new character.");
    nextButton.signal_clicked().connect(sigc::mem_fun(*this,
                                                      &MyGrid::Page2));
    message.set_label("Welcome on the Vampire creation interface.");
    message.override_font(myfont);
    nextButton.set_size_request(100,50);
    Page1();
}

void MyGrid::Page1(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);


    coverVampire.set("covervampire.png");


    //this->attach(message, 0, 0, 1, 1);
    this->attach(coverVampire,0,1,1,1);
    this->attach(nextButton,0,2,2,1);
    // This packs the button into the Window (a container);
    this->show_all();
}


void MyGrid::initPage2() {
    nameLabel.set_label("Name :");
    playerLabel.set_label("Player name :");
    chronicleLabel.set_label("Chronicle :");
    generationLabel.set_label("Generation :");
    sirLabel.set_label("Sire :");
    conceptLabel.set_text("Concept :");
    clanLabel.set_text("Clan :");
    comboClan.append("Caitiff");
    for (std::string clanName : Parser::parseClan()){
        comboClan.append(clanName);
    }

    comboClan.set_active(0);
    natureLabel.set_text("Nature:");
    for (std::string nature : Parser::parseNature()){
        comboNature.append(nature);
        comboDemeanor.append(nature);
    }

    comboNature.set_active(0);
    demeanorLabel.set_text("Demeanor:");
    comboDemeanor.set_active(0);
    goBack.set_label("Back");
    goBack.signal_clicked().connect(sigc::mem_fun(*this,
                                                  &MyGrid::Page1));
    goPage3.set_label("Next");
    goPage3.signal_clicked().connect(sigc::mem_fun(*this,
                                                   &MyGrid::savePage2));
}



void MyGrid::Page2() {
    if (!isSavedPage2){
        initPage2();
    }
    goPage2.set_label("Next");
    goPage3.set_label("Next");
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);

    // Name label and entry
    this->attach(nameLabel, 0, 0, 1, 1);
    this->attach(nameEntry, 1, 0, 1, 1);

    // player
    this->attach(playerLabel, 2, 0, 1, 1);
    this->attach(playerEntry, 3, 0, 1, 1);

    //chronicle
    this->attach(chronicleLabel, 0, 2, 1, 1);
    this->attach(chronicleEntry, 1, 2, 1, 1);

    //generation
    this->attach(generationLabel, 2, 2, 1, 1);
    this->attach(generationEntry, 3, 2, 1, 1);

    //Sir
    this->attach(sirLabel, 0, 4, 1, 1);
    this->attach(sirEntry, 1, 4, 1, 1);

    // Concept
    this->attach(conceptLabel, 2,4,1,1);
    this->attach(conceptEntry,3,4,1,1);

    //Clan
    this->attach(clanLabel,0,6,1,1);

    this->attach(comboClan, 1,6,1,1);

    //Nature
    this->attach(natureLabel,0,5,1,1);

    this->attach(comboNature, 1,5,1,1);

    //Demeanor
    this->attach(demeanorLabel,2,5,1,1);

    this->attach(comboDemeanor, 3,5,1,1);
//
//    // image
//    firstPart.set("/home/hugo/Pictures/firstpart.png");
//    this->attach(firstPart,0,7,4,1);

    // Go back

    this->attach(goBack,0,8,1,1);


    // Next button

    this->attach(goPage3,3,8,2,1);
    // This packs the button into the Window (a container);
    this->show_all();

}

void MyGrid::savePage2(){
    // save the value of the entry if the user go back
    nameEntry.set_text(nameEntry.get_text());
    playerEntry.set_text(playerEntry.get_text());
    chronicleEntry.set_text(chronicleEntry.get_text());
    generationEntry.set_text(generationEntry.get_text());
    sirEntry.set_text(sirEntry.get_text());
    conceptEntry.set_text(conceptEntry.get_text());

    if(nameEntry.get_text()!="" && playerEntry.get_text()!="" && chronicleEntry.get_text()!="" && sirEntry.get_text()!="" && conceptEntry.get_text()!="") {
        if (!isSavedPage2) {
            isSavedPage2 = true;
            initPage3();
        }
        comboNature.set_active_text(comboNature.get_active_text());
        Page3();
    }else{
        Gtk::MessageDialog d("Missing Input", false, Gtk::MESSAGE_INFO);
       d.set_secondary_text("Please fill all the fields.");
        d.run();
    }

}



void MyGrid::initPage3(){
    /***** Attributes ******/
    attributesLabel.set_text("Attributes");
    attributesLabel.override_font(myfont);
    physicalLabel.set_text("Physical");
    physicalLabel.override_font(myfont2);
    strengthLabel.set_text("Strength");
    strengthSpin.set_range(1,7);
    strengthSpin.set_value(1);
    strengthSpin.set_increments(1,1);
    strengthSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                              &MyGrid::changeTotalPhysical));
    dexterityLabel.set_text("Dexterity :");
    dexteritySpin.set_range(1,7);
    dexteritySpin.set_value(1);
    dexteritySpin.set_increments(1,1);
    dexteritySpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                               &MyGrid::changeTotalPhysical));
    staminaLabel.set_text("Stamina :");
    staminaSpin.set_range(1,7);
    staminaSpin.set_value(1);
    staminaSpin.set_increments(1,1);
    staminaSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                             &MyGrid::changeTotalPhysical));
    socialLabel.set_text("Social");
    socialLabel.override_font(myfont2);
    charismaLabel.set_text("Charisma :");
    charismaSpin.set_range(1,7);
    charismaSpin.set_value(1);
    charismaSpin.set_increments(1,1);
    charismaSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                              &MyGrid::changeTotalSocial));
    manipulationLabel.set_text("Manipulation :");
    manipulationSpin.set_range(1,7);
    manipulationSpin.set_value(1);
    manipulationSpin.set_increments(1,1);
    manipulationSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                                  &MyGrid::changeTotalSocial));
    appearanceLabel.set_text("Appearance :");
    appearanceSpin.set_range(1,7);
    appearanceSpin.set_value(1);
    appearanceSpin.set_increments(1,1);
    appearanceSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                                &MyGrid::changeTotalSocial));
    mentalLabel.set_text("Mental");
    mentalLabel.override_font(myfont2);
    perceptionLabel.set_text("Perception :");
    perceptionSpin.set_range(1,7);
    perceptionSpin.set_value(1);
    perceptionSpin.set_increments(1,1);
    perceptionSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                                &MyGrid::changeTotalMental));
    intelligenceLabel.set_text("Intelligence :");
    intelligenceSpin.set_range(1,7);
    intelligenceSpin.set_value(1);
    intelligenceSpin.set_increments(1,1);
    intelligenceSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                                  &MyGrid::changeTotalMental));
    witsLabel.set_text("Wits : ");
    witsSpin.set_range(1,7);
    witsSpin.set_value(1);
    witsSpin.set_increments(1,1);
    witsSpin.signal_value_changed().connect(sigc::mem_fun(*this,
                                                          &MyGrid::changeTotalMental));
    totalPoint.set_text("Total Point added : ");
    totalPointPhysical.set_text("0");
    totalPointMental.set_text("0");
    totalPointSocial.set_text("0");

    goPage2.set_label("Go back");
    goPage2.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::Page2));
    goPage4.set_label("Next");
    goPage4.signal_clicked().connect(sigc::mem_fun(*this,
                                                   &MyGrid::ApplyPage3));
}

/**
 * Open page 3
 */
void MyGrid::Page3(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);
    goPage2.set_label("Go back");
    goPage4.set_label("Next");
    /***** Attributes ******/
    this->attach(attributesLabel, 0,0,6,1);
    // Physical
    this->attach(physicalLabel, 0,1,2,1);
    //strength
    this->attach(strengthLabel,0,2,1,1);
    this->attach(strengthSpin,1,2,1,1);
    // dexterity
    this->attach(dexterityLabel, 0,3,1,1);
    this->attach(dexteritySpin, 1,3,1,1);
    // stamina
    this->attach(staminaLabel, 0,4,1,1);
    this->attach(staminaSpin, 1,4,1,1);
    // // Social
    this->attach(socialLabel,2,1,2,1);
    // Charisma
    this->attach(charismaLabel, 2,2,1,1);
    this->attach(charismaSpin, 3,2,1,1);
    // Manipulation
    this->attach(manipulationLabel, 2,3,1,1);
    this->attach(manipulationSpin, 3,3,1,1);
    // Appearance
    this->attach(appearanceLabel, 2,4,1,1);
    this->attach(appearanceSpin, 3,4,1,1);
    // // Mental
    this->attach(mentalLabel, 4,1,2,1);
    // Perception
    this->attach(perceptionLabel, 4,2,1,1);
    this->attach(perceptionSpin, 5,2,1,1);
    // intelligence
    this->attach(intelligenceLabel,4,3,1,1);
    this->attach(intelligenceSpin,5,3,1,1);
    //wits
    this->attach(witsLabel, 4,4,1,1);
    this->attach(witsSpin, 5,4,1,1);

    this-> attach(totalPoint, 0,5,1,1);
    this->attach(totalPointPhysical,1 ,5,1,1);
    this->attach(totalPointMental,3 ,5,1,1);

    this->attach(totalPointSocial,5 ,5,1,1);

    this->attach(goPage2, 0,8,1,1);
    // Next button

    this->attach(goPage4,5,8,1,1);

    // This packs the button into the Window (a container);
    this->show_all();
}

void MyGrid::ApplyPage3(){
    // save input
    std::cout << strengthSpin.get_value() << std::endl; 
    strengthSpin.set_value(strengthSpin.get_value());
    dexteritySpin.set_value(dexteritySpin.get_value());
    staminaSpin.set_value(staminaSpin.get_value());
    charismaSpin.set_value(charismaSpin.get_value());
    manipulationSpin.set_value(manipulationSpin.get_value());
    appearanceSpin.set_value(appearanceSpin.get_value());
    perceptionSpin.set_value(perceptionSpin.get_value());
    intelligenceSpin.set_value(intelligenceSpin.get_value());
    witsSpin.set_value(witsSpin.get_value());
   if (checkCorrectRepartition()==1){ // if repartition is not correct
         Gtk::MessageDialog d("Repartition error", false, Gtk::MESSAGE_INFO);
        d.set_secondary_text("Please put (7/5/3) points.");
       d.run();
    }else {

    if (!isSavedPage3){initPage4();isSavedPage3=true;}
        Page4();
    }
}


void MyGrid::initPage4(){
    pointsTalents.set_text("1");
    pointsSkills.set_text("1");
    pointsKnowledges.set_text("1");
    abilitiesLabel.set_text("Abilities");
    abilitiesLabel.override_font(myfont);
    talentsLabel.set_text("Talents :");
    talentsLabel.override_font(myfont2);
    for(std::string talent : allTalents){talentsCombo.append(talent);}
    talentsCombo.set_active(0);

    wList.push_back(&talentsCombo);
    talentsSpin.set_range(1,3);
    talentsSpin.set_value(1);
    talentsSpin.set_increments(1,1);
    talentsSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalTalents));
    spinListTalent.push_back(&talentsSpin);

    addTalent.set_label("Add talent");
    signalTalent = addTalent.signal_clicked().connect(sigc::mem_fun(*this,
                                                     &MyGrid::addTalentClicked));

    // configure remove talent button but don't display it yet
    removeTalent.set_label("Remove talent");
    removeTalentSignal = removeTalent.signal_clicked().connect(sigc::mem_fun(*this,
                                                        &MyGrid::removeTalentClicked));

    skillsLabel.set_label("Skills :");
    skillsLabel.override_font(myfont2);
    for(std::string skill : allSkills){skillsCombo.append(skill);}
    skillsCombo.set_active(0);

    skillsList.push_back(&skillsCombo);
    skillsSpin.set_range(1,3);
    skillsSpin.set_value(1);
    skillsSpin.set_increments(1,1);
    skillsSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalSkill));
    spinListSkills.push_back(&skillsSpin);

    addSkills.set_label("Add skill");
    signalSkill = addSkills.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addSkillsClicked));
    removeSkills.set_label("Remove skill");
    removeSkillSignal = removeSkills.signal_clicked().connect(sigc::mem_fun(*this,
                                                        &MyGrid::removeSkillsClicked));

    knowledgesLabel.set_label("Knowledges :");
    knowledgesLabel.override_font(myfont2);
    for(std::string know : allKnowledges){knowledgesCombo.append(know);}
    knowledgesCombo.set_active(0);

    knowledgesList.push_back(&knowledgesCombo);
    knowledgesSpin.set_range(1,3);
    knowledgesSpin.set_value(1);
    knowledgesSpin.set_increments(1,1);
    knowledgesSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalKnowledge));
    spinListKnowledges.push_back(&knowledgesSpin);

    addKnowledges.set_label("Add knowledge");
    signalKnowledges = addKnowledges.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addKnowledgesClicked));

    removeKnowledges.set_label("Remove knowledge");
    removeKnowledegeSignal=removeKnowledges.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeKnowledgesClicked));

    goPage3.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::Page3));
    goPage3.set_label("Go back");
    goPage5.set_label("Next");
    goPage5.signal_clicked().connect(sigc::mem_fun(*this,&MyGrid::go5));

}


void MyGrid::Page4(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);
    goPage3.set_label("Go back");
    goPage5.set_label("Next");
    this->attach(abilitiesLabel, 0,0,8,1);

    /******* Talents *******/

    this->attach(talentsLabel,0,1,2,1);
    this->attach(pointsTalents, 1,1,1,1);
    // add talents to the combobox and attach
    int yPos = 2;
    for(Gtk::ComboBoxText *gt : wList){
        this->attach(*gt, 0,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinListTalent){
        this->attach(*sp,1,yPos,1,1);
        yPos++;
    }

    this->attach(addTalent,0,yPos,1,1);
    /******* Skills *******/
    this->attach(pointsSkills,4,1,1,1);
    this->attach(skillsLabel, 3,1,2,1);
    yPos = 2;
    // add skills to the combobox and attach
    for(Gtk::ComboBoxText *gt : skillsList){
        this->attach(*gt, 3,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinListSkills){
        this->attach(*sp,4,yPos,1,1);
        yPos++;
    }

    this->attach(addSkills, 3,yPos,1,1);

    /******* Knowledges ******/
    this->attach(pointsKnowledges,7,1,1,1);
    this->attach(knowledgesLabel,6,1,2,1);
    yPos=2;
    for(Gtk::ComboBoxText *ct : knowledgesList){
        this->attach(*ct, 6,yPos,1,1);
        yPos++;
    }
    yPos = 2;
    for(Gtk::SpinButton *sp : spinListKnowledges){
        this->attach(*sp, 7,yPos,1,1);
        yPos++;
    }
    this->attach(addKnowledges,6,yPos,1,1);


    /**** extra ****/
    this->attach(vsep1, 2,1,1,10);
    this->attach(vsep2, 5,1,1,10);

    // Buttons
    this->attach(goPage3,0,25,1,1);

    this->attach(goPage5, 7,25,1,1);
    this->set_row_spacing(5);
    this->set_column_spacing(10);
    this->show_all();
}

void MyGrid::go5() {
    if (!checkRepartitionAbility()) {
        Gtk::MessageDialog d("Repartition error", false, Gtk::MESSAGE_INFO);
        d.set_secondary_text("Please put (13/9/5) points.");
        d.run();
    } else {
        if (!isSavedPage5) {
            initPage5();
            isSavedPage5 = true;
        }
        std::cout << comboClan.get_active_text();
        Page5();
    }
}


void MyGrid::initPage5() {
    pointsDiscipline.set_text("1");
    pointsBackground.set_text("1");
    pointsVirtue.set_text("0");
    advantageLabel.set_label("Advantages");
    disciplineLabel.set_label("Disciplines :");
    backgroundLabel.set_label("Background :");
    virtuesLabel.set_label("Virtues :");

    for(std::string di : Parser::getClanDiscipline(comboClan.get_active_text())){disciplineCombo.append(di);}
    disciplineCombo.set_active(0);
    disciplineSpin.set_increments(1,1);
    disciplineSpin.set_range(1,5);
    disciplineSpin.set_value(1);
    disciplineSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalDiscipline));
    disciplineList.push_back(&disciplineCombo);
    spinDisciplineList.push_back(&disciplineSpin);
    for(std::string ba : allBackgrounds){backgroundCombo.append(ba);}
    backgroundCombo.set_active(0);
    backgroundSpin.set_increments(1,1);
    backgroundSpin.set_range(1,5);
    backgroundSpin.set_value(1);
    backgroundSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalBackground));
    backgroundList.push_back(&backgroundCombo);
    spinBackgroundList.push_back(&backgroundSpin);

    conscienceLabel.set_label("Conscience :");
    instinctLabel.set_label("Instinct :");
    courageLabel.set_label("Courage :");

    virtueSpin1.set_range(1,5);
    virtueSpin1.set_value(1);
    virtueSpin1.set_increments(1,1);
    virtueSpin1.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalVirtue));
    virtueSpin2.set_range(1,5);
    virtueSpin2.set_value(1);
    virtueSpin2.set_increments(1,1);
    virtueSpin2.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalVirtue));
    virtueSpin3.set_range(1,5);
    virtueSpin3.set_value(1);
    virtueSpin3.set_increments(1,1);
    virtueSpin3.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalVirtue));


    addDisciplines.set_label("Add disciplines");
    signalConnectionDisciplineAdd = addDisciplines.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addDisciplineClicked));
    removeDisciplines.set_label("Remove disciplines");
    removeDisciplineSignal = removeDisciplines.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeDisciplineClicked));

    addBackgrounds.set_label("Add background");
    signalCBackgrounds = addBackgrounds.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addBackgroundClicked));
    removeBackgrounds.set_label("Remove background");
    removeBackgroundSignal=removeBackgrounds.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeBackgroundClicked));

    goPage4.set_label("Back");
    goPage6.set_label("Next");
    goPage6.signal_clicked().connect(sigc::mem_fun(*this,
                                                   &MyGrid::goFreebiePage));
}


void MyGrid::Page5(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);
    // if clan has changed delete previous discipline
    if (selectedClan!=comboClan.get_active_text()){
        disciplineCombo.remove_all();
        disciplineList.clear();
        spinDisciplineList.clear();
        for(std::string di : Parser::getClanDiscipline(comboClan.get_active_text())){disciplineCombo.append(di);}
        disciplineCombo.set_active(0);
        disciplineCombo.set_sensitive(true);
        disciplineList.push_back(&disciplineCombo);
        disciplineSpin.set_value(1);
        spinDisciplineList.push_back(&disciplineSpin);
        disciplineClicked=0;
    }

    selectedClan = comboClan.get_active_text();
    goPage4.set_label("Back");
    goPage6.set_label("Next");
    this->attach(vsep3, 3,1,1,3);
    this->attach(vsep4, 6,1,1,3);

    // layout first row of label
    this->attach(advantageLabel,0,0,8,1);
    this->attach(pointsDiscipline,1,1,1,1);
    this->attach(disciplineLabel,0,1, 2,1);
    this->attach(backgroundLabel,4,1,2,1);
    this->attach(pointsBackground, 5,1,1,1);
    this->attach(virtuesLabel,7,1,1,1);
    this->attach(pointsVirtue,8,1,1,1);
    // add the combobox/spin
    int yPos = 2;
    for(Gtk::ComboBoxText *ct : disciplineList){
        this->attach(*ct,0,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinDisciplineList){
        this->attach(*sp, 1,yPos,1,1);
        yPos++;
    }
    // attach add discipline only if they are more disciplines
    if(disciplineList.size()!=Parser::getClanDiscipline(selectedClan).size()){
        this->attach(addDisciplines,0,yPos,1,1);
    }
    // attach remove discipline if they are more than one discipline displayed
    if(disciplineList.size()>1){this->attach(removeDisciplines,1,yPos,1,1);}
    yPos=2;
    for(Gtk::ComboBoxText *ct : backgroundList){
        this->attach(*ct, 4,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinBackgroundList){
        this->attach(*sp,5,yPos,1,1);
        yPos++;
    }
    this->attach(addBackgrounds, 4,3,1,1);

    // virtue

    this->attach(conscienceLabel, 7,2,1,1),
    this->attach(instinctLabel, 7,3,1,1);
    this->attach(courageLabel,7,4,1,1);

    this->attach(virtueSpin1,8,2,1,1);
    this->attach(virtueSpin2,8,3,1,1);
    this->attach(virtueSpin3,8,4,1,1);

    // buttons

//
//    advantagesImage.set("/home/hugo/Pictures/advantages.png");
//    this->attach(advantagesImage,0,10,7,1);

    this->attach(goPage4,0,30,1,1);


    this->attach(goPage6, 8,30,1,1);

    this->show_all();
}

void MyGrid::goFreebiePage(){
    if(!checkRepartitionAbilities()){
        Gtk::MessageDialog d("Repartition error", false, Gtk::MESSAGE_INFO);
      d.set_secondary_text("Please put 3 points in disciplines, 5 in backgrounds and 7 in virtues.");
       d.run();
    }else{
        initFreebie();
    }
}

void MyGrid::initFreebie() {
    // Set previous user choice as minimum value of Freebie, record nonFreebie repartition
    strengthSpin.set_range(strengthSpin.get_value(), 9);
    lastStrength = strengthSpin.get_value_as_int();
    strengthSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addStrengthCost));
    strengthSaved = strengthSpin.get_value();

    dexteritySpin.set_range(dexteritySpin.get_value(), 9);
    dexteritySpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addDexterityCost));
    lastDexterity = dexteritySpin.get_value_as_int();


    staminaSpin.set_range(staminaSpin.get_value(), 9);
    staminaSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addStaminaCost));
    lastStamina = staminaSpin.get_value_as_int();

    charismaSpin.set_range(charismaSpin.get_value(), 9);
    charismaSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addCharismaCost));
    lastCharisma = charismaSpin.get_value_as_int();

    manipulationSpin.set_range(manipulationSpin.get_value(), 9);
    manipulationSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addManipulationCost));
    lastManipulation = manipulationSpin.get_value_as_int();

    appearanceSpin.set_range(appearanceSpin.get_value(), 9);
    appearanceSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addAppearanceCost));
    lastAppearance = appearanceSpin.get_value_as_int();

    perceptionSpin.set_range(perceptionSpin.get_value(), 9);
    perceptionSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addPerceptionCost));
    lastPerception = perceptionSpin.get_value_as_int();

    intelligenceSpin.set_range(intelligenceSpin.get_value(), 9);
    intelligenceSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addIntelligenceCost));
    lastIntelligence = intelligenceSpin.get_value_as_int();

    witsSpin.set_range(witsSpin.get_value(), 9);
    witsSpin.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addWitsCost));
    lastWits = witsSpin.get_value_as_int();

    virtueSpin1.set_range(virtueSpin1.get_value(), 5);
    lastVirtue1 = virtueSpin1.get_value_as_int();
    virtueSpin1.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addVirtue1Cost));
    virtueSpin2.set_range(virtueSpin2.get_value(), 5);
    lastVirtue2 = virtueSpin2.get_value_as_int();
    virtueSpin2.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addVirtue2Cost));
    virtueSpin3.set_range(virtueSpin3.get_value(), 5);
    lastVirtue3 = virtueSpin3.get_value_as_int();
    virtueSpin3.signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addVirtue3Cost));

    /** Abilities ***/
    for(Gtk::SpinButton *sp : spinListTalent){
        lastSumTalents += sp->get_value_as_int();
        sp->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addTalentsCost));
        sp->set_range(sp->get_value(), 9);
    }


    for(Gtk::SpinButton *sp : spinListSkills){
        lastSumSkills += sp->get_value_as_int();
        sp->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addSkillsCost));
        sp->set_range(sp->get_value(), 9);
    }


    for(Gtk::SpinButton *sp : spinListKnowledges){
        lastSumKnowledge += sp->get_value_as_int();
        sp->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addKnowledgesCost));
        sp->set_range(sp->get_value(), 9);
    }

    for(Gtk::SpinButton *sp : spinDisciplineList){
        lastSumDiscipline += sp->get_value_as_int();
        sp->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addDisciplineCost));
        sp->set_range(sp->get_value(), 9);
    }

    for(Gtk::SpinButton *sp : spinBackgroundList){
        lastSumBackground += sp->get_value_as_int();
        sp->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addBackgroundsCost));
        sp->set_range(sp->get_value(), 9);
    }

    // Rebinding of add elements and remove elements button
    talentChoiceCount = wList.size();
    signalTalent.disconnect();
    addTalent.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addFreebieTalent));
    removeTalentSignal.disconnect();
    removeTalent.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeFreebieTalent));

    skillChoiceCount = skillsList.size();
    signalSkill.disconnect();
    addSkills.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addFreebieSkills));
    removeSkillSignal.disconnect();
    removeSkills.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeFreebieSkills));

    knowledgeChoiceCount = knowledgesList.size();
    signalKnowledges.disconnect();
    addKnowledges.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addFreebieKnowledges));
    removeKnowledegeSignal.disconnect();
    removeKnowledges.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeFreebieKnowledges));

    disciplineChoiceCount = disciplineList.size();
    signalConnectionDisciplineAdd.disconnect();
    addDisciplines.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addFreebieDiscipline));
    removeDisciplineSignal.disconnect();
    removeDisciplines.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeFreebieDiscipline));

    backgroundChoiceCount = backgroundList.size();
    signalCBackgrounds.disconnect();
    addBackgrounds.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addFreebieBackgrounds));
    removeBackgroundSignal.disconnect();
    removeBackgrounds.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeFreebieBackgrounds));
    goFinal.set_label("Generate PDF");
    goFinal.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::Page6));
    totalPointsFreebie.set_label("Remaining points : ");
    totalsPointsValueFreebie.set_label("15");
    FreebiePage();
}

void MyGrid::FreebiePage(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);


    /***** Attributes ******/
    freebieLabel.set_label("Freebie points");
    this->attach(totalPointsFreebie,4,0,1,1);
    this->attach(totalsPointsValueFreebie,6,0,1,1);
    this->attach(freebieLabel, 0,0,2,1);

    // Physical
    this->attach(physicalLabel, 0,1,2,1);
    //strength
    this->attach(strengthLabel,0,2,1,1);
    this->attach(strengthSpin,1,2,1,1);
    // dexterity
    this->attach(dexterityLabel, 0,3,1,1);
    this->attach(dexteritySpin, 1,3,1,1);
    // stamina
    this->attach(staminaLabel, 0,4,1,1);
    this->attach(staminaSpin, 1,4,1,1);
    // // Social
    this->attach(socialLabel,2,1,2,1);
    // Charisma
    this->attach(charismaLabel, 2,2,1,1);
    this->attach(charismaSpin, 3,2,1,1);
    // Manipulation
    this->attach(manipulationLabel, 2,3,1,1);
    this->attach(manipulationSpin, 3,3,1,1);
    // Appearance
    this->attach(appearanceLabel, 2,4,1,1);
    this->attach(appearanceSpin, 3,4,1,1);
    // // Mental
    this->attach(mentalLabel, 4,1,2,1);
    // Perception
    this->attach(perceptionLabel, 4,2,1,1);
    this->attach(perceptionSpin, 5,2,1,1);
    // intelligence
    this->attach(intelligenceLabel,4,3,1,1);
    this->attach(intelligenceSpin,5,3,1,1);
    //wits
    this->attach(witsLabel, 4,4,1,1);
    this->attach(witsSpin, 5,4,1,1);

    this->attach(conscienceLabel, 7,2,1,1),
    this->attach(instinctLabel, 7,3,1,1);
    this->attach(courageLabel,7,4,1,1);

    this->attach(virtuesLabel,7,1,1,1);
    this->attach(virtueSpin1,8,2,1,1);
    this->attach(virtueSpin2,8,3,1,1);
    this->attach(virtueSpin3,8,4,1,1);


    this->attach(hsep1, 0, 6, 10, 1);

    /**** abilities ****/
    this->attach(abilitiesLabel, 0,7,8,1);

    /******* Talents *******/

    this->frameAbilities.attach(talentsLabel,0,1,2,1);
    // add talents to the combobox and attach
    int yPos = 2;
    for(Gtk::ComboBoxText *gt : wList){
        gt->set_sensitive(false);
        this->frameAbilities.attach(*gt, 0,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinListTalent){
        this->frameAbilities.attach(*sp,1,yPos,1,1);
        yPos++;
    }

    this->frameAbilities.attach(addTalent,0,yPos,1,1);
    /******* Skills *******/
    this->frameAbilities.attach(skillsLabel, 3,1,2,1);
    yPos = 2;
    // add skills to the combobox and attach
    for(Gtk::ComboBoxText *gt : skillsList){
        gt->set_sensitive(false);
        this->frameAbilities.attach(*gt, 3,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinListSkills){
        this->frameAbilities.attach(*sp,4,yPos,1,1);
        yPos++;
    }

    this->frameAbilities.attach(addSkills, 3,yPos,1,1);

    /******* Knowledges ******/
    this->frameAbilities.attach(knowledgesLabel,6,1,2,1);
    yPos=2;
    for(Gtk::ComboBoxText *ct : knowledgesList){
        ct->set_sensitive(false);
        this->frameAbilities.attach(*ct, 6,yPos,1,1);
        yPos++;
    }
    yPos = 2;
    for(Gtk::SpinButton *sp : spinListKnowledges){
        this->frameAbilities.attach(*sp, 7,yPos,1,1);
        yPos++;
    }
    this->frameAbilities.attach(addKnowledges,6,yPos,1,1);

    scrolledAbilities.add(frameAbilities);
    scrolledAbilities.set_min_content_height(250);
    this->attach(scrolledAbilities, 0,20,10,10);
    /***** Advanatges *****/


    // layout first row of label
    this->frameAdvantages.attach(advantageLabel,0,0,8,1);

    this->frameAdvantages.attach(disciplineLabel,0,1, 2,1);
    this->frameAdvantages.attach(backgroundLabel,4,1,2,1);
    this->frameAdvantages.attach(virtuesLabel,7,1,1,1);

    // add the combobox/spin
    yPos = 2;
    for(Gtk::ComboBoxText *ct : disciplineList){
        ct->set_sensitive(false);
        this->frameAdvantages.attach(*ct,0,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinDisciplineList){
        this->frameAdvantages.attach(*sp, 1,yPos,1,1);
        yPos++;
    }
    // attach add discipline only if they are more disciplines
    if(disciplineList.size()!=allDisciplines.size()){
        this->frameAdvantages.attach(addDisciplines,0,yPos,1,1);
    }

    //if(disciplineList.size()>1){this->attach(removeDisciplines,1,yPos,1,1);}
    yPos=2;
    for(Gtk::ComboBoxText *ct : backgroundList){
        ct->set_sensitive(false);
        this->frameAdvantages.attach(*ct, 4,yPos,1,1);
        yPos++;
    }
    yPos=2;
    for(Gtk::SpinButton *sp : spinBackgroundList){
        this->frameAdvantages.attach(*sp,5,yPos,1,1);
        yPos++;
    }
    this->frameAdvantages.attach(addBackgrounds, 4,yPos,1,1);

    scrolledAdvantages.add(frameAdvantages);
    scrolledAdvantages.set_min_content_height(250);

    this->attach(scrolledAdvantages, 0,40,10,1);

    this->attach(goFinal,8,50,1,1);
    // This packs the button into the Window (a container);
    this->show_all();
}

void MyGrid::Page6(){
    generateCh();
    pdf.setCh(cr.getCharacter());
    cr.getCharacter().talk();
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);

    //moreImage.set("/home/hugo/Pictures/more.png");

    goPage5.set_label("Back");
    this->attach(goPage5,0,10,1,1);
    pdf.set_size_request(768,946);

    scrolledForDescription.add(pdf);
    scrolledForDescription.set_size_request(768,600);
    this->attach(scrolledForDescription, 0,1,3,1);
    save.set_label("Save");

     this->attach(save,2,10,1,1) ;
    //this->attach(moreImage,10,10,1,1);

    //scrolledForDescription.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    //scrolledForDescription.add(textViewDescription);
    //textViewDescription.set_buffer(bufferDescription);

    //this->attach(scrolledForDescription,1,1,10,10);
    //this->attach(pdf, 10,10,10,10);
    this->show_all();
}


void MyGrid::FinalPage(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);



}







