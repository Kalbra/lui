//
// Created by kalle on 4/16/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainFrame.h" resolved


#include "mainframe.h"

#include "./Blocks/Connector.hpp"
#include "./Blocks/LcdNumberOutputBlock.hpp"
#include "./Blocks/SpinBoxInputBlock.h"
#include "./ProjectFileIO.h"
#include "./PropertySet.h"


MainFrame::MainFrame(QWidget *parent) : QWidget(parent) {
    Connector connector;
    auto *male_property_set = new PropertySet();


    auto *male1 = connector.newMale<int>(male_property_set);
    male1->SetData(4545);





    //qDebug() << std::get<FemaleChannel<int>*>(lcdblock->GetFemalePlugs()[0])->GetData();

    auto *property_set = new PropertySet();

    property_set->addDouble("D", 1);
    property_set->addString("S", "Hello World");
    property_set->addBool("B", true);
    property_set->addStdDoubleByKey("DIGIT_COUNT", 20);

    auto *spin_box = new SpinBoxInputBlock(&connector, this, property_set);
    auto *lcdblock = new LcdNumberOutputBlock(&connector, this, property_set);
    std::get<MaleChannel<int>*>(spin_box->getMalePlugs().at(0))->ConnectToFemale(std::get<FemaleChannel<int>*>(lcdblock->GetFemalePlugs()[0]));
    lcdblock->update();

    std::vector<PropertySet> pro_vec;
    //pro_vec.emplace_back(lcdblock->getPropertySet());

}

MainFrame::~MainFrame() {
}
