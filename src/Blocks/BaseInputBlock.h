//
// Created by kalle on 4/20/23.
//

#ifndef LUI_BASEINPUTBLOCK_H
#define LUI_BASEINPUTBLOCK_H

#include <vector>
#include <QString>
#include <QWidget>

#include "Connector.hpp"
#include "MaleChannel.hpp"

class BaseInputBlock {
public:
    BaseInputBlock(Connector *connector, QWidget *widget, PropertySet *property_set){
        _connector = connector;
        _property_set = property_set;
    }

    MalePointerVector getMalePlugs(){
        return male_plugs_of_block;
    }

protected:
    MalePointerVector male_plugs_of_block;
    Connector *_connector;
    PropertySet *_property_set;
};


#endif //LUI_BASEINPUTBLOCK_H
