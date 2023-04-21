//
// Created by kalle on 4/21/23.
//

#ifndef LUI_BASEUPDATE_H
#define LUI_BASEUPDATE_H


class BaseUpdate {
public:
    BaseUpdate() = default;
    virtual void update(){};
};

class BaseUpdatePointer {
public:
    BaseUpdatePointer() = default;
    void (BaseUpdate::*_update_pointer)();
};


#endif //LUI_BASEUPDATE_H
