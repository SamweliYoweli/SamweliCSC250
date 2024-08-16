// Samweli Yoweli
// 1/8/2024
// CSC 250
//
// Rectangle Program
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// max size for my partially-filled arrays
const int SIZE = 40;

//function prototypes

// read the length and width from rectangles.txt
//  storing back into main's arrays {automatically pass by ref}
int input(float* &length, float* &width, int max_size);

// calculate the area and perimeter
void calculate(const float length[], const float width[],
               float a[], float p[], int num_items);

// output the area and perimeter
void output(const float a[], const float p[], int num_items);

int main()
{

    float *len, *wid, *perim, *area;
    int num_items;

    // read the length and wid
    num_items = input(len, wid, SIZE);

    //debug
//    for(int i=0; i < num_items; i++)
//    {
//        cout << "len: " << len[i] << " wid: " << wid[i] << endl;
//    }
//
//    cout << endl << endl;

    // allocate space for perim and
    perim = new float[num_items];
    area = new float[num_items];

    // calculate the perimeter and area of the rectangle
    calculate(len, wid, area, perim, num_items);

    // displays the area and perimeter
    output(area, perim, num_items);

    return 0;
}

// read the length and width from rectangles.txt
//  storing back into main's arrays {automatically pass by ref}
int input(float* &length, float* &width, int max_size)
{
    ifstream inputFile;
    int num_items;

    // read the length and width of a group of rectangle
    //   storing them back into main's dataspace

    // connect to the rectangles.txt
    inputFile.open("rectangles.txt");
    if (!inputFile)
    {
        cout << "Error opening rectangles.txt!!\n\n";
        exit(102);
    }

   inputFile = new float[num_items];

   length = new float[num_items];
   width = new float[num_items];

    for(i=0; i< num_items; i++)
    {
        inputFile >> length[i] >> width[i]
    }


    // send the number of items in the array back to main
    return num_items;
}


// calculate the perimeter and area of the rectangle
 void calculate(const float length[], const float width[], float a[], float p[], int num_items)
 {
    for (int i = 0; i < num_items; i++)
    {
        a[i] = length[i] * width[i];
        p[i] = 2 * length[i] + 2 * width[i];

    }

    return;
}

// displays the area and perimeter of the rectangle
void output(const float a[], const float p[], int num_items){

    cout << fixed << setprecision(2);

    cout << "\tYour Results\n\n";
    cout << "       Area       Perimeter\n";

    for(int i = 0; i < num_items; i++){

    cout << setw(12) << a[i] << setw(12) << p[i] << endl;
    }
    return;
}
