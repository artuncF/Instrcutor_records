/*
 *"Everything that we see is a shadow cast by that which we do not see." Martin Luther King Jr.
**/
#include <iostream>
#include "InstructorList.h"
#include <string>
#include <stdlib.h>

using namespace std;

class AddressBook
{
    InstructorList List;  /*InstructorList is constructed*/
    public:
        AddressBook() { }  /*constructor*/
        void program();
        ~AddressBook() {    /*deconstructor*/
        }
};
void AddressBook::program()
{
    bool turn=true;
     int choice;
     char choose;
    while(turn){
    cout<<"1. Add a new instructor"<<endl;
    cout<<"2. Delete an instructor"<<endl;
    cout<<"3. List all instructors"<<endl;
    cout<<"4. Search by Name"<<endl;            /*program interface*/
    cout<<"5. Search by Surname"<<endl;
    cout<<"6. Search by Telephone Number"<<endl;
    cout<<"7. Search by Room Number"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Enter the number for operation you want to perform:"<<endl;
    cin>>choice;
    int i=-1;
    string key;
    switch(choice)
    {
        case 1:
            List.add_new();
            break;
        case 2:
            List.delete_instructor();
            break;
        case 3:
            List.list_all();
            break;
        case 4:
            {
            cout<<"Enter the first name:"<<endl;
            cin.ignore(1000,'\n');
            getline(cin,key);
            i=List.lookfor_firstname(key);
            if(i>=0)
            {
                List.print_one(List.Liste[i]);
            }
            else cout<<"Not found!"<<endl;
            break;
            }
        case 5:
            {
            cout<<"Enter the last name:"<<endl;
            cin.ignore(1000,'\n');
            getline(cin,key);                                       /*program interface*/
            i=List.lookfor_lastname(key);
            if(i>=0)
            {
                List.print_one(List.Liste[i]);
            }
            else cout<<"Not found!"<<endl;
            break;
            }
        case 6:
            {
            cout<<"Enter the telephone number:"<<endl;
            cin.ignore(1000,'\n');
            getline(cin,key);
            i=List.lookfor_phnum(key);
            if(i>=0)
            {
                List.print_one(List.Liste[i]);
            }
            else cout<<"Not found!"<<endl;
            break;                                          /*program interface*/
            }
        case 7:
            {
            cout<<"Enter the room number:"<<endl;
            cin.ignore(1000,'\n');
            cin>>key;
            i=List.lookfor_rnumber(key);
            if(i>=0)
            {
                List.print_one(List.Liste[i]);
            }
            else cout<<"Not found!"<<endl;
            break;
            }
        case 8:
            cout<<"Program exiting..."<<endl;
            exit(0);
            break;
        default:
            cout<<"Input value should be in range (1 to 8)!"<<endl;
            break;
    }
    cout<<"Do you want to perform another operation?(Y/N)"<<endl;
    cin>>choose;
    if(choose=='n' || choose=='N') turn=false;
}

}
int main()
{
    AddressBook book;
    book.program();     /*main*/
    book.~AddressBook();
    return 0;
}
