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
    avgProfit[MAX_SIZE],    /// Average profit of each item
    quaterValue[MAX_SIZE][quater];  /** Amount of profit/loss value of item
                                        in input file */

string itemName[MAX_SIZE],  /// Item Names in file
       temp;                /// Temperary variable

void ReadInput();
void ShowInput();
void TotalProfit();
void QuaterlyProfit();

int main()
{
    ReadInput();
    ShowInput();
    TotalProfit();
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
        totalProfit[i] = 0; /// Initializing value to zero
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

void TotalProfit()
{
    // Calculating total and average profit of each item
    for(i = 0; i < totalItems; i++)
    {
        for(j = 0; j < quater; j++)
        {
            // Adding values of quaters of each item
            totalProfit[i] += quaterValue[i][j];
        }
        // Dividing total profit with no of quaters i.e. 4
        avgProfit[i] = totalProfit[i] / quater;
    }

    // Displaying Profit and average profit

    cout << "\nTotal Profit and Average Profit of each Item\n" << endl;
    cout << "Item Name \t Total Profit \t Average Profit" << endl;

    for(i = 0; i < totalItems; i++)
    {
        cout << itemName[i] << "\t\t"
             << totalProfit[i] << "\t\t"
             << avgProfit[i]
             << endl;
    }
}
