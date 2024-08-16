// Turkey_SY
// Date: created 2/4/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 2/07/2024
// Write a program that calculates and displays
// the amount of feed the turkey needs each day

// Need functions to first fill the array
// Calculate the day totals
// Calculate the week totals
// Calculate the overall total
// Display the data

#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const int DAYS = 7;
const int WEEKS = 16;

//Prototypes

// function to fill the array
void FillArray(float data[][DAYS], int weeks, int days);

// function to calculate and return the overall total
float calcTurkeyTot(const float data[][DAYS], int weeks);

// function calculates the weekly turkey feed total
void calcTurkeyWeekTot(const float data[][DAYS], float week_totals[],
                        int weeks);

// function to calculate the day totals
void calcTurkeyDayTot(const float data[][DAYS], int weeks,
                      float day_totals[]);

// function to display the Turkey feed schedule
void displayTurkey(const float data[][DAYS], const float week_totals[],
                   int weeks, const float day_totals[], float total);

int main()
{

// intializing Array2D
 float data[WEEKS][DAYS];

// intializing week_totals and day_totals
// with {0}
 float week_totals[WEEKS] = {0};
 float day_totals[DAYS] = {0};

 // declares total as a float data type
 // and assigns it the value 0
 float total = 0;


    // calling the fill array function
    FillArray(data, WEEKS, DAYS);

    // calls the function that calculates the total turkey feed
    calcTurkeyTot(data, WEEKS);

    // calls the function that calculates
    // the weekly total turkey feed
    calcTurkeyWeekTot(data, week_totals, WEEKS);

    // calls the function that calculates
    // the daily total turkey feed
    calcTurkeyDayTot(data, WEEKS, day_totals);

    // calls the function that displays
    // the turkey feed in the table
    displayTurkey(data, week_totals, WEEKS, day_totals, total);

    return 0;
}

// function to display the Turkey feed schedule
void displayTurkey(const float data[][DAYS], const float week_totals[],
                   int weeks, const float day_totals[], float total)
{
    // print the day headings
    cout << "\n\n\t";
    for(int d=0; d<DAYS; d++)
    {
        // prints the day number
        // we have the +1 to start the
        // days at day 1
        cout << setw(13) <<" Day:" << setw(2) << d+1;
    }
    cout << "       Row Totals\n";

    cout <<"______________________________________________________________________________________________________________________________________\n";

    // print the data set the row print
    // the columns for that row
    // then move to the next row
    for(int w=0; w < weeks; w++)
    {
        // prints the weeks
        cout <<" Week: " << setw(2) << w+1;

        // for loop that prints the data
        //
        for(int d=0; d < DAYS; d++)
            cout << setw(15) << data[w][d];

        cout << setw(14) << week_totals[w] << endl;
    }

cout <<"___________________________________________________________________________________________________________________________________________";

    // print the column totals
    cout << "\nTotals: ";
    for(int d=0; d < DAYS; d++)
    {
        cout << setw(15.9) << day_totals[d];
       total = total + day_totals[d];
    }
    cout << setw(14) << total << endl;

    return;
}

void FillArray(float data[][DAYS], int weeks, int days)
{
    // filling the first row in the value 50
    for(int j=0; j < days; ++j)
    {
        data[0][j] = 50;
    }

    // multiplier value
    float increment = 1.5;

    // fill each row with the
    // values multipled by 1.5
    for(int i = 1; i < weeks; ++i)
    {
        for(int j = 0; j < days; ++j)
        {
            data[i][j] = data[i-1][j] * increment;
        }
    }

    return;
}


// function to calculate and return the overall total
float calcTurkeyTot(const float data[][DAYS], int weeks)
{
    // assigns the float data type to total
    // and the value of 0
    float total = 0;

    // calculates the overall total
    for (int w=0; w < weeks; w++)
    {
        for(int d = 0; d < DAYS; d++)
        {
            total = total + data[w][d];
        }

    }

    return total;

}

// function calculates the weekly turkey feed total
void calcTurkeyWeekTot(const float data[][DAYS], float week_totals[], int weeks)
{
    // nested for loop calculates
    // weekly total turkey feed
    for (int w=0; w < weeks; w++)
    {
        week_totals[w] =0;
        for (int d=0; d < DAYS; d++)
        {
            week_totals[w] = week_totals[w] + data[w][d];
        }
    }

    return;

}


// function to calculate the day totals
void calcTurkeyDayTot(const float data[][DAYS], int weeks, float day_totals[])
{

    // nested for loop to calculate
    // the day totals
    for(int d=0; d< DAYS; d++)
    {
        day_totals[d] = 0;
        for(int w=0; w < weeks; w++)
        {
            day_totals[d] = day_totals[d] + data[w][d];
        }
    }
    return;

}


