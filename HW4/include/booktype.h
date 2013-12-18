#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_BOOKS = 100,
          MAX_AUTHORS = 4;

class bookType
{
    public:
        /** Default constructor */
        bookType();

        /** Default destructor */
        ~bookType();

        /** Add new bok record */
        void addBook();

        /** Update book record */
        void updateBook();

        /** Search book record */
        void searchBook();

        /** Book Menu */
        void bookMenu();

    protected:

        int totalAuthor[MAX_BOOKS],        /**< Total authors of book */
            publicationYear[MAX_BOOKS],    /**< Year of publication */
            totalBooks,                    /**< Total Book records in file */
            bookPrice[MAX_BOOKS],          /**< Book Price */
            stock[MAX_BOOKS],              /**< No. of copies in stock */
            i, j,                          /**< Looping variables */
            index;                         /** index of array */

        string title[MAX_BOOKS],                /**< Title of book */
               author[MAX_BOOKS][MAX_AUTHORS],  /**< No of authors per book */
               publisher[MAX_BOOKS],            /**< Publisher of book */
               ISBNNumber[MAX_BOOKS],           /**< ISBN Number */
               temp;                            /**< Temporary variable */

        const string inputFile = "book.in";     /**< Input file for book record */

};

#endif // BOOKTYPE_H
