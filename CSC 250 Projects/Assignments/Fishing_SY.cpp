// Fishing_SY
// Date: created 1/22/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 1/29/2024
// Write a program that sorts participants number
// and puts it into ascending order while keeping
// their fish weight parallel to them

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

// constants

//max size of the array
const int SIZE = 50;

// Sentinel value stops binary search when entered
const int SENTINEL = -99;

//prototypes

// reads the contestantants number and their associated
// fish weight
// stores it back into main's arrays by passing by reference
int input(int ID[], float weight[], int max_size);

// sort the array in ascending order, using selection sort algorithm
// and keeping fish weight in parallel with array
void selectionSort(int ID[], float weight[], int max_size);

// print the array
void display(const int ID[], const float weight[], int max_size);

//Binary search
int binarySearch(const int ID[], int max_size, int search_value);

int main()
{
    //declaring local variables
    int contestant_ID[SIZE];
    float fish_weight[SIZE];
    int num_items;
    int search_value, results;

    //read the ID and fish weight
    num_items = input(contestant_ID, fish_weight, SIZE);

   // sort the array in ascending order, using selection sort
    // and keep the fish weight parallel with the array
  selectionSort(contestant_ID, fish_weight, num_items);

    // prompts the user to enter a search value
    cout << "Enter the search value or " << SENTINEL << " to stop: ";

    //  while loop is executed when the search value
    // is not equal to the SENTINEL value
    while(search_value != SENTINEL)
    {

    // while loop to validate if
   // user has entered an integer value
    while(!(cin >> search_value))
    {
        // explain the error
        cout << "\nError: enter a valid search value: ";

        // Clear the previous input
        cin.clear();
        // Discard previous input
        // ignores unwanted characters
        cin.ignore(123, '\n');
    }

        // assigns results with the value of
        // binarySearch(contestant_ID, num_items, search_value)
        results = binarySearch(contestant_ID, num_items, search_value);

        //if binarySearch returned -1, then search value was not found.
        if(results == -1)
        {
           cout << search_value << " was not found\n";
        }

        else
        {
            // Otherwise results contains the subscript of
            // the first 50 in the array
            cout << search_value << " was found at 0-based location " << endl;

           // displays the contestant's ID number
           // and the associated fish weight
            cout << "\nContestant ID: " << search_value <<" Fish weight: " << fish_weight[results] << endl;
        }

            cout << "\nEnter the search value or " << SENTINEL << " to stop: ";

    }

    //display(contestant_ID, fish_weight, num_items);

    return 0;
}

// function subprograms

// reads the contestant number and their associated
// fish weight
// stores it back into main's arrays by passing by reference
int input(int ID[], float weight[], int max_size)
{

    ifstream inputFile;
    int count;

    // read the contestant ID and fish weight
    // storing them back into main's dataspace

    // connect to fish.txt
    inputFile.open("fish.txt", ios::in);
    if(!inputFile)
    {
        cout << "Error opening fish.txt!!\n\n";
        exit(101);
    }

    count = 0;
    while(count < max_size && inputFile >> ID[count] >> weight[count])
    {
        count ++;
    }

    // closes the file;
    inputFile.close();

    // send the number of items in the array back to main
    return count;
}


// sort the array in ascending order, using selection sort algorithm
// and keeping fish weight in parallel with array
void selectionSort(int ID[], float weight[], int max_size)
{
    int smallest_loc;

    //Outer loop, move the wall through
    // the data, one item at a time,
    // stop when we're one from the end
    for(int wall = 0; wall < max_size-1; wall++)
    {

        smallest_loc = wall;

        // inner loop, find the smallest value
        // in the unsorted data
        // swap it to the front of the unsorted data

        for(int i = wall; i < max_size; i++)
        {
            if(ID[smallest_loc] > ID[i])
            {
                smallest_loc = i;
            }

        }

        // smallest value in the unsorted data
        // is in smallest_loc
        // swap smallest location with the value
        // with the value at wall
        swap(ID[smallest_loc], ID[wall]);
        swap(weight[smallest_loc], weight[wall]);

    }
    return;
}


// displays the array
//void display(const int ID[], const float weight[], int max_size)
//{
//    // setting decimal placement to one
//    cout << fixed << setprecision(1);
//    cout << endl;
//
//     //displays the contestant ID and Fish weight
//    cout <<"    contestant ID        Fish Weight\n";
//     for (int i = 0; i < max_size; i++)
//    {
//        cout << setw(8) << ID[i] << setw(20) << weight[i] << endl;
//    }
//    cout << endl;
//
//    return;
//}


//Binary search
int binarySearch(const int ID[], int max_size, int search_value)
{
    // declaring variables
   int first_loc, last_loc;
   int middle_loc;
   int position;

    //Starting with the entire array
    first_loc = 0;
    last_loc = max_size - 1;
    position = -1;


   while( (position == -1) && (first_loc <= last_loc) )
   {

        middle_loc = ((first_loc + last_loc) / 2);

        // executes when search value is
        // less than the middle location
        if(search_value < ID[middle_loc])
        {
            last_loc = middle_loc -1;
        }

        // executes when our search value
        // is greater than the middle location
        else if (search_value > ID[middle_loc])
        {
            first_loc = middle_loc + 1;
        }
        else // search value is equal
        {
            position = middle_loc;
        }
   }
    return position;
}










