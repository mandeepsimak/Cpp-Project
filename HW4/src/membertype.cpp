#include "membertype.h"

memberType::memberType()
{
    //ctor

    // Reading member details from input file

    ifstream inFile;

    inFile.open("member.in");//"fileName.c_str());

    inFile >> totalMembers;
    getline(inFile, temp, '\n');

    for(i = 0; i < totalMembers; i++)
    {
        getline(inFile, name[i], '\n');
        inFile >> memberID[i]
               >> amountSpent[i]
               >> booksBought[i]
               >> membershipFee[i];

        getline(inFile, temp, '\n');
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
    cin >> booksBought[index];

    cout << "Membership Fee Paid(Y/N): ";
    cin >> membershipFee[index];

    totalMembers++;

}

/**
 *  Search Member from record and show member details
 */

void memberType :: searchMember()
{
    int memID;

    cout << "\n\t SEARCH MEMBER \n" << endl;

    cout << "Enter member ID: ";
    cin >> memID;

    for(i = 0; i < totalMembers; i++)
    {
        if(memID == memberID[i])
        {
            index = i;
            break;
        }
        else
            index = -1;
    }
    cout << "index: " << index << endl;

    if(index >= 0)
    {
        cout << "\n MEMBER DETAILS\n" << endl;

        cout << "Member Name: " << name[index] << endl;

        cout << "Member ID: " << memberID[index] << endl;

        cout << "Amount Spent: " << amountSpent[index] << endl;

        cout << "No. of books bought: " << booksBought[index] << endl;

        cout << "Membership Fee Paid(Y/N): " << membershipFee[index] << endl;

    }
    else
    {
        cout << "\n MEMBER DOES NOT EXISTS \n" << endl;
    }
}

/**
 *  update member record
 */

void memberType :: updateMember()
{
    int memID,
        choice;

    cout << "\n\t UPDATE MEMBER \n" << endl;

    cout << "Enter member ID: ";
    cin >> memID;

    for(i = 0; i < totalMembers; i++)
    {
        if(memID == memberID[i])
        {
            index = i;
            break;
        }
        else
            index = -1;
    }

    if(index >= 0)
    {
        do
        {
            do
            {
                cout << "Select option to update value\n" << endl
                     << "1 \t Name" << endl
                     << "2 \t mamberID" << endl
                     << "3 \t Amount Spent" << endl
                     << "4 \t No. of books bought" << endl
                     << "5 \t Membership Fee Paid(Y/N)" << endl
                     << "0 \t EXIT" << endl
                     << "\n Enter Choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1:
                        cout << "Member Name: ";
                        cin >> name[index];

                        break;

                    case 2:
                        cout << "Member ID: ";
                        cin >> memberID[index];

                        break;

                    case 3:
                        cout << "Amount Spent: ";
                        cin >> amountSpent[index];

                        break;

                    case 4:
                        cout << "No. of books bought: ";
                        cin >> booksBought[index];
                        break;

                    case 5:
                        cout << "Membership Fee Paid(Y/N): ";
                        cin >> membershipFee[index];
                        break;

                    case 0:
                        cout << "\n EXIT \n" << endl;
                        break;

                    default:
                        cout << "\n WRONG CHOICE." << endl;
                        break;
                };


            }while(choice < 0 || choice > 5);

        }while(choice != 0);

    }
    else
    {
        cout << "\n MEMBER DOES NOT EXISTS \n" << endl;
    }
}

/**
 *  Member Menu of Book Store
 */

 void memberType :: memberMenu()
 {
    int choice;
    cout << "\n\t BOOK STORE MEMBER MENU \n" << endl;

    do
    {
        do
        {
            cout << "Select option to perform action on record.\n" << endl
                 << "1 \t Add New Member" << endl
                 << "2 \t Update Member Record" << endl
                 << "3 \t Search Member Record" << endl
                 << "0 \t EXIT" << endl
                 << "\n Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    newMember();
                    break;

                case 2:
                    updateMember();
                    break;

                case 3:
                    searchMember();
                    break;

                case 0:
                    cout << "\n EXIT \n";
                    break;

                default:
                    cout << "\n WRONG CHOICE \n" << endl;
                    break;
            };

        }while(choice < 0 || choice > 3);

    }while(choice != 0);
 }

