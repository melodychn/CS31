//
//  Ticket.cpp
//  Project 5 BoxOffice
//
//  Created by Melody Chen on 2/23/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include "Ticket.h"
Ticket::Ticket(string row, int seat, string event, string venue, double price,KIND kind, string daytime)
{
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    mKind = kind;
    mDayTime = daytime;
}

string Ticket::getRow()
{
    return mRow;
}
int Ticket::getSeat()
{
    return mSeat;
}
string Ticket::getEvent()
{
    return mEvent;
}
string Ticket::getVenue()
{
    return mVenue;
}
double Ticket::getPrice()
{
    return mPrice;
}

void Ticket::setPrice(double price)
{
    mPrice = price;
}
Ticket::KIND Ticket::getKind()
{
    return mKind;
}
string Ticket::getDayTime()
{
    return mDayTime;
}

