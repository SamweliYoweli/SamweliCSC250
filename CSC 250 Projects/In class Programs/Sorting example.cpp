// sorting example
// CSC 250
// Samweli Yoweli

#include <iostream>
#include <iomanip>
using namespace std;

// constants
const int SIZE = 10;

//prototypes

// print the array
void print(const int array[], int size);

// sort the array in ascending order, using a bubble sort algorithm
void bubbleSort(int array[], int size);

int main()
{
    int data[SIZE] = {65, 23, 49, 36, 52, 19, 75, 21, 30, 87};

    cout << "The original data is \n";
    print(data, SIZE);

    bubbleSort(data, SIZE);

    cout << "The Sorted data is \n";
    print(data, SIZE);

    return 0;
}

// print the array
void print(const int array[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(6) << array[i];
    }
    cout << endl;

    return;
}

// sort the array in ascending order, using a bubble sort algorithm
void bubbleSort(int array[], int size)
{
    int temp;
    bool sorted;

    // outer loop, keep making passes until its ordered
    //      which means there is one complete pass without a swap

    do{

        // start a new pass
        sorted = false;

        // Inner pass, should move through the area
        // if adjacent items are out of order, it should swap them

        for(int i = 0; i < size-1; i++)
        {
            if(array[i] > array[i+1])
            {
                // swap them if if it's greater
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;

                sorted = true;
            }


        }

    } while(sorted == true);

    return;

}




