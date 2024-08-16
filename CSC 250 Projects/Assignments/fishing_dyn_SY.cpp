// Fishing_dyn_SY
// Date: created 2/13/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 2/15/2024

// Write a program that sorts participants number
// and puts it into ascending order while keeping
// their fish weight parallel to them
// additionally, binary search will
// check to make sure the search value is valid
// if invalid it will ask to enter a valid integer

// Additionally the program will read the first number
// from the text file to get the size of the element
// Then it will dynamically allocate the arrays
// and read the data from the file and process it.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

// constants

// Sentinel value stops binary search when entered
const int SENTINEL = -99;

//prototypes

// reads the size of the file
// then allocates the array
// finally it reads the data into the arrays
// The function prototype has changed from array notation
// to pointer notation
int readData(int* &array, float* &array2);

// sort the array in ascending order, using selection sort algorithm
// and keeping fish weight in parallel with array
void selectionSort(int ID[], float weight[], int max_size);

// prints the array
void display(const int ID[], const float weight[], int max_size);

//Binary search
int binarySearch(const int ID[], int max_size, int search_value);

int main()
{
    // declares pointer variables
    int* data1;
    float* data2;

    //declaring local variables
    int num_items;
    int search_value, results;

    //read the ID and fish weight
    num_items = readData (data1, data2);

   // sort the array in ascending order, using selection sort
    // and keep the fish weight parallel with the array
  selectionSort(data1, data2, num_items);

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
        // binarySearch (data1, num_items, search_value)
        results = binarySearch(data1, num_items, search_value);

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
            cout << "\nContestant ID: " << search_value <<" Fish weight: " << data2[results] << endl;
        }

            cout << "\nEnter the search value or " << SENTINEL << " to stop: ";

    }

    // releases the memory of data1 and data2
    delete[] data1;
    delete[] data2;

    data1 = nullptr;
    data2 = nullptr;

    return 0;
}

// function subprograms


// reads the size of the file
// then allocates the array
// finally it reads the data into the arrays
int readData(int* &array, float* &array2)
{

    int num_items;

   ifstream inFile;
   inFile.open("fish_dyn.txt");

   // The if statement will execute if the file fails to open
   // the else statement will execute when the file opens successfully
   if(!inFile)
    {
        cout << "Error opening fish_dyn.txt!!\n\n";
        array = nullptr;
        array2 = nullptr;
        num_items = 0;
    }
    else
    {

        // reads the numbers of items in the file
        inFile >> num_items;

        if(num_items > 0)
        {
            // allocates the space for array and array2
            array = new int[num_items];
            array2 = new float[num_items];

            // for loop will read data from file
            // since we have a specific number of elements
            for(int i=0; i < num_items; i++)
            {
                // changed array[i] and array2[i]
                // to pointer notation
                inFile >> *(array + i) >> *(array2 + i);
            }
        }
        else
        {
            num_items = 0;
            array = nullptr;
            array2 = nullptr;
        }

    }

    // closes the file
    inFile.close();

    // returns the number of items to main
    return(num_items);

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
void display(const int ID[], const float weight[], int max_size)
{
    // setting decimal placement to one
    cout << fixed << setprecision(1);
    cout << endl;

     //displays the contestant ID and Fish weight
    cout <<"    contestant ID        Fish Weight\n";
     for (int i = 0; i < max_size; i++)
    {
        cout << setw(8) << ID[i] << setw(20) << weight[i] << endl;
    }
    cout << endl;

    return;
}


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

   // returns the position
    return position;
}










