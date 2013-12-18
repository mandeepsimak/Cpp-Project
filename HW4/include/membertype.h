#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_MEM   =   50;     // Maximum members

class memberType
{
    public:
        /** Default constructor */
        memberType();

        /** Default destructor */
        ~memberType();

        /** Add new member */
        void newMember();

        /** Search Member from record */
        void searchMember();

        /** update member record */
        void updateMember();

        /** Member menu */
        void memberMenu();

    protected:
        string name[MAX_MEM],        // Member name
               temp;

        const string fileName = "member.in";

        int memberID[MAX_MEM],          // Member ID
            amountSpent[MAX_MEM],       // Amount spent on book store
            booksBought[MAX_MEM],       // No of books bought
            totalMembers,               // total Members
            i, j,
            index;

        char membershipFee[MAX_MEM];     // Membership fee yes = paid and no = not pais

};

#endif // MEMBERTYPE_H
