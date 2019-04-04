//
//  main.cpp
//  tests
//
//  Created by Melody Chen on 2/5/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void csReverse(char c[]);
void csReverse2(char c[]);
void printArray(char c[]);
int* computeFibonacciSequence(int& n);
void pointToNumber(int* & ptr);
int breakInTwo(int);
void removeNonAlpha(char[]);
bool insert(char str[], int max, int ind, char c);
int countNotFound( string first, string second )
{
    int result = 0;
    if (first.length() == 0 || second.length() == 0)
    {
        result = -1;
    }
    else
    {
        for (size_t secondSize = 0; secondSize < second.length(); secondSize++)
        {
            bool found = false;
            for (size_t firstSize = 0; firstSize < first.length(); firstSize++)
            {
                if (first.at(firstSize) == second.at(secondSize))
                {
                    found = true;
                }
            }
            if (!found)
            {
                result = result + 1;
            }
        }
    }
    return( result );
}

void removeNonAlpha(char m[]){
    for(int k=0; m[k]!='\0';k++){
        if(!isalpha(m[k])){
            int i;
            for(i = k; m[i+1]!='\0'; i++){
                m[i] = m[i+1];
            }
            m[i]='\0';
            k--;
        }
    }
}

void csReverse(char c[])
{
    int len = 0;
    while(c[len]!='\0') len++;
    for(int k=0; k<len/2; k++){
        char tmp = c[k];
        c[k] = c[len-1-k];
        c[len-1-k] = tmp;
    }
}
void csReverse2(char c[])
{
    char* ptr = c;
    int length = 0;
    while(*ptr!='\0'){
        length++;
        ptr++;
    }
    ptr--;
    char* ptr2 = c;
    for(int k = 0; k< length/2; k++){
        char temp = *ptr;
        *ptr = *ptr2;
        *ptr2 = temp;
        ptr--;
        ptr2++;
    }
}
void pointToNumber(int* & ptr)
{
    int * x = new int(10);
    ptr = x;
}

int breakInTwo(int num)
{
    int score1 = num%10;
    num/=10;
    int score2 = num%10;
    num/=10;
    cout<<num<<endl;
    return score1 + score2*10;
}

bool insert(char str[], int max, int ind, char c){
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    if(length>=max)
        return false;
    for(int k=length; k>=ind; k--){
        str[k+1] = str[k];
    }
    str[ind]=c;
    return true;
}
int main(){
    cout<<countNotFound("appplebb", "applewww");
    return 0;
}
