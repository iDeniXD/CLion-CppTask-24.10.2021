//
// Created by Denis on 06/11/2021.
//

#ifndef TASK0_ISERIALIZABLE_H
#define TASK0_ISERIALIZABLE_H

#include "iostream"
using namespace std;

class ISerializable
{
public:
    virtual ~ISerializable();
    virtual string ToString()=0;
    virtual void FromString(string &s)=0;
};

#endif //TASK0_ISERIALIZABLE_H
