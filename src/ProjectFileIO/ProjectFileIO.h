//
// Created by kalle on 4/19/23.
//

#ifndef LUI_PROJECTFILEIO_H
#define LUI_PROJECTFILEIO_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <cstdint>

#include "PropertySet.h"
#include "../Blocks/BaseOutputBlock.hpp"

class ProjectFileIO {
public:
    explicit ProjectFileIO(QString file, std::vector<BaseOutputBlock*> *output_blocks);

    void save();

private:
    QString _file;
    std::vector<BaseOutputBlock*> *_output_blocks;

    static QJsonObject generatePropertySet(PropertySet property_set);
};


#endif //LUI_PROJECTFILEIO_H
