#include <iostream>
#include <fstream>

using namespace std;

// Global variables used for reading data and for finding yearly details

const int MAX_SIZE = 20;    /** Maximum value of total no. of items. You can
                                change according to you. */
const int quater   = 4;     /// No. of quarters in year.

string fileName = "input.in"; /// Input file name

int i , j,                  /// for looping variables
    totalItems,             /// Total Items in Input file
    totalProfit[MAX_SIZE],  /// Total Profit of each item
    quaterValue[MAX_SIZE][quater];  /** Amount of profit/loss value of item
                                        in input file */

string itemName[MAX_SIZE],
       temp;

void ReadInput();
void ShowInput();
void TotalProfit();

using namespace std;

int main()
{
    ReadInput();
    ShowInput();
    //cout << "Hello world!" << endl;
    return 0;
}

/**
 *  Reading Input file(input.in) and displaying it's contents.
 */

void ReadInput()
{
    ifstream inFile;

    inFile.open(fileName.c_str());

    // Reading data from file

    inFile >> totalItems;

    for(i = 0; i < totalItems; i++)
    {
        getline(inFile, temp, '\n');        // Reading blank space.
        getline(inFile, itemName[i], '\n'); // Reading item name from file

        for(j = 0; j < quater; j++)
        {
            inFile >> quaterValue[i][j];
        }
    }

    inFile.close();
}

/**
 *  Displaying data from Input file
 */

void ShowInput()
{
// Displaying data of input file
    cout << totalItems << " items \n" << endl
         << "Item Name \t Quarter Values" << endl;

    for(i = 0; i < totalItems; i++)
    {
        cout << itemName[i] << "\t\t";
        for(j = 0; j < quater; j++)
        {
            cout << quaterValue[i][j] << " ";
        }
        cout << endl;
    }
}
