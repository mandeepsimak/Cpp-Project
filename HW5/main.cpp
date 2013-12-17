#include <iostream>
#include <fstream>

using namespace std;

struct BankAccount
{
    string first_name,       /**< First Name of depositor */
           last_name,        /**< Last Name of depositor */
           security_no,      /**< Social Security No. */
           acc_type;         /**< Account Type: checking, Saving, CD */

    int acc_no,              /**< Account No. */
        acc_balance;         /**< Account Balance */
};

// List of functions used for data processing
int read_accts(BankAccount account[], int max_accts);
int find_acct(const BankAccount account[], int num_accts, int requested_account);
void withdrawal(BankAccount account[], int num_accts);
void deposit(BankAccount account[], int num_accts);
int new_acct(BankAccount account[], int num_accts);
int close_acct(BankAccount account[], int num_accts);
void balance(const BankAccount account[], int num_accts);
void account_info(const BankAccount account[], int num_accts);
void print_accts(const BankAccount account[], int num_accts);

// Bank Menu
void menu();

/**
 *  Main Method
 */

int main()
{
    menu();

    return 0;
}

/**
 *  Menu of Bank Account
 */
 void menu()
 {
    const int MAX_NUM = 10;         // Max no. of account
    BankAccount account[MAX_NUM];   // Structure object array

    int num_accts;  // No of accounts in database

    char choice;    //  Choice/option entered by user from menu

    num_accts = read_accts(account, MAX_NUM);

    // For displaying menu till user not quit
    do
    {
        do
        {
            // Displaying Menu
            cout << "\n\t BANK ACCOUNT MENU \n" << endl
                 << "W  -   Withdrawal" << endl
                 << "D  -   Deposit" << endl
                 << "N  -   New Account" << endl
                 << "B  -   Balance" << endl
                 << "I  -   Account Info" << endl
                 << "C  -   Close Account" << endl
                 << "Q  -   Quit" << endl;

            cout << "\n Enter your choice: ";
            cin >> choice;

            // Wrong choice
            if(choice != 'W' && choice != 'D' && choice != 'N' && choice != 'B' &&
               choice != 'I' && choice != 'C' && choice != 'Q')
                cout << "\n \t Wrong Choice.\n" << endl;

        }while(choice != 'W' && choice != 'D' && choice != 'N' && choice != 'B' &&
               choice != 'I' && choice != 'C' && choice != 'Q');

        switch(choice)
        {
            case 'W':

                break;

            case 'D':

                break;

            case 'N':

                break;

            case 'B':

                break;

            case 'I':

                break;

            case 'C':

                break;

            case 'Q':

                break;
        };

    }while(choice != 'Q');

 }

/**
 *  Reading data from file
 */

int read_accts(BankAccount account[], int max_accts)
{
    ifstream infile;

    string file_name = "accounts.in",
           temp;    // for temporary storage

    int num_accts;  // No. of accounts in database

    infile.open(file_name.c_str());

    infile >> num_accts;

    if(num_accts > max_accts)
    {
        cout << "\n\t Max account allowed: " << max_accts;
        num_accts = max_accts;
    }

    getline(infile, temp, '\n');

    for(int i = 0; i < num_accts; i++)
    {
        getline(infile, account[i].first_name, '\n');
        getline(infile, account[i].last_name, '\n');
        getline(infile, account[i].security_no, '\n');
        infile >> account[i].acc_no;
        getline(infile, temp, '\n');
        getline(infile, account[i].acc_type, '\n');
        infile >> account[i].acc_balance;
    }

    infile.close();

    return num_accts;
}

/**
 *  Finding account in databasse
 */

int find_acct(const BankAccount account[], int num_accts, int requested_account)
{
    int index = -1; // Default value to -1 ie account not found
    for(int i = 0; i < num_accts; i++)
    {
        if(requested_account == account[i].acc_no)
        {
            index = i;  // Return index value if account no matches
            break;
        }
    }

    return index;
}

/**
 *  Withdrawal from bank account
 */

void withdrawal(BankAccount account[], int num_accts)
{
    int acc_no,
        index;      // Index value of account in database

    cout << "\n\t WITHDRAWAL AMOUNT FROM BANK ACCOUNT \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index < 0)
    {
        cout << "\n\t ACCOUNT NOT FOUND \n" << endl;
    }

}

/**
 *  Deposit money in bank
 */

void deposit(BankAccount account[], int num_accts)
{

}

/**
 *  Adding new Bank account
 */

int new_acct(BankAccount account[], int num_accts)
{

}

/**
 *  Closing Account
 */

int close_acct(BankAccount account[], int num_accts)
{

}

/**
 *  Balance in Bank accounts
 */

void balance(const BankAccount account[], int num_accts)
{

}

/**
 *  Account Information
 */

void account_info(const BankAccount account[], int num_accts)
{

}

/**
 *  Print all bank account details
 */

void print_accts(const BankAccount account[], int num_accts)
{

}
