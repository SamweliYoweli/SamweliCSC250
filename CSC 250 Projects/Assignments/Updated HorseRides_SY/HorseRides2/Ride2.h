// Include guard
#ifndef RIDE2_H
#define RIDE2_H
#include <cstring>
#include <iomanip>
using namespace std;

// Note**
// The program is returning boolean values
// and has an extra column for the
// ratio of riders to wranglers
// for the extra credit points

class Ride2
{

// private class members
private:

    // pointer to dynamically allocate
    // memory for the Ride2 name
    char *name;
    float time;
    int wrangler;
    float cost;
    int riders;

// public class functions
public:

     // 1st constructor it’s a default constructor that
    // Initializes our Ride object to set all
   // the member variables to zero.
    Ride2()
    {
        // setting all our fields
        // to zero
        name = nullptr;
        time = 0.0;
        wrangler = 0;
        cost = 0.0;
        riders = 0;
    }

    // 2nd constructor
   // Initializes our Ride object to our provided
   // values for name, time, wrangler, cost, and riders.
    Ride2(char *n, float t, int w, float c, int r)
    {
        // allocating memory for the name
        name = new char[strlen(n) + 1];

        strcpy(name,n);

        time = t;
        wrangler = w;
        cost = c;
        riders = r;
    }

    // copy constructor
    Ride2(const Ride2 &obj)
    {

    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);

//    time = obj.time;
//    wrangler = obj.wrangler;
//    cost = obj.cost;
//    riders = obj.riders;

    // Mutators
     setName(obj.name);
     setTime(obj.time);
     setWrangler(obj.wrangler);
     setCost(obj.cost);
     setRiders(obj.riders);

    }

    // Destructor to release memory
    ~Ride2();

    // Mutators
      void setName(char *n);
      bool setTime(float);
      bool setWrangler(int);
      bool setCost(float);
      bool setRiders(int);

    // Accessors
    void getName(char *buffer, int max_letter) const;

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

