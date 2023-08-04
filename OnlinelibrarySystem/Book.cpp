#include "Book.h"
int Book :: counter = 0 ;
Book::Book()
{
     title = "" ;
     isbn = "" ;
    id = 0;
     category = "";
     averageRating = 0.0 ;
     User author ;
     numOfRating = 0 ;
     sumOfRating = 0.0 ;
}
Book::Book(string title, string isbn, string category){
    this->title = title;
    this->isbn = isbn ;
    this->category = category ;
    counter++;
    id = counter;
   averageRating = 0.0 ;
     User author ;
     numOfRating = 0 ;
     sumOfRating = 0.0 ;
}
Book::Book(const Book& book){
title = book.title;
isbn = book.isbn ;
category = book.category ;
id = book.id;
averageRating = book.averageRating ;
author = book.author;
numOfRating = book.numOfRating;
sumOfRating = book.sumOfRating;
}
void Book :: setTitle(string title){
this->title = title;
}
string Book ::getTitle()const{
    return title;
}
void Book :: setIsbn(string isbn){
this->isbn = isbn;
}
string Book ::getIsbn()const{
return isbn;
}
void Book :: setCategory(string category){
this->category = category ;
}
string Book :: getCategory()const{
return category;
}
void Book::setId(int id){
    this->id = id;
}
int Book :: getId()const{
return id;
}
void Book::setAuthor(User & author){
this->author = author;
}
User Book:: getAuthor() const{
    return author;
}
void Book::setAverage(double Average){
averageRating = Average ;
}
double Book::getAverage(){
return averageRating;
}
void Book:: rateBook(double rate){
numOfRating++;
sumOfRating+= rate;
averageRating = double(sumOfRating/numOfRating);
}
bool Book:: operator== (const Book& book) {
   return(title==book.title && isbn == book.isbn &&  id == book.id && category == book.category && author == book.author);
}
ostream &operator<< (ostream & out  , const Book & book){
     cout << "========Book" << book.id << "Info========" <<endl;
    out <<"Title: " << book.title << " | " << "Isbn: " <<book.isbn<< " | " << "Id: " <<book.id << " | "<< "Category: " << book.category ;
    out<< " | " << "Average Rate: "  << book.averageRating<<endl ;
    if(book.author.getName()!="") cout<<book.author ;

        cout << "=======================================" <<endl;

return out ;

        }
istream &operator>> (istream & input ,  Book & book){
     cout << "Title  Isbn   Category " <<endl;
     input>> book.title >> book.isbn >>book.category ;
     Book::counter++;
    book.id = Book::counter;
     return input;
}


