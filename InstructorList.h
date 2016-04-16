/*
 *"Everything that we see is a shadow cast by that which we do not see." Martin Luther King Jr.
**/
#ifndef _INSTRUCTORLIST_H_
#define _INSTRUCTORLIST_H_
#include <iostream>
#include <string>
#include <string.h>       /*used for strtok function look at split method*/
#include "Instructor.h"
#define DEFAULT_SIZE 5  /*default size is defined*/

using namespace std;

class InstructorList {
    int List_size;              /*List size is a private variable that will be set to size of  class array*/
    int numofel;       /*numofel represents number of elements in the class array*/
    public:
        Instructor* Liste;
        InstructorList()
        {                                   /*Default constructor*/
            List_size=DEFAULT_SIZE;
            numofel=3;
            Liste=new Instructor[List_size];
            Liste[0].setter("Prof. Dr.","Ulug","Bayazit","ulugbayazit","4308","(+90 212)2853591","ulugbayazit@itu.edu.tr","MAT271E,MAT281E,KOM505E");
            Liste[1].setter("Doc. Dr.","Hatice","Kose","hatice.kose","3315","(+90 212)2853593","hatice.kose@itu.edu.tr","BLG252E");
            Liste[2].setter("Prof. Dr.","Zehra","Cataltepe","cataltepe","3301","(+90 212)2853551","cataltepe@itu.edu.tr","BLG252E,AI455,AI555");
        }
        InstructorList(int ensize)
        {                           /*constructor with parameter to enable user to adjust size*/
            List_size=ensize;
            Liste=new Instructor[List_size];
            numofel=0;
        }
        int lookfor_firstname(string);
        int lookfor_lastname(string);
        int lookfor_phnum(string);
        int lookfor_rnumber(string);       /*required methods*/
        void add_new();
        void delete_instructor();
        void list_all();
        void print_one(Instructor);
        string* split(string);
    ~InstructorList() { }  /*destructor*/
};

void InstructorList::print_one(Instructor teacher)              /*it enables me to print search result->founded Instructor*/
{
    string* hold;
    hold=split(teacher.getcourses());
    cout<<"Title: "<<teacher.gettitle()<<endl;
    cout<<"Name: "<<teacher.getname()<<endl;
    cout<<"Surname "<<teacher.getsurname()<<endl;
    cout<<"Telephone Number: "<<teacher.getphonenumber()<<endl;
    cout<<"Room Number: "<<teacher.getroomnumber()<<endl;
    cout<<"User Name: "<<teacher.getusername()<<endl;
    cout<<"E-mail: "<<teacher.getemail()<<endl;
    cout<<"Courses: [";
    for(int i=0;hold[i]!="end";i++)
    {
        if(hold[i+1]=="end")cout<<hold[i]<<"]"<<endl;
        else cout<<hold[i]<<",";
    }
}

void InstructorList::add_new()
{
    string title,namer,rnum,surnamer,phnum,emailadd,username,lecture_str;
    cin.ignore(1000,'\n');
    cout<<"Enter the title:"<<endl;
    getline(cin,title);
    cout<<"Enter the First Name:"<<endl;
    getline(cin,namer);
    cout<<"Enter the Last Name:"<<endl;
    getline(cin,surnamer);
    cout<<"Enter the Telephone Number: "<<endl;
    getline(cin,phnum);
    cout<<"Enter the Room Number:"<<endl;
    getline(cin,rnum);
    cout<<"Enter the User Name: "<<endl;
    getline(cin,username);
    emailadd=username+"@itu.edu.tr";        /*email address is equal to username@itu.edu.tr*/
    cout<<"Enter the courses: "<<endl;
    getline(cin,lecture_str);            /*In here courses are taken as string but split function divide string into parts and stores parts in string array*/

    if(lookfor_firstname(namer)>=0)
    {
        cout<<"The instructor has already been added in address book!!"<<endl;
    }

    else
    {
        Instructor newbee;                              /*new instructor constructed and variables are set with setter method*/
        newbee.setter(title,namer,surnamer,username,rnum,phnum,emailadd,lecture_str);

        if(List_size>numofel)      /*first case array size is not changed*/
        {
            Liste[numofel]=newbee;
            numofel+=1;
        }
        else                    /*second case array size is not sufficient and should be changed*/
        {
            int rsize=numofel+1;
            Instructor* new_temp=new Instructor[rsize];
            for(int i=0;i<numofel;i++)
            {
                new_temp[i]=Liste[i];     /*values are putted in temp array*/
            }
            new_temp[numofel]=newbee; /*new instructor is put in temp*/
            delete [] Liste;            /*insufficient array is deleted*/
            numofel=0;
            Liste=new Instructor[rsize+5];  /*sufficient array is constructed with 6 more size*/
            for(int i=0;i<rsize;i++)
            {
                Liste[i]=new_temp[i];    /*returning elements in original array*/
                numofel+=1;
            }
            delete [] new_temp;     /*temp is deleted*/
            cout<<"New instructor is added!"<<endl;
        }
    }
}

string* InstructorList::split(string input)
{
    char* hold=new char[input.size()+1]; /*Because strtok() uses char* taken string will be stored in char* */
    hold[input.size()]='\0';
    copy(input.begin(),input.end(),hold); /*string is copied in hold */
    for(int i=0;hold[i]!='\0';i++)
    {
        if(hold[i]==' ' || hold[i]=='-') hold[i]=','; /*in here I inserted new delimiter options one space or dash are turned into comma*/
    }
    string* newlines=new string[input.size()];
    char* splitted=strtok(hold,",");
    int i=0;
    int num_of_words=0;
    while(splitted)
    {
        newlines[i]=splitted;
        splitted=strtok(NULL,",");  /*splitting*/
        num_of_words++;         /*count how many separated courses there are*/
        i++;
    }
    string* course_list = new string[num_of_words+1]; /*use that counter for dynamic allocation*/
    for(i=0;i<num_of_words;i++)
    {
        course_list[i]=newlines[i];
    }
    course_list[num_of_words]="end"; /* "end" is used to terminate string array like '\0' */
    delete [] newlines;
    return course_list;  /*string* is returned and courses are stored in string array aka string* that is dynamically allocated */
};

void InstructorList::delete_instructor()
{
    string name,surname;
    cout<<"Enter the first name of the record to be deleted:";
    cin.ignore(1000,'\n');
    getline(cin,name);
    cout<<"Enter the last name of the record to be deleted:";
    getline(cin,surname);

    Instructor* temp=new Instructor[numofel]; /*temp array is constructed*/
    int check_name=lookfor_firstname(name);  /*checking the given name and surname whether already in list or not*/
    int check_surname=lookfor_lastname(surname);/*search methods return the position of searched instructor*/
    if(check_name>=0 && check_surname>=0)
    {
        for(int i=0;i<numofel;i++)
        {
            if(i==check_name && i==check_surname)  /*if the position and i is same do not do anything*/
            {
                continue;
            }
            else
            {
                if(i>check_name && i>check_surname) temp[i-1]=Liste[i];     /*if i bigger than position list would be shifted*/
                else temp[i]=Liste[i]; /*in normal case each element are transported temp array*/
            }
        }
        delete [] Liste; /*old array deallocated*/
        if(numofel<DEFAULT_SIZE)Liste = new Instructor[DEFAULT_SIZE]; /*allocate new array*/
        else Liste = new Instructor[numofel-1];
        numofel-=1; /*decrement one number of elements*/
        for(int i=0;i<numofel;i++)
        {
            Liste[i]=temp[i];   /*send back elements respectively*/
        }
        delete [] temp; /*delete temporary array*/
        cout<<"Record Deleted!"<<endl; /*print success message*/
    }
    else
    {
        cout<<"Wrong entry"<<endl;      /*if given name is not in list error message are printed*/
        cout<<"Check the list of instructors"<<endl;
        list_all();                   /*list is also printed to provide clear sight*/
    }
}

void InstructorList::list_all()
{
    string* hold;  /*for the courses of instructors*/

    cout<<"----------List of all Instructors in Computer Engineering of ITU ---------- "<<endl;
    int i=0;
    while(i<numofel)
    {
        hold=split(Liste[i].getcourses());
        cout<<"Title: "<<Liste[i].gettitle()<<endl;
        cout<<"Name: "<<Liste[i].getname()<<endl;      /*get methods were utilized here*/
        cout<<"Surname "<<Liste[i].getsurname()<<endl;
        cout<<"Telephone Number: "<<Liste[i].getphonenumber()<<endl;
        cout<<"Room Number: "<<Liste[i].getroomnumber()<<endl;
        cout<<"User Name: "<<Liste[i].getusername()<<endl;
        cout<<"E-mail: "<<Liste[i].getemail()<<endl;
        cout<<"Courses: [";
        for(int j=0;hold[j]!="end";j++)
        {
            if(hold[j+1]=="end") cout<<hold[j]<<"]"<<endl;
            else cout<<hold[j]<<",";
        }
        cout<<endl;
        cout<<"****************************************************************************"<<endl;
        i++;
    }

}

int InstructorList::lookfor_firstname(string key_name)
{
    int position=-1;
    for(int i=0;i<numofel;i++)
    {
        if(key_name==Liste[i].getname())        /*search for target name and return position*/
        {
            position=i;
            return position;
        }
    }
    return position;
}

int InstructorList::lookfor_lastname(string key_surname)
{
    int position=-1;
    for(int i=0;i<numofel;i++)                      /*search for target surname and return position*/
    {
        if(key_surname==Liste[i].getsurname())
        {
            position=i;
            return position;
        }
    }
    return position;
}

int InstructorList::lookfor_phnum(string key_phonnum)
{
    int position=-1;
    for(int i=0;i<numofel;i++)
    {                                                 /*search for target telephone number and return position*/
        if(key_phonnum==Liste[i].getphonenumber())
        {
            position=i;
            return position;
        }
    }
    return position;
}

int InstructorList::lookfor_rnumber(string key_rnumber)
{
    int position=-1;
    for(int i=0;i<numofel;i++)                      /*search for target room number and return position*/
    {
        if(key_rnumber==Liste[i].getroomnumber())
        {
            position=i;
            return position;
        }
    }
    return position;
}
#endif
