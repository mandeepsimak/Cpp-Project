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
    protected:
    private:
};

#endif // BOOKSTORE_H
