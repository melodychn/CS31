//
//  Ticket.h
//  Project 5 BoxOffice
//
//  Created by Melody Chen on 2/23/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#ifndef Ticket_h
#define Ticket_h
#include<iostream>
using namespace std;
#include <string>
#include <climits>
#include <cassert>

class Ticket{
public:
    enum KIND {ATHLETICGAME, CONCERT, MOVIE, OTHER};
private:
    string mRow;
    int mSeat;
    string mEvent;
    string mVenue;
    double mPrice;
    KIND mKind;
    string mDayTime;
public:
    Ticket(string row, int seat, string event, string venue, double price,KIND kind, string daytime); //constructor
    string getRow();
    int getSeat();
    string getEvent();
    string getVenue();
    double getPrice();
    void setPrice(double price);
    KIND getKind();
    string getDayTime();
};

#endif /* Ticket_h */
