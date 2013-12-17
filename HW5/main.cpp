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
    menu(); // Calling Bank Menu

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

    num_accts = read_accts(account, MAX_NUM);   // No. of accounts

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
            case 'W':       // Withdrawal
                withdrawal(account, num_accts);

                break;

            case 'D':       // Deposit
                deposit(account,num_accts);

                break;

            case 'N':       // New Account
                num_accts = new_acct(account, num_accts);

                break;

            case 'B':       // Balance
                balance(account,num_accts);

                break;

            case 'I':       // Account Info
                account_info(account, num_accts);

                break;

            case 'C':       // Close Account
                num_accts = close_acct(account, num_accts);

                break;

            case 'Q':       // Quit and print values in file
                print_accts(account, num_accts);

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

    string file_name = "accounts.in",   // Input file name
           temp;    // for temporary storage

    int num_accts;  // No. of accounts in database

    infile.open(file_name.c_str());

    infile >> num_accts;

    if(num_accts > max_accts)
    {
        cout << "\n\t Max account allowed: " << max_accts;
        num_accts = max_accts;
    }

    getline(infile, temp, '\n');    // reading blank line

    for(int i = 0; i < num_accts; i++)
    {
        getline(infile, account[i].first_name, '\n');
        getline(infile, account[i].last_name, '\n');
        getline(infile, account[i].security_no, '\n');
        infile >> account[i].acc_no;
        getline(infile, temp, '\n');    // reading blank line
        getline(infile, account[i].acc_type, '\n');
        infile >> account[i].acc_balance;
        getline(infile, temp, '\n');    // reading blank line
    }

    infile.close();

    return num_accts;   // returninh total no. of accounts
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
        index,      // Index value of account in database
        withdrawal_amt; //  Amount of withdrawal

    cout << "\n\t WITHDRAWAL AMOUNT FROM BANK ACCOUNT \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index < 0)   // if index < 0 means account not exists
    {
        cout << "\n\t ACCOUNT NOT FOUND \n" << endl;
    }
    else
    {
        cout << "\nEnter amount of withdrawal: ";
        cin >> withdrawal_amt;

        // If Balance < withdrawal amount then cancel transaction
        if(withdrawal_amt > account[index].acc_balance)
            cout << "\n\t NOT SUFFICIENT BALANCE. TRANSACTION CANCELLED.\n" << endl;
        else
        {
            account[index].acc_balance = account[index].acc_balance - withdrawal_amt;
            cout << "\n\t TRANSACTION SUCCESSFULLY DONE. \n";
        }
    }

}

/**
 *  Deposit money in bank
 */

void deposit(BankAccount account[], int num_accts)
{
    int acc_no,
        index,        // Index value of account in database
        deposit_amt;  //  Amount of withdrawal

    cout << "\n\t DEPOSIT AMOUNT IN BANK ACCOUNT \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index < 0)
    {
        cout << "\n\t ACCOUNT NOT FOUND \n" << endl;
    }
    else
    {
        cout << "\nEnter amount to deposit: ";
        cin >> deposit_amt;
        // Adding deposit amount with current balance
        account[index].acc_balance = account[index].acc_balance + deposit_amt;
        cout << "\n\t TRANSACTION SUCCESSFULLY DONE. \n";
    }
}

/**
 *  Adding new Bank account
 */

int new_acct(BankAccount account[], int num_accts)
{
    int acc_no,
        index;        // Index value of account in database

    cout << "\n\t ADD NEW BANK ACCOUNT \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index >= 0)
    {
        cout << "\n\t ACCOUNT ALREADY EXISTS \n" << endl;
    }
    else
    {
        cout << "\n\t Enter Depositor's detail.\n" << endl;
        index = num_accts;  // Index value of new account
        num_accts++;    //  Incrementing total accounts

        account[index].acc_no = acc_no;

        cout << "First Name: ";
        cin >> account[index].first_name;
        cout << "Last Name: ";
        cin >> account[index].last_name;
        cout << "Social Security No.: ";
        cin >> account[index].security_no;
        cout << "Account Type(Checking, Saving, CD): ";
        cin >> account[index].acc_type;
        cout << "Initial Deposit Amount: ";
        cin >> account[index].acc_balance;
    }

    return num_accts;
}

/**
 *  Closing Account
 */

int close_acct(BankAccount account[], int num_accts)
{
    int acc_no,
        index;      // Index value of account in database

    cout << "\n\t CLOSE BANK ACCOUNT \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index < 0)
    {
        cout << "\n\t ACCOUNT NOT EXITS \n" << endl;
    }
    else
    {
        // deleting entry from account by matching
        // index and shifting elements by 1
        for(int i = index; i < num_accts; i++)
        {
            account[i].first_name = account[i + 1].first_name;
            account[i].last_name = account[i + 1].last_name;
            account[i].security_no = account[i + 1].security_no;
            account[i].acc_no = account[i + 1].acc_no;
            account[i].acc_type = account[i + 1].acc_type;
            account[i].acc_balance = account[i + 1].acc_balance;
        }

        // Decrementing total accounts by 1
        num_accts--;
    }

    return num_accts;
}

/**
 *  Balance in Bank accounts
 */

void balance(const BankAccount account[], int num_accts)
{
    int acc_no,
        index;      // Index value of account in database

    cout << "\n\t CHECK AMOUNT BALANCE IN BANK \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index < 0)
    {
        cout << "\n\t ACCOUNT NOT FOUND \n" << endl;
    }
    else
    {
        cout << "\nBalance: " << account[index].acc_balance << endl;
    }
}

/**
 *  Account Information
 */

void account_info(const BankAccount account[], int num_accts)
{
    int acc_no,
        index;      // Index value of account in database

    cout << "\n\t CHECK AMOUNT INFO IN BANK \n" << endl;

    cout << "Enter account number: ";
    cin >> acc_no;

    index = find_acct(account, num_accts, acc_no);

    if(index < 0)
    {
        cout << "\n\t ACCOUNT NOT FOUND \n" << endl;
    }
    else
    {
        cout << "\nAccount Info of " << acc_no << "\n" << endl;
        cout << "First Name: " << account[i].first_name << endl
             << "Last Name: " << account[i].last_name << endl
             << "Security No: " << account[i].security_no << endl
             << "Account Type: " << account[i].acc_type << endl
             << "Balance: " << account[i].acc_balance << endl;
    }
}

/**
 *  Print all bank account details
 */

void print_accts(const BankAccount account[], int num_accts)
{
    ofstream outfile;

    string file_name = "accounts.out";  //  Output file for details

    cout << "\n\t Check 'accounts.out' file to see all updated records\n" << endl;

    outfile.open(file_name.c_str());

    outfile << "Total Accounts: " << num_accts << "\n" << endl;

    outfile << "First Name \t Last Name \t Security No. \t Account No. \t "
               "Account Type \t Balance\n" << endl;

    for(int i = 0; i < num_accts; i++)
    {
        outfile << account[i].first_name << "\t"
                << account[i].last_name << "\t"
                << account[i].security_no << "\t"
                << account[i].acc_no << "\t"
                << account[i].acc_type << "\t"
                << account[i].acc_balance << endl;
    }

    outfile.close();
}
