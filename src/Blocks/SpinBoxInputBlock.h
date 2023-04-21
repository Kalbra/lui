//
// Created by kalle on 4/20/23.
//

#ifndef LUI_SPINBOXINPUTBLOCK_H
#define LUI_SPINBOXINPUTBLOCK_H

#include <QObject>
#include <QSpinBox>

#include "BaseInputBlock.h"
#include "MaleChannel.hpp"
#include "../ProjectFileIO/PropertySet.h"

class SpinBoxInputBlock : public QObject, public BaseInputBlock {
Q_OBJECT

public:
    explicit SpinBoxInputBlock(Connector *connector, QWidget *widget, PropertySet *property_set) :
            BaseInputBlock(connector, widget, property_set) {
        spin_box = new QSpinBox(widget);
        male_plugs_of_block.emplace_back(connector->newMale<int>(_property_set));

        connect(spin_box, &QSpinBox::valueChanged, this, &SpinBoxInputBlock::setData);
    }

private:
    QSpinBox *spin_box;

private slots:
    void setData(int i){
        std::get<MaleChannel<int>*>(male_plugs_of_block.at(0))->SetData(i);
    }
};


#endif //LUI_SPINBOXINPUTBLOCK_H
