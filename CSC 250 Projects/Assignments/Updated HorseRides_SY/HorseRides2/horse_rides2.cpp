// horse_rides
// Date: created 4/24/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 4/26/2024

// Write a program that uses a Ride2 class
// with private member variables and
// public member functions
// to display name of the ride by dynamically allocating
// the char array for the name field.

// The time required for the ride in hours
// the number of wranglers required on the ride
// the cost that riders pay for the ride
// and the number of riders allowed on the ride

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ride2.h"

using namespace std;

// constants
const int SIZE = 5;

// displays all our data
void displayData(const Ride2 stable[],int size);

// function to change the ride name into upper case
void nameToUpper(char *str);

int main()
{
    // initializing 5 ride objects with our data
    Ride2 stable[SIZE] = {
        Ride2(const_cast<char*> ("Tree Line"), 2.5, 3, 150, 7.0),
        Ride2(const_cast<char*> ("Beaver Creek"), 1.5, 2, 75, 8.0),
        Ride2(const_cast<char*> ("Pine Lake"), 0.5, 2, 40, 10.0),
        Ride2(const_cast<char*> ("Outer Ranch"), 3.0, 3, 200, 5.0),
        Ride2(const_cast<char*> ("Wild Meadow"), 1.0, 2, 60, 10.0)
    };

    // calls the display data function
    displayData(stable,SIZE);
    cout << endl;

    return 0;
}

// displays all our data
void displayData(const Ride2 stable[], int size)
{
    // declaring our total_time
    // total_wranglers and total_riders
    // and total_revenue and total_cost and
    // total_ratio variables and
    // initializing them to 0
    float total_time = 0.0;
    int total_wranglers = 0;
    float total_cost = 0.0;
    int total_riders = 0;
    float total_revenue = 0.0;
    float total_ratio = 0.0;
    char nameBuffer[100];

    cout << left << setw(15) << "Name" << setw(6) << "Time"
    << setw(14) << "Wranglers" << setw(10) << "Cost" << setw(10)
    << "Riders" << setw(10) << "Revenue" << setw(10) << "Ratio" << endl;
    cout << "_______________________________________________________________________" << endl;


    // for loop to display all the data
    // from our array in main while changing
    // the name to upper case using a recursive function
    for(int i = 0; i < size; i++)
    {
        // Gets us the name of the current Ride2 object
        stable[i].getName(nameBuffer, sizeof(nameBuffer));

        // changes the name to uppercase
        nameToUpper(nameBuffer);

        // displays the ride data
        cout << left << setw(15) << nameBuffer;
        cout << setw(10) << fixed << setprecision(2) << stable[i].getTime();
        cout << setw(10) << stable[i].getWrangler();
        cout << setw(12) << fixed << setprecision(2) << stable[i].getCost();
        cout << setw(8) << stable[i].getRiders();
        cout << setw(10) << fixed << setprecision(2) << stable[i].getRevenue();
        cout << setw(6) << fixed << setprecision(2) << stable[i].getRatio() << endl;

    }
    cout << "_______________________________________________________________________" << endl;

    // for loop to calculate the total_time
    // and total_wranglers and total_cost
    // and total_riders and total_revenue
    // and total_ratio
    for(int i = 0; i < size; i++)
    {
        total_time += stable[i].getTime();
        total_wranglers += stable[i].getWrangler();
        total_cost += stable[i].getCost();
        total_riders += stable[i].getRiders();
        total_revenue += stable[i].getRevenue();
        total_ratio += stable[i].getRatio();
    }

    // calculating the average ratio
    total_ratio = (total_ratio)/(size);

    // displays the totals of each column
    cout << left << setw(15) << "Totals ";
    cout << setw(9) << fixed << setprecision(2) << total_time;
    cout << setw(11) << total_wranglers;
    cout << setw(12) << fixed << setprecision(2) << total_cost;
    cout << setw(8) << total_riders;
    cout << setw(10) << fixed << setprecision(2) << total_revenue;
    cout << setw(10) << fixed << setprecision(2) << total_ratio;

    return;
}


// function to change the name into upper case
void nameToUpper(char *str)
{
    // this is our base case:
    // if our current character
    // is the null terminator
    // we return
    if(*str == '\0')
    {
        return;
    }

    else
    {
        // converting our current characters
        // to uppercase
        *str = toupper(*str);

        // we are calling our recursive function
        // nameToUpper for the next character
        nameToUpper(str+1);
    }

}
