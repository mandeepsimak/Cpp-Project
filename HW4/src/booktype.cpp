#include "booktype.h"

bookType::bookType()
{
    //ctor

    // Reading book details from input file
    ifstream inFile;

    inFile.open(inputFile.c_str());

    inFile >> totalBooks;
    getline(inFile, temp, '\n');

    for(i = 0; i < totalBooks; i++)
    {
        getline(inFile, title[i], '\n');
        inFile >> totalAuthor[i];

        getline(inFile, temp, '\n');

        for(j = 0; j < totalAuthor[i]; j++)
        {
            getline(inFile, author[i][j], '\n');
        }

        getline(inFile, publisher[i], '\n');
        getline(inFile, ISBNNumber[i], '\n');

        inFile >> bookPrice[i]
               >> publicationYear[i]
               >> stock[i];

        getline(inFile, temp, '\n');
    }


    inFile.close();

}

bookType::~bookType()
{
    //dtor
}

/**
 *  Add new book record
 */
void bookType :: addBook()
{
    index = totalBooks;
    cout << "\n\t ADD NEW BOOK RECORD \n" << endl;

    cout << "Book Title: ";
    cin >> title[index];

    cout << "No. of authors of book: ";
    cin >> totalAuthor[index];

    for(i = 0; i < totalAuthor[index]; i++)
    {
        cout << "Author " << (i + 1) << ": ";
        cin >> author[index][i];
    }

    cout << "Name of publisher: ";
    cin >> publisher[index];

    cout << "Enter ISBN Number: ";
    cin >> ISBNNumber[index];

    cout << "Year of publication: ";
    cin >> publicationYear[index];

    cout << "Book Price: ";
    cin >> bookPrice[index];

    cout << "Books in stock: ";
    cin >> stock[index];

    totalBooks++;
}

/**
 *  Update book record
 */
void bookType :: updateBook()
{
    string recordNo;
    int choice;

    cout << "\n\t UPDATE BOOK RECORD \n" << endl;

    cout << "Enter ISBN number to update book record: ";
    cin >> recordNo;

    for(i = 0; i < totalBooks; i++)
    {
        if(recordNo == ISBNNumber[i])
        {
            index = i;
            do
            {
                do
                {
                    cout << "Select option to update value\n" << endl
                         << "1 \t Title" << endl
                         << "2 \t Authors" << endl
                         << "3 \t Publisher Name" << endl
                         << "4 \t ISBN Number" << endl
                         << "5 \t Year of Publication" << endl
                         << "6 \t Book Price" << endl
                         << "7 \t Books in stock" << endl
                         << "0 \t EXIT" << endl
                         << "\n Enter Choice: ";
                    cin >> choice;

                    switch(choice)
                    {
                        case 1:
                            cout << "Book Title: ";
                            cin >> title[index];
                            break;

                        case 2:
                            cout << "No. of authors of book: ";
                            cin >> totalAuthor[index];

                            for(i = 0; i < totalAuthor[index]; i++)
                            {
                                cout << "Author " << (i + 1) << ": ";
                                cin >> author[index][i];
                            }
                            break;

                        case 3:
                            cout << "Name of publisher: ";
                            cin >> publisher[index];
                            break;

                        case 4:
                            cout << "Enter ISBN Number: ";
                            cin >> ISBNNumber[index];
                            break;

                        case 5:
                            cout << "Year of publication: ";
                            cin >> publicationYear[index];
                            break;

                        case 6:
                            cout << "Book Price: ";
                            cin >> bookPrice[index];
                            break;

                        case 7:
                            cout << "Books in stock: ";
                            cin >> stock[index];
                            break;

                        case 0:
                            cout << "\n EXIT \n" << endl;
                            break;

                        default:
                            cout << "\n WRONG CHOICE." << endl;
                            break;
                    };


                }while(choice < 0 || choice > 7);

            }while(choice != 0);
        }
        else
        {
            cout << "\n\t RECORD NOT FOUND. \n" << endl;
        }
    }

}

/**
 *  Search book record
 */
void bookType :: searchBook()
{
    string recordNo;

    cout << "\n\t SEARCH BOOK RECORD \n" << endl;

    cout << "Enter ISBN number to search book record: ";
    cin >> recordNo;

    for(i = 0; i < totalBooks; i++)
    {
        if(recordNo == ISBNNumber[i])
        {
            index = i;

            // Displaying Book details
            cout << "Book Title: " << title[index] << endl;

            cout << "No. of authors of book: "<< totalAuthor[index] << endl;

            for(i = 0; i < totalAuthor[index]; i++)
            {
                cout << "Author " << (i + 1) << ": " << author[index][i] << endl;
            }

            cout << "Name of publisher: " << publisher[index] << endl;

            cout << "Enter ISBN Number: " << ISBNNumber[index] << endl;

            cout << "Year of publication: " << publicationYear[index] << endl;

            cout << "Book Price: " << bookPrice[index] << endl;

            cout << "Books in stock: " << stock[index] << endl;
        }
        else
        {
            cout << "\n\t RECORD NOT FOUND. \n" << endl;
        }
    }
}

/**
 *  Book Menu for Book Store
 */

 void bookType :: bookMenu()
 {
    int choice;
    cout << "\n\t BOOK MENU \n" << endl;

    do
    {
        do
        {
            cout << "Select option to perform action on record.\n" << endl
                 << "1 \t Add New Book" << endl
                 << "2 \t Update Book Record" << endl
                 << "3 \t Search Book Record" << endl
                 << "0 \t EXIT" << endl
                 << "\n Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    addBook();
                    break;

                case 2:
                    updateBook();
                    break;

                case 3:
                    searchBook();
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
