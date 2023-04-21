//
// Created by kalle on 4/19/23.
//

#include "PropertySet.h"

#include <QDebug>

PropertySet::PropertySet() = default;

void PropertySet::addDouble(const QString& key, double value) {
    key_double_property_vector->emplace_back(key);
    double_property_vector->emplace_back(value);
}

void PropertySet::addString(const QString& key, const QString& value) {
    key_string_property_vector->emplace_back(key);
    string_property_vector->emplace_back(value);
}

void PropertySet::addBool(const QString& key, bool value) {
    key_bool_property_vector->emplace_back(key);
    bool_property_vector->emplace_back(value);
}

void PropertySet::getDoubleByIndex(uint16_t index, QString *key, double *value) {
    *key = key_double_property_vector->at(index);
    *value = double_property_vector->at(index);
}

void PropertySet::getStringByIndex(uint16_t index, QString *key, QString *value) {
    *key = key_string_property_vector->at(index);
    *value = string_property_vector->at(index);
}

void PropertySet::getBoolByIndex(uint16_t index, QString *key, bool *value) {
    *key = key_bool_property_vector->at(index);
    *value = bool_property_vector->at(index);
}

bool PropertySet::getDoubleByKey(const QString& key, double *value, uint16_t *index) {
    auto result = std::find(key_double_property_vector->begin(), key_double_property_vector->end(), key);
    //Found something
    if(result != key_double_property_vector->end()){
        *index = result - key_double_property_vector->begin();
        *value = double_property_vector->at(*index);
        return true;
    } else {
        return false;
    }
}

bool PropertySet::getStringByKey(const QString& key, QString *value, uint16_t *index) {
    auto result = std::find(key_string_property_vector->begin(), key_string_property_vector->end(), key);
    if(result != key_string_property_vector->end()){
        *index = result - key_string_property_vector->begin();
        *value = string_property_vector->at(*index);
        return true;
    } else {
        return false;
    }
}

bool PropertySet::getBoolByKey(const QString& key, bool *value, uint16_t *index) {
    auto result = std::find(key_bool_property_vector->begin(), key_bool_property_vector->end(), key);
    if(result != key_bool_property_vector->end()){
        *index = result - key_bool_property_vector->begin();
        *value = bool_property_vector->at(*index);
        return true;
    } else {
        return false;
    }
}

uint16_t PropertySet::getDoubleSize() {
    return double_property_vector->size();
}

uint16_t PropertySet::getStringSize() {
    return string_property_vector->size();
}

uint16_t PropertySet::getBoolSize() {
    return bool_property_vector->size();
}

void PropertySet::addStdDoubleByKey(const QString& key, double value) {
    if(!getDoubleByKey(key, nullptr, nullptr)){
        addDouble(key, value);
    }
}

void PropertySet::addStdStringByKey(const QString& key, const QString& value) {
    if(!getStringByKey(key, nullptr, nullptr)){
        addString(key, value);
    }
}

void PropertySet::addStdBoolByKey(const QString& key, bool value) {
    if(!getBoolByKey(key, nullptr, nullptr)){
        addBool(key, value);
    }
}

double PropertySet::getDoubleByKey(const QString& key) {
    auto *value = new double;
    auto index = new uint16_t;
    getDoubleByKey(key, value, index);
    return *value;
}

QString PropertySet::getStringByKey(const QString& key) {
    QString *value;
    getStringByKey(key, value, nullptr);
    return *value;
}

bool PropertySet::getBoolByKey(const QString& key) {
    bool *value;
    getBoolByKey(key, value, nullptr);
    return *value;
}

int PropertySet::getDoubleByKeyAsInt(const QString &key) {
    return static_cast<int>(getDoubleByKey(key));
}





