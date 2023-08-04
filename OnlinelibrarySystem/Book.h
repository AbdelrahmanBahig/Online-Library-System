#ifndef BOOK_H
#define BOOK_H
#include "User.h"

#include <iostream>

using namespace std;
class Book
{
     private:
         string title ;
         string isbn ;
         int id ;
         string category;
         double averageRating ;
         int numOfRating ;
         double sumOfRating ;
         User author;

     public:
         static int counter;
        Book();
        Book(string , string , string);
        Book(const Book&);
         void setTitle(string) ;
        string getTitle()const;
        void setIsbn(string);
        string getIsbn()const;
        void setCategory(string);
        string getCategory()const;
        void setId(int);
         int getId()const;
         void setAuthor(User &);
         User getAuthor() const;
         void setAverage(double Average);
         double getAverage();

        void rateBook(double);
        bool operator== (const Book&) ;
        friend ostream &operator<< (ostream & , const Book &);
        friend istream &operator>> (istream & ,  Book &);



     protected:


};

#endif // BOOK_H
