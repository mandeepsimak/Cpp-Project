#include <iostream>

using namespace std;

const int totalBorough = 5;     // Total Boroughs

int getNumAccidents(string);    // Get Value from user
int findLowest(int arr[]);      // finding lowest value

int main()
{
    int i,              // For looping variable
        lowestIndex;    // Lowest accidents index value

    // Names of boroughs
    string borough[totalBorough] = {"New York City", "The Bronx",
                                    "Brooklyn", "State Island",
                                    "Manhattan"};
    // Total no. of accidents in each borough
    int totalAccidents[totalBorough];

    // Calling getNumAccdents() to getting input from user.
    for(i = 0; i < totalBorough; i++)
    {
        totalAccidents[i] = getNumAccidents(borough[i]);
    }

    // Calling function for finding index of lowest value
    lowestIndex = findLowest(totalAccidents);

    // Displaying Result
    cout << "Total Number of accidents in following cities." << endl
         << "\nCity Name \t Number of Accidents" << endl;

    for(i = 0; i < totalBorough; i++)
    {
        cout << borough[i] << "\t\t"
             << totalAccidents[i]
             << endl;
    }

    cout << "\nBorough with lowest accidents: "
         << borough[lowestIndex] << " ("
         << totalAccidents[lowestIndex] << " accidents)."
         << endl;

    return 0;
}

/**
 *  For taking input from user, validate that and then return value
 */

int getNumAccidents(string borough)
{
    int num;
    do
    {
        // Asking user to enter value of accidents
        cout << "\nEnter number of accidents occured in "
             << borough << ": ";
        cin >> num;

        /* Validating: If entered number is negative then show
           message and user has to re-enter value */
        if( num < 0)
            cout << "\n INVALID INPUT. Number should be greater or eqaul to zero(0)" << endl;

    }while(num < 0);

    return num;
}

/**
 *  Finding lowest value from array and returning its index value.
 */

int findLowest(int arr[])
{
    int length = totalBorough;

    int minIndex = 0;

    for(int i = 1; i < length; i++)
    {
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }

    return minIndex;
}
