#include "UserList.h"

UserList::UserList()
{
    capacity = 0 ;
    usersCount = 0;
}
UserList::UserList(int capacity)
{
    this->capacity = capacity ;
    users = new User[capacity];
    usersCount = 0;
}
void UserList:: addUser (User & user)
{
    users[usersCount] = user ;
    usersCount++;
}
User * UserList::  searchUser(string name)
{
    for(int i = 0 ; i < usersCount ; i++)
    {
        if(name == users[i].getName()){
            return & users[i];
        break;
        }
    }
    return nullptr;

}
User *UserList:: searchUser(int id)
{
    for(int i = 0 ; i < usersCount ; i++)
    {
        if(id == users[i].getId())
        {
            return & users[i];
            break;
        }
    }
    return nullptr;
}
void UserList:: deleteUser(int id)
{
    int i ;
    for( i = 0 ; i < usersCount ; i++)
    {
        if(id == users[i].getId())
            break;
    }
    if (i < usersCount)
    {
        // reduce size of array and move all
        // elements on space ahead
        usersCount = usersCount - 1;
        for(int j = i ; j < usersCount ; j++)
        {
            users[j]= users[j+1];

        }
    }
}
ostream &operator <<(ostream & out, const UserList & usersList)
{
    for(int i = 0 ; i < usersList.usersCount ; i++)
    {
        out << usersList.users[i] <<endl;
    }
    cout << "======================================"  <<endl;
    return out ;

}

UserList::~UserList()
{
    delete []users ;
}
