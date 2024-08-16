// 2D array Processing
// CSC 250
// Samweli Yoweli
// 01/31/2024

#include <iostream>
#include <iomanip>
using namespace std;

// constants
const int ROWS = 3;
const int COLS = 5;

// prototypes
void print2Darray(const float data[][COLS],const float row_totals[], int rows,
                  const float col_totals[], float total);

// function to calculate and return the overall total
float calc2DarrayTot(const float data[][COLS], int rows);

void calc2DarrayRowTotals(const float data[][COLS], float row_totals[], int rows);

// calculate the column totals and store them
// into the appropriate element
// in the col_totals

void calc2DarrayColTotals(const float data[][COLS], int rows,
                          float col_totals[]);

int main()
{
    float data[ROWS][COLS] = {   {12, 53, 25, 36, 78},
                                    {10, 23, 30, 89, 99},
                                    {15, 67, 45, 52, 74} };

    float row_totals[ROWS] = {0};
    float col_totals[COLS] = {0};

    float total;

    // find the overall total
    total = calc2DarrayTot(data, ROWS);

    // find the row and column totals
    calc2DarrayRowTotals(data, row_totals, ROWS);
    calc2DarrayColTotals(data, ROWS, col_totals);

    // print the data in a table with headings
    print2Darray(data, row_totals, ROWS, col_totals, total);

    return 0;
}

// function to print the data in a 2D array
// in a table
// passing 2D arrays compiler
// needs to know how many columns per row
// when it complies any statement
//that's accessing any elements
//in a 2D array
void print2Darray(const float data[][COLS],const float row_totals[], int rows,
                  const float col_totals[], float total)
{
    //print the column headings
    cout << "\n\n\t";
    for (int c=0; c < COLS; c++)
    {
        cout <<"    Col " << setw(2) << c+1;

    }
    cout <<"                         Row Totals\n";


    // print the data
    // set the row print the columns for that row
    // then move to the next row
    for(int r=0; r < rows; r++)
    {
        for(int c=0; c < COLS; c++)
            cout << setw(15) << data[r][c];

        cout << setw(14) << row_totals[r] << endl;
    }

    // print the column totals
    cout << "   Totals: ";
    for (int c=0; c < COLS; c++)
    {
        cout << setw(12) << col_totals[c];
    }
    cout << setw(14) << total << endl;

    return;

}

// function to calculate and return the overall total
float calc2DarrayTot(const float data[][COLS], int rows)
{
    float total = 0;

    for (int r=0; r <rows; r++)
    {
            for(int c=0; c < COLS; c++)
            {
                total = total + data[r][c];
            }


    }
    return total;

}

// calculate the row totals and store them in
// to the appropriate element
// in the row_totals array
void calc2DarrayRowTotals(const float data[][COLS], float row_totals[], int rows)
{

    for (int r=0; r <rows; r++)
    {
            row_totals[r] = 0;
            for (int c=0; c < COLS; c++)
            {
                row_totals[r] = row_totals[r] + data[r][c];
            }

    }
    return;

}

// calculate the columns totals and store them into
// the appropriate element in the col_totals array

void calc2DarrayColTotals(const float data[][COLS], int rows,
                          float col_totals[])
{
    for (int c=0; c < COLS; c++)
    {
        col_totals[c] =0;
        for (int r=0; r < rows; r++)
        {
                col_totals[c] = col_totals[c] + data[r][c];
        }

    }
    return;

}






