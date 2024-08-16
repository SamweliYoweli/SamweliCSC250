// Fishing_dyn_SY
// Date: created 4/1/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 4/5/2024

// Write a program that allows a user
// to add a record to a file
// and displays the data to the terminal
// Then allow the user to edit all quantities
// Finally allow the user to exit the program

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <limits>

using namespace std;

// constants
// size of our string
const int SIZE = 50;

// enumerator for the kind of plant
enum Kind
{
    FLOWER, VEGETABLE, GRASS, SHRUB
};

// enumerated data type for
// the user's choice
enum Choice
{
    ADD, PRINT, EDIT, EXIT
};

// structure for the plant
// details
struct Plants
{
char name[SIZE];
Kind type;
double cost;
int qty_available;

};

// function prototypes

// function to display the menu
void DisplayMenu();

// converts our plant type from an integer
// to its actual word/ string
void PrintType(Kind type);

// function that converts the menu options
// into its actual world/ string
string MenuOptions(Choice decision);

// function to add the user's input
// we reference our file as the function parameter
void AddData(fstream & PlantFile);

// function to display the user's input
// we reference our file as the function parameter
void PrintData(fstream & PlantFile);

// function to edit the user's input
// we reference our file as the function parameter
void EditData(fstream & PlantFile);


int main()
{
    //Plants data;
    int choice;

    // Opens a file for binary output.
    // truncates by default
    fstream DataFile;
    DataFile.open("plants.dat", ios::in | ios:: binary);


    if(!DataFile)
    {
        DataFile.clear();
        DataFile.open("plants.dat", ios::out | ios:: binary);
    }

    // closes the Data file
    DataFile.close();

   DataFile.open("plants.dat", ios::in | ios ::out| ios::binary);
   // DataFile.open("plants.dat", ios::in | ios ::out| ios::app | ios::binary);

    do{
         // displaying our menu;
        DisplayMenu();
        cin >> choice;
        cin.ignore();

        switch(choice){

        // When the user enters choice 1
        // It will add to the file
          case 1:
            {
            //calls our AddData function
            AddData(DataFile);
            }
            break;

        // When the user enters choice 2
        // the data from the file will be
        // printed to the screen
          case 2:
            {
            // calls our PrintData function
             PrintData(DataFile);
            }
            break;


        // When the user enters choice 3
        // The user will be able to edit the file
          case 3:
            {
                // calls the EditData function
                EditData(DataFile);
            }
            break;

        // When the user enter choice 4
        // The program is exited
          case 4:
            {
            cout << "\nExiting the program!!!\n";

            }
            break;

        }

    } while(choice !=4);

    // closes our dataFile
    DataFile.close();

    return 0;
}


//function subprograms

// Function to display the menu
void DisplayMenu()
{
     // displays the user's choices
    cout << "\nMenu" << endl;

    // for loop to displays the user options
    // from enumerated to string
    for(int i = ADD; i <= EXIT; i++)
    {
        // prints the user's options
        cout << i + 1 << ". " << MenuOptions(static_cast <Choice> (i)) << endl;
    }
    // instructions for the user
    cout << "Enter your choice: ";

    return;

}

// converts our plant type from an integer
// to its actual word/ string
void PrintType(Kind type)
{
    // switch statement changes based
    // on the type that's entered by the user
    switch(type)
    {
    case FLOWER:
        cout << "Flower";
        break;

    case VEGETABLE:
        cout << "Vegetable";
        break;

    case GRASS:
        cout << "Grass";
        break;

    case SHRUB:
        cout << "Shrub";
        break;

    default:
        cout << "Unknown Plant type";
        break;
    }

    return;
}

// converts the menu options
// into its actual world/ string
string MenuOptions(Choice decision)
{
switch(decision)
    {
    case ADD:
        return "Add";

    case PRINT:
        return "Print";

    case EDIT:
        return "Edit";

    case EXIT:
        return"Exit";

    default:
        return "Unknown entry";
    }

}

// function to add the user's input
// we reference our file as the function parameter
void AddData(fstream & PlantFile)
{

    Plants data;
    int temp;
    char choice;

    PlantFile.clear();
    PlantFile.seekp(0L, ios::end);

do{
    cout << "\nEnter the following data:" << endl;


    // prompts the user to enter
    // plant name
    cout << "Plant name: ";

    // gets the user's input
    cin.getline(data.name, SIZE);

    // prompts the user to enter
    // the plant type
    cout << " Enter a Plant Type ";
    cout << "(0: FLOWER, 1: VEGETABLE, 2: GRASS, 3: SHRUB):";
    cin >> temp;
    // converts our plant_type from
    // an integer to the enumerated data type
    data.type = static_cast<Kind> (temp);

    // prompts the user to enter
    // the cost
    cout << "Cost: $";
    cin >> data.cost;

    // prompts the user to enter
    // the quantity available
    cout << "Quantity available: ";
    cin >> data.qty_available;

    cin.ignore();

    // writes the data from the Plants
    // structure to the file
    PlantFile.seekp(0, ios::end);
    PlantFile.write(reinterpret_cast<char *>(&data), sizeof(data));

    //prompts the user to add another plant record
    cout << "\nDo you want to add another plant record? (Y/N): ";
    cin >> choice;

    cin.ignore();

}while(toupper(choice)== 'Y');

    //cout << "Current put pointer position after writing data: " << PlantFile.tellp() << endl;

    cout << "\nData added successfully!" << endl;


    return;
}

// function to display the user's input
// we reference our file as the function parameter
void PrintData(fstream & PlantFile)
{

    Plants data;

    cout << "Here is the plant data: \n\n";
    PlantFile.clear();
    PlantFile.seekg(0L, ios::beg);

    //cout << "Current get pointer position before reading data: " << PlantFile.tellg() << endl;

    cout << left << setw(25) << "Plant Name" << setw(20) << "Plant Type" << setw(10) << "Cost" << "Quantity Available" << endl;
    cout << "_________________________________________________________________________" << endl;
    // reads the first record
    // from our file
    while(PlantFile.read(reinterpret_cast<char *> (&data),
    sizeof(data)))
    {
        // displays the records
        cout << left << setw(25) << data.name;
        cout << right << setw(9);
        PrintType(data.type);
        cout << right << fixed << setprecision(2) << setw(11) << "$" << data.cost;
        cout << right << setw(15) << data.qty_available << endl;
    }

    //cout << "Current get pointer position after reading data: " << PlantFile.tellg() << endl;

    // error checker
    // end of the file
    if(PlantFile.eof())
    {
        cout <<"\n\n end of the file has been reached.";
    }

    // if we fail to read the data
    else if (PlantFile.fail())
    {
        cout << "\nFailed to read data from the file.\n";
    }
   // cout << "Current get pointer position after reading data: " << PlantFile.tellg() << endl;

}

// function to edit the user's input
// we reference our file as the function parameter
void EditData(fstream & PlantFile)
{
    // assigns our index, temp
    // and RecordSize as integer
    // data types
    int index;
    int temp;
    int RecordSize;

    // Reads the entry from the file
    Plants data;

    //displays the current data;
    cout << "\ncurrent data\n" << endl;
    PrintData(PlantFile);
    cout << endl;

    // prompting the user to enter which
    // index they want to edit
    cout <<"\nEnter the index of the plant data you want ";
    cout << "to edit (index starts at 1):";
    cin >> index;
    cin.ignore();

    // We need to calculate the position
    // to seek based on the index
    // the user has entered and the size of each entry
   RecordSize = sizeof(Plants);
    //streampos pos = static_cast<streampos>(index-1) * RecordSize;

    // Moving our file pointer to the position
    // of the entry that the user wants to edit
    PlantFile.clear();
    PlantFile.seekg((index-1) * RecordSize, ios::beg);

    // reads the structure
    PlantFile.read(reinterpret_cast<char *>(&data),
                   sizeof(data));

    cout << "Enter the following data" << endl;

   // cin.ignore();

    // prompts the user to enter
    // plant name
    cout << "Plant name: ";

    // gets the user's input
    cin.getline(data.name, SIZE);

    // prompts the user to enter
    // the plant type
    cout << " Enter a Plant Type ";
    cout << "(0: FLOWER, 1: VEGETABLE, 2: GRASS, 3: SHRUB):";
    cin >> temp;
    // converts our temp from
    // an integer to the enumerated data type
    data.type = static_cast<Kind> (temp);

    // prompts the user to enter
    // the cost
    cout << "Cost: $";
    cin >> data.cost;

    // prompts the user to enter
    // the quantity available
    cout << "Quantity available: ";
    cin >> data.qty_available;

    cin.ignore();

    PlantFile.clear();

    // writes the data from the Plants
    // structure to the file
    PlantFile.seekp((index-1) * RecordSize, ios::beg);
    PlantFile.write(reinterpret_cast<char *>(&data), sizeof(data));

// cout << "Data edited successfully!" << endl;

//    cout << "Updated plant data:\n";
//    PrintData(PlantFile);

    return;
}

