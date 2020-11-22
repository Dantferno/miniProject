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
    myfont.set_size(15000);
    myfont.set_family("Arial");
    this->set_row_spacing(10);
    Page1();
}

void MyGrid::Page1(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);
    nextButton.override_font(myfont);
    nextButton.set_label("Create new character.");
    nextButton.signal_clicked().connect(sigc::mem_fun(*this,
                                                      &MyGrid::Page2));

    //coverVampire.set("/home/hugo/Pictures/covervampire.png");

    message.set_label("Welcome on the Vampire creation interface.");
    message.override_font(myfont);
    this->attach(message, 0, 0, 1, 1);
    //this->attach(coverVampire,0,1,1,1);
    nextButton.set_size_request(100,50);
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
    comboClan.append("None");
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

    if (!isSavedPage2) {
        isSavedPage2 = true;
        initPage3();
    }
    comboNature.set_active_text(comboNature.get_active_text());
    Page3();
}

void MyGrid::InitializeCr(){
//    cr.StepZero(nameEntry.get_text(),playerEntry.get_text(), chronicleEntry.get_text(), generationEntry.get_text(), sirEntry.get_text());
//
//    cr.StepOne(conceptEntry.get_text(), comboClan.get_active_text(), comboNature.get_active_text(), comboDemeanor.get_active_text());
//    cr.getCharacter().talk();
    //Page3();
}

void MyGrid::initPage3(){
    /***** Attributes ******/
    attributesLabel.set_text("Attributes");
    physicalLabel.set_text("Physical");
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
    //if (checkCorrectRepartition()==1){ // if repartition is not correct
     //   Gtk::MessageDialog d("Repartition error", false, Gtk::MESSAGE_INFO);
      //  d.set_secondary_text("Please put the points (7/5/3)");
      //  d.run();
    //}else {
/*        Attributes attri;
        attri.setPhysical(strengthSpin.get_value_as_int(), dexteritySpin.get_value_as_int(),
                          staminaSpin.get_value_as_int());
        attri.setSocial(charismaSpin.get_value_as_int(), manipulationSpin.get_value_as_int(),
                        appearanceSpin.get_value_as_int());
        attri.setMental(perceptionSpin.get_value_as_int(), intelligenceSpin.get_value_as_int(),
                        witsSpin.get_value_as_int());
        cr.StepTwo(attri);
        cr.getCharacter().talk();*/
if (!isSavedPage3){initPage4();isSavedPage3=true;}
        Page4();
    //}
}

void MyGrid::removeTalentClicked(){
    talentClicked--;
    this->remove(addTalent);
    this->remove(removeTalent);
    this->remove(*wList.back());
    this->remove(*spinListTalent.back());
    wList.pop_back();
    std::cout << "Wlist :" << wList.size() << std::endl;
    spinListTalent.pop_back();
    if (talentClicked >=1){

        this->attach(addTalent, 0, 3+talentClicked,1,1);
        this->attach(removeTalent,1, 3+talentClicked,1,1);
    }else{
        this->attach(addTalent, 0, 3+talentClicked,1,1);
    }

    this->show_all();
}

void MyGrid::addTalentClicked(){
    // increase talentClicked to update the positions
    talentClicked ++;
    std::cout << "Talent clicked" << talentClicked << std::endl;
    // remove the add button
    this->remove(addTalent);
    this->remove(removeTalent);
    // add a combobox and spinbox
    Gtk::ComboBoxText *addedP = new Gtk::ComboBoxText;
    Gtk::SpinButton *addedSpinP = new Gtk::SpinButton;
    // configure them

    // Copy allTalents but pop back talents selected in another combobox
    std::vector<std::string> availableTalents;
    for(std::string talent : allTalents){
        availableTalents.push_back(talent);
        for (Gtk::ComboBoxText *c : wList){
            if(c->get_active_text().raw() == talent){
                availableTalents.pop_back();
            }
        }
    }
    // if no more talents are available, don't reattach the "add" button
    if(availableTalents.size() >= 2){
        this->attach(addTalent, 0, 3+talentClicked,1,1);
    }
    // add Available talents to the combobox
    for(std::string talent : availableTalents){
        addedP->append(talent);
    }

    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    // store them in vectors
    wList.push_back(addedP);
    spinListTalent.push_back(addedSpinP);
    // add remove Talent button (configured in Page4)

    this->attach(removeTalent,1, 3+talentClicked,1,1);
    // attach and show
    this->attach(*addedP,0,2+talentClicked,1,1);
    this->attach(*addedSpinP, 1,2+talentClicked,1,1);
    this->show_all();
}


void MyGrid::initPage4(){
    abilitiesLabel.set_text("Abilities");
    talentsLabel.set_text("Talents :");
    for(std::string talent : allTalents){talentsCombo.append(talent);}
    talentsCombo.set_active(0);

    wList.push_back(&talentsCombo);
    talentsSpin.set_range(1,3);
    talentsSpin.set_value(1);
    talentsSpin.set_increments(1,1);
    spinListTalent.push_back(&talentsSpin);

    addTalent.set_label("Add talent");
    addTalent.signal_clicked().connect(sigc::mem_fun(*this,
                                                     &MyGrid::addTalentClicked));

    // configure remove talent button but don't display it yet
    removeTalent.set_label("Remove talent");
    removeTalent.signal_clicked().connect(sigc::mem_fun(*this,
                                                        &MyGrid::removeTalentClicked));

    skillsLabel.set_label("Skills :");
    for(std::string skill : allSkills){skillsCombo.append(skill);}
    skillsCombo.set_active(0);

    skillsList.push_back(&skillsCombo);
    skillsSpin.set_range(1,3);
    skillsSpin.set_value(1);
    skillsSpin.set_increments(1,1);

    spinListSkills.push_back(&skillsSpin);

    addSkills.set_label("Add skill");
    addSkills.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addSkillsClicked));
    removeSkills.set_label("Remove skill");
    removeSkills.signal_clicked().connect(sigc::mem_fun(*this,
                                                        &MyGrid::removeSkillsClicked));

    knowledgesLabel.set_label("Knowledges :");
    for(std::string know : allKnowledges){knowledgesCombo.append(know);}
    knowledgesCombo.set_active(0);

    knowledgesList.push_back(&knowledgesCombo);
    knowledgesSpin.set_range(1,3);
    knowledgesSpin.set_value(1);
    knowledgesSpin.set_increments(1,1);
    spinListKnowledges.push_back(&knowledgesSpin);

    addKnowledges.set_label("Add knowledge");
    addKnowledges.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addKnowledgesClicked));

    removeKnowledges.set_label("Remove knowledge");
    removeKnowledges.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeKnowledgesClicked));

    goPage3.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::Page3));
    goPage3.set_label("Go back");
    goPage5.set_label("Next");
    goPage5.signal_clicked().connect(sigc::mem_fun(*this,&MyGrid::Page5));

}


void MyGrid::Page4(){
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);

    this->attach(abilitiesLabel, 0,0,8,1);

    /******* Talents *******/

    this->attach(talentsLabel,0,1,2,1);
    // add talents to the combobox and attach
    this->attach(talentsCombo, 0,2,1,1);

    this->attach(talentsSpin,1,2,1,1);

    this->attach(addTalent,0,3,1,1);
    /******* Skills *******/
    this->attach(skillsLabel, 3,1,2,1);
    // add skills to the combobox and attach
    this->attach(skillsCombo, 3,2,1,1);


    this->attach(skillsSpin,4,2,1,1);

    this->attach(addSkills, 3,3,1,1);

    /******* Knowledges ******/
    this->attach(knowledgesLabel,6,1,2,1);

    this->attach(knowledgesCombo, 6,2,1,1);

    this->attach(knowledgesSpin, 7,2,1,1);
    this->attach(addKnowledges,6,3,1,1);


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

void MyGrid::Page5(){
    for(Gtk::ComboBoxText *a: wList){
        std::cout << a->get_active_text() << std::endl;
    }
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);

    this->attach(vsep3, 3,1,1,3);
    this->attach(vsep4, 6,1,1,3);

    // layout first row of label
    advantageLabel.set_label("Advantages");
    this->attach(advantageLabel,0,0,8,1);
    disciplineLabel.set_label("Disciplines :");
    this->attach(disciplineLabel,0,1, 2,1);
    backgroundLabel.set_label("Background :");
    this->attach(backgroundLabel,4,1,2,1);
    virtuesLabel.set_label("Virtues :");
    this->attach(virtuesLabel,7,1,1,1);

    // add the combobox/spin
    for(std::string di : allDisciplines){disciplineCombo.append(di);}
    disciplineCombo.set_active(0);
    disciplineSpin.set_increments(1,1);
    disciplineSpin.set_range(1,5);
    disciplineSpin.set_value(1);
    disciplineList.push_back(&disciplineCombo);
    spinDisciplineList.push_back(&disciplineSpin);
    for(std::string ba : allBackgrounds){backgroundCombo.append(ba);}
    backgroundCombo.set_active(0);
    backgroundSpin.set_increments(1,1);
    backgroundSpin.set_range(1,5);
    backgroundSpin.set_value(1);
    backgroundList.push_back(&backgroundCombo);
    spinBackgroundList.push_back(&backgroundSpin);
    this->attach(disciplineCombo,0,2,1,1);
    this->attach(disciplineSpin, 1,2,1,1);
    this->attach(backgroundCombo, 4,2,1,1);
    this->attach(backgroundSpin,5,2,1,1);

    // virtue
    conscienceLabel.set_label("Conscience :");
    instinctLabel.set_label("Instinct :");
    courageLabel.set_label("Courage :");
    this->attach(conscienceLabel, 7,2,1,1),
    this->attach(instinctLabel, 7,3,1,1);
    this->attach(courageLabel,7,4,1,1);
    virtueSpin1.set_range(1,5);
    virtueSpin1.set_value(1);
    virtueSpin1.set_increments(1,1);
    virtueSpin2.set_range(1,5);
    virtueSpin2.set_value(1);
    virtueSpin2.set_increments(1,1);
    virtueSpin3.set_range(1,5);
    virtueSpin3.set_value(1);
    virtueSpin3.set_increments(1,1);
    this->attach(virtueSpin1,8,2,1,1);
    this->attach(virtueSpin2,8,3,1,1);
    this->attach(virtueSpin3,8,4,1,1);

    // buttons
    addDisciplines.set_label("Add disciplines");
    addDisciplines.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addDisciplineClicked));
    removeDisciplines.set_label("Remove disciplines");
    removeDisciplines.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeDisciplineClicked));
    this->attach(addDisciplines,0,3,1,1);
    addBackgrounds.set_label("Add background");
    addBackgrounds.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::addBackgroundClicked));
    removeBackgrounds.set_label("Remove background");
    removeBackgrounds.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::removeBackgroundClicked));
    this->attach(addBackgrounds, 4,3,1,1);
//
//    advantagesImage.set("/home/hugo/Pictures/advantages.png");
//    this->attach(advantagesImage,0,10,7,1);

    goPage4.set_label("Back");
    this->attach(goPage4,0,30,1,1);

    goPage6.set_label("Next");
    goPage6.signal_clicked().connect(sigc::mem_fun(*this,
                                                   &MyGrid::Page6));
    this->attach(goPage6, 8,30,1,1);

    this->show_all();
}

void MyGrid::Page6(){
    cr.StepZero(nameEntry.get_text(),playerEntry.get_text(), chronicleEntry.get_text(), generationEntry.get_text(), sirEntry.get_text());
    cr.StepOne(conceptEntry.get_text(), comboClan.get_active_text(), comboNature.get_active_text(), comboDemeanor.get_active_text());
    Attributes attri;
    attri.setPhysical(3,3,1);
    attri.setSocial(2,2,1);
    attri.setMental(1,1,1);
    cr.StepTwo();
    pdf.setCh(cr.getCharacter());
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
    save.set_label("Save")                          ;
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


void MyGrid::changeTotalMental(){
   int spin1, spin2, spin3;
   spin1 = std::stoi(perceptionSpin.get_text().raw());
   spin2 = std::stoi(intelligenceSpin.get_text().raw());
   spin3 = std::stoi(witsSpin.get_text().raw());
   std::string newTotal = std::to_string(spin1 + spin2 + spin3-3);
   totalPointSocial.set_text(newTotal);
}

void MyGrid::changeTotalSocial() {
    int spin4, spin5, spin6;
    spin4 = std::stoi(charismaSpin.get_text().raw());
    spin5 = std::stoi(manipulationSpin.get_text().raw());
    spin6 = std::stoi(appearanceSpin.get_text().raw());
    std::string newTotalMental = std::to_string(spin4 + spin5 + spin6-3);
    totalPointMental.set_text(newTotalMental);
}


void MyGrid::changeTotalPhysical() {
    int spin7, spin8, spin9;
    spin7 = std::stoi(strengthSpin.get_text().raw());
    spin8 = std::stoi(dexteritySpin.get_text().raw());
    spin9 = std::stoi(staminaSpin.get_text().raw());
    std::string newTotalPhysical = std::to_string(spin7 + spin8 + spin9-3);
    totalPointPhysical.set_text(newTotalPhysical);

}

int MyGrid::checkCorrectRepartition(){
    int tot1, tot2, tot3;
    std::vector<int> values;
    tot1 = std::stoi(totalPointPhysical.get_text().raw());
    tot2 = std::stoi(totalPointSocial.get_text().raw());
    tot3 = std::stoi(totalPointMental.get_text().raw());
    values.push_back(tot1);values.push_back(tot2); values.push_back(tot3);
    int key1(7), key2(5), key3(3);
    if (std::count(values.begin(), values.end(), key1)
    && std::count(values.begin(), values.end(), key2)
    && std::count(values.begin(), values.end(), key3))
    {
        return 0;
    }else{return 1;}
}

void MyGrid::addSkillsClicked() {
// increase skillClicked to update the positions
    skillClicked ++;
    // remove the add button
    this->remove(addSkills);
    this->remove(removeSkills);
    // add a combobox and spinbox
    Gtk::ComboBoxText *addedP = new Gtk::ComboBoxText;
    Gtk::SpinButton *addedSpinP = new Gtk::SpinButton;
    // configure them

    // Copy allSkills but pop back talents selected in another combobox
    std::vector<std::string> availableSkills;
    for(std::string skill : allSkills){
        availableSkills.push_back(skill);
        for (Gtk::ComboBoxText *c : skillsList){
            if(c->get_active_text().raw() == skill){
                availableSkills.pop_back();
            }
        }
    }
    // if no more skill are available, don't reattach the "add" button
    if(availableSkills.size() >= 2){
        this->attach(addSkills, 3, 3+skillClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string skill : availableSkills){
        addedP->append(skill);
    }

    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    // store them in vectors
    skillsList.push_back(addedP);
    spinListSkills.push_back(addedSpinP);
    // add remove skill button (configured in Page4)

    this->attach(removeSkills,4, 3+skillClicked,1,1);
    // attach and show
    this->attach(*addedP,3,2+skillClicked,1,1);
    this->attach(*addedSpinP, 4,2+skillClicked,1,1);
    this->show_all();
}
void MyGrid::removeSkillsClicked() {
    skillClicked--;
    this->remove(addSkills);
    this->remove(removeSkills);
    this->remove(*skillsList.back());
    this->remove(*spinListSkills.back());
    skillsList.pop_back();
    spinListSkills.pop_back();
    if (skillClicked >=1){

        this->attach(addSkills, 3, 3+skillClicked,1,1);
        this->attach(removeSkills,4, 3+skillClicked,1,1);
    }else{
        this->attach(addSkills, 3, 3+skillClicked,1,1);
    }

    this->show_all();
}

void MyGrid::addKnowledgesClicked() {
    knowledgeClicked ++;
    // remove the add button
    this->remove(addKnowledges);
    this->remove(removeKnowledges);
    // add a combobox and spinbox
    Gtk::ComboBoxText *addedP = new Gtk::ComboBoxText;
    Gtk::SpinButton *addedSpinP = new Gtk::SpinButton;
    // configure them

    // Copy allSkills but pop back talents selected in another combobox
    std::vector<std::string> availableKnowledges;
    for(std::string know : allKnowledges){
        availableKnowledges.push_back(know);
        for (Gtk::ComboBoxText *c : knowledgesList){
            if(c->get_active_text().raw() == know){
                availableKnowledges.pop_back();
            }
        }
    }
    // if no more skill are available, don't reattach the "add" button
    if(availableKnowledges.size() >= 2){
        this->attach(addKnowledges, 6, 3+knowledgeClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string know : availableKnowledges){
        addedP->append(know);
    }

    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    // store them in vectors
    knowledgesList.push_back(addedP);
    spinListKnowledges.push_back(addedSpinP);
    // add remove skill button (configured in Page4)

    this->attach(removeKnowledges,7, 3+knowledgeClicked,1,1);
    // attach and show
    this->attach(*addedP,6,2+knowledgeClicked,1,1);
    this->attach(*addedSpinP, 7,2+knowledgeClicked,1,1);
    this->show_all();
}

/**
 * executed upon clicking on "remove Knowledges" button.
 * Remove last spinKnowledge and combobox and re attach the
 */
void MyGrid::removeKnowledgesClicked() {
    knowledgeClicked--;
    this->remove(addKnowledges);
    this->remove(removeKnowledges);
    this->remove(*knowledgesList.back());
    this->remove(*spinListKnowledges.back());
    knowledgesList.pop_back();
    spinListKnowledges.pop_back();
    if (knowledgeClicked >=1){

        this->attach(addKnowledges, 6, 3+knowledgeClicked,1,1);
        this->attach(removeKnowledges,7, 3+knowledgeClicked,1,1);
    }else{
        this->attach(addKnowledges, 6, 3+knowledgeClicked,1,1);
    }

    this->show_all();
}

void MyGrid::addBackgroundClicked() {
    backgroundClicked ++;
    // remove the add button
    this->remove(addBackgrounds);
    this->remove(removeBackgrounds);
    // add a combobox and spinbox
    Gtk::ComboBoxText *addedP = new Gtk::ComboBoxText;
    Gtk::SpinButton *addedSpinP = new Gtk::SpinButton;
    // configure them

    // Copy allSkills but pop back talents selected in another combobox
    std::vector<std::string> availableBackgrounds;
    for(std::string bac : allBackgrounds){
        availableBackgrounds.push_back(bac);
        for (Gtk::ComboBoxText *c : backgroundList){
            if(c->get_active_text().raw() == bac){
                availableBackgrounds.pop_back();
            }
        }
    }
    // if no more skill are available, don't reattach the "add" button
    if(availableBackgrounds.size() >= 2){
        this->attach(addBackgrounds, 4, 3+backgroundClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string ba : availableBackgrounds){
        addedP->append(ba);
    }

    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    // store them in vectors
    backgroundList.push_back(addedP);
    spinBackgroundList.push_back(addedSpinP);
    // add remove skill button (configured in Page4)

    this->attach(removeBackgrounds,5, 3+backgroundClicked,1,1);
    // attach and show
    this->attach(*addedP,4,2+backgroundClicked,1,1);
    this->attach(*addedSpinP, 5,2+backgroundClicked,1,1);
    this->show_all();
}


void MyGrid::addDisciplineClicked() {
    disciplineClicked ++;
    // remove the add button
    this->remove(addDisciplines);
    this->remove(removeDisciplines);
    // add a combobox and spinbox
    Gtk::ComboBoxText *addedP = new Gtk::ComboBoxText;
    Gtk::SpinButton *addedSpinP = new Gtk::SpinButton;
    // configure them

    // Copy allSkills but pop back talents selected in another combobox
    std::vector<std::string> availableDisciplines;
    for(std::string bac : allDisciplines){
        availableDisciplines.push_back(bac);
        for (Gtk::ComboBoxText *c : disciplineList){
            if(c->get_active_text().raw() == bac){
                availableDisciplines.pop_back();
            }
        }
    }
    // if no more skill are available, don't reattach the "add" button
    if(availableDisciplines.size() >= 2){
        this->attach(addDisciplines, 0, 3+disciplineClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string ba : availableDisciplines){
        addedP->append(ba);
    }

    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    // store them in vectors
    disciplineList.push_back(addedP);
    spinDisciplineList.push_back(addedSpinP);
    // add remove skill button (configured in Page4)

    this->attach(removeDisciplines,1, 3+disciplineClicked,1,1);
    // attach and show
    this->attach(*addedP,0,2+disciplineClicked,1,1);
    this->attach(*addedSpinP, 1,2+disciplineClicked,1,1);
    this->show_all();
}

void MyGrid::removeBackgroundClicked() {
    backgroundClicked--;
    this->remove(addBackgrounds);
    this->remove(removeBackgrounds);
    this->remove(*backgroundList.back());
    this->remove(*spinBackgroundList.back());
    backgroundList.pop_back();
    spinBackgroundList.pop_back();
    if (backgroundClicked >=1){
        this->attach(addBackgrounds, 4, 3+backgroundClicked,1,1);
        this->attach(removeBackgrounds,5, 3+backgroundClicked,1,1);
    }else{
        this->attach(addBackgrounds, 4, 3+backgroundClicked,1,1);
    }

    this->show_all();
}


void MyGrid::removeDisciplineClicked() {
    disciplineClicked--;
    this->remove(addDisciplines);
    this->remove(removeDisciplines);
    this->remove(*disciplineList.back());
    this->remove(*spinDisciplineList.back());
    disciplineList.pop_back();
    spinDisciplineList.pop_back();
    if (disciplineClicked >=1){

        this->attach(addDisciplines, 0, 3+disciplineClicked,1,1);
        this->attach(removeDisciplines,1, 3+disciplineClicked,1,1);
    }else{
        this->attach(addDisciplines, 0, 3+disciplineClicked,1,1);
    }

    this->show_all();
}




DrawPDF::DrawPDF(){};
DrawPDF::~DrawPDF(){};

bool DrawPDF::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
    // the center of the window
    //cr->scale(width, heig
    Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("/home/hugo/Pictures/testpdf.png");
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // Draw the image in the middle of the drawing area, or (if the image is
    // larger than the drawing area) draw the middle part of the image.
    Gdk::Cairo::set_source_pixbuf(cr, image,
                                  (width - image->get_width())/2, (height - image->get_height())/2);
    cr->paint();

    cr->set_source_rgb( 0.1, 0.1, 0.1);
    cr->set_font_size(10);

    // nom
    cr->move_to(118,137);
    cr->show_text(ch.getBackground().getName());

    // player
    cr->move_to(121,158);
    cr->show_text(ch.getBackground().getPlayer());
    cr->save();

    // Chronicle
    cr->move_to(144,177);
    cr->show_text(ch.getBackground().getChronicle());

    // Nature
    cr->move_to(336,137);
    cr->show_text("");

    // Demeanor
    cr->move_to(354,157);
    cr->show_text("Test nom ");

    // Concept
    cr->move_to(344,177);
    cr->show_text(ch.getBackground().getConcept());

    // Clan
    cr->move_to(530,137);
    cr->show_text(ch.getBackground().getClan());

    // Generation
    cr->move_to(568,156);
    cr->show_text(ch.getBackground().getGeneration());

    // Sire
    cr->move_to(528,176);
    cr->show_text(ch.getBackground().getSire());

    return Widget::on_draw(cr);
}

void DrawPDF::setCh(Character ch) {
    this->ch = ch;
}
