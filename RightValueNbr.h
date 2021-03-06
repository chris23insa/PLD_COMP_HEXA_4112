#pragma once

#include <string.h>
#include <iostream>
#include "RightValue.h"

using namespace std;

class RightValueNbr : public RightValue
{
public:
    RightValueNbr() {}
    RightValueNbr(int nbr) : RightValue("",nbr) {};
    ~RightValueNbr() {};
    string toString()
    { return "RightValueNbr "+to_string(nbr)+"\n"; }
    string getId(){ return ""; };
    int getNbr(){ return nbr; };
    virtual bool estCst(list<string> & opti){ return true; };
};
