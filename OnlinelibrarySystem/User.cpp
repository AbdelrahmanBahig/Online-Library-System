#include "User.h"
#include <iostream>

using namespace std;
int User:: counter = 0 ;
User::User()
{
    name = "";
    password = "" ;
    email = "";
    age = 0 ;
   id = 0;

}
User :: User(string name , int age , string email, string password ){
    this->name = name;
    this->age = age ;
    this->password = password ;
    this->email =email;
     counter++;
    id = counter;


}
User::User(const User& u){
    name = u.name;
    age = u.age ;
    password = u.password ;
    email = u.email;
    id = u.id ;
}
 bool  User :: operator ==(const User& u) {
     if (name == u.name && email == u.email && age == u.age && id ==u.id)
        return true ;
     else
        return false;
 }
 void User:: setName(string n) {
     name = n ;

 }
string User:: getName()const{
return name ;
}
void User :: setPassword(string p){
    password = p ;
}
string User :: getPassword()const{
return password;
}
void User :: setEmail(string e){
    email = e ;
}
string User :: getEmail()const{
return email;
}
void User :: setAge(int a) {
age = a ;
}
int User :: getAge()const{
return age ;
}
void User :: setId(int i){
    id = i ;
}
int User :: getId()const {
return id ;
}
 void User :: display(){
     cout << "========User" << id << "Info========" <<endl;
 cout <<"Name: " <<name  << " | " << "Age: " <<age << " | " << "Id: " <<id << " | "<< "Email: " << email <<endl ;
 cout << "======================================"  <<endl;
 }
ostream &operator<<(ostream & out , const User & u){
cout << "========User" << u.id << "Info========" <<endl;
out <<"Name: " <<u.name  << " | " << "Age: " <<u.age << " | " << "Id: " <<u.id << " | "<< "Email: " << u.email <<endl ;
return out ;
}
istream &operator>>( istream &input, User &user )
{

    cout << "Name  Age   Email   Password  " << endl;
    input >> user.name;
    input >> user.age;
    input >> user.email;
    input >> user.password;

 User::counter++;
    user.id = User::counter;
    return input;
}

