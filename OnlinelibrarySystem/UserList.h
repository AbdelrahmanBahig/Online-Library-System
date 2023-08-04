#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"
class UserList
{
      private:
          User * users ;
          int capacity ;
          int usersCount;

    public:
        UserList();
        UserList(int capacity);
        void addUser (User &) ;
        User * searchUser(string);
        User * searchUser(int);
        void deleteUser(int);
         friend ostream &operator <<(ostream & , const UserList &);
        ~UserList();

    protected:


};

#endif // USERLIST_H
