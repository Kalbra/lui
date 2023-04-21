//
// Created by kalle on 4/17/23.
//

#ifndef LUI_MALECHANNEL_HPP
#define LUI_MALECHANNEL_HPP

#include <vector>
#include <variant>

#include "BaseUpdate.h"
#include "FemaleChannel.hpp"

template <class DataStream>
class MaleChannel : public Channel {
public:
    explicit MaleChannel(ChannelId *channel_id, PropertySet *property_set) : Channel(channel_id, property_set){
        channel_properties->addString("CHANNEL_TYPE", "male");
    };

    void ConnectToFemale(FemaleChannel<DataStream> *female_channel){
        female_channel->setDataStreamPointer(&data);
        connected_female_channels.push_back(female_channel);
    }

    void SetData(DataStream data_){
        data = data_;
        for(auto &connected_female_channel : connected_female_channels){
            BaseUpdatePointer *update_pointer = connected_female_channel;

        }
    }

private:
    FemalePointerVector connected_female_channels;
    DataStream data;
};

typedef std::vector<std::variant<MaleChannel<int>*>> MalePointerVector;



#endif //LUI_MALECHANNEL_HPP
