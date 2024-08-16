// sorting example
// CSC 250
// Samweli Yoweli

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// constants
const int SIZE = 10;

//prototypes

// print the array
void print(const int array[], const float array2[], int size);


//sort the array in ascending order, using selection sort algorithm
// and keeping array2 in parallel with array
void selectionSort(int array[], float array2[], int size);

int main()
{
    int data[SIZE] = {65, 23, 49, 36, 52, 19, 75, 21, 30, 87};
    float data2[SIZE] = {5.2, 6.3, 4.2, 3.5, 2.3, 6.0,
                        4.7, 5.2, 3.6, 4.0};

    cout << "The original data is \n";
    print(data, data2, SIZE);

   selectionSort(data, data2, SIZE);

    cout << "The Sorted data is \n";
    print(data, data2, SIZE);

    return 0;
}

// print the array
void print(const int array[], const float array2[], int size)
{
    cout << fixed << setprecision(1);
    cout << endl;
    cout <<"    data        data2\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(6) << array[i] << setw(12) << array2[i] << endl;
    }
    cout << endl;

    return;
}


//sort the array in ascending order, using selection sort algorithm
// and keeping array2 in parallel with array
void selectionSort(int array[], float array2[], int size)
{

    int smallest_loc;

    //Outer loop, move the wall through
    // the data, one item at a time,
    // stop when we're one from the end
    for(int wall = 0; wall < size-1; wall++)
    {

        // inner loop, find the smallest value
            //in the unsorted data
        // swap it to the front of the unsorted data
        smallest_loc = wall;

        for(int i = wall; i < size; i++)
        {
            if(array[smallest_loc] > array[i])
            {
                    smallest_loc = i;

            }

        }
         // smallest value on this pass
        //
        //
        // swap smallest location with the value
        // with the value of wall
       swap(array[smallest_loc], array[wall]);
       swap(array2[smallest_loc], array2[wall]);

     }
    return;
}




