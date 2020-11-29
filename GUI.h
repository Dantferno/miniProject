//
// Created by hugo on 25/10/20.
//

#ifndef MINIPROJECT_GUI_H
#define MINIPROJECT_GUI_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/listbox.h>
#include <gtkmm/image.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/spinbutton.h>
#include "characterClass.h"
#include <pangomm.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/separator.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/filechooserdialog.h>

class CustomSpinButton: public Gtk::SpinButton{
public:

};


class DrawPDF : public Gtk::DrawingArea
{
public:
    DrawPDF();
    virtual ~DrawPDF();
    void setCh(Character);

protected:
    //Override default signal handler:
    void fillPlayerInfo(const Cairo::RefPtr<Cairo::Context>& cr);
    void fillAttributes(const Cairo::RefPtr<Cairo::Context>& cr);
    void fillAbilities(const Cairo::RefPtr<Cairo::Context>& cr);
    void fillAdvantages(const Cairo::RefPtr<Cairo::Context>& cr);
    void fillRest(const Cairo::RefPtr<Cairo::Context>& cr);
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    Character ch;
    double m_radius;
    double m_line_width;


};
class DrawPDF2 : public Gtk::DrawingArea
{
public:
    DrawPDF2();
    virtual ~DrawPDF2();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    double m_radius;
    double m_line_width;
};

class DrawPDF3 : public Gtk::DrawingArea
{
public:
    DrawPDF3();
    virtual ~DrawPDF3();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    double m_radius;
    double m_line_width;
};


class MyGrid: public Gtk::Grid
{
    CharacterCreation cr;
    Pango::FontDescription myfont, myfont2;

    Gtk::VSeparator vsep1, vsep2, vsep3, vsep4;

    /**** Page 1 ***/
    Gtk::Label message;
    Gtk::Image coverVampire;
    Gtk::Button nextButton;

    /**** Page 2 ****/
    Gtk::Label nameLabel, playerLabel, chronicleLabel, generationLabel, sirLabel,
                conceptLabel, natureLabel, demeanorLabel, clanLabel;
    Gtk::Entry nameEntry, playerEntry, chronicleEntry, generationEntry, sirEntry,
            conceptEntry;

    Gtk::ComboBoxText comboNature, comboDemeanor, comboClan;
    Gtk::Button goPage3, goBack, goPage2;
    Gtk::Image firstPart;


    /**** Page 3 ****/
    Gtk::Image attribImage;
    Gtk::Label totalPoint, totalPointPhysical, totalPointSocial, totalPointMental;
    Gtk::Label attributesLabel, physicalLabel, strengthLabel, dexterityLabel, staminaLabel,
                socialLabel, charismaLabel, manipulationLabel, appearanceLabel,
                mentalLabel, perceptionLabel, intelligenceLabel, witsLabel;
    CustomSpinButton strengthSpin, dexteritySpin, staminaSpin, charismaSpin, manipulationSpin, appearanceSpin,
                    perceptionSpin, intelligenceSpin, witsSpin;
    Gtk::Button goPage4;

    /**** Page 4 ****/
    Gtk::Image abilitiesImage;
    // talents part
    Gtk::Label abilitiesLabel, talentsLabel, skillsLabel, knowledgesLabel, pointsTalents, pointsSkills, pointsKnowledges;
    Gtk::ComboBoxText talentsCombo, skillsCombo, knowledgesCombo;
    Gtk::SpinButton talentsSpin, skillsSpin, knowledgesSpin;
    Gtk::Button goBack3, goPage5, addTalent, removeTalent, addSkills, removeSkills, addKnowledges, removeKnowledges;
    int talentClicked = 0, skillClicked = 0, knowledgeClicked=0;
    std::vector<std::string> allTalents = Parser::parseTalents();
    std::vector<std::string> allSkills = Parser::parseSkills();
    std::vector<std::string> allKnowledges = Parser::parseKnowledges();
    std::vector<Gtk::ComboBoxText*> wList, skillsList, knowledgesList;
    std::vector<Gtk::SpinButton*> spinListTalent, spinListSkills, spinListKnowledges;



    /*** Page 5 ***/
    std::string selectedClan = "None"; // keep track if user changed clan for the disciplines
    int backgroundClicked =0, disciplineClicked=0;
    std::vector<Gtk::ComboBoxText*> backgroundList,  disciplineList;
    std::vector<Gtk::SpinButton*>  spinBackgroundList,  spinDisciplineList;
    Gtk::Image advantagesImage;
    Gtk::Label advantageLabel, disciplineLabel, backgroundLabel, virtuesLabel, conscienceLabel, instinctLabel, courageLabel,
    pointsDiscipline, pointsBackground, pointsVirtue;
    Gtk::ComboBoxText disciplineCombo, backgroundCombo;
    Gtk::SpinButton disciplineSpin, backgroundSpin, virtueSpin1, virtueSpin2, virtueSpin3;
    Gtk::Button goPage6, addDisciplines, removeDisciplines, addBackgrounds, removeBackgrounds;
    std::vector<std::string> allDisciplines = Parser::parseDisciplines();
    std::vector<std::string> allBackgrounds = Parser::parseBackgrounds();

    /*** store selected values ***/
    int strengthSaved, dexteritySaved, staminaSaved, charismaSaved, manipulationSaved, appearanceSaved,
    perceptionSaved, intelligenceSaved, witsSaved;

    /**** Freebie page ****/
    sigc::connection signalConnectionDisciplineAdd, signalCBackgrounds, signalTalent, signalSkill, signalKnowledges,
    removeTalentSignal, removeSkillSignal, removeKnowledegeSignal, removeDisciplineSignal, removeBackgroundSignal; // keep reference to sigc::connection to disconnect it
    Gtk::ScrolledWindow scrolledAbilities, scrolledAdvantages;
    bool isFreebieePage;
    Gtk::Grid frameAdvantages, frameAbilities;
    Gtk::Button goFinal, goBackFreebie;
    Gtk::Label freebieLabel, totalPointsFreebie, totalsPointsValueFreebie;
    Gtk::HSeparator hsep1;
    int disciplineChoiceCount, talentChoiceCount, skillChoiceCount, knowledgeChoiceCount, backgroundChoiceCount; // number selected before freebie
    int lastStrength, lastDexterity, lastStamina, lastCharisma, lastManipulation, lastAppearance, lastPerception, lastIntelligence, lastWits,
    lastVirtue1, lastVirtue2, lastVirtue3, lastSumTalents=0, lastSumSkills=0, lastSumKnowledge=0, lastSumDiscipline=0, lastSumBackground=0;

    /*** Page 6 ***/
    Gtk::Image moreImage;

    Gtk::ScrolledWindow scrolledForDescription, scrolledForDescription2,scrolledForDescription3;
    Gtk::TextView textViewDescription;
    Glib::RefPtr<Gtk::TextBuffer> bufferDescription;

    /**** Final Page ****/
    DrawPDF pdf;
    DrawPDF2 pdf2;
    DrawPDF3 pdf3;
    Gtk::Button save;

    /**** advancement ***/
    bool isSavedPage1 =false, isSavedPage2=false, isSavedPage3=false,
    isSavedPage4=false, isSavedPage5=false;


public:
    MyGrid();
    void Page1();
    void initPage2();
    void Page2();
    void savePage2();
    void InitializeCr();
    void SelectTalents();
    void initPage3();
    void Page3();
    void initPage4();
    void Page4();
    void initPage5();
    void Page5();
    void goFreebiePage();
    void initFreebie();
    void FreebiePage();
    void Page6();
    void FinalPage(); // display constructed character sheet
    // button binding
    void addTalentClicked();
    void removeTalentClicked();
    void addSkillsClicked();
    void removeSkillsClicked();
    void addKnowledgesClicked();
    void removeKnowledgesClicked();
    void addBackgroundClicked();
    void removeBackgroundClicked();
    void addDisciplineClicked();
    void removeDisciplineClicked();

    // Freebie Page binding
    void addFreebieTalent();
    void addFreebieSkills();
    void addFreebieKnowledges();
    void addFreebieDiscipline();
    void addFreebieBackgrounds();

    void removeFreebieTalent();
    void removeFreebieSkills();
    void removeFreebieKnowledges();
    void removeFreebieDiscipline();
    void removeFreebieBackgrounds();

    // handle value change for total freebie points
    void addStrengthCost();
    void addDexterityCost();
    void addStaminaCost();
    void addCharismaCost();
    void addManipulationCost();
    void addAppearanceCost();
    void addPerceptionCost();
    void addIntelligenceCost();
    void addWitsCost();
    void addVirtue1Cost();
    void addVirtue2Cost();
    void addVirtue3Cost();
    void addTalentsCost();
    void addSkillsCost();
    void addKnowledgesCost();
    void addDisciplineCost();
    void addBackgroundsCost();


    void ApplyPage3();
    void generateCh();

    // block talents
    void changeTotalSocial();
    void changeTotalPhysical();
    void changeTotalMental();
    void changeTotalTalents();
    void changeTotalSkill();
    void changeTotalKnowledge();
    void changeTotalDiscipline();
    void changeTotalBackground();
    void changeTotalVirtue();
    int checkCorrectRepartition();
    bool checkRepartitionAbility();
    bool checkRepartitionAbilities();

    void go5();

    void goToPDF1();
    void secondPDF();
};


class Fenetre : public Gtk::Window
{

public:
    Fenetre();
    virtual ~Fenetre(); // Setup window

    void welcomeView(); // Remove the current grid from the window and replace it by WelcomeGrid

protected:
    //Member widgets:
    MyGrid welcome;



};


#endif //MINIPROJECT_GUI_H
