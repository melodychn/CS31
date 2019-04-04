//
//  main.cpp
//  Discussion Problems
//
//  Created by Melody Chen on 1/18/19.
//  Copyright © 2019 Melody Chen. All rights reserved.
//

#include <iostream>
using namespace std;


#include <iostream>
#include <cmath>
using namespace std;

double g(double t1, double t2, double d, double D)
{
    return (2/(t1+t2)*(D/t2-d/t1));
}

void sumerror(double& sum, double g)
{
    double avg = 9.903;
    sum+= pow((g-avg),2);
    cout << "sum: " << sum << endl;
}
double getg()
{
    double t1, t2, d, D;
    cout << "t1:";
    cin >> t1;
    cout << "t2:";
    cin >> t2;
    d = 0.084;
    D = 0.272;
    double gg = g(t1,t2,d,D);
    cout<<"g: "<< gg<<endl;
    return gg;
}

int main()
{
    cout << "option 1/2: ";
    string op;
    getline(cin, op);
    if(op == "2"){
        double sum = 0;
        double g;
        double count = 0;
        string cond = "c";
        string temp;
        do{
            g = getg();
            sumerror(sum, g);
            count++;
            getline(cin, temp);
            cout<<"count: "<<count<<endl;
            cout << "Enter c to continue: ";
            getline(cin, cond);
        }while(cond == "c");
        double ans = pow((sum/(count-1)), 0.5)/pow(count, 0.5);
        cout << "calc error: " << ans <<endl;
    }else{
        double t1, t2, d, D;
        cout << "t1:" <<endl;
        cin >> t1;
        cout << "t2:" <<endl;
        cin >> t2;
        d = 0.084;
        D = 0.631;
        g(t1,t2,d,D);
    }
}


