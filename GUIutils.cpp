//
// Created by hugo on 23/11/20.
//

#include "GUI.h"

void MyGrid::changeTotalMental(){
    /**
     * Increase or decrease the total value of points added to mental, and change the value of the corresponding label
     */
    int spin1, spin2, spin3;
    spin1 = std::stoi(perceptionSpin.get_text().raw());
    spin2 = std::stoi(intelligenceSpin.get_text().raw());
    spin3 = std::stoi(witsSpin.get_text().raw());
    std::string newTotal = std::to_string(spin1 + spin2 + spin3-3);
    totalPointSocial.set_text(newTotal);
}

void MyGrid::changeTotalSocial() {
    /**
 * Increase or decrease the total value of points added to social, and change the value of the corresponding label
 */
    int spin4, spin5, spin6;
    spin4 = std::stoi(charismaSpin.get_text().raw());
    spin5 = std::stoi(manipulationSpin.get_text().raw());
    spin6 = std::stoi(appearanceSpin.get_text().raw());
    std::string newTotalMental = std::to_string(spin4 + spin5 + spin6-3);
    totalPointMental.set_text(newTotalMental);
}


void MyGrid::changeTotalPhysical() {
    /**
 * Increase or decrease the total value of points added to physical, and change the value of the corresponding label
 */
    int spin7, spin8, spin9;
    spin7 = std::stoi(strengthSpin.get_text().raw());
    spin8 = std::stoi(dexteritySpin.get_text().raw());
    spin9 = std::stoi(staminaSpin.get_text().raw());
    std::string newTotalPhysical = std::to_string(spin7 + spin8 + spin9-3);
    totalPointPhysical.set_text(newTotalPhysical);

}

void MyGrid::changeTotalTalents(){
    /**
 * Increase or decrease the total value of points added to talents, and change the value of the corresponding label
 */
    int points = 0;
    for(Gtk::SpinButton *sp : spinListTalent) {
        points += sp->get_value_as_int();
    }
    pointsTalents.set_text(std::to_string(points));
}

void MyGrid::changeTotalSkill() {
    /**
 * Increase or decrease the total value of points added to skills, and change the value of the corresponding label
 */
    int points = 0;
    for(Gtk::SpinButton *sp : spinListSkills) {
        points += sp->get_value_as_int();
    }
    pointsSkills.set_text(std::to_string(points));
}

void MyGrid::changeTotalKnowledge() {
    /**
 * Increase or decrease the total value of points added to knowledges, and change the value of the corresponding label
 */
    int points = 0;
    for(Gtk::SpinButton *sp : spinListKnowledges) {
        points += sp->get_value_as_int();
    }
    pointsKnowledges.set_text(std::to_string(points));
}

void MyGrid::changeTotalDiscipline() {
    /**
 * Increase or decrease the total value of points added to disciplines, and change the value of the corresponding label
 */
    int points = 0;
    for(Gtk::SpinButton *sp : spinDisciplineList) {
        points += sp->get_value_as_int();
    }
    pointsDiscipline.set_text(std::to_string(points));
}

void MyGrid::changeTotalBackground() {
    /**
 * Increase or decrease the total value of points added to background, and change the value of the corresponding label
 */
    int points = 0;
    for(Gtk::SpinButton *sp : spinBackgroundList) {
        points += sp->get_value_as_int();
    }
    pointsBackground.set_text(std::to_string(points));
}

void MyGrid::changeTotalVirtue() {
    /**
 * Increase or decrease the total value of points added to virtue, and change the value of the corresponding label
 */
    int spin1, spin2, spin3;
    spin1 = virtueSpin1.get_value_as_int();
    spin2 = virtueSpin2.get_value_as_int();
    spin3 = virtueSpin3.get_value_as_int();
    std::string newTotal = std::to_string(spin1 + spin2 + spin3-3);
    pointsVirtue.set_text(newTotal);
}


void MyGrid::addStrengthCost(){
    /**
     * Change available freebie point displayed, considering that increasing strength cost 5 freebie points
     */
    if(lastStrength - strengthSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastStrength = strengthSpin.get_value_as_int();
}

void MyGrid::addDexterityCost() {
    /**
 * Change available freebie point displayed, considering that increasing dexterity cost 5 freebie points
 */
    if(lastDexterity - dexteritySpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastDexterity = dexteritySpin.get_value_as_int();
}

void MyGrid::addStaminaCost() {
    /**
 * Change available freebie point displayed, considering that increasing stamina cost 5 freebie points
 */
    if(lastStamina - staminaSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastStamina = staminaSpin.get_value_as_int();
}

void MyGrid::addCharismaCost() {
    /**
 * Change available freebie point displayed, considering that increasing charisma cost 5 freebie points
 */
    if(lastCharisma - charismaSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastCharisma = charismaSpin.get_value_as_int();
}

void MyGrid::addManipulationCost() {
    /**
 * Change available freebie point displayed, considering that increasing manipulation cost 5 freebie points
 */
    if(lastManipulation - manipulationSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastManipulation = manipulationSpin.get_value_as_int();
}

void MyGrid::addAppearanceCost() {
    /**
 * Change available freebie point displayed, considering that increasing appearance cost 5 freebie points
 */
    if(lastAppearance - appearanceSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastAppearance = appearanceSpin.get_value_as_int();
}

void MyGrid::addPerceptionCost() {
    /**
 * Change available freebie point displayed, considering that increasing perception cost 5 freebie points
 */
    if(lastPerception - perceptionSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastPerception = perceptionSpin.get_value_as_int();
}
void MyGrid::addIntelligenceCost() {
    /**
 * Change available freebie point displayed, considering that increasing intelligence cost 5 freebie points
 */
    if(lastIntelligence - intelligenceSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastIntelligence = intelligenceSpin.get_value_as_int();
}

void MyGrid::addWitsCost() {
    /**
 * Change available freebie point displayed, considering that increasing wits cost 5 freebie points
 */
    if(lastWits - witsSpin.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 5));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 5));
    }
    lastWits = witsSpin.get_value_as_int();
}

void MyGrid::addVirtue1Cost() {
    /**
 * Change available freebie point displayed, considering that increasing Virtue 1 cost 2 freebie points
 */
    if(lastVirtue1 - virtueSpin1.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 2));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 2));
    }
    lastVirtue1 = virtueSpin1.get_value_as_int();
}

void MyGrid::addVirtue2Cost() {
    /**
* Change available freebie point displayed, considering that increasing Virtue 2 cost 2 freebie points
*/
    if(lastVirtue2 - virtueSpin2.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 2));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 2));
    }
    lastVirtue2 = virtueSpin2.get_value_as_int();
}

void MyGrid::addVirtue3Cost() {
    /**
* Change available freebie point displayed, considering that increasing Virtue 3 cost 2 freebie points
*/
    if(lastVirtue3 - virtueSpin3.get_value_as_int()>0){
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) + 2));
    }else{
        totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) - 2));
    }
    lastVirtue3 = virtueSpin3.get_value_as_int();
}


void MyGrid::addTalentsCost() {
    /**
* Change available freebie point displayed, considering that increasing talents cost 2 freebie points
     * Use the sum of talents and the new sum to see if the value increased or decreased.
     * Use the difference of the sum to know how many points have been removed in the case of the deletion of a spin with value >1
*/
    int currentSum= 0;
    for(Gtk::SpinButton *sp : spinListTalent){
        currentSum += sp->get_value_as_int();
    }
    if (currentSum>lastSumTalents){
        for(int i =0; i<currentSum-lastSumTalents; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) -2));
        }
    }else{
        for(int i =0; i<lastSumTalents-currentSum; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) +2));
        }
    }
    lastSumTalents = currentSum;
}

void MyGrid::addSkillsCost() {
    /**
* Change available freebie point displayed, considering that increasing skills cost 2 freebie points
 * Use the sum of talents and the new sum to see if the value increased or decreased.
 * Use the difference of the sum to know how many points have been removed in the case of the deletion of a spin with value >1
*/
    int currentSum= 0;
    for(Gtk::SpinButton *sp : spinListSkills){
        currentSum += sp->get_value_as_int();
    }
    if (currentSum>lastSumSkills){
        for(int i =0; i<currentSum-lastSumSkills; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) -2));
        }
    }else{
        for(int i =0; i<lastSumSkills-currentSum; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) +2));
        }
    }
    lastSumSkills = currentSum;
}


void MyGrid::addKnowledgesCost() {
    /**
* Change available freebie point displayed, considering that increasing knowledges cost 2 freebie points
 * Use the sum of talents and the new sum to see if the value increased or decreased.
 * Use the difference of the sum to know how many points have been removed in the case of the deletion of a spin with value >1
*/
    int currentSum= 0;
    for(Gtk::SpinButton *sp : spinListKnowledges){
        currentSum += sp->get_value_as_int();
    }
    if (currentSum>lastSumKnowledge){
        for(int i =0; i<currentSum-lastSumKnowledge; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) -2));
        }
    }else{
        for(int i =0; i<lastSumKnowledge-currentSum; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) +2));
        }
    }
    lastSumKnowledge = currentSum;
}

void MyGrid::addDisciplineCost(){
    /**
* Change available freebie point displayed, considering that increasing discipline cost 7 freebie points
 * Use the sum of talents and the new sum to see if the value increased or decreased.
 * Use the difference of the sum to know how many points have been removed in the case of the deletion of a spin with value >1
*/

    int currentSum= 0;
    for(Gtk::SpinButton *sp : spinDisciplineList){
        currentSum += sp->get_value_as_int();
    }
    if (currentSum>lastSumDiscipline){
        for(int i =0; i<currentSum-lastSumDiscipline; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) -7));
        }
    }else{
        for(int i =0; i<lastSumDiscipline-currentSum; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) +7));
        }
    }
    lastSumDiscipline = currentSum;
}

void MyGrid::addBackgroundsCost() {
    /**
* Change available freebie point displayed, considering that increasing background cost 2 freebie points
 * Use the sum of talents and the new sum to see if the value increased or decreased.
 * Use the difference of the sum to know how many points have been removed in the case of the deletion of a spin with value >1
*/
    int currentSum= 0;
    for(Gtk::SpinButton *sp : spinBackgroundList){
        currentSum += sp->get_value_as_int();
    }
    if (currentSum>lastSumBackground){
        for(int i =0; i<currentSum-lastSumBackground; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) -1));
        }
    }else{
        for(int i =0; i<lastSumBackground-currentSum; i++){
            totalsPointsValueFreebie.set_text(std::to_string(std::stoi(totalsPointsValueFreebie.get_text()) +1));
        }
    }
    lastSumBackground = currentSum;
}



int MyGrid::checkCorrectRepartition(){
    /**
     * Check for the correct repartition of attributes. Used to allow the progression to the ability page
     */
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

bool MyGrid::checkRepartitionAbility(){
    /**
     * Check for the correct repartition of abilities. Used to allow the progression to the advantage page
     */
    int tot1, tot2, tot3;
    std::vector<int> values;
    tot1 = std::stoi(pointsTalents.get_text().raw());
    tot2 = std::stoi(pointsSkills.get_text().raw());
    tot3 = std::stoi(pointsKnowledges.get_text().raw());
    values.push_back(tot1);values.push_back(tot2); values.push_back(tot3);
    int key1(13), key2(9), key3(5);
    if (std::count(values.begin(), values.end(), key1)
        && std::count(values.begin(), values.end(), key2)
        && std::count(values.begin(), values.end(), key3))
    {
        return true;
    }else{return false;}
}

bool MyGrid::checkRepartitionAbilities(){
    /**
 * Check for the correct repartition of advantages. Used to allow the progression to the advantage page
 */
    if(std::stoi(pointsDiscipline.get_text())!=3 || std::stoi(pointsBackground.get_text())!=5 || std::stoi(pointsVirtue.get_text())!=7){
        return false;
    }else{
        return true;

    }
}

void MyGrid::addSkillsClicked() {
    /**
     * Triggers the addition of a skill combobox and a spinbutton
     */
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
    skillsList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,9);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_show().connect(sigc::mem_fun(*this, &MyGrid::changeTotalSkill));
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalSkill));
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
    /**
 * Triggers the supression of a skill combobox and a spinbutton
 */
    skillClicked--;
    this->remove(addSkills);
    this->remove(removeSkills);
    this->remove(*skillsList.back());
    this->remove(*spinListSkills.back());
    skillsList.pop_back();
    pointsSkills.set_text(std::to_string(std::stoi(pointsSkills.get_text())-spinListSkills.back()->get_value_as_int()));
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
    /**
 * Triggers the addition of a knowledge combobox and a spinbutton
 */
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
    knowledgesList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,9);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_show().connect(sigc::mem_fun(*this, &MyGrid::changeTotalKnowledge));
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalKnowledge));
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


void MyGrid::removeKnowledgesClicked() {
    /**
 * remove last added combobox and spinbutton for knowledge
 */
    knowledgeClicked--;
    this->remove(addKnowledges);
    this->remove(removeKnowledges);
    this->remove(*knowledgesList.back());
    this->remove(*spinListKnowledges.back());
    knowledgesList.pop_back();
    pointsKnowledges.set_text(std::to_string(std::stoi(pointsKnowledges.get_text())-spinListKnowledges.back()->get_value_as_int()));
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
    /**
* Triggers the addition of a background combobox and a spinbutton
*/
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
    backgroundList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,5);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_show().connect(sigc::mem_fun(*this, &MyGrid::changeTotalBackground));
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalBackground));
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
    /**
* Triggers the addition of a discipline combobox and a spinbutton
*/
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
    for(std::string bac : Parser::getClanDiscipline(comboClan.get_active_text())){
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
    disciplineList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_show().connect(sigc::mem_fun(*this, &MyGrid::changeTotalDiscipline));
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalDiscipline));
    disciplineList.back()->set_sensitive(false);
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

void MyGrid::addFreebieBackgrounds(){
    /**
* Triggers the addition of a background combobox and a spinbutton on the Freebie Page.
     * call addBackgroundsCost() to take into account the new points
*/
        backgroundClicked ++;
        // remove the add button
        this->frameAdvantages.remove(addBackgrounds);
        this->frameAdvantages.remove(removeBackgrounds);
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
            this->frameAdvantages.attach(addBackgrounds, 4, 3+backgroundClicked,1,1);
        }
        // add Available skill to the combobox
        for(std::string ba : availableBackgrounds){
            addedP->append(ba);
        }

        addedP->set_active(0);
        addedSpinP->set_range(1,3);
        addedSpinP->set_increments(1,1);
        addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addBackgroundsCost));
        // store them in vectors
        backgroundList.push_back(addedP);
        spinBackgroundList.push_back(addedSpinP);
        // add remove skill button (configured in Page4)

        this->frameAdvantages.attach(removeBackgrounds,5, 3+backgroundClicked,1,1);
        // attach and show
        this->frameAdvantages.attach(*addedP,4,2+backgroundClicked,1,1);
        this->frameAdvantages.attach(*addedSpinP, 5,2+backgroundClicked,1,1);
        addBackgroundsCost();
        this->show_all();
};

void MyGrid::addFreebieDiscipline() {
    /**
* Triggers the addition of a discipline combobox and a spinbutton on the Freebie Page.
 * call addBackgroundsCost() to take into account the new points
*/
    disciplineClicked ++;
    // remove the add button
    this->frameAdvantages.remove(addDisciplines);
    this->frameAdvantages.remove(removeDisciplines);
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
        this->frameAdvantages.attach(addDisciplines, 0, 3+disciplineClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string ba : availableDisciplines){
        addedP->append(ba);
    }

    addedP->set_active(0);
    addedSpinP->set_range(1,3);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addDisciplineCost));
    disciplineList.back()->set_sensitive(false);
    // store them in vectors
    disciplineList.push_back(addedP);
    spinDisciplineList.push_back(addedSpinP);
    // add remove skill button (configured in Page4)
    this->frameAdvantages.attach(removeDisciplines,1, 3+disciplineClicked,1,1);
    // attach and show
    this->frameAdvantages.attach(*addedP,0,2+disciplineClicked,1,1);
    this->frameAdvantages.attach(*addedSpinP, 1,2+disciplineClicked,1,1);
    addDisciplineCost();
    this->show_all();

}

void MyGrid::removeBackgroundClicked() {
    /**
     * remove last added background combobox and spinbutton
     */
    backgroundClicked--;
    this->remove(addBackgrounds);
    this->remove(removeBackgrounds);
    this->remove(*backgroundList.back());
    this->remove(*spinBackgroundList.back());
    backgroundList.pop_back();
    pointsBackground.set_text(std::to_string(std::stoi(pointsBackground.get_text())-spinBackgroundList.back()->get_value_as_int()));
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
    /**
 * remove last added discipline combobox and spinbutton
 */
    disciplineClicked--;
    this->remove(addDisciplines);
    this->remove(removeDisciplines);
    this->remove(*disciplineList.back());
    this->remove(*spinDisciplineList.back());
    disciplineList.pop_back();
    pointsDiscipline.set_text(std::to_string(std::stoi(pointsDiscipline.get_text())-spinDisciplineList.back()->get_value_as_int()));
    spinDisciplineList.pop_back();
    if (disciplineClicked >=1){

        this->attach(addDisciplines, 0, 3+disciplineClicked,1,1);
        this->attach(removeDisciplines,1, 3+disciplineClicked,1,1);
    }else{
        this->attach(addDisciplines, 0, 3+disciplineClicked,1,1);
    }

    this->show_all();
}

void MyGrid::generateCh() {
    /**
     * Generate the character by taking all the inputed information in the GUI
     */
    cr.StepZero(nameEntry.get_text(),playerEntry.get_text(), chronicleEntry.get_text(), generationEntry.get_text(), sirEntry.get_text());
    cr.StepOne(conceptEntry.get_text(), comboClan.get_active_text(), comboNature.get_active_text(), comboDemeanor.get_active_text());
    Attributes attri;
    attri.setPhysical(strengthSpin.get_value_as_int(),dexteritySpin.get_value_as_int(),staminaSpin.get_value_as_int());
    attri.setSocial(charismaSpin.get_value_as_int(),manipulationSpin.get_value_as_int(),appearanceSpin.get_value_as_int());
    attri.setMental(perceptionSpin.get_value_as_int(),intelligenceSpin.get_value_as_int(),witsSpin.get_value_as_int());
    cr.StepTwo(attri);
    /****** abilities *****/
    Abilities abbi;
    // get position of selected talents in allTalents
    std::vector<int> indexTalents;
    for (Gtk::ComboBoxText *cb : wList){
        indexTalents.push_back(std::find(allTalents.begin(), allTalents.end(), cb->get_active_text()) - allTalents.begin());
    }
    // get position of selected skills in allSkills
    std::vector<int> indexSkills;
    for (Gtk::ComboBoxText *cb : skillsList){
        indexSkills.push_back(std::find(allSkills.begin(), allSkills.end(), cb->get_active_text()) - allSkills.begin());
    }
    // get position of selected knowledges in allKnowledges
    std::vector<int> indexKnowledges;
    for (Gtk::ComboBoxText *cb : knowledgesList){
        indexKnowledges.push_back(std::find(allKnowledges.begin(), allKnowledges.end(), cb->get_active_text()) - allKnowledges.begin());
    }
    // Values
    std::vector<int> valuesT;
    for(Gtk::SpinButton *sp : spinListTalent){
        valuesT.push_back(sp->get_value_as_int());
    }
    std::vector<int> valuesS;
    for(Gtk::SpinButton *sp : spinListSkills){
        valuesS.push_back(sp->get_value_as_int());
    }
    std::vector<int> valuesK;
    for(Gtk::SpinButton *sp : spinListKnowledges){
        valuesK.push_back(sp->get_value_as_int());
    }

    abbi.setTalents(indexTalents);
    abbi.setValueTalents(valuesT);
    abbi.setSkills(indexSkills);
    abbi.setValueSkills(valuesS);
    abbi.setKnowledges(indexKnowledges);
    abbi.setValueKnowledges(valuesK);
    cr.StepThree(abbi);
    /***** Advantage *****/
    Advantages adv;
    std::vector<std::string> disciplineName;
    std::vector<int> disciplinePoints;

    for (Gtk::ComboBoxText *cb : disciplineList){
        disciplineName.push_back(cb->get_active_text());
    }
    for(Gtk::SpinButton *sp: spinDisciplineList){
        disciplinePoints.push_back(sp->get_value_as_int());
    }
    adv.setDisciplines(disciplineName, disciplinePoints);

    std::vector<std::string> backgroundName;
    std::vector<int> backgroundPoints;
    for (Gtk::ComboBoxText *cb : backgroundList){
        backgroundName.push_back(cb->get_active_text());
    }
    for(Gtk::SpinButton *sp: spinBackgroundList){
        backgroundPoints.push_back(sp->get_value_as_int());
    }

    adv.setBackgrounds(backgroundName, backgroundPoints);
    adv.setVirtue(virtueSpin1.get_value_as_int(), virtueSpin2.get_value_as_int(), virtueSpin3.get_value_as_int());
    cr.StepFour(adv);
    // create blood pool
    BloodPool bloodPool{};
    // set the max blood pool using the character generation
    bloodPool.setMaxBloodPool();
    // create humanity and willpower
    int conscience = cr.getCharacter().getAdvantages().getConscience();
    int instinct= cr.getCharacter().getAdvantages().getInstinct();
    int courage= cr.getCharacter().getAdvantages().getCourage();
    HumanityWill hw(conscience, instinct, courage);
    cr.StepFive(bloodPool, hw);
}


void MyGrid::removeTalentClicked(){
    /**
     * remove last added talent combobox and spinbutton
     */
    talentClicked--;
    this->remove(addTalent);
    this->remove(removeTalent);
    this->remove(*wList.back());
    this->remove(*spinListTalent.back());
    wList.pop_back();
    // change points total value on delete of talents
    pointsTalents.set_text(std::to_string(std::stoi(pointsTalents.get_text())-spinListTalent.back()->get_value_as_int()));
    spinListTalent.pop_back();
    if (talentClicked >=1){

        this->attach(addTalent, 0, 3+talentClicked,1,1);
        this->attach(removeTalent,1, 3+talentClicked,1,1);
    }else{
        this->attach(addTalent, 0, 3+talentClicked,1,1);
    }

    this->show_all();
}

void MyGrid::addFreebieTalent() {
    /**
     * Add a combox and spinbutton for talent in the freebie page, taking care of the remeaning points
     */
    // increase talentClicked to update the positions
    talentClicked ++;
    // remove the add button
    this->frameAbilities.remove(addTalent);
    this->frameAbilities.remove(removeTalent);
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
        this->frameAbilities.attach(addTalent, 0, 3+talentClicked,1,1);
    }
    // add Available talents to the combobox
    for(std::string talent : availableTalents){
        addedP->append(talent);
    }
    //set last combobox insensitive
    wList.back()->set_sensitive(false);

    addedP->set_active(0);
    addedSpinP->set_range(1,9);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addTalentsCost));
    // store them in vectors
    wList.push_back(addedP);
    spinListTalent.push_back(addedSpinP);
    // add remove Talent button (configured in Page4)

    this->frameAbilities.attach(removeTalent,1, 3+talentClicked,1,1);
    // attach and show
    this->frameAbilities.attach(*addedP,0,2+talentClicked,1,1);
    this->frameAbilities.attach(*addedSpinP, 1,2+talentClicked,1,1);
    addTalentsCost();
    this->show_all();
}

void MyGrid::addTalentClicked(){
    /**
     * Add a talent combox andd spinbutton
     */
    // increase talentClicked to update the positions
    talentClicked ++;
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
    wList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,9);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_show().connect(sigc::mem_fun(*this, &MyGrid::changeTotalTalents));
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::changeTotalTalents));
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

void MyGrid::addFreebieSkills() {
    /**
     * add a combobox and spinbutton for skills on the freebie page
     */
// increase skillClicked to update the positions
    skillClicked ++;
    // remove the add button
    this->frameAbilities.remove(addSkills);
    this->frameAbilities.remove(removeSkills);
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
        this->frameAbilities.attach(addSkills, 3, 3+skillClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string skill : availableSkills){
        addedP->append(skill);
    }
    skillsList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,9);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addSkillsCost));
    // store them in vectors
    skillsList.push_back(addedP);
    spinListSkills.push_back(addedSpinP);
    // add remove skill button (configured in Page4)

    this->frameAbilities.attach(removeSkills,4, 3+skillClicked,1,1);
    // attach and show
    this->frameAbilities.attach(*addedP,3,2+skillClicked,1,1);
    this->frameAbilities.attach(*addedSpinP, 4,2+skillClicked,1,1);
    addSkillsCost();
    this->show_all();
}

void MyGrid::addFreebieKnowledges(){
    /**
 * add a combobox and spinbutton for knowledges on the freebie page
 */
    knowledgeClicked ++;
    // remove the add button
    this->frameAbilities.remove(addKnowledges);
    this->frameAbilities.remove(removeKnowledges);
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
        this->frameAbilities.attach(addKnowledges, 6, 3+knowledgeClicked,1,1);
    }
    // add Available skill to the combobox
    for(std::string know : availableKnowledges){
        addedP->append(know);
    }
    knowledgesList.back()->set_sensitive(false);
    addedP->set_active(0);
    addedSpinP->set_range(1,9);
    addedSpinP->set_increments(1,1);
    addedSpinP->signal_value_changed().connect(sigc::mem_fun(*this, &MyGrid::addKnowledgesCost));
    // store them in vectors
    knowledgesList.push_back(addedP);
    spinListKnowledges.push_back(addedSpinP);
    // add remove skill button (configured in Page4)

    this->frameAbilities.attach(removeKnowledges,7, 3+knowledgeClicked,1,1);
    // attach and show
    this->frameAbilities.attach(*addedP,6,2+knowledgeClicked,1,1);
    this->frameAbilities.attach(*addedSpinP, 7,2+knowledgeClicked,1,1);
    addKnowledgesCost();
    this->show_all();
}

void MyGrid::removeFreebieTalent(){
    /**
     * remove last added talent from the freebie page
     */
    talentClicked--;
    this->frameAbilities.remove(addTalent);
    this->frameAbilities.remove(removeTalent);
    this->frameAbilities.remove(*wList.back());
    this->frameAbilities.remove(*spinListTalent.back());
    wList.pop_back();
    spinListTalent.pop_back();
    if (talentClicked >=talentChoiceCount){
        wList.back()->set_sensitive(true);

        this->frameAbilities.attach(addTalent, 0, 3+talentClicked,1,1);
        this->frameAbilities.attach(removeTalent,1, 3+talentClicked,1,1);
    }else{
        this->frameAbilities.attach(addTalent, 0, 3+talentClicked,1,1);
    }
    addTalentsCost();
    this->show_all();
}


void MyGrid::removeFreebieSkills() {
    /**
     * remove last added skill from the freebie page
     */
    skillClicked--;
    this->frameAbilities.remove(addSkills);
    this->frameAbilities.remove(removeSkills);
    this->frameAbilities.remove(*skillsList.back());
    this->frameAbilities.remove(*spinListSkills.back());
    skillsList.pop_back();
    spinListSkills.pop_back();
    if (skillClicked >=skillChoiceCount){
        skillsList.back()->set_sensitive(true);
        this->frameAbilities.attach(addSkills, 3, 3+skillClicked,1,1);
        this->frameAbilities.attach(removeSkills,4, 3+skillClicked,1,1);
    }else{
        this->frameAbilities.attach(addSkills, 3, 3+skillClicked,1,1);
    }
    addSkillsCost();
    this->show_all();
}

void MyGrid::removeFreebieKnowledges() {
    /**
     * remove last added knowledge from the freebie page
     */
    knowledgeClicked--;
    this->frameAbilities.remove(addKnowledges);
    this->frameAbilities.remove(removeKnowledges);
    this->frameAbilities.remove(*knowledgesList.back());
    this->frameAbilities.remove(*spinListKnowledges.back());
    knowledgesList.pop_back();
    spinListKnowledges.pop_back();
    if (knowledgeClicked >=knowledgeChoiceCount){
        knowledgesList.back()->set_sensitive(true);
        this->frameAbilities.attach(addKnowledges, 6, 3+knowledgeClicked,1,1);
        this->frameAbilities.attach(removeKnowledges,7, 3+knowledgeClicked,1,1);
    }else{
        this->frameAbilities.attach(addKnowledges, 6, 3+knowledgeClicked,1,1);
    }
    addKnowledgesCost();
    this->show_all();
}

void MyGrid::removeFreebieDiscipline() {
    /**
 * remove last added discipline from the freebie page
 */
    disciplineClicked--;
    this->frameAdvantages.remove(addDisciplines);
    this->frameAdvantages.remove(removeDisciplines);
    this->frameAdvantages.remove(*disciplineList.back());
    this->frameAdvantages.remove(*spinDisciplineList.back());
    disciplineList.pop_back();
    spinDisciplineList.pop_back();
    if (disciplineClicked >=disciplineChoiceCount){
        disciplineList.back()->set_sensitive(true);
        this->frameAdvantages.attach(addDisciplines, 0, 3+disciplineClicked,1,1);
        this->frameAdvantages.attach(removeDisciplines,1, 3+disciplineClicked,1,1);
    }else{
        this->frameAdvantages.attach(addDisciplines, 0, 3+disciplineClicked,1,1);
    }
    addDisciplineCost();
    this->show_all();
}

void MyGrid::removeFreebieBackgrounds() {
    /**
 * remove last added background from the freebie page
 */
    backgroundClicked--;
    this->frameAdvantages.remove(addBackgrounds);
    this->frameAdvantages.remove(removeBackgrounds);
    this->frameAdvantages.remove(*backgroundList.back());
    this->frameAdvantages.remove(*spinBackgroundList.back());
    backgroundList.pop_back();
    spinBackgroundList.pop_back();
    if (backgroundClicked >=backgroundChoiceCount){
        backgroundList.back()->set_sensitive(true);
        this->frameAdvantages.attach(addBackgrounds, 4, 3+backgroundClicked,1,1);
        this->frameAdvantages.attach(removeBackgrounds,5, 3+backgroundClicked,1,1);
    }else{
        this->frameAdvantages.attach(addBackgrounds, 4, 3+backgroundClicked,1,1);
    }
    addBackgroundsCost();
    this->show_all();
}