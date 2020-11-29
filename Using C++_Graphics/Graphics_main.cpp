#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include"main.h"

#define UP 72
#define DOWN 80
int count=0;
using namespace std;

void displayArrow(int x,int y,char* str)
{
    setbkcolor(WHITE);
    setcolor(1);
    settextstyle(10,0,4);
    outtextxy(x+50,y,str);
    settextstyle(10,0,3);
    outtextxy(x,y,"->");
}

void removeArrow(int x,int y,char* str)
{
    setbkcolor(WHITE);
    setcolor(BLACK);
    settextstyle(10,0,4);
    outtextxy(x+50,y,str);
    setcolor(WHITE);
    settextstyle(10,0,3);
    outtextxy(x,y,"->");
}

void mainMenu()
{
    count=0;
    char *arr[7] = {"Issue Section","Renue Section","Return Section",
                             "Book Section", "Student Section","Employee Section","Exit"};
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<7;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=540 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                count++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[k]);
                count--;
            }
        }
    }
}

void bookMenu()
{
    Book b;
    char *arr[5] = {"Add New Book","Get Book Details","Update Book Details",
                             "Delete Book","Exit"};
    int ct=0;
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<5;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=400 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                ct++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[k]);
                ct--;
            }
        }
    }

    switch(ct+1)
    {
        case 1:
            system("CLS");
            closegraph();
            b.getData();
            b.addBook(b);
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            bookMenu();
            break;

        case 2:
            system("CLS");
            closegraph();
            b.getBookDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            bookMenu();
            break;

        case 3:
            system("CLS");
            closegraph();
            b.updateBookDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            bookMenu();
            break;

        case 4:
            system("CLS");
            closegraph();
            b.deleteBook();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            bookMenu();
            break;

        case 5:
            cleardevice();
            mainMenu();
            break;

    }
}

void studentMenu()
{
    Student s;
    char *arr[5] = {"Add New Student","Get Student Details","Update Student Details",
                             "Delete Student","Exit"};
    int ct=0;
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<5;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=400 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                ct++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[i]);
                ct--;
            }
        }
    }
    switch(ct+1)
    {
        case 1:
            closegraph();
            system("CLS");
            s.getData();
            s.addStudent(s);
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            studentMenu();
            break;

        case 2:
            closegraph();
            system("CLS");
            s.getStudentDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            studentMenu();
            break;

        case 3:
            system("CLS");
            closegraph();
            s.updateStudentDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            studentMenu();
            break;

        case 4:
            system("CLS");
            closegraph();
            s.deleteStudent();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            studentMenu();
            break;

        case 5:
            cleardevice();
            mainMenu();
            break;

    }
}

void employeeMenu()
{
    Employeer e;
    char *arr[5] = {"Add New Employee","Get Employee Details","Update Employee Details",
                             "Delete Employee","Exit"};
    int ct=0;
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<5;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=400 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                ct++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[k]);
                ct--;
            }
        }
    }
    switch(ct+1)
    {
        case 1:
            system("CLS");
            closegraph();
            e.getData();
            e.addEmployee(e);
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            employeeMenu();
            break;

        case 2:
            system("CLS");
            closegraph();
            e.getEmployeeDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            employeeMenu();
            break;

        case 3:
            system("CLS");
            closegraph();
            e.updateEmployeeDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            employeeMenu();
            break;

        case 4:
            system("CLS");
            closegraph();
            e.deleteEmployee();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            employeeMenu();
            break;

        case 5:
            cleardevice();
            mainMenu();
            break;

    }
}

void issueMenu()
{
    Operation o;
    char *arr[3] = {"Issue Book","Get Issuer Details","Exit"};
    int ct=0;
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<3;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=280 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                ct++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[k]);
                ct--;
            }
        }
    }
    switch(ct+1)
    {
        case 1:
            system("CLS");
            closegraph();
            o.issueBook();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            issueMenu();
            break;

        case 2:
            system("CLS");
            closegraph();
            o.getIssuerDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            issueMenu();
            break;

        case 3:
            cleardevice();
            mainMenu();
            break;

    }
}


void renueMenu()
{
    Operation o;
    char *arr[3] = {"Renue Book","Get Renuer Details","Exit"};
    int ct=0;
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<3;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=280 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                ct++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[k]);
                ct--;
            }
        }
    }
    switch(ct+1)
    {
        case 1:
            system("CLS");
            closegraph();
            o.renueBook();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            renueMenu();
            break;

        case 2:
            system("CLS");
            closegraph();
            o.getRenueDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            renueMenu();
            break;

        case 3:
            cleardevice();
            mainMenu();
            break;

    }
}


void returnMenu()
{
    Operation o;
    char *arr[3] = {"Return Book","Get Returner Details","Exit"};
    int ct=0;
    int i=0,x=500,y=160,a,k=0;
    setlinestyle(3,3,3);
    settextstyle(10,0,4);

    for(int i=0,j=0;i<3;i++,j+=60)
    {
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x+50,y+j,arr[i]);
    }
    displayArrow(x,y,arr[k]);
    i=60;
    while(a != 13)
    {
        a = getch();
        if(y<=280 && y>=160)
        {
            if(a == DOWN)
            {
                removeArrow(x,y,arr[k]);
                y+=i;
                k++;
                displayArrow(x,y,arr[k]);
                ct++;
            }

            if(a == UP)
            {
                removeArrow(x,y,arr[k]);
                y-=i;
                k--;
                displayArrow(x,y,arr[k]);
                ct--;
            }
        }
    }
    switch(ct+1)
    {
        case 1:
            system("CLS");
            closegraph();
            o.returnBook();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            returnMenu();
            break;

        case 2:
            system("CLS");
            closegraph();
            o.getReturnDetails();
            initwindow(1360,720,"Library Management System");
            floodfill(10,10,WHITE);
            returnMenu();
            break;

        case 3:
            cleardevice();
            mainMenu();
            break;

    }
}

void choice()
{
    switch(count+1)
    {
        case 1:
            cleardevice();
            issueMenu();
            break;

        case 2:
            cleardevice();
            renueMenu();
            break;

        case 3:
            cleardevice();
            returnMenu();
            break;

        case 4:
            cleardevice();
            bookMenu();
            break;

        case 5:
            cleardevice();
            studentMenu();
            break;

        case 6:
            cleardevice();
            employeeMenu();
            break;

        case 7:
            closegraph();
    }
    getch();
}

void splashScreen()
{
    settextstyle(10,0,7);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(530,100,"Library");
    outtextxy(480,180,"Management");
    outtextxy(550,260,"System");
	setcolor(10);

	setfillstyle(XHATCH_FILL,BLUE);
	bar(450,550,900,570);

	for(int i = 0 ; i <= 450 ; i++)
	{
		setfillstyle(SOLID_FILL,RED);
		bar(450,550,450+i,570);
		delay(5);
	}
}

int main()
{
    initwindow(1360,720,"Library Management System");
    floodfill(10,10,WHITE);
    splashScreen();
    cleardevice();
    mainMenu();
    while(1)
    {
        cleardevice();
        choice();
    }
    getch();
    closegraph();
}
