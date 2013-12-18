#include "bookstore.h"

bookStore::bookStore() : bookType(), memberType()   // calling cunstructor of base classes
{
    //ctor
}

bookStore::~bookStore()
{
    //dtor
}

/**
 *  But book from book store
 */

void bookStore :: buyBook()
{
    int maxBook = 10,
        bookIndex,
        memIndex;
    float discount = 0;

    string ISBNNo;

    // Taking value of ISBN number for buying book
    cout << "\n\t BUY BOOK \n" << endl;

    cout << "Enter ISBN number of book: ";
    cin >> ISBNNo;

    // Finding book in database
    for(i = 0; i < totalBooks; i++)
    {
        if(ISBNNo == ISBNNumber[i])
        {
            bookIndex = i;
            break;
        }
        else
            bookIndex = -1;
    }

    // If book found
    if(bookIndex >= 0)
    {
        char mem;
        int memID;
        // Check book in stock or not
        if(stock[bookIndex] > 0)
        {
            cout << "Are you a member(Y/N): ";
            cin >> mem;
            // If customer is a member
            if(mem == 'Y' || mem == 'y')
            {
                cout << "Enter member ID: ";
                cin >> memID;

                // Find member in database
                for(i = 0; i < totalMembers; i++)
                {
                    if(memID == memberID[i])
                    {
                        memIndex = i;
                        break;
                    }
                    else
                        memIndex = -1;
                }

                // If member found
                if(memIndex >= 0)
                {
                    // Find discount if member has paid membership
                    if(membershipFee[memIndex] == 'Y' || membershipFee[memIndex] == 'y')
                        discount = 5 * bookPrice[bookIndex] / 100;
                    else
                        discount = 0;

                    // Add average of amount spent in discount if booksBought = 10 and set spent amount to 0
                    if(booksBought[memIndex] == maxBook)
                    {
                        discount += amountSpent[memIndex] / 10;
                    }
                }
                else
                {
                    cout << "\n\t MEMBER DOES NOT EXISTS \n" << endl;
                }
            }
            // Show book cost
            int buy;
            cout << "\n Cost of book: " << bookPrice[bookIndex] << endl
                 << "Discount = " << discount << endl
                 << "Book Price: " << (bookPrice[bookIndex] - discount) << endl
                 << "Press 1 to buy: ";
            cin >> buy;

            if(buy == 1)
            {
                cout << "\n Book Purchased. Thanks. \n" << endl;
                if(mem == 'Y' || mem == 'y')
                {
                    // updating value in database of member
                    if(booksBought[memIndex] == maxBook)
                    {
                        amountSpent[memIndex] = 0;
                    }
                    else
                    {
                        // If books bought < 10, increment books bought and add price in amount spent
                        booksBought[memIndex]++;
                        amountSpent[memIndex] += bookPrice[bookIndex];
                    }
                }
            }
        }
        else
        {
            cout << "\n\t BOOK IS NOT IN STORE \n" << endl;
        }
    }
}

/**
 *  Book store menu for accessing books and members
 */

void bookStore :: bookStoreMenu()
{
    int choice,
        memID;

    cout << "\n\t BOOK STORE MENU \n" << endl;

    do
    {
        do
        {
            cout << "Select any option" << endl
                 << "1 \t Book Menu" << endl
                 << "2 \t Membership Menu" << endl
                 << "3 \t Buy Book" << endl
                 << "0 \t EXIT" << endl
                 << "\n Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    bookMenu();
                    break;

                case 2:
                    memberMenu();
                    break;

                case 3:
                    buyBook();
                    break;

                case 0:
                    cout << "\n\t EXIT" << endl;
                    break;

                default:
                    cout << "\n\t WRONG CHOICE" << endl;
                    break;
            }

        }while(choice < 0 || choice > 3);

    }while(choice != 0);
}
