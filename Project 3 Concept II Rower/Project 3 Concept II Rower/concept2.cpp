//
//  main.cpp
//  Project 3 Concept II Rower
//
//  Created by Melody Chen on 1/25/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <climits>
#include <cassert>
//#include <fstream>

bool isValidRowerString(string rowerString);
int number( string s, int& startingposition );
int numberZ( string s, int& startingposition );
int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);
int getIndex(string s, char c, int index);
int getIndex(string s, string str, int index);
double fundraiser(string rowerString);
//void testCases();

int main() {
    assert(isValidRowerString("   5:00 500 s/m    500 m  600")==true);//tests for valid
    assert(isValidRowerString("   5:00")==false);//missing data
    assert(isValidRowerString("   5:00 500 s/m    ")==false); //missing data
    assert(isValidRowerString("   5:00 500 s/m    500 m")==false); //missing data
    assert(isValidRowerString("   5:5 500 s/m    500 m  600")==false); //extra seconds value
    assert(isValidRowerString("   05:50 500 s/m    500 m  600")==false); //leading zero
    assert(isValidRowerString("   5: 50 500 s/m    500 m  600")==false); //extra seconds value
    assert(isValidRowerString("   000005:50 500 s/m    500 m  600")==false); //leading zero
    assert(isValidRowerString("   :00 500 s/m    500 m  600")==true);//tests for no minute value
    assert(isValidRowerString("   :60 500 s/m    500 m  600")==false); //invalid seconds value
    assert(isValidRowerString("   5 :59 500 s/m    500 m  600")==false); //extra spaces
    assert(isValidRowerString("   59: 500 s/m    500 m  600")==false); //missing seconds value
    assert(isValidRowerString("   0:50 500 s/m    500 m  600")==false); //invalid minute value
    assert(isValidRowerString("   50:0 500 s/m    500 m  600")==false); //single 0 value for seconds
    assert(isValidRowerString("   555:50 500 s/m    500 m  600")==false); //invalid minute value
    assert(isValidRowerString("   a60:50 500 s/m    500 m  600")==false); //invalid leading character
    assert(isValidRowerString("   5:a50 500 s/m    500 m  600")==false); //invalid character in string
    assert(isValidRowerString("   ::50 500 s/m    500 m  600")==false); //extra colon
    assert(isValidRowerString("   5:050 500 s/m    500 m  600")==false); //leading zero for seconds value
    assert(isValidRowerString("   5:05 500     s/m    500 m  600")==false); //extra spaces
    assert(isValidRowerString("   5:05 500 00 s/m    500 m  600")==false); //extra zeroes
    assert(isValidRowerString("   5:05 50s/m    500 m  600")==false); //missing spaces
    assert(isValidRowerString("   5:05     500 s/m    500 m  600")==true); //tests for validity
    assert(isValidRowerString("   5:05 1000 s/m    500 m  600")==false); //s/m value too large
    assert(isValidRowerString("   5:05 0500 s/m    500 m  600")==false); //extra leading zeroes
    assert(isValidRowerString("   5:05 499 s/m    500 m  600")==true);
    assert(isValidRowerString("   5:05 500 ssm    500 m  600")==false); //wrong spelling
    assert(isValidRowerString("   5:05 500 s /m    500 m  600")==false); //extra spaces
    assert(isValidRowerString("   5:05 100 s/ m    500 m  600")==false); //extra spaces
    assert(isValidRowerString("   5:05 100 s    500 m  600")==false); //wrong spelling
    assert(isValidRowerString("   5:00 500 s/m    0 m  600")==false); //zero for distance rowed
    assert(isValidRowerString("   5:00 500 s/m    50m  600")==false); //missing space
    assert(isValidRowerString("   5:00 500 s/m    -50 m  600")==false); //negative values
    assert(isValidRowerString("   5:00 500 s/m    50  m  600")==false); //extra space
    assert(isValidRowerString("   5:00 500 s/m    50 s  600")==false); //wrong spelling
    assert(isValidRowerString("   5:00 500 s/m    1000 m  600")==true); //can handle large distance rowed
    assert(isValidRowerString("       5:00 500 s/m 50 m  600")==true); //can handle extra spaces
    assert(isValidRowerString("   5:00 500 s/m    50 00 m  600")==false); //extra zeroes
    assert(isValidRowerString("   5:00 500 s/m    500 m  1000")==false); //heartRate value invalid
    assert(isValidRowerString("   5:00 500 s/m    500 m  0")==false); //heartRate value cannot be zero
    assert(isValidRowerString("   5:00 500 s/m    500 m  -500")==false); //negative heartRate
    assert(isValidRowerString("   5:00 500 s/m    500 m  50 50")==false); //extra numbers
    assert(isValidRowerString("   5:00 500 s/m    500 m  a50")==false); //extra char
    assert(isValidRowerString("   5:00 500 s/m    500 m  50abc")==false); //extra chars
    assert(elapsedSeconds("       5:00    400 s/m 50 m  1999")==-1); //return -1 for invalid rowerString
    assert(elapsedMinutes("       50:00    400 s/m 70 m  199")==50); //func returns correct min value
    assert(elapsedSeconds("       50:00    400 s/m 70 m  199")==0); //function reuturns correct seconds value
    assert(strokesPerMinute("       50:00    400 s/m 70 m  199")==400); //function returns correct s/m value
    assert(totalDistance("       50:00    400 s/m 70 m  199")==70); //function returns correct distance rowed
    assert(heartRate("       50:00    400 s/m 70 m  199")==199); //function returns correct heartRate
    //testCases();
    assert( fundraiser( "12:14    28 s/m     42 m    110" ) == 4.00 );  // $4.00 = 8 * 0.50
    
    assert( fundraiser( "asdfrasd . 12:14    28 s/m     42 m    110" ) == 0.00 );  // invalid
    
    assert( fundraiser( "48:14    28 s/m     6042 m    160" ) == 11.00 );  // $11.00 = 6 * $1.00 + 8 * 0.50 + $1.00
    return 0;
}

//reads in text file of test cases
/*
void testCases()
{
    string filename = "myfile.txt";
    ifstream file;
    file.open(filename.c_str());
    if(!file.is_open()){
        cerr<< "Error opening file: "
        <<filename
        <<". Aborting program."<<endl;
    }
    int lineCount = 0;
    string line;
    while(file.good())
    {
        int temp =0;
        getline(file, line);
        int num1 = getIndex(line,'"', temp);
        int num2 = getIndex(line,'"', 1);
        string s = line.substr(num1+1, num2-num1-1);
        assert(isValidRowerString(s)==true);
        lineCount++;
        temp =0;
    }
    cerr<<"all test cases of Danning's passed!"<<endl;
    file.close();
}
*/
double fundraiser(string rowerString)
{
    double raised = 0;
    if(isValidRowerString(rowerString)){
        raised+=totalDistance(rowerString)/1000;
        if(strokesPerMinute(rowerString)>=20){
            raised+=(strokesPerMinute(rowerString)-20)*0.5;
        }
        if(heartRate(rowerString)>150)
            raised+=1;
    }
    return raised;
}
bool isValidRowerString(string rowerString)
{
    int currentPosition = 0;
    //check first condition
    int colon_loc = getIndex(rowerString, ':', currentPosition); //location of :
    int firstNum = number(rowerString, currentPosition);
    int secNum;

    //current loc needs to be at colon, or else false
    if(colon_loc==currentPosition)
        //makes sure that first num is either right before colon or right after
    {
        if(firstNum==-1){
            int temp = colon_loc+1;
            if(numberZ(rowerString, temp)==-1) //if there is sec num after colon n its length
                return false;
        }else if(!(firstNum<60 && firstNum>0))
            return false;
    }else{
        return false;
    }
    //lets say first num is okay or no first num but colon in right place
    currentPosition = colon_loc+1;
    secNum=numberZ(rowerString, currentPosition);
    if(!(secNum<60 && secNum>=0)) return false;
    if(currentPosition!=colon_loc+3) return false;
    
    //SECOND CONDITION
    int thirdNum = number(rowerString, currentPosition);
    if(!(thirdNum>0 && thirdNum<1000)) return false;
    //current loc rn needs to be a space and then s/m
    if(rowerString[currentPosition]!=' ') return false;
    //check if s/m is at the right place
    if(getIndex(rowerString, "s/m", currentPosition)!=currentPosition+4) return false;
    currentPosition = currentPosition+4;
    
    //THIRD CONDITION
    int fourthNum = number(rowerString, currentPosition);
    if(fourthNum==-1) return false;
    if(getIndex(rowerString, "m", currentPosition)!=currentPosition+2) return false;
    currentPosition = currentPosition+2;
    
    //FOURTH CONDITION
    int fifthNum = number(rowerString, currentPosition);
    if(fifthNum==-1) return false;
    if(!(fifthNum>0 && fifthNum<1000)) return false;
    
    //NO EXTRA ENDING CHARACTER or SPACE
    if(currentPosition!=rowerString.size()) return false;
    
    //ALL CONDITION PASSES
    return true;
}

int elapsedMinutes(string rowerString){
    //checks if rowerString is valid
    if(isValidRowerString(rowerString) == false) return -1;
    int currentPosition = 0;
    //get elapsedMinutes
    int firstNum = number(rowerString, currentPosition);
    if(firstNum == -1) return 0;
    return firstNum;
}

int elapsedSeconds(string rowerString){
    //checks if rowerString is valid
    if(isValidRowerString(rowerString) == false) return -1;
    //update currentPosition to get elapsedSeconds
    int colon_loc = getIndex(rowerString, ':', 0);
    int currentPosition = colon_loc + 1;
    int secNum = numberZ(rowerString, currentPosition);
    return secNum;
}

int strokesPerMinute(string rowerString){
    //checks if rowerString is valid
    if(isValidRowerString(rowerString) == false) return -1;
    //update currentPosition to get strokesPerMinute
    int colon_loc = getIndex(rowerString, ':', 0);
    int currentPosition = colon_loc + 1;
    numberZ(rowerString, currentPosition);
    int thirdNum = number(rowerString, currentPosition);
    return thirdNum;
}

int totalDistance(string rowerString){
    //checks if rowerString is valid
    if(isValidRowerString(rowerString) == false) return -1;
    //update currentPosition to get totalDistance
    int colon_loc = getIndex(rowerString, ':', 0);
    int currentPosition = colon_loc + 1;
    numberZ(rowerString, currentPosition);
    number(rowerString, currentPosition);
    currentPosition+=4;
    int fourthNum = number(rowerString, currentPosition);
    return fourthNum;
}

int heartRate(string rowerString){
    //checks if rowerString is valid
    if(isValidRowerString(rowerString) == false) return -1;
    //update currentPosition to get totalDistance
    int colon_loc = getIndex(rowerString, ':', 0);
    int currentPosition = colon_loc + 1;
    numberZ(rowerString, currentPosition);
    number(rowerString, currentPosition);
    currentPosition+=4;
    number(rowerString, currentPosition);
    currentPosition+=2;
    int fifthNum = number(rowerString, currentPosition);
    return fifthNum;
}

//returns first found location of certain char from index
int getIndex(string s, char c, int index)
{
    for(int k = index; k<s.size();k++)
    {
        //if find the char in s
        if(s[k]==c){
            return k;
        }
    }
    return -1;
}

//return location at end of s+1 of certain str from index
int getIndex(string s, string str, int index)
{
    for(int k=index; k<s.size();k++){
        //if find s[0] anywhere in s[k]
        if(s[k] == str[0]){
            for(int z=1; z<str.size();z++){
                if(s[k+z]!=str[z]) return -1;
            }
            return k+str.size();
        }
    }
    return -1;
}

//provided code, finds num at index ignoring spaces, does not take leading zeroes
int number(string s, int& startingposition)

{
    int result = -1;
    //ignore leading whitespace
    while (startingposition < s.length() &&  isspace( s.at( startingposition ) ))
    {
        startingposition = startingposition + 1;
    }
   // no leading zeros
   if (startingposition < s.length())
   {
        if (s.at( startingposition ) >= '1' && s.at( startingposition ) <= '9')
        {
            result = 0;
            while (startingposition < s.length() && s.at( startingposition ) >= '0'
                   && s.at( startingposition ) <= '9')
            {
                int value = s.at( startingposition ) - '0';
                result = (result * 10) + value;
                /// move on down the road
                startingposition = startingposition + 1;
            }
        }
    }
    return(result);
}

//stricter number and allows for zero inputs
//does not allow for num greater than two digits
int numberZ(string s, int& startingposition)

{
    int result = -1;
    int init = startingposition;
    if (startingposition < s.length())
    {
        //allows for zero
        if (s.at( startingposition ) >= '0' && s.at( startingposition ) <= '9')
        {
            result = 0;
            while (startingposition < s.length() && s.at( startingposition ) >= '0'
                   && s.at( startingposition ) <= '9')
            {
                if(startingposition>=init+2)
                    return -1;
                int value = s.at( startingposition ) - '0';
                result = (result * 10) + value;
                /// move on down the road
                startingposition = startingposition + 1;
            }
        }
    }
    return(result);
}
