//
//  main.cpp
//  SampleClass
//
//  Created by Melody Chen on 2/20/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include <iostream>
#include "Pet.h"

int main() {
    Pet p;
    cout<< p.getName() << endl;
    Pet pixie("Pixie", "Poodle", 1);
    cout<< pixie.getName() << endl;
    return 0;
    
    //only error when you say you will make something, and someone tries to call those functions
    //if no one calls the functions you didn't implemented ==> no error
}
