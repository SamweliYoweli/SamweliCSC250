// greenhouse_cstring_SY
// Date: created 2/25/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 3/3/2024
// Write a program using cstring
// that allows a user to enter a full or partial name
// Then display a sorted list to display all seed types
// Lastly, it will display the total number of seeds planted

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// constants

// number of plants
const int MAX_PLANTS = 10;

// max length of plant name
const int PLANT_SIZE = 50;

// prototypes

// function that gets the data from the text file called
// seeds_planted.txt
int getdata(char names[][PLANT_SIZE], int seeds[], int max_plants);

// The sort data function is going to sort the plants in alphabetical order while keeping the number of seeds parallel to them.
void sortdata (char names[][PLANT_SIZE], int seeds[], int num_plants);

// The display sorted data function is going to display the plants in alphabetical
// order left justified and number of seeds right justified.
void displaySortedData (const char names[][PLANT_SIZE], const int seeds[], int num_plants);

// The totalseeds function is going to calculate the total seeds planted
int totalSeeds (const int seeds[], int num_plants);

// function to display the menu
void displayMenu();

// function to search the plants in the text file
void SearchPlants(const char names[][PLANT_SIZE], const int seeds[], int num_plants);

int main()
{

// declaring plantNames and seedsAmount and the user's choice
char plantNames[MAX_PLANTS][PLANT_SIZE];
int seedsAmount[MAX_PLANTS];
int user_choice;

// calling the getdata function
getdata(plantNames, seedsAmount, MAX_PLANTS);

// do while loop is going to ask the user to enter
// a number from 1 to 4 and it will
// execute the action to the corresponding number.
do {
    displayMenu();
    cout << "Enter your choice: ";

    // while loop to validate if
   // user has entered an integer value
    while(!(cin >> user_choice))
    {
        // explain the error
        cout << "\nError: enter an integer between 1 and 4: ";

        // Clear the previous input
        cin.clear();
        // Discard previous input
        // ignores unwanted characters
        cin.ignore(123, '\n');
    }

    switch(user_choice){
        case 1:
            {
        // calling the search plants function
        SearchPlants(plantNames, seedsAmount, MAX_PLANTS);

            }
        break;
    case 2:
            {
    // calling the sorted data function
    sortdata(plantNames, seedsAmount, MAX_PLANTS);

    // calls the displaySortData function
    displaySortedData(plantNames, seedsAmount, MAX_PLANTS);
            }
            break;
        case 3:
            {

        // calling our total seeds function
        // and making the return value of it
        // equal to total
        int total = totalSeeds(seedsAmount, MAX_PLANTS);
        cout << endl;
        cout << "\nTotal Seeds: " << total << endl;

            break;
            }
        case 4:
            {
        cout << "\nExiting the program!!!\n";
        break;
    default:
            cout << "\nYou have entered an invalid number. Please enter a number from 1 to 4.\n";

            }

}
            } while(user_choice !=4);

    return 0;
}

//subfunctions

// function that gets the data from the text file called
// seeds_planted.txt
int getdata(char names[][PLANT_SIZE], int seeds[], int max_plants)
{

    ifstream inFile;

    //opens the text file
    inFile.open ("seeds_planted.txt");
    if(!inFile)
    {
        // executes when there is an error
        // opening our file
        cout << " Error opening seeds_planted.txt!!!\n";
        exit(101);
    }

    // getting the data from the file

    int numPlants = 0;
    while(numPlants < max_plants && inFile >> seeds[numPlants])
    {
        inFile.ignore();

        inFile.getline(names[numPlants], PLANT_SIZE);

        numPlants++;
    }

    // closes the file
    inFile.close();
    return numPlants;
}

//The sort data function is going to sort the plants in alphabetical order while keeping the number of seeds parallel to them.
void sortdata (char names[][PLANT_SIZE], int seeds[], int num_plants)
{
    // we are going to go through each element in the array
    for(int i=0; i< num_plants; i++)
    {
        // We are going to assume that our current index
        // has the our smallest value
        int minimum = i;

        // Let's find the index of our smallest element
        // in our unsorted part of the array
        for(int j= i +1; j < num_plants; j++)
        {
            // Let's compare our current element with the
            // element in the element at minimum
                // if our current element is smaller
                // then let's update our minimum to our current index
            if(strcmp(names[j], names[minimum]) < 0)
            {
                minimum = j;
            }
        }

        // swapping our plant names

        // We will swap our current element with the
        // smallest element we have found
        char tempPlantName[PLANT_SIZE];
        strcpy(tempPlantName, names[i]);
        strcpy(names[i], names[minimum]);
        strcpy(names[minimum], tempPlantName);

        // We are swapping our number of seeds
        // at the same time we swap the plant names
        // To keep the seed amount and the plant
        // name parallel to each other.
        int TempSeedsNUM = seeds[i];
        seeds[i] = seeds[minimum];
        seeds[minimum] = TempSeedsNUM;

    }

    return;
}

//The totalseeds function is going to display the number of seeds planted.
int totalSeeds (const int seeds[], int num_plants)
{
    // we are initializing our variable
    // at zero so it can store the total
    // number of seeds
    int total = 0;

    // Go through each element in the seed array
    for(int i=0; i< num_plants; i++)
    {
        // Let's add our seed count
        // of our current plant to our total
        total = total + seeds[i];

    }


    // returning the total number of seeds.
    return total;
}

// The display sorted data function is going to display the plants in alphabetical
// order left justified and number of seeds right justified.
void displaySortedData (const char names[][PLANT_SIZE], const int seeds[], int num_plants)
{

    cout << "\nSorted List: " << endl;

    cout << setw(20) << left << "Plant Name " << setw(10) << right << "Seeds Amount\n";
    // Iterate through each plant name
    // and seed count and display them both
    for(int i=0; i < num_plants; i++)
    {
        cout << setw(20) << left << names[i];
        cout << setw(10) << right << seeds[i] << endl;

    }

    return;
}

// function to display the menu
void displayMenu()
{
    // displays the user's choices
    cout << "\nMenu\n";
    cout << "1. Search seeds\n";
    cout << "2. Print the sorted list\n";
    cout << "3. Print the total plants\n";
    cout << "4. Exit\n";
    return;
}

// function to search the plants in the text file
void SearchPlants(const char names[][PLANT_SIZE], const int seeds[], int num_plants)
{

            // We will prompt the user
    cout << "Enter a plant name: ";

    // defining an array that's going to hold
    // our user's input for our search value
    char searchPlants[PLANT_SIZE];

     cin.ignore();

    // Read the user's input for our search value
    cin.getline(searchPlants, PLANT_SIZE);

    cout << "\nThe plants matching or partially matching " << searchPlants << "':'" << endl;

    cout << setw(20) << left << "Plant Name: " << setw(10) << right << "Seeds Amount " << endl;

    // We will search for plants that are exact matches
    // or partial matches.

     for(int i =0; i < num_plants; i++)
     {
        // use strstr to check whether our search value
    // was found in the current plant name
    if(strstr(names[i],searchPlants) != nullptr)
    {
        // When we find an exact match or partial match
        // we will display the corresponding plant name
        // and seed count

        cout << setw(20) << left << names[i];

        cout << setw(10) << right << seeds[i] << endl;

    }

     }

     return;

}


