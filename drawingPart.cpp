//
// Created by hugo on 23/11/20.
//

#include "GUI.h"
#include "gtkmm.h"
DrawPDF::DrawPDF(){};
DrawPDF::~DrawPDF(){};

/**
 *
 * @param cr
 * @return
 */
bool DrawPDF::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * use previously generated character to draw on the pdf
     */
    // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
    // the center of the window
    //cr->scale(width, heig
    Glib::RefPtr<Gdk::Pixbuf> image;
    image = Gdk::Pixbuf::create_from_file("testpdf.png");
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

    fillPlayerInfo(cr);

    fillAttributes(cr);

    fillAbilities(cr);

    fillAdvantages(cr);

    fillRest(cr);

    return Widget::on_draw(cr);
}

void DrawPDF::setCh(Character ch) {
    /**
     * give character to the drawing area
     */
    this->ch = ch;
}

void DrawPDF::fillAttributes(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * Fill all the attributes info on the PDF
     */
    /***** Attributes *****/
    // Physical
    int pointsToAdd = ch.getAttributes().getStrength();
    cr->set_source_rgb( 0.1, 0.1, 0.1);
    int dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(177+dx, 237, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }

    pointsToAdd = ch.getAttributes().getDexterity();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(177+dx, 252, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    pointsToAdd = ch.getAttributes().getStamina();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(177+dx, 269, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    //social
    pointsToAdd = ch.getAttributes().getCharisma();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(388+dx, 237, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    pointsToAdd = ch.getAttributes().getManipulation();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(388+dx, 252, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    pointsToAdd = ch.getAttributes().getAppearance();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(388+dx, 269, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    // Mental

    pointsToAdd = ch.getAttributes().getPerception();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(596+dx, 237, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    pointsToAdd = ch.getAttributes().getIntelligence();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(596+dx, 252, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();

    pointsToAdd = ch.getAttributes().getWits();
    dx = 0;
    for(int i=0; i<pointsToAdd; i++){
        cr->move_to(0,0);
        cr->arc(596+dx, 269, 4.5, 0, 2*M_PI);

        dx += 10.17;
        cr->fill_preserve();
    }
    cr->save();
}

/**
 * Add all the infomation from the first part of the character sheet
 * @param cr
 */
void DrawPDF::fillPlayerInfo(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * Fill all the player info on the PDF
     */
    /**** Background ****/
    // nom
    cr->move_to(118,137);
    cr->show_text(ch.getBackground().getName());

    // player
    cr->move_to(121,158);
    cr->show_text(ch.getBackground().getPlayer());


    // Chronicle
    cr->move_to(144,177);
    cr->show_text(ch.getBackground().getChronicle());

    // Nature
    cr->move_to(336,137);
    cr->show_text(ch.getBackground().getNature());

    // Demeanor
    cr->move_to(354,157);
    cr->show_text(ch.getBackground().getDemeanor());

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
    cr->save();
}

void DrawPDF::fillAbilities(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * fill all the abilities informations on the pdf
     */
    int startYcoord = 330;
    int talentsXcoord = 178;
    int skillsXcoord = 388;
    int knowledgesXcoord = 596;
    int dx = 10.17;
    int dy = 15;
    // talents
    std::vector<int> talents = ch.getAbilities().getTalents();
    std::vector<int> valueTalents = ch.getAbilities().getValueTalents();
    int posPoint =0;
    for (int a : talents){
        // numberOfPoint for this talent -> valueTalents[posPoint]
        for(int i=0; i<valueTalents.at(posPoint); i++){
            cr->move_to(0,0);
            cr->arc(talentsXcoord+i*dx, startYcoord+a*dy+a-a/2, 4.5, 0, 2*M_PI);
            cr->fill_preserve();
        }
        posPoint++;
    }
    cr->save();

    // Skills
    std::vector<int> skills = ch.getAbilities().getSkills();
    std::vector<int> valueSkills = ch.getAbilities().getValueSkills();
    posPoint =0;
    for (int a : skills){
        // numberOfPoint for this skill -> valueSkills[posPoint]
        for(int i=0; i<valueSkills.at(posPoint); i++){
            cr->move_to(0,0);
            cr->arc(skillsXcoord+i*dx, startYcoord+a*dy+a-a/2, 4.5, 0, 2*M_PI);
            cr->fill_preserve();
        }
        posPoint++;
    }
    cr->save();

    //Knowledges
    std::vector<int> knowledge = ch.getAbilities().getKnowledge();
    std::vector<int> valueKnowledge = ch.getAbilities().getValueKnowledge();
    posPoint =0;
    for (int a : knowledge){
        // numberOfPoint for this talent -> valueTalents[posPoint]
        for(int i=0; i<valueKnowledge.at(posPoint); i++){
            cr->move_to(0,0);
            cr->arc(knowledgesXcoord+i*dx, startYcoord+a*dy+a-a/2, 4.5, 0, 2*M_PI);
            cr->fill_preserve();
        }
        posPoint++;
    }
    cr->save();
}

void DrawPDF::fillAdvantages(const Cairo::RefPtr<Cairo::Context> &cr){
    /**
     * fill all the player advantages on the pdf
     */
    int labelx=80, startx=178,starty=550, dx=10, dy=15.5;
    auto disciplineMap = ch.getAdvantages().getDisciplines();
    int numberDiscipline =0;
    for (auto it = disciplineMap.begin(); it != disciplineMap.end(); ++it){
        cr->move_to(labelx,starty+numberDiscipline*dy);
        cr->show_text(it->first);
        for (int i=0; i<it->second;i++){
            cr->move_to(0,0);
            cr->arc(startx+i*dx, starty+numberDiscipline*dy, 4.5,0,2*M_PI);
            cr->fill_preserve();
            cr->save();
        }
        numberDiscipline++;
    }
    // backgrounds
    labelx = 290;
    startx = 388;
    auto backgroundMap = ch.getAdvantages().getBackgrounds();
    int numberBackground = 0;
    for (auto it = backgroundMap.begin(); it != backgroundMap.end(); ++it){
        cr->move_to(labelx,starty+numberBackground*dy);
        cr->show_text(it->first);
        for (int i=0; i<it->second;i++){
            cr->move_to(0,0);
            cr->arc(startx+i*dx, starty+numberBackground*dy, 4.5,0,2*M_PI);
            cr->fill_preserve();
            cr->save();
        }
        numberBackground++;
    }

    // Virtue
    int virtue1Points = ch.getAdvantages().getConscience();
    int virtue2Points = ch.getAdvantages().getInstinct();
    int virtue3Points = ch.getAdvantages().getCourage();
    int virtuex = 637, consciencey = 550,instincty = 581,couragey= 612;
    for(int i=0; i<virtue1Points; i++){
        cr->move_to(0,0);
        cr->arc(virtuex+i*dx, consciencey, 4.5, 0, 2*M_PI);
        cr->fill_preserve();
        cr->save();
    }
    for(int i=0; i<virtue2Points; i++){
        cr->move_to(0,0);
        cr->arc(virtuex+i*dx, instincty, 4.5, 0, 2*M_PI);
        cr->fill_preserve();
        cr->save();
    }
    for(int i=0; i<virtue3Points; i++){
        cr->move_to(0,0);
        cr->arc(virtuex+i*dx, couragey, 4.5, 0, 2*M_PI);
        cr->fill_preserve();
        cr->save();
    }
}

void DrawPDF::fillRest(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * fill the remeaning informations (humanity, willpower and bloodpool) on the pdf
     */
    int humanityX=312,dx=10, humanityY= 700, willpowerY=750, bloodpoolY=806;
    // humanity
    for(int i=0; i<ch.getHumanityWill().getHumanity(); i++){
        cr->move_to(0,0);
        cr->arc(humanityX+i*dx, humanityY, 4.5, 0, 2*M_PI);
        cr->fill_preserve();
        cr->save();
    }
    // willpower
    for(int i=0; i<ch.getHumanityWill().getWillpower(); i++){
        cr->move_to(0,0);
        cr->arc(humanityX+i*dx, willpowerY, 4.5, 0, 2*M_PI);
        cr->fill_preserve();
        cr->save();
    }
    // bloodpool
    for(int i=0; i<ch.getBloodPool().getMaxBloodPool();i++){
        cr->move_to(0,0);
        cr->arc(humanityX+i*dx, bloodpoolY, 4.5, 0, 2*M_PI);
        cr->fill_preserve();
        cr->save();
    }
}

bool DrawPDF2::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * Drawing area for the second page
     */
    // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
    // the center of the window
    //cr->scale(width, heig
    Glib::RefPtr<Gdk::Pixbuf> image;
    image = Gdk::Pixbuf::create_from_file("pdf2.png");
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // Draw the image in the middle of the drawing area, or (if the image is
    // larger than the drawing area) draw the middle part of the image.
    Gdk::Cairo::set_source_pixbuf(cr, image,
                                  (width - image->get_width())/2, (height - image->get_height())/2);
    cr->paint();

    return Widget::on_draw(cr);
}
bool DrawPDF3::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    /**
     * drawing arean for the third pdf page
     */
    // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
    // the center of the window
    //cr->scale(width, heig
    Glib::RefPtr<Gdk::Pixbuf> image;
    image = Gdk::Pixbuf::create_from_file("pdf3.png");
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // Draw the image in the middle of the drawing area, or (if the image is
    // larger than the drawing area) draw the middle part of the image.
    Gdk::Cairo::set_source_pixbuf(cr, image,
                                  (width - image->get_width())/2, (height - image->get_height())/2);
    cr->paint();

    return Widget::on_draw(cr);
}

DrawPDF2::DrawPDF2(){};
DrawPDF2::~DrawPDF2(){};

DrawPDF3::DrawPDF3(){};
DrawPDF3::~DrawPDF3(){};