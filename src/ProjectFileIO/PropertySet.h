//
// Created by kalle on 4/19/23.
//

#ifndef LUI_PROPERTYSET_H
#define LUI_PROPERTYSET_H

#include <vector>
#include <cstdint>
#include <algorithm>

#include <QString>

/**
 * @brief Load and save data
 *
 * The property set stores data in 3 various types (double, string, bool).
 */
class PropertySet {
public:
    PropertySet();

    void addDouble(const QString&, double);
    void addString(const QString&, const QString&);
    void addBool(const QString&, bool);

    void getDoubleByIndex(uint16_t, QString*, double*);
    void getStringByIndex(uint16_t, QString*, QString*);
    void getBoolByIndex(uint16_t, QString*, bool*);

    bool getDoubleByKey(const QString&, double*, uint16_t*);
    bool getStringByKey(const QString&, QString*, uint16_t*);
    bool getBoolByKey(const QString&, bool*, uint16_t*);

    double getDoubleByKey(const QString& key);
    QString getStringByKey(const QString& key);
    bool getBoolByKey(const QString& key);

    int getDoubleByKeyAsInt(const QString& key);


    uint16_t getDoubleSize();
    uint16_t getStringSize();
    uint16_t getBoolSize();

    /**
     * @brief Add property, no override
     *
     * Adds an property if no property with the given key exists.
     * Implementation for double type.
     * @param key
     * @param value
     */
    void addStdDoubleByKey(const QString& key, double value);

    /**
     * @brief Add property, no override
     *
     * Adds an property if no property with the given key exists.
     * Implementation for string type.
     * @param key
     * @param value
     */
    void addStdStringByKey(const QString& key, const QString& value);

    /**
     * @brief Add property, no override
     *
     * Adds an property if no property with the given key exists.
     * Implementation for bool type.
     * @param key
     * @param value
     */
    void addStdBoolByKey(const QString& key, bool value);



private:
    std::vector<QString> *key_double_property_vector = new std::vector<QString>;
    std::vector<double> *double_property_vector = new std::vector<double>;

    std::vector<QString> *key_string_property_vector = new std::vector<QString>;
    std::vector<QString> *string_property_vector = new std::vector<QString>;

    std::vector<QString> *key_bool_property_vector = new std::vector<QString>;
    std::vector<bool> *bool_property_vector = new std::vector<bool>;
};


#endif //LUI_PROPERTYSET_H
