#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"

using namespace std;
void update(BookList *bookL,  UserList *userL, Book book)
{

    int choice, id;
    do
    {
        cout<<"1-Update author\n";
        cout<<"2-Update name\n";
        cout<<"3-Update Category\n";
        cout<<"4-Delete Book\n";
        cout<<"5-Rate Book\n";
        cout<<"6-Return To book Menu\n";
        cin>>choice;
        switch(choice)
        {
        case 1 :
        {
            cin >> id;
            User u =  *(userL->searchUser(id));
            if(u.getId()!=0)
            {
                bookL->updateAuthor(book.getId(), u);
            }
            else
            {
                cout << "No Author found with id = " << id << endl;
            }
        }
        break;
        case 2 :
        {
            string name;
            cin >> name;
            bookL->updateName(book.getId(),name);
        }
        break;
        case 3 :
        {
            string category ;
            cin >> category;
            bookL->updateCategory(book.getId(), category);
        }
        break;
        case 4 :
            bookL->deleteBook(book.getId());
            break;
        case 5 :
        {
            cout<<"Enter Rating value: "<<endl;
            double rateValue;
            cin>> rateValue;
            bookL->rateBook(book.getId(), rateValue);
        }
        break;
        case 6 :
            break;
        }
    }
    while(choice!=6);
}
int main()
{
    UserList *users;
    BookList *books;
    while(true)
    {
        cout << "Select one of the following choices:"<<endl;
        cout <<"1-Books Menu\n" << "2-Users Menu\n" <<"3-Exit\n" ;
        int choice ;

        cin >> choice ;

        switch(choice)
        {
        case 1 :
        {
            cout << "How many Books will be added ? \n" ;
            int n;
            cin >> n ;
            books= new BookList(n);
            do
            {
                cout << "Books Menu\n";
                cout<<"1-Create a book and add it to this list \n";
                cout<<"2-search for a book \n";
                cout<<"3-Display all books \n";
                cout<<"4-Get the highest rating book \n";
                cout<<"5-Get all of a user \n";
                cout<<"6-Back to the main menu \n";
                int choice;
                cin>>choice;
                switch(choice)
                {
                case 1 :
                {
                    Book book;
                    cin >> book;

                    cout<<"1-Assign Author \n";
                    cout<<"2-Continue \n";
                    cin >> choice ;
                    switch(choice)
                    {
                    case 1 :
                    {
                        int id ;
                        cout << "Enter ID: \n";
                        cin >> id;
                        User user =*(users->searchUser(id));

                        if(user.getId() != 0)
                        {
                            book.setAuthor(user);
                            books->addBook(book);
                        }
                        else
                        {
                            cout << "No Author found with id = " << id << endl;
                        }
                    }
                    break;
                    case 2:
                        books->addBook(book);
                        break;
                    }
                }
                break;
                case 2 :

                    do
                    {
                        cout << "Search for a Book\n" ;
                        cout << "1-Search by name\n" << "2-Search by id\n" << "3-Return to book menu\n";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1 :
                        {
                            cout <<"Enter Name: \n" ;
                            string name ;
                            cin >> name;
                            Book book = *books->searchBook(name) ;
                            cout << book ;
                            update(books,users,book);
                        }
                        break;
                            case 2 :
                            {
                             int id ;
                             cout << "Enter ID: \n";
                             cin >> id;
                             Book book = *books->searchBook(id) ;
                             cout << book ;
                             update(books,users,book);

                            }
                            break ;
                            case 3 :
                             break;
                            }
                    }while(choice!=3);
                    break;
                case 3 :
                    cout << *books ;
                    break;
                case 4 :
                    books->getTheHeighestRatedBook();
                    break;
                case 5 :
                    {
                     int id ;
                        cout << "Enter ID: \n";
                        cin >> id;
                        User user =*(users->searchUser(id));

                        if(user.getId() != 0)
                        {

                            books->getBooksForUser(user);
                        }
                        else
                        {
                            cout << "No Author found with id = " << id << endl;
                        }

                    }
                    break;
                case 6:
                    break;


                }//switch book menu
            }while(choice != 6) ;// loop of book menu
        }// case1 book of main menu
        break;
        case 2 :
        {

            cout << "How many users will be added ? \n" ;
            int n;
            cin >> n ;
            users= new UserList(n);
            do
            {
                cout << "Users Menu\n";
                cout << "1-Create a User and add it to the list\n" << "2-Search for a User\n" << "3-Display All Users\n" << "4-Back to the main menu\n";
                cin >> choice;
                switch(choice)
                {
                case 1 :
                {
                    User u ;
                    cin >> u ;
                    users->addUser(u);
                }

                break;
                case 2 :


                    do
                    {
                        cout << "Search for a User\n" ;
                        cout << "1-Search by name\n" << "2-Search by id\n" << "3-Return to user menu\n";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1 :
                        {
                            cout <<"Enter Name: \n" ;
                            string name ;
                            cin >> name;
                            User us = *users->searchUser(name) ;
                            cout << us ;
                            cout << "1-Delete user by id \n" << "2-Back to search menu\n" ;
                            cin >>choice ;
                            switch(choice)
                            {
                            case 1:
                                users->deleteUser(us.getId());
                                break ;
                            case 2 :
                                break;
                            }

                        }
                        break;
                        case 2 :
                        {

                            int id ;
                            cout << "Enter ID: \n";
                            cin >> id;
                            User *us = users->searchUser(id) ;
                            if(us == nullptr) {cout <<"Not found \n";break;}
                            cout << *us ;
                            cout << "1-Delete user by id \n" << "2-Back to search menu\n" ;
                            cin >>choice ;
                            switch(choice)
                            {
                            case 1:
                                users->deleteUser(us->getId());
                                break ;
                            case 2 :
                                break;
                            }

                        }
                        break ;
                        case 3 :
                            break;
                        }
                    }
                    while(choice!=3);
                    break;
                case 3 :
                    cout << *users;
                    break;
                case 4 :
                    break;
                }
            }
            while(choice!=4);
        }
        break;

        }
    }



    return 0;
}
