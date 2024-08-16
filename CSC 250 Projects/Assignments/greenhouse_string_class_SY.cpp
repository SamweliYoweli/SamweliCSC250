// greenhouse_string_SY
// Date: created 2/25/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 3/3/2024
// Write a program using c class
// that allows a user to enter a full or partial name
// Then display a sorted list to display all seed types
// Lastly, it will display the total number of seeds planted

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// constants

// number of plants
const int MAX_PLANTS = 10;

// prototypes

// function that gets the data from the text file called
// seeds_planted.txt
void getdata(string plant_names[], int seeds[], int &num_plants);

// The sort data function is going to sort the plants in alphabetical order while keeping the number of seeds parallel to them.
void sortdata (string plant_names[], int seeds[], int num_plants);

// The display sorted data function is going to display the plants in alphabetical
// order left justified and number of seeds right justified.
void displaySortedData (const string plant_names[], const int seeds[], int num_plants);

// The totalseeds function is going to calculate the total seeds planted
int totalSeeds (const int seeds[], int num_plants);

// function to display the menu
void displayMenu();

//function to search the plants in the text file
void SearchPlants(const string names[], const int seeds[], int num_plants);


int main()
{

// declaring plantNames and seedsAmount and the user's choice
string plantNames[MAX_PLANTS];
int seedsAmount[MAX_PLANTS];
int num_plants;
int user_choice;


// calling the getdata function
getdata(plantNames, seedsAmount, num_plants);

do{
    // calling the displayMenu function
    displayMenu();
    cout << "Enter your choice: ";

//     while loop to validate if
//    user has entered an integer value
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
    // calling the searchPlants function
    SearchPlants(plantNames, seedsAmount, MAX_PLANTS);

 }
        break;

    case 2:
        {

    // calling the sorted data function
    sortdata(plantNames, seedsAmount, MAX_PLANTS);

    // calls the displaySortData function
    displaySortedData(plantNames, seedsAmount, MAX_PLANTS);

            break;
        }
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
            cout << "\nExiting the program!!!";
            break;
    default:
        cout << "\nYou have entered an invalid number. Please enter a number from 1 to 4.\n";
        }
    }
}
while(user_choice != 4);


    return 0;
}

//subfunctions

// function that gets the data from the text file called
// seeds_planted.txt
void getdata(string plant_names[], int seeds[], int &num_plants)
{

    ifstream inFile;

    // opens the text file
    inFile.open ("seeds_planted.txt");
    if(!inFile)
    {
        // executes when there is an error
        // opening our file
        cout << " Error opening seeds_planted.txt!!!\n";
        exit(101);
    }

    // assigns count the integer 0
    int count = 0;

    // getting the data from the file
    while(count < MAX_PLANTS && inFile >> seeds[count])
    {
        inFile.ignore();
        getline(inFile, plant_names[count]);
        count++;
    }

    num_plants = count;

    // closes the file
    inFile.close();

    return;
}

//The sort data function is going to sort the plants in alphabetical order while keeping the number of seeds parallel to them.
void sortdata (string plant_names[], int seeds[], int num_plants)
{
    // we are going to go through each element in the array
    for(int i=0; i< num_plants-1; i++)
    {
        // We are going to assume that our current index
        // has the our smallest value
        int minimum = i;


        // Let's find the index of our smallest element
        // in our unsorted part of the array
        for(int j= i + 1; j < num_plants; ++j)
        {
            // Let's compare our current element with the
            // element in the element at minimum
                // if our current element is smaller
                // then let's update our minimum to our current index
            if(plant_names[j] < plant_names[minimum])
            {
                minimum = j;
            }
        }

        // swapping our plant names

        // We will swap our current element with the
        // smallest element we have found
        string tempPlantName = plant_names[i];
        plant_names[i] = plant_names[minimum];
        plant_names[minimum] = tempPlantName;

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
    // we are initialzing our variable
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
void displaySortedData (const string names[], const int seeds[], int num_plants)
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

//function to search the plants in the text file
void SearchPlants(const string names[], const int seeds[], int num_plants)
{

    //clearing newline for our input buffer
    cin.ignore();

    // We will prompt the user
    cout << "Enter a plant name: ";

    // defining an array that's going to hold
    // our user's input for our search value
    string searchPlants;

    // Read the user's input for our search value
    getline(cin,searchPlants);

    cout << "\nThe plants matching or partially matching " << searchPlants << ":" << endl;

    cout << setw(20) << left << "Plant Name: " << setw(10) << right << "Seeds Amount " << endl;

 // We will search for plants that are exact matches
// or partial matches.
 for(int i = 0; i < num_plants; i++)
 {
    // We are checking to see whether our search value
    // was found in the current plant name
    if( names[i].find(searchPlants) != string::npos)
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


