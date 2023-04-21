#include <QLCDNumber>

#include "BaseOutputBlock.hpp"
#include "FemaleChannel.hpp"
#include "../ProjectFileIO/PropertySet.h"

class LcdNumberOutputBlock : public BaseOutputBlock{
public:
    explicit LcdNumberOutputBlock(Connector *connector, QWidget *widget, PropertySet *property_set) :
            BaseOutputBlock(connector, widget, property_set) {

        lcd_number = new QLCDNumber(widget);
        female_plugs_of_block.emplace_back(connector->newFemale<int>(_property_set, &BaseUpdate::update));

        lcd_number->setDecMode();

        lcd_number->setDigitCount(_property_set->getDoubleByKeyAsInt("DIGIT_COUNT"));
        lcd_number->show();
    }

    virtual void update(){
        qDebug() << "Update";
        lcd_number->display(std::get<FemaleChannel<int>*>(female_plugs_of_block[0])->GetData());
    }

    static PropertySet* standard_property_set(){
        auto property_set = new PropertySet();
        property_set->addDouble("DIGIT_COUNT", 4);

        return property_set;
    }

private:
    QLCDNumber *lcd_number;
};