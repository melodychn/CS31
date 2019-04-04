//
//  Pet.hpp
//  SampleClass
//
//  Created by Melody Chen on 2/20/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#ifndef Pet_h
#define Pet_h

using namespace std;
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>


class Pet
{
    //lacking any guidance, C++ file assume private
    
public:
    //constructor
    Pet(); //default constructor no arguments
    //cannot make object without constructors
    //extremely weird, if you have no constructor, C++ provides default parameterless constructor
    Pet(string aName, string aBreed, int aAge);
    //driver code convenience
    
    //comon part of a class
    string getName(); //getter... "accessor"  lets you access private information
    void setName(string aName); //setter... "mutator" lets you change your object
    
    //leftover
    void feed();
    void play();
    void speak();
    
    enum KIND {DOG, CAT, FISH, SNAKE, TURTLE, HAMSTER};
    
    
private:
    string name;
    int age;
    string breed;
    double weight;
    
};


#endif /* Pet_hpp */
