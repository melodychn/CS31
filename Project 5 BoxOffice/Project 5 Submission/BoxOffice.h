//
//  BoxOffice.hpp
//  Project 5 BoxOffice
//
//  Created by Melody Chen on 2/23/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#ifndef BoxOffice_h
#define BoxOffice_h

#include<iostream>
using namespace std;
#include <string>
#include <climits>
#include <cassert>
#include "Ticket.h"
#include "Project5Helper.h"

class BoxOffice{
public:
    BoxOffice();
    Ticket buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
private:
    double calculatePrice(Ticket::KIND, string daytime, string row, string type = "");
    Project5Helper helper;
};

#endif /* BoxOffice_hpp */
