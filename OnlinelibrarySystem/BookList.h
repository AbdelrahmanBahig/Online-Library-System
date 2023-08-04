#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"

class BookList
{
    private:
        Book *books;
        int capacity ;
        int booksCount;
    public:
        BookList();
        BookList(int);
        BookList(const BookList&);
        void addBook(Book&);
        Book * searchBook(string name);
        Book * searchBook(int id);
        void deleteBook(int id);
        Book getTheHeighestRatedBook();
        void getBooksForUser(User &);
        void updateName(int id ,string name);
        void updateAuthor(int id ,User u);
        void updateCategory(int id ,string category);
        void rateBook(int id ,double rating );
        Book &operator [] (int position);
        friend ostream &operator<<(ostream& , BookList&);
        ~BookList();

    protected:


};

#endif // BOOKLIST_H
