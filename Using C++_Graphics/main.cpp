/*#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

class Book
{
    public:
        int Book_ID,quantity,flag;
        char bname[50],publication[50],author[50];
        double price;

        Book()
        {
            flag=1;
            Book_ID=0;
            quantity=0;
            strcpy(bname,(char*)"");
            strcpy(publication,(char*)"");
            strcpy(author,(char*)"");
            price=0.0;
        }

        void getData()
        {
            cout<<endl<<"Enter Book ID :- ";
            cin>>Book_ID;
            cout<<endl<<"Enter Book Name :- ";
            cin>>bname;
            cout<<endl<<"Enter Author :- ";
            cin>>author;
            cout<<endl<<"Enter Publication :- ";
            cin>>publication;
            cout<<endl<<"Enter Quantity available in Library :- ";
            cin>>quantity;
            cout<<endl<<"Enter Price  :- ";
            cin>>price;
        }

        void addBook(Book b)
        {
            fstream fptr("Book.bin",ios::out|ios::app|ios::binary);
            fptr.write((char*)&b,sizeof(Book));
            fptr.close();
            cout<<endl<<"Book Added.";
        }

        char* getName(int id)
        {
            char *temp = new char[50];
            Book b;
            fstream fptr("Book.bin",ios::in|ios::binary);
            while(fptr.read((char*)&b,sizeof(b)))
            {
                    if(id == b.Book_ID)
                    {
                        strcpy(temp,b.bname);
                        return temp;
                    }
            }
        }

        void getBookDetails()
        {
            Book b;
            fstream fptr("Book.bin",ios::in|ios::binary);
            while(fptr.read((char*)&b,sizeof(Book)))
            {
                if(b.flag==1)
                    b.display();
            }
            fptr.close();
        }

        void updateBookDetails()
        {
            Book b;
            int id,p;
            fstream fptr("Book.bin",ios::in|ios::out|ios::binary);
            getBookDetails();
            cout<<endl<<"Enter Book ID to Update:- ";
            cin>>id;
            p = fptr.tellg();
            while(!fptr.eof())
            {
                fptr.seekp(p,ios::beg);
                fptr.read((char*)&b,sizeof(Book));
                if(id == b.Book_ID && b.flag==1)
                {
                    fptr.seekp(p,ios::beg);
                    b.getData();
                    b.flag = 1;
                    fptr.write((char*)&b,sizeof(Book));
                    break;
                }
                else
                {
                    p = fptr.tellg();
                }
            }
            fptr.close();
            cout<<endl<<"Book Updated.";
        }

        void deleteBook()
        {
            Book b;
            int id,p;
            fstream fptr("Book.bin",ios::in|ios::out|ios::binary);
            getBookDetails();
            cout<<endl<<"Enter Book ID to Delete:- ";
            cin>>id;
            p = fptr.tellg();
            while(!fptr.eof())
            {
                fptr.seekp(p,ios::beg);
                fptr.read((char*)&b,sizeof(Book));
                if(id == b.Book_ID && b.flag==1)
                {
                    fptr.seekp(p,ios::beg);
                    b.flag=0;
                    fptr.write((char*)&b,sizeof(Book));
                    break;
                }
                else
                {
                    p = fptr.tellg();
                }
            }
            fptr.close();
            cout<<endl<<"Book Deleted.";
        }

        void display()
        {
            cout<<endl<<"Book ID :- "<<Book_ID;
            cout<<endl<<"Book Name :- "<<bname;
            cout<<endl<<"Author :- "<<author;
            cout<<endl<<"Publication :- "<<publication;
            cout<<endl<<"Quantity :- "<<quantity;
            cout<<endl<<"Price  :- "<<price<<endl;
        }
};


class Student
{
    public:
        int Student_ID,age,level,flag;
        char name[50],gender[10],DOB[20];

        Student()
        {
            flag=1;
            Student_ID=0;
            age=0;
            level=0;
            strcpy(name,(char*)"");
            strcpy(gender,(char*)"");
            strcpy(DOB,(char*)"");
        }

        void getData()
        {
            cout<<endl<<"Enter Student ID :- ";
            cin>>Student_ID;
            cout<<endl<<"Enter Name of Student:- ";
            cin>>name;
            cout<<endl<<"Enter Age :- ";
            cin>>age;
            cout<<endl<<"Enter year of study at college :- ";
            cin>>level;
            cout<<endl<<"Enter gender :- ";
            cin>>gender;
            cout<<endl<<"Enter Date of Birth  :- ";
            cin>>DOB;
        }

        void addStudent(Student x)
        {
            fstream fptr("Student.bin",ios::out|ios::app|ios::binary);
            fptr.write((char*)&x,sizeof(x));
            fptr.close();
            cout<<endl<<"Student Added.";
        }

        char* getName(int id)
        {
            Student s;
            char* temp = new char[50];
            fstream fptr("Student.bin",ios::in|ios::binary);
            while (fptr.read((char*)&s,sizeof(s)))
            {
                if(id == s.Student_ID)
                {
                    strcpy(temp,s.name);
                    return temp;
                }
            }
        }

        void getStudentDetails()
        {
            Student s;
            fstream fptr("Student.bin",ios::in|ios::binary);
            while(fptr.read((char*)&s,sizeof(Student)))
            {
                if(s.flag==1)
                    s.display();
            }
            fptr.close();
        }

        void updateStudentDetails()
        {
            Student x;
            int id,p;
            fstream fptr("Student.bin",ios::in|ios::out|ios::binary);
            getStudentDetails();
            cout<<endl<<"Enter Student ID that you want to Update:- ";
            cin>>id;
            p = fptr.tellg();
            while(!fptr.eof())
            {
                fptr.seekp(p,ios::beg);
                fptr.read((char*)&x,sizeof(Student));
                if(id == x.Student_ID && x.flag==1)
                {
                    fptr.seekp(p,ios::beg);
                    x.getData();
                    x.flag=1;
                    fptr.write((char*)&x,sizeof(Student));
                    break;
                }
                else
                {
                    p = fptr.tellg();
                }
            }
            fptr.close();
            cout<<endl<<"Student Updated.";
        }

        void deleteStudent()
        {
            Student x;
            int id,p;
            fstream fptr("Student.bin",ios::in|ios::out|ios::binary);
            getStudentDetails();
            cout<<endl<<"Enter Student ID that you want to Delete:- ";
            cin>>id;
            p = fptr.tellg();
            while(!fptr.eof())
            {
                fptr.seekp(p,ios::beg);
                fptr.read((char*)&x,sizeof(Student));
                if(id == x.Student_ID && x.flag==1)
                {
                    fptr.seekp(p,ios::beg);
                    x.flag=0;
                    fptr.write((char*)&x,sizeof(Student));
                    break;
                }
                else
                {
                    p = fptr.tellg();
                }
            }
            fptr.close();
            cout<<endl<<"Student Deleted.";
        }

        void display()
        {
            cout<<endl<<"Student ID :- "<<Student_ID;
            cout<<endl<<"Name of Student:- "<<name;
            cout<<endl<<"Age :- "<<age;
            cout<<endl<<"Year of study at college :- "<<level;
            cout<<endl<<"Gender :- "<<gender;
            cout<<endl<<"Date of Birth  :- "<<DOB<<endl;
        }
};

class Employeer
{
    public:
        int Employee_ID,age,flag;
        char name[50],gender[10],designation[20];
        double salary;

        Employeer()
        {
            flag=1;
            Employee_ID=0;
            age=0;
            salary=0.0;
            strcpy(name,(char*)"");
            strcpy(gender,(char*)"");
            strcpy(designation,(char*)"");
        }

        void getData()
        {
            cout<<endl<<"Enter Employee ID :- ";
            cin>>Employee_ID;
            cout<<endl<<"Enter Name of Employee:- ";
            cin>>name;
            cout<<endl<<"Enter Age :- ";
            cin>>age;
            cout<<endl<<"Enter Designation :- ";
            cin>>designation;
            cout<<endl<<"Enter gender :- ";
            cin>>gender;
            cout<<endl<<"Enter Salary :- ";
            cin>>salary;
        }

        void addEmployee(Employeer x)
        {
            fstream fptr("Employee.bin",ios::out|ios::app|ios::binary);
            fptr.write((char*)&x,sizeof(x));
            fptr.close();
            cout<<endl<<"Employee Added.";
        }

        void getEmployeeDetails()
        {
            Employeer e;
            fstream fptr("Employee.bin",ios::in|ios::binary);
            while(fptr.read((char*)&e,sizeof(Employeer)))
            {
                if(e.flag==1)
                    e.display();
            }
            fptr.close();
        }

        char* getName(int id)
        {
            Employeer e;
            char* temp = new char[50];
            fstream fptr("Employee.bin",ios::in|ios::binary);
            while (fptr.read((char*)&e,sizeof(e)))
            {
                if(id == e.Employee_ID)
                {
                    strcpy(temp,e.name);
                    return temp;
                }
            }
        }

        void updateEmployeeDetails()
        {
            Employeer x;
            int p,id;
            fstream fptr("Employee.bin",ios::in|ios::out|ios::binary);
            getEmployeeDetails();
            cout<<endl<<"Enter Employeer ID that you want to Update :- ";
            cin>>id;
            p = fptr.tellg();
            while(!fptr.eof())
            {
                fptr.seekp(p,ios::beg);
                fptr.read((char*)&x,sizeof(Employeer));
                if(id == x.Employee_ID && x.flag==1)
                {
                    fptr.seekp(p,ios::beg);
                    x.getData();
                    x.flag=1;
                    fptr.write((char*)&x,sizeof(Employeer));
                    break;
                }
                else
                {
                    p = fptr.tellg();
                }
            }
            fptr.close();
            cout<<endl<<"Employee Updated.";
        }

        void deleteEmployee()
        {
            Employeer x;
            int p,id;
            fstream fptr("Employee.bin",ios::in|ios::out|ios::binary);
            getEmployeeDetails();
            cout<<endl<<"Enter Employeer ID that you want to Update :- ";
            cin>>id;
            p = fptr.tellg();
            while(!fptr.eof())
            {
                fptr.seekp(p,ios::beg);
                fptr.read((char*)&x,sizeof(Employeer));
                if(id == x.Employee_ID && x.flag==1)
                {
                    fptr.seekp(p,ios::beg);
                    x.flag=0;
                    fptr.write((char*)&x,sizeof(Employeer));
                    break;
                }
                else
                {
                    p = fptr.tellg();
                }
            }
            fptr.close();
            cout<<endl<<"Employee Deleted.";
        }

        void display()
        {
            cout<<endl<<"Employee ID :- "<<Employee_ID;
            cout<<endl<<"Name of Employee :- "<<name;
            cout<<endl<<"Age :- "<<age;
            cout<<endl<<"Gender :- "<<gender;
            cout<<endl<<"Designation :- "<<designation;
            cout<<endl<<"Salary  :- "<<salary<<endl;
        }
};

class Operation
{
    public:
        int sid,bid,eid,flag=0;
        char ename[10],sname[10],bname[10];

    Operation(){flag=1;}

    void issueBook()
    {
            Operation o;
            Book b;
            Employeer e;
            Student s;
            int efg=0,sfg=0,bfg=0,p;

            fstream is("Issuer.bin",ios::out|ios::app|ios::binary);
            fstream bk("Book.bin",ios::in|ios::out|ios::binary);
            fstream st("Student.bin",ios::in|ios::binary);
            fstream em("Employee.bin",ios::in|ios::binary);

            cout<<endl<<"Enter ID of Employee :- ";
            cin>>o.eid;

            while(em.read((char*)&e,sizeof(e)))
            {
                if(e.Employee_ID == o.eid && e.flag == 1)
                {
                        efg=1;
                        strcpy(o.ename,e.getName(o.eid));
                        cout<<endl<<"Enter ID of Student :- ";
                        cin>>o.sid;

                        while(st.read((char*)&s,sizeof(s)))
                        {
                            if(s.Student_ID == o.sid && s.flag == 1)
                            {
                                    sfg=1;
                                    strcpy(o.sname,s.getName(o.sid));
                                    cout<<endl<<"Enter Book ID :- ";
                                    cin>>o.bid;

                                    while(bk.read((char*)&b,sizeof(b)))
                                    {
                                        if(b.Book_ID == o.bid && b.flag == 1)
                                        {
                                            bfg=1;
                                            strcpy(o.bname,b.getName(o.bid));
                                            break;
                                        }
                                    }
                            }
                        }
                }
                if(sfg == 1 && efg == 1 && bfg==1)
                    break;
                else
                {
                    cout<<endl<<"Enter Proper IDs.";
                    return;
                }
            }
            em.close();
            st.close();

            bk.seekp(0,ios::beg);
            p = bk.tellg();
            while(!bk.eof())
            {
                bk.seekp(p,ios::beg);
                bk.read((char*)&b,sizeof(b));
                if(o.bid == b.Book_ID && b.flag==1)
                {
                    bk.seekp(p,ios::beg);
                    if(b.quantity == 0)
                    {
                        cout<<endl<<"Book is not Currently Available.";
                        return;
                    }
                    b.quantity -= 1;
                    bk.write((char*)&b,sizeof(b));
                    break;
                }
                else
                    p = bk.tellg();
            }
            bk.close();
            is.write((char*)&o,sizeof(o));
            is.close();
            cout<<endl<<"Book Issued.";
    }


    void renueBook()
    {
            Operation o;
            Book b;
            Employeer e;
            Student s;
            int efg=0,sfg=0,bfg=0,p;

            fstream rn("Renuer.bin",ios::out|ios::app|ios::binary);
            fstream bk("Book.bin",ios::in|ios::binary);
            fstream st("Student.bin",ios::in|ios::binary);
            fstream em("Employee.bin",ios::in|ios::binary);
            cout<<"\t\tIssuer Information."<<endl;
            getIssuerDetails();
            cout<<endl<<"Enter ID of Employee :- ";
            cin>>o.eid;

            while(em.read((char*)&e,sizeof(e)))
            {
                if(e.Employee_ID == o.eid && e.flag == 1)
                {
                        efg=1;
                        strcpy(o.ename,e.getName(o.eid));
                        cout<<endl<<"Enter ID of Student :- ";
                        cin>>o.sid;

                        while(st.read((char*)&s,sizeof(s)))
                        {
                            if(s.Student_ID == o.sid && s.flag == 1)
                            {
                                    sfg=1;
                                    strcpy(o.sname,s.getName(o.sid));
                                    cout<<endl<<"Enter Book ID :- ";
                                    cin>>o.bid;

                                    while(bk.read((char*)&b,sizeof(b)))
                                    {
                                        if(b.Book_ID == o.bid && b.flag == 1)
                                        {
                                            bfg=1;
                                            strcpy(o.bname,b.getName(o.bid));
                                            break;
                                        }
                                    }
                            }
                        }
                }
                if(sfg == 1 && efg == 1 && bfg==1)
                    break;
                else
                {
                    cout<<endl<<"Enter Proper IDs.";
                    return;
                }
            }
            em.close();
            st.close();
            bk.close();
            rn.write((char*)&o,sizeof(o));
            rn.close();
            cout<<endl<<"Book Renued.";
    }

    void returnBook()
    {
            Operation o,x;
            Book b;
            Employeer e;
            Student s;
            int efg=0,sfg=0,bfg=0,p;

            fstream is("Issuer.bin",ios::in|ios::out|ios::binary);
            fstream rt("Returner.bin",ios::out|ios::app|ios::binary);
            fstream bk("Book.bin",ios::in|ios::out|ios::binary);
            fstream st("Student.bin",ios::in|ios::binary);
            fstream em("Employee.bin",ios::in|ios::binary);
            cout<<"\t\tIssuer Information."<<endl;
            getIssuerDetails();
            cout<<endl<<"Enter ID of Employee :- ";
            cin>>o.eid;

            while(em.read((char*)&e,sizeof(e)))
            {
                if(e.Employee_ID == o.eid && e.flag == 1)
                {
                        efg=1;
                        strcpy(o.ename,e.getName(o.eid));
                        cout<<endl<<"Enter ID of Student :- ";
                        cin>>o.sid;

                        while(st.read((char*)&s,sizeof(s)))
                        {
                            if(s.Student_ID == o.sid && s.flag == 1)
                            {
                                    sfg=1;
                                    strcpy(o.sname,s.getName(o.sid));
                                    cout<<endl<<"Enter Book ID :- ";
                                    cin>>o.bid;

                                    while(bk.read((char*)&b,sizeof(b)))
                                    {
                                        if(b.Book_ID == o.bid)
                                        {
                                            bfg=1;
                                            strcpy(o.bname,b.getName(o.bid));
                                            break;
                                        }
                                    }
                            }
                        }
                }
                if(sfg == 1 && efg == 1 && bfg==1)
                    break;
                else
                {
                    cout<<endl<<"Enter Proper IDs.";
                    return;
                }
            }
            em.close();
            st.close();

            bk.seekp(0,ios::beg);
            p = bk.tellg();
            while(!bk.eof())
            {
                bk.seekp(p,ios::beg);
                bk.read((char*)&b,sizeof(b));
                if(o.bid == b.Book_ID && b.flag==1)
                {
                    bk.seekp(p,ios::beg);
                    b.quantity += 1;
                    bk.write((char*)&b,sizeof(b));
                    break;
                }
                else
                    p = bk.tellg();
            }
            bk.close();

            is.seekp(0,ios::beg);
            p = is.tellg();
            while(!is.eof())
            {
                is.seekp(p,ios::beg);
                is.read((char*)&x,sizeof(x));
                if(o.bid == x.bid && o.eid == x.eid && o.sid == x.sid)
                {
                    is.seekp(p,ios::beg);
                    x.flag=0;
                    is.write((char*)&x,sizeof(x));
                    break;
                }
                else
                {
                    p = is.tellg();
                }
            }
            is.close();
            rt.write((char*)&o,sizeof(o));
            rt.close();
            cout<<endl<<"Book Returned.";
        }

        void getIssuerDetails()
        {
            Operation o;
            fstream is("Issuer.bin",ios::in|ios::binary);
            while(is.read((char*)&o,sizeof(o)))
            {
                    if(o.flag == 1)
                        o.displayData();
            }
        }

        void getReturnDetails()
        {
            Operation o;
            fstream rt("Returner.bin",ios::in|ios::binary);
            while(rt.read((char*)&o,sizeof(o)))
            {
                    if(o.flag == 1)
                        o.displayData();
            }
        }

        void getRenueDetails()
        {
            Operation o;
            fstream rt("Renuer.bin",ios::in|ios::binary);
            while(rt.read((char*)&o,sizeof(o)))
            {
                    if(o.flag == 1)
                        o.displayData();
            }
        }

        void displayData()
        {
            cout<<endl<<endl<<"Book ID :- "<<bid;
            cout<<endl<<"Book Name :- "<<bname;
            cout<<endl<<"Student ID :- "<<sid;
            cout<<endl<<"Student Name :- "<<sname;
            cout<<endl<<"Employee ID :- "<<eid;
            cout<<endl<<"Employee Name :- "<<ename<<endl;
        }
};

int main()
{
    Book b;
    Student s;
    Employeer e;
    Operation o;
    int choice,c;
    while(1)
    {
        cout<<endl<<"1). Issue Section. ";
        cout<<endl<<"2). Renue Section. ";
        cout<<endl<<"3). Return Section. ";
        cout<<endl<<"4). Book Section. ";
        cout<<endl<<"5). Student Section. ";
        cout<<endl<<"6). Employee Section. ";
        cout<<endl<<"7). Exit. ";
        cout<<endl<<"Enter Your Choice :- ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                system("CLS");
                cout<<endl<<"1). Issue Book. ";
                cout<<endl<<"2). Issuer Information. ";
                cout<<endl<<"3). Exit. ";
                cout<<endl<<"Enter your choice to perform operation in Issue Section :- ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        o.issueBook();
                        break;

                    case 2:
                        o.getIssuerDetails();
                        break;

                    case 3:
                        return 0;

                    default:
                        cout<<endl<<"No such option found in Issue Section.";
                }
            break;

            case 2:
                system("CLS");
                cout<<endl<<"1). Renue Book. ";
                cout<<endl<<"2). Renuer Information. ";
                cout<<endl<<"3). Exit. ";
                cout<<endl<<"Enter your choice to perform operation in Renue Section :- ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        o.renueBook();
                        break;

                    case 2:
                        o.getRenueDetails();
                        break;

                    case 3:
                        return 0;

                    default:
                        cout<<endl<<"No such option found in Renue Section.";
                }
                break;

            case 3:
                system("CLS");
                cout<<endl<<"1). Return Book. ";
                cout<<endl<<"2). Returner Information. ";
                cout<<endl<<"3). Exit. ";
                cout<<endl<<"Enter your choice to perform operation in Return Section :- ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        o.returnBook();
                        break;

                    case 2:
                        o.getReturnDetails();
                        break;

                    case 3:
                        return 0;

                    default:
                        cout<<endl<<"No such option found in Return Section.";
                }
                break;

            case 4:
                system("CLS");
                cout<<endl<<"1). Add new Book in Library";
                cout<<endl<<"2). Get Book details.";
                cout<<endl<<"3). Update Book details.";
                cout<<endl<<"4). Delete Book.";
                cout<<endl<<"5). Exit";
                cout<<endl<<"Enter your choice to perform operation in Book Section :- ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        b.getData();
                        b.addBook(b);
                        break;

                    case 2:
                        b.getBookDetails();
                        break;

                    case 3:
                        b.updateBookDetails();
                        break;

                    case 4:
                        b.deleteBook();
                        break;

                    case 5:
                        return 0;

                    default:
                        cout<<endl<<"No such option found in Book Section.";
                }
            break;

            case 5:
                system("CLS");
                cout<<endl<<"1). Add new Student.";
                cout<<endl<<"2). Get Student details.";
                cout<<endl<<"3). Update Student details.";
                cout<<endl<<"4). Delete Student.";
                cout<<endl<<"5). Exit.";
                cout<<endl<<"Enter your choice to perform operation in Student Section :- ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        s.getData();
                        s.addStudent(s);
                        break;

                    case 2:
                        s.getStudentDetails();
                        break;

                    case 3:
                        s.updateStudentDetails();
                        break;

                    case 4:
                        s.deleteStudent();
                        break;

                    case 5:
                        return 0;

                    default:
                        cout<<endl<<"No such option found in Student Section.";
                }
            break;

            case 6:
                system("CLS");
                cout<<endl<<"1). Add new Employee.";
                cout<<endl<<"2). Get Employee details.";
                cout<<endl<<"3). Update Employee details.";
                cout<<endl<<"4). Delete Employee.";
                cout<<endl<<"5). Exit.";
                cout<<endl<<"Enter your choice to perform operation in Employee Section :- ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        e.getData();
                        e.addEmployee(e);
                        break;

                    case 2:
                        e.getEmployeeDetails();
                        break;

                    case 3:
                        e.updateEmployeeDetails();
                        break;

                    case 4:
                        e.deleteEmployee();
                        break;

                    case 5:
                        return 0;

                    default:
                        cout<<endl<<"No such option found in Employee Section.";
                }
            break;

            case 7:
                return 0;

            default:
                cout<<endl<<"Invalid Choice.";
        }
    }
}
*/
