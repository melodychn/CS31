//
//  Pet.cpp
//  SampleClass
//
//  Created by Melody Chen on 2/20/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include "Pet.h"
using namespace std;

Pet::Pet() : name(""), age(0), breed("") //intialization list
{
    //purpose: called very beginning of the lifecycle
}

Pet::Pet(string aName, string aBreed, int aAge)
{
    name = aName;
    breed = aBreed;
    age = aAge;
}


string Pet::getName()
{
    return name;
}
void Pet::setName(string aName)
{
    name = aName;
}


