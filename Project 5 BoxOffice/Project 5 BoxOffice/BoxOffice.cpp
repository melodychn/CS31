//
//  BoxOffice.cpp
//  Project 5 BoxOffice
//
//  Created by Melody Chen on 2/23/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include "BoxOffice.h"
#include "Project5Helper.h"
BoxOffice::BoxOffice()
{
    //constructor
    
}
Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime)
{
    //calculate price
    double price = 0;
    //create a Ticket object
    Ticket t1(row, seat, event, venue, price, kind, daytime);
    return t1;
}
Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    //calculate price
    double price = calculatePrice(kind, daytime, row, "student");
    //create a ticket object
    Ticket t1(row, seat, event, "Royce Hall", price, kind, daytime);
    return t1;
}
Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    //calculate price
    double price = calculatePrice(kind, daytime, row, "staff");
    //create a ticket object
    Ticket t1(row, seat, event, "Royce Hall", price, kind, daytime);
    return t1;
}
Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    //calculate price
    double price = calculatePrice(kind, daytime, row);
    //create a ticket object
    Ticket t1(row, seat, event, "Royce Hall", price, kind, daytime);
    return t1;
}
double BoxOffice::calculatePrice(Ticket::KIND kind, string daytime, string row,  string type)
{
    double price = 0;
    //deals with which type of event
    switch(kind){
        case Ticket::KIND::ATHLETICGAME:
            price = 75.0;
            break;
        case Ticket::CONCERT:
            if(helper.endsWithPM(daytime))
                price = 65.0;
            else price = 50.0;
            break;
        case Ticket::MOVIE:
            price = 12.5;
            break;
        case Ticket::OTHER:
            if(helper.endsWithPM(daytime))
                price = 55.0;
            else price = 40.0;
    }
    //if orchestra seats...
    if(helper.startsWithOrchestra(row))
        price*=2;
    //for special discounts...
    if(type == "staff")
    {
        if(price >=40)
            price -= 20;
        else
            price*=0.9;
    }else if(type == "student")
    {
        if(price >=40)
            price -= 30;
        else
            price*=0.8;
    }
    
    return price;
}




