//
//  main.cpp
//  Project 2 Bruin Meal Plan Calculator
//
//  Created by Melody Chen on 1/14/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <climits>

int main() {
    //Breakfast cost values
    const double TICKET_B = 12.5;
    const double STAFF_B = 11.25;
    const double RES_B = 9.75;
    const double NONRES_B = 10;
    //Lunch cost values
    const double TICKET_L = 14.5;
    const double STAFF_L = 12.75;
    const double RES_L = 11.25;
    const double NONRES_L = 11.75;
    //Dinner cost values
    const double TICKET_D = 17;
    const double STAFF_D = 14.75;
    const double RES_D = 12.25;
    const double NONRES_D = 12.75;
    //Questions
    string q1 = "Ticket or BruinCard?";
    string q2 = "Breakfast, Lunch or Dinner?";
    string q3 = "Student or Staff?";
    string q4 = "Resident?";
    string e1 = "The kind value must either be Ticket or BruinCard.";
    string e2 = "The meal value must either be Breakfast, Lunch or Dinner.";
    string e3 = "The type value must either be Student or Staff.";
    string e4 = "The resident value must either be Yes or No.";
    string ans1 = "Thank you for eating at UCLA today.  Your meal cost is $";
    string ans2 = ".";
    
    //setup the output double format
    cout.setf( ios::showpoint ); //show decimal point even if not necessary
    cout.setf( ios::fixed ); //make sure not print in scientific notification
    cout.precision(2); //use two digit after decimal point whether needed or not
    
    //Ask the Questions
    
    //Question 1
    cout << q1;
    string r1;
    getline(cin, r1);
    cout << endl;
    
    //if error, then show error message
    if(r1 != "Ticket" && r1 != "BruinCard")
    {
        cout << e1 << endl;
        return -1;
    }

    //Question 2
    cout << q2;
    string r2;
    getline(cin, r2);
    cout << endl;
    
    //if error, then show error message
    if(r2 != "Breakfast" && r2 != "Lunch" && r2 != "Dinner")
    {
        cout << e2 << endl;
        return -1;
    }
    //if r1 == ticket, then don't need last two questions
    if(r1 == "Ticket")
    {
        if(r2 == "Breakfast")
        {
            cout << ans1 << TICKET_B << ans2 << endl;
        }else if(r2 == "Lunch")
        {
            cout << ans1 << TICKET_L << ans2 << endl;
        }else if(r2 == "Dinner")
        {
            cout << ans1 << TICKET_D << ans2 << endl;
        }
        return 0;
    }
    
    //Question 3
    cout << q3;
    string r3;
    getline(cin, r3);
    cout << endl;
    
    //if error, then show error message
    if(r3 != "Student" && r3 != "Staff")
    {
        cout << e3 << endl;
        return -1;
    }
    //if Question 3 answer is staff, skip last question
    if(r3 == "Staff")
    {
        if(r2 == "Breakfast")
        {
            cout << ans1 << STAFF_B << ans2 << endl;
        }else if(r2 == "Lunch")
        {
            cout << ans1 << STAFF_L << ans2 << endl;
        }else if(r2 == "Dinner")
        {
            cout << ans1 << STAFF_D << ans2 << endl;
        }
        return 0;
    }
    
    //Question 4
    cout << q4;
    string r4;
    getline(cin, r4);
    cout << endl;
    
    //if error, then show error message
    if(r4 != "Yes" && r4 != "No")
    {
        cout << e4 << endl;
        return -1;
    }
    //else
    if(r4 == "Yes")
    {
        if(r2 == "Breakfast")
        {
            cout << ans1 << RES_B << ans2 << endl;
        }else if(r2 == "Lunch")
        {
            cout << ans1 << RES_L << ans2 << endl;
        }else if(r2 == "Dinner")
        {
            cout << ans1 << RES_D << ans2 << endl;
        }
        return 0;
    }else if(r4 == "No")
    {
        if(r2 == "Breakfast")
        {
            cout << ans1 << NONRES_B << ans2 << endl;
        }else if(r2 == "Lunch")
        {
            cout << ans1 << NONRES_L << ans2 << endl;
        }else if(r2 == "Dinner")
        {
            cout << ans1 << NONRES_D << ans2 << endl;
        }
        return 0;
    }
    
    return 0;
}
