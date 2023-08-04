#include "BookList.h"

BookList::BookList()
{
    capacity = 0  ;
    booksCount = 0 ;
}
BookList :: BookList(int capacity){
 this->capacity = capacity;
 books = new Book[capacity];
 booksCount = 0 ;
 }
BookList :: BookList(const BookList& bookList){
capacity = bookList.capacity ;
booksCount = bookList.booksCount;
}
void BookList :: addBook(Book& book){
    books[booksCount] = book ;
    booksCount++;
}
Book * BookList :: searchBook(string name){
for(int i = 0 ; i < booksCount ; i++){
    if(books[i].getTitle() == name){
        return &books[i];
        break;
    }
}
}
Book * BookList :: searchBook(int id){
for(int i = 0 ; i < booksCount ; i++){
    if(books[i].getId() == id){
        return &books[i];
        break;
    }
}
}
void BookList::updateName(int id ,string name){
for(int i = 0 ; i <booksCount ; i++){
    if(books[i].getId() == id){
         books[i].setTitle(name);
    break;
    }
}
}
void BookList::updateAuthor(int id ,User u){
for(int i = 0 ; i <booksCount ; i++){
    if(books[i].getId() == id){
         books[i].setAuthor(u);
    break;
    }
}
}
void BookList::updateCategory(int id ,string category){
for(int i = 0 ; i <booksCount ; i++){
    if(books[i].getId() == id){
         books[i].setCategory(category);
    break;
    }
}
}
void BookList :: deleteBook(int id){
int i ;
for(i = 0 ; i <booksCount ; i++){
    if(books[i].getId() == id)
    break;
}
if(i<booksCount){
    booksCount-=1 ;
    for(int j = i ; j < booksCount ; j++){
        books[j] = books[j+1];
    }
}
}
void BookList::rateBook(int id ,double rating ){
for(int i = 0 ; i <booksCount ; i++){
    if(books[i].getId() == id){
         books[i].rateBook(rating);
    break;
    }
}
}
Book BookList :: getTheHeighestRatedBook(){
    double maxRate = 0;
    int index = 0 ;
for( int i = 0 ; i < booksCount ; i++){
    if(books[i].getAverage() > maxRate){
        maxRate = books[i].getAverage();
        index = i ;
    }
}
return books[index];
}
void BookList :: getBooksForUser(User & user){
    for(int i = 0 ; i < booksCount ; i++){
        if(books[i].getAuthor() == user){
            cout << books[i];
        }
    }

}
Book & BookList :: operator [] (int position){
return books[position];
}
ostream &operator<<(ostream& out , BookList& bookList){
    for(int i = 0 ; i < bookList.booksCount ; i++){
        out << bookList.books[i] ;
    }
    return out ;

}

BookList::~BookList()
{
    delete []books ;
}
