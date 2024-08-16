// Include guard
#include <iostream>
#include <string>
#include "Ride.h"
using namespace std;

// Note**
// The program is returning boolean values
// and has an extra column for the
// ratio of riders to wranglers
// for the extra credit points

    // Mutators
    void Ride::setName(string n)
    {
       name = n;
    }

    // function to set the time
    bool Ride::setTime(float t)
    {
        // declaring our rc variable as
        // a boolean value
        bool rc;

        // executes when t is greater than
        // zero and assigns the value of t
        // as time and sets rc as true
        if(t > 0)
        {
            time = t;
            rc = true;
        }

        // executes when t is less than zero
        // and sets rc as false
        else
        {
            cout << "Invalid Number\n";
            rc = false;
        }

        // returning our boolean
        // value rc
        return rc;

    }

    // function to set the number of wranglers
    bool Ride::setWrangler(int w)
    {
        // declaring our rc variable as
        // a boolean value
        bool rc;

        // executes when w is greater than
        // zero and assigns the value of w
        // as time and sets rc as true
        if(w > 0)
        {
            wrangler = w;
            rc = true;
        }

        // executes when t is less than zero
        // and sets rc as false
        else
        {
            cout << "Invalid Number\n";
            rc = false;
        }

        // returning our boolean
        // value rc
        return rc;
    }

    // function to set the cost
    bool Ride::setCost(float c)
    {
        // declaring our rc variable as
        // a boolean value
        bool rc;

        // executes when c is greater than
        // zero and assigns the value of c
        // as time and sets rc as true
        if(c > 0)
        {
            cost = c;
            rc = true;
        }

        // executes when t is less than zero
        // and sets rc as false
        else
        {
            cout << "Invalid Number\n";
            rc = false;
        }

        // returning our boolean
        // value rc
        return rc;

    }

    // function to set the number of riders
    bool Ride::setRiders(int r)
    {
        // declaring our rc variable as
        // a boolean value
        bool rc;

        // executes when r is greater than
        // zero and assigns the value of r
        // as time and sets rc as true
        if(r > 0)
        {
            riders = r;
            rc = true;

        }

        // executes when t is less than zero
        // and sets rc as false
        else
        {
            cout << "Invalid Number\n";
            rc = false;
        }

        // returning our boolean
        // value rc
        return rc;
    }








