/*
 *"Everything that we see is a shadow cast by that which we do not see." Martin Luther King Jr.
**/
#ifndef _INSTRUCTOR_H_
#define _INSTRUCTOR_H_
#include <string>
#include <iostream>
using namespace std;

class Instructor
{                                                       /*Instructor class is written with its' private variables,constructors and setter-getters*/
    string title;
    string name;
    string lastname;
    string username;
    string roomnumber;
    string phonenumber;
    string emailaddress;
    string courses;
	public:
        Instructor() { }
        Instructor(string) { }
        Instructor(string const & title, string const & name, string & lastname, string const & username,string const & roomnumber, string const & phonenumber, string const & emailaddress, string const & courses): title(title), name(name), lastname(lastname), username(username), roomnumber(roomnumber),phonenumber(phonenumber), emailaddress(emailaddress),courses(courses){ }
        void setter(string truth, string first, string last, string user, string rnum, string phnum, string mail, string lectures)
        {
                title=truth;
                name=first;
                lastname=last;
                username=user;
                roomnumber=rnum;
                phonenumber=phnum;
                emailaddress=mail;
                courses=lectures;
        }
        string gettitle();
        string getname();
        string getsurname();
        string getusername();
        string getroomnumber();
        string getphonenumber();
        string getemail();
        string getcourses();
       ~Instructor() { }
};
string Instructor::gettitle()
{
    return title;
}
string Instructor::getname()
{
    return name;
}
string Instructor::getsurname()
{
    return lastname;
}
string Instructor::getusername()
{
    return username;
}
string Instructor::getphonenumber()
{
    return phonenumber;
}
string Instructor::getroomnumber()
{
    return roomnumber;
}
string Instructor::getcourses()
{
    return courses;
}
string Instructor::getemail()
{
    return emailaddress;
}
#endif // _INSTRUCTOR_H_
