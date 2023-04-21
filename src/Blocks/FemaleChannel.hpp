//
// Created by kalle on 4/17/23.
//

#ifndef LUI_FEMALECHANNEL_HPP
#define LUI_FEMALECHANNEL_HPP

#include <vector>
#include <variant>

#include "BaseUpdate.h"
#include "Channel.hpp"


template <class DataStream>
class FemaleChannel : public Channel, protected BaseUpdatePointer{
public:
    explicit FemaleChannel(ChannelId *channel_id, PropertySet *property_set, void (BaseUpdate::*update_pointer)()) : Channel(channel_id, property_set){
        _update_pointer = update_pointer;
        channel_properties->addString("CHANNEL_TYPE", "female");
    };
    void setDataStreamPointer(DataStream *data_stream){
        data = data_stream;
    }
    DataStream GetData(){
        return *data;
    }

private:
    DataStream *data;
};

typedef std::vector<std::variant<FemaleChannel<int>*>> FemalePointerVector;

#endif //LUI_FEMALECHANNEL_HPP
