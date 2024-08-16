// Include guard
#ifndef RIDE_H
#define RIDE_H
#include <string>
#include <iomanip>
using namespace std;

// Note**
// The program is returning boolean values
// and has an extra column for the
// ratio of riders to wranglers
// for the extra credit points

class Ride
{

// private class members
private:
    string name;
    float time;
    int wrangler;
    float cost;
    int riders;

// public class functions
public:

     // 1st constructor it’s a default constructor that
    // Initializes our Ride object to set all
   // the member variables to zero.
    Ride()
    {
        // setting all our fields
        // to zero
        name = " ";
        time = 0.0;
        wrangler = 0;
        cost = 0.0;
        riders = 0;
    }

    // 2nd constructor
   // Initializes our Ride object to our provided
   // values for name, time, wrangler, cost, and riders.

    Ride(string n, float t, int w, float c, int r)
    {
        name = n;
        time = t;
        wrangler = w;
        cost = c;
        riders = r;
    }

    // Mutators
    void setName(string);
    bool setTime(float);
    bool setWrangler(int);
    bool setCost(float);
    bool setRiders(int);

     // Accessors
    string getName() const
    { return name; }

    float getTime() const
    { return time; }

    int getWrangler() const
    { return wrangler; }

    float getCost() const
    { return cost; }

    int getRiders() const
    { return riders; }

    float getRevenue() const
    { return cost*riders; }

    float getRatio() const
    { return static_cast<float>(riders)/wrangler; }


};
#endif // RIDE_H

