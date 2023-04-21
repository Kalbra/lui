//
// Created by kalle on 4/17/23.
//

#ifndef LUI_CHANNEL_HPP
#define LUI_CHANNEL_HPP

#include <cstdint>

#include "../ProjectFileIO/PropertySet.h"

typedef uint16_t ChannelId;


class Channel{
public:
    explicit Channel(ChannelId *current_channel_id, PropertySet *property_set){
        channel_id = *current_channel_id;
        *current_channel_id = *current_channel_id + 1;

        channel_properties = property_set;

        channel_properties->addDouble("CHANNEL_ID", static_cast<double>(channel_id));
        qDebug() << channel_id;
    }

    uint16_t getChannelId(){
        return channel_id;
    }

protected:
    PropertySet *channel_properties;

private:
    ChannelId channel_id;

};


#endif //LUI_CHANNEL_HPP
