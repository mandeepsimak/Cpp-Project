#include <iostream>
#include <fstream>

using namespace std;

// Global variables used for reading data and for finding yearly details

const int MAX_SIZE = 20;    /** Maximum value of total no. of items. You can
                                change according to you. */
const int quarter   = 4;     /// No. of quarters in year.

string fileName = "input.in"; /// Input file name

int i , j,                  /// for looping variables
    totalItems,             /// Total Items in Input file
    totalProfit[MAX_SIZE],  /// Total Profit of each item
    avgProfit[MAX_SIZE],    /// Average profit of each item
    quarterValue[MAX_SIZE][quarter];  /** Amount of profit/loss value of item
                                        in input file */

string itemName[MAX_SIZE],  /// Item Names in file
       temp;                /// Temperary variable

void ReadInput();
void ShowInput();
void TotalProfit();
void QuarterlyProfit();
void ProfitLossQuarter();
void QuarterGraph();

int main()
{
    ReadInput();
    ShowInput();
    TotalProfit();
    QuarterlyProfit();
    ProfitLossQuarter();
    QuarterGraph();

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

        for(j = 0; j < quarter; j++)
        {
            inFile >> quarterValue[i][j];
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
    cout << "Total Items: " << totalItems << endl
         << "Item Name \t Quarter Values" << endl;

    for(i = 0; i < totalItems; i++)
    {
        cout << itemName[i] << "\t\t";
        for(j = 0; j < quarter; j++)
        {
            cout << quarterValue[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 *  Finding total profit of each item and its average profit too.
 */

void TotalProfit()
{
    // Calculating total and average profit of each item
    for(i = 0; i < totalItems; i++)
    {
        for(j = 0; j < quarter; j++)
        {
            // Adding values of quarters of each item
            totalProfit[i] += quarterValue[i][j];
        }
        // Dividing total profit with no of quarters i.e. 4
        avgProfit[i] = totalProfit[i] / quarter;
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

/**
 *  Finding item having greatest profit and its quarter
 */

 void QuarterlyProfit()
 {
    int maxProfit[totalItems];  /* Storing index value of quarter
                                   having maximum value of each item */
    int length;

    for(i = 0; i < totalItems; i++)
    {
        length = quarter;  // establish size of array

        maxProfit[i] = 0;//quarterValue[i][0];       // start with max = index of first element

        // Finding index value for maximum profit of each item

        for(j = 1; j < length; j++)
        {
            if(quarterValue[i][j] > quarterValue[i][maxProfit[i]])
                maxProfit[i] = j;
        }
    }

    // Finding Maximum profit from all items.
    int maxItemProfit;  // Storing index value item having maximum profit
    length = totalItems;
    maxItemProfit = 0;
    for(i = 1; i < length; i++)
    {
        if(quarterValue[i][maxProfit[i]] > quarterValue[maxItemProfit][maxProfit[maxItemProfit]])
            maxItemProfit = i;
    }
    cout << itemName[maxItemProfit] << endl;

    // Displaying Maximum profit of quartly of each item and item which has maximum value

    cout << "\n Maximun profit Quarterly" << endl;
    cout << "\nItem Name \t Quarter \t Profit" << endl;

    for(i = 0; i < totalItems; i++)
    {
        cout << itemName[i] << "\t\t"
             << (maxProfit[i] + 1) << "\t\t"
             << quarterValue[i][maxProfit[i]] << endl;
    }
}

/**
 *  Finding no. of profit and loss quarters of each item
 */

void ProfitLossQuarter()
{
    int profitQuarter[totalItems],   // For stroring no. of quarters having profit
        lossQuarter[totalItems];     // For storing no. of quarters having loss

    // Finding loss and profit quarters
    for(i = 0; i < totalItems; i++)
    {
        // Initialize value to zero
        profitQuarter[i] = 0;
        lossQuarter[i] = 0;
        for(j = 0; j < quarter; j++)
        {
            if(quarterValue[i][j] < 0)
                lossQuarter[i]++;
            else
                profitQuarter[i]++;
        }
    }

    // Displaying no. of loss and profit quarters

    cout << "\n No. of profit and loss quarters for each item" << endl;
    cout << "\nItem Name \t Total Profit Quarters \t Total Loss Quarters" << endl;

    for(i = 0; i < totalItems; i++)
    {
        cout << itemName[i] << "\t\t\t"
             << profitQuarter[i] << "\t\t\t"
             << lossQuarter[i] << endl;
    }

}

/**
 *  Finding Up/Down profit rate of each item
 */

void QuarterGraph()
{
    string upDownGraph[totalItems][quarter],
           up = "UP",
           down = "DOWN";

    for(i = 0; i < totalItems; i++)
    {
        int previousValue = quarterValue[i][0];
        if(previousValue > 0)
            upDownGraph[i][0] = up;
        else
            upDownGraph[i][0] = down;

        for(j = 1; j < quarter; j++)
        {
            if(quarterValue[i][j] > previousValue)
                upDownGraph[i][j] = up;
            else
                upDownGraph[i][j] = down;

            previousValue = quarterValue[i][j];
        }
    }

    // Displaying graph up-down graph

    cout << "\n Up-Down Profit Quarter Graph" << endl;
    cout << "\nItem Name \t Quater (1 : 2 : 3 : 4)" << endl;

    for(i = 0; i < totalItems; i++)
    {
        cout << itemName[i] << "\t\t";
        for(j = 0; j < quarter; j++)
        {
            cout << upDownGraph[i][j] << " \t ";
        }
        cout << endl;
    }

}
