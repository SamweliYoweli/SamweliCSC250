// plants_SY
// Date: created 3/07/2024
// CSC 250
// Samweli Yoweli
// Date Updated: 3/19/2024
// Create a program the prints items available
// in a numbered tabled with columns for the name,
// type, cost, qty available and qty ordered for each size
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// constants

// 7% Tax Rate
const double TAXRATE = 1.07;

// Number of plants
const int SIZE = 10;


enum Kind
{
    FLOWER, VEGETABLE, GRASS, SHRUB
};

struct Plants
{
    string name;
    Kind type;
    double cost;
    int qty_avail;
    int qty_ordered;

};

// prototypes

// function to display the items available
// with columns for name, type,
//  cost, qty available, qty ordered, total
void displayData(const Plants inventory[], int size, double untaxed_total);

// function to display the menu options
void displayMenu();

// function to get the user's choice
// in the menu
int menuChoice();

// converts our plant type from an integer
// to its actual word/ string
void printType(Kind type);

// function to Get the user's order and
// updates the quantity available and quantity ordered
// in our array
void userOrder(Plants (&inventory)[SIZE]);

// function to calculate the user's total cost
// of the user's order with the 7% tax rate
double calcTaxTotal(Plants (&inventory)[SIZE], int item_num);

// clears the input buffer
void InputBufferClear();

// displays the items that
// the user has ordered
void displayItemsOrdered(const Plants inventory[], int size, double total);

// resets the number of items ordered to zero and
// the total back to zero
void resetOrder(Plants inventory[], int size);

// function to calculate the user's untaxed total cost
double CalcUntaxedTotal(Plants (&inventory)[SIZE], int size);


int main()
{
    Plants Inventory[SIZE] =
    { {"Purple Iris", FLOWER, 10.50, 25,0},
    {"Fuschia Peony", FLOWER, 24.99, 15,0},
    {"Orange Day Lily", FLOWER, 14.50, 25,0},
    {"Beefsteak Tomato", VEGETABLE, 4.50, 40,0},
    {"Butternut Squash", VEGETABLE, 3.50, 25,0},
    {"Jalapeno Pepper", VEGETABLE, 2.99, 30,0},
    {"Striped Lemon Grass", GRASS, 10.50, 15,0},
    {"Blue Spike", GRASS, 8.50, 40,0},
    {"Everbearing Raspberry", SHRUB, 7.50, 25,0},
    {"Hardy Blueberry", SHRUB, 25.99, 15,0}
    };

    // assigns the user choice
    // the data type int
    int choice;

    do
    {

        // displaying our menu;
        displayMenu();

        // calling our menuChoice function
        // which gets the user's choice of what they want to do
        // We are making that function equal to our choice
        // since the function is returning an integer.
        choice = menuChoice();

        switch(choice){

        // When the user enters choice 1
        // the user will be able to see the available items
          case 1:
            {
                //assigning our untaxed_total
                // to the our CalcUntaxedTotal function
                double untaxed_total = CalcUntaxedTotal(Inventory, SIZE);

                // calling our display data function
                // so the user can see what's in stock
                displayData(Inventory, SIZE, untaxed_total);

            }
            break;

        // When the user enters choice 2
        // the user will be able to order items
          case 2:
            {
                // calls the user order function
                userOrder(Inventory);
                cout << endl;

            }
            break;


        // When the user enters choice 3
        // the user will go to the checkout
          case 3:
            {
                // assigning our total cost to
                // our calcTaxTotal function
                double Taxed_total_cost = calcTaxTotal(Inventory,SIZE);

                // calling the displayItemsOrdered function
                displayItemsOrdered(Inventory, SIZE, Taxed_total_cost);

                // calling the resetOrder function
                // so that the items ordered and
                // the total are rest back to zero
                resetOrder(Inventory, SIZE);
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


    return 0;
}


// subfunctions

// function to display the items available
// with columns for name, type,
//  cost, qty available, qty ordered, total
void displayData(const Plants inventory[], int size, double untaxed_total)
{

    cout << endl;
    // displays our item name and plant type
    // and Cost and quantity available
    // as well as quantity ordered in columns
    cout << setw(40) << "Item name ";
    cout << setw(16) << right << "Plant Type ";
    cout << setw(12) << right << "Cost ";
    cout << setw(21) << right << "Quantity Available ";
    cout << setw(19) << right << "Quantity Ordered";
    cout << setw(17) << right << "Total " << endl;

    // the for loop executes when our index is less than our size
    // and it incremented after each loop
    // displays our plant name, type, cost, quantity available,
    // quantity ordered and total
    for(int i = 0; i < size; i++)
    {

    // calculates the total cost of each item
    double Item_Total = inventory[i].qty_ordered * inventory[i].cost;

    // prints the item name of one plant per iteration
    cout << setw(5) << "Item number " << i << " ";
    cout << setw(27) << inventory[i].name;

    // calls the printType function to display our plant
    // type of one plant per iteration
    cout << setw(13) << right;
    printType(inventory[i].type);

    //prints the cost of one item per iteration
    cout << setw(13) << right << fixed << setprecision(2) << inventory[i].cost;

    //prints the Quantity available of one item per iteration
    cout << setw(12) << right << inventory[i].qty_avail;
    //prints the Quantity ordered of one item per iteration
    cout << setw(22) << right << inventory[i].qty_ordered;

    // prints the total in each column
    cout << setw(19) << right << fixed << setprecision(2) << "$" << Item_Total << endl;
    }

    // prints the untaxed_total
    cout << setw(25) << left << "Overall Total without tax: ";
    cout << setw(93) << right << fixed << setprecision(2) << "$" << untaxed_total << endl;


    return;
}

// function to display the menu options
void displayMenu()
{

    // displays the user's choices
    cout << "\nMenu\n";
    cout << "1. Show available Items\n";
    cout << "2. Order Items\n";
    cout << "3. Checkout\n";
    cout << "4. Exit\n";
    return;
}

// function to get the user's choice
// in the menu
int menuChoice()
{
    // declaring our user choice;
    int user_choice;

    cout << endl;
    // Prompting the user
    cout << "Enter your choice: ";
    cin >> user_choice;

    // while loop to check if the user's
    // input is valid. It will check if our
    // our user choice is invalid, or less than 1
    // or greater than 4
    while(cin.fail() || user_choice < 1 || user_choice > 4)
    {
        cout << endl;
        cout << "You have entered an invalid choice.";
        cout << "\nPlease enter an integer between 1 and 4" << endl;

        // calls the display menu function
        // to show the menu items
        // displayMenu();

        //clearing our error status
        cin.clear();

        // calls the InputBufferClear
        InputBufferClear();

        cout << endl;
        // Prompts the user
        cout << "Enter your choice: ";
        cin >> user_choice;
    }

    // returns the user's choice back to main
    return user_choice;
}

// function to Get the user's order and
// updates the quantity available and quantity ordered
// in our array
void userOrder(Plants (&inventory)[SIZE])
{
    // Declaring our plant quantity and
    // our item number as integers
    // And then making our valid_user_input false
    int quan_plant;
    int item_num;
    bool valid_user_input = false;

    // This while loop will execute when
    // valid_user_input is true
    while(!valid_user_input) {

    // prompts the user for the item number the want
    cout << "Enter an item number of the plant you want from (0-9): ";
    cin >> item_num;

    if(item_num >= 0 && item_num < SIZE)
    {
        // we will assume that our value is true
        valid_user_input = true;

        // Prompts the user to enter the number of plants they want
        cout << endl;
        cout << "Enter the amount of plants you want: ";
        cin >> quan_plant;

        // This if statement will execute when the
        // user has entered a quantity that exceeds
        // the quantity available
        if(quan_plant > inventory[item_num].qty_avail)
        {

            // displays an error message to the user
            cout << endl;
            cout << "The quantity you want to order exceeds the quantity available" << endl;
            valid_user_input = false;

        }

        // else statement will execute when the user has entered
        // a valid quantity of plant they want
        else{

            // assigns our quantity available = to the quantity available
            // subtracting the quantity of plants the user entered
            inventory[item_num].qty_avail = inventory[item_num].qty_avail - quan_plant;
            inventory[item_num].qty_ordered = quan_plant;
            }

        }

        // else statement will execute when the user has entered
        // an invalid item number
        else {

        cout << endl;
        cout << "You have entered an invalid item number." << endl;

        }

    }
}


// function to calculate the user's total cost
// of the user's order with the 7% tax rate
double calcTaxTotal(Plants (&inventory)[SIZE], int size)
{
    // declaring our total
    double total = 0;

    // calculates the total of the user's ordered
    for(int i = 0; i < size; i++)
    {
        total = total + (inventory[i].cost * inventory[i].qty_ordered);

    }

    // calculates the overall total with the 7% tax rate
    total = total * TAXRATE;


    // returns the total back to main
    return total;
}

// converts our plant type from an integer
// to its actual word/ string
void printType(Kind type)
{
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

// displays the items that
// the user has ordered
void displayItemsOrdered(const Plants inventory[], int size, double total)
{
    cout << "\nItems ordered:" << endl;

    // displays our item name and plant type
    // and Cost and quantity available
    // as well as quantity ordered in columns
    cout << endl;
    cout << setw(25) << left << "Item name ";
    cout << setw(15) << right << "Plant Type ";
    cout << setw(10) << right << "Cost ";
    cout << setw(20) << right << "Quantity Ordered";
    cout << setw(20) << right << "Total " << endl;

    for(int i = 0; i < size; i++)
    {
        // the if statement executes when the
        // the quantity ordered is greater than 0
        if(inventory[i].qty_ordered > 0)
        {

        // calculates the total cost of each item
        double Item_Total = inventory[i].qty_ordered * inventory[i].cost;

    // prints the item name of one plant per iteration
    cout << setw(25) << left << inventory[i].name;

    // calls the printType function to display our plant
    // type of one plant per iteration
    cout << setw(12) << right;
    printType(inventory[i].type);

    //prints the cost of one item per iteration
    cout << setw(12) << right << fixed << setprecision(2) << inventory[i].cost;

    //prints the Quantity ordered of one item per iteration
    cout << setw(15) << right << inventory[i].qty_ordered;

    // prints the item total per iteration
    cout << setw(20) << right << fixed << setprecision(2) << "$" << Item_Total << endl;

        }

    }

    cout << endl;

    // displays the overall total
    cout << setw(25) << left << "Overall total with 7% tax: ";
    cout << setw(57) << right << fixed << setprecision(2) << "$" << total << endl;


    return;
}

// clears the input buffer
void InputBufferClear()
{
    // this will ignore up to 10000 characters
    // or a newline
    cin.ignore(123, '\n');
}

// resets the number of items ordered to zero and
// the total back to zero
void resetOrder(Plants inventory[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        // assigns our quantity ordered the integer 0
        // to rest the order
        inventory[i].qty_ordered = 0;
    }
}

// function to calculate the user's untaxed total cost
double CalcUntaxedTotal(Plants (&inventory)[SIZE], int size)
{
    // declaring our total
    double untaxed_total = 0;

    for(int i = 0; i < size; i++)
    {
        // assigns untaxed_total = to the untaxed_total
        // multiplied by the cost and quantity ordered per iteration
        untaxed_total = untaxed_total + (inventory[i].cost * inventory[i].qty_ordered);

    }

    //returns the untaxed total back to main
    return untaxed_total;

}









