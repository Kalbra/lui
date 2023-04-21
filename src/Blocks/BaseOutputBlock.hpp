//
// Created by kalle on 4/16/23.
//

#ifndef LUI_BASEOUTPUTBLOCK_HPP
#define LUI_BASEOUTPUTBLOCK_HPP

#include <vector>
#include <QString>
#include <QWidget>

#include "BaseUpdate.h"
#include "Connector.hpp"
#include "FemaleChannel.hpp"


class BaseOutputBlock : public BaseUpdate {
public:
    BaseOutputBlock(Connector *connector, QWidget *widget, PropertySet *property_set){
        _connector = connector;
        _property_set = property_set;
    }

    FemalePointerVector GetFemalePlugs(){
        return female_plugs_of_block;
    }

    PropertySet getPropertySet(){
        return *_property_set;
    }

    virtual void update(){};

protected:
    FemalePointerVector female_plugs_of_block;
    Connector *_connector;
    PropertySet *_property_set;
};


#endif //LUI_BASEOUTPUTBLOCK_HPP
