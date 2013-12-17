#include "membertype.h"

memberType::memberType()
{
    //ctor

    // Reading member details from input file

    ifstream inFile;

    inFile.open(fileName.c_str());

    inFile >> totalMembers;

    for(i = 0; i << totalMembers; i++)
    {
        getline(inFile, name[i], '\n');
        inFile >> memberID[i]
               >> amountSpent[i]
               >> booksBought[i]
               >> membershipFee[i];
    }

    inFile.close();
}

memberType::~memberType()
{
    //dtor
}

/**
 *  Add new member
 */

void memberType :: newMember()
{
    cout << "\n\t ADD NEW MEMBER \n" << endl;

    cout << "Enter membership details\n" << endl;

    index = totalMembers;

    cout << "Member Name: ";
    cin >> name[index];

    cout << "Member ID: ";
    cin >> memberID[index];

    cout << "Amount Spent: ";
    cin >> amountSpent[index];

    cout << "No. of books bought: ";
    cin >> booksBought[i];

    cout << "Membership Fee Paid(Y/N): ";
    cin >> membershipFee[i];

    totalMembers++;

}

/**
 *  Search Member from record
 */

void memberType :: searchMember()
{

}

/**
 *  update member record
 */

void memberType :: updateMember()
{

}
