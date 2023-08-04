#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;
class User
{
      private:
          string name ;
          int age ;
          int id ;
          string password ;
          string email;
    public:
        static int counter;
        User();
        User(string , int , string , string);
        User(const User&);
        bool operator ==(const User&) ;
        void setName(string) ;
        string getName()const;
        void setPassword(string);
        string getPassword()const;
        void setEmail(string);
        string getEmail()const;
        void setAge(int);
        int getAge()const;
        void setId(int);
        int getId()const;
        void display();
        friend ostream &operator <<(ostream & , const User &);
        friend istream &operator>>(istream &  ,  User & );



    protected:


};

#endif // USER_H
