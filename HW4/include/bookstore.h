#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "booktype.h"
#include "membertype.h"

class bookStore : public bookType, public memberType
{
    public:
        /** Default constructor */
        bookStore();

        /** Default destructor */
        ~bookStore();

        /** buy book from book store */
        void buyBook();

        /** Book store menu */
        void bookStoreMenu();

    protected:
        int i, j;

};

#endif // BOOKSTORE_H
