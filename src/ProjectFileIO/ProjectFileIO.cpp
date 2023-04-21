//
// Created by kalle on 4/19/23.
//

#include "ProjectFileIO.h"

ProjectFileIO::ProjectFileIO(QString file, std::vector<BaseOutputBlock*> *output_blocks) {
    _file = file;
    _output_blocks = output_blocks;
}

QJsonObject ProjectFileIO::generatePropertySet(PropertySet property_set) {
    QJsonObject json_property_set;

    //Insert for double properties
    for(uint16_t i = 0; i < property_set.getDoubleSize(); i++){
        auto *key = new QString();
        auto *value = new double;
        property_set.getDoubleByIndex(i, key, value);
        json_property_set.insert(*key, QJsonValue(*value));
    }

    //Insert for string properties
    for(uint16_t i = 0; i < property_set.getStringSize(); i++){
        auto *key = new QString();
        auto *value = new QString;
        property_set.getStringByIndex(i, key, value);
        json_property_set.insert(*key, *value);
    }

    //Insert for bool properties
    for(uint16_t i = 0; i < property_set.getBoolSize(); i++){
        auto *key = new QString();
        auto *value = new bool;
        property_set.getBoolByIndex(i, key, value);
        json_property_set.insert(*key, QJsonValue(*value));
    }
    return json_property_set;
}



void ProjectFileIO::save() {
    QFile file;
    file.setFileName(_file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QJsonDocument json_document;
    QJsonArray block_array;

    for(auto &_output_block : *_output_blocks){
        block_array.append(generatePropertySet(_output_block->getPropertySet()));
    }

    json_document.setArray(block_array);

    file.write(json_document.toJson());
    file.close();
}

