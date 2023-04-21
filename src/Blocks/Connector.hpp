//
// Created by kalle on 4/17/23.
//

#ifndef LUI_CONNECTOR_HPP
#define LUI_CONNECTOR_HPP

#include <vector>
#include <variant>

#include "BaseUpdate.h"
#include "FemaleChannel.hpp"
#include "MaleChannel.hpp"


class Connector {
public:
    Connector() = default;

    template <class DataStream>
    MaleChannel<DataStream> *newMale(PropertySet *property_set){
        auto *male_channel = new MaleChannel<DataStream>(&current_channel_id, property_set);
        male_channels.push_back(male_channel);
        return male_channel;
    }

    template <class DataStream>
    FemaleChannel<DataStream> *newFemale(PropertySet *property_set, void (BaseUpdate::*update_pointer)()){
        auto *female_channel = new FemaleChannel<DataStream>(&current_channel_id, property_set, update_pointer);
        female_channels.push_back(female_channel);
        return female_channel;
    }

private:
    MalePointerVector male_channels;
    FemalePointerVector female_channels;

    ChannelId current_channel_id = 0;

};

#endif //LUI_CONNECTOR_HPP