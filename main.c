#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "billAndStock.h"
#include "SupplierAndEmployee.h"
#include "NameAndTimer.h"

// function declaration

void Login_Section();
int Display_choice();
void admin_section();
void admin_login();
void admin_choices();

int main()
{
    Login_Section();  // To display the login page
                      // function declared in Admin.h header file
    return 0;
}



void Login_Section()
{
    Shop_Name();
    timer();
    int choice;
    REPEAT:
    choice = Display_choice();
    if(choice == 1)
    	admin_section();				// Here will be the function
		    							// call for administrator section
    else if(choice != 2)				// The user will be asked to
    	goto REPEAT;	                // enter the choice again if
	else								// the choice is invalid
		system("cls")	;
}



int Display_choice()
{
    Shop_Name();
    timer();
    // code for printing the rectangle

	gotoxy(59,5);
    printf("*******************************************************\n");

    int i;
    for(i =6; i <=18; i++)
    {
        gotoxy(59, i);
        printf("*                                                     *\n");
    }

        gotoxy(59,19);
    printf("*******************************************************\n\n");

    gotoxy(75,10);
    printf("1. Administrator Section\n");

	gotoxy(75,11);
    printf("2. Exit.\n");

	gotoxy(59,22);
    printf("*******************************************************\n");

    int c;
    gotoxy(75,13);
    printf("Please Enter your choice no.: ");
    scanf("%d", &c);
	return c;
}

void admin_section()
{

    int n=0,i;
    gotoxy(59,5);
    printf("*******************************************************\n");
    for(i=6;i<=18;i++)
    {
        gotoxy(59, i);
        printf("*                                                     *\n");
    }
    gotoxy(59, 19);
    printf("*******************************************************\n\n");
    gotoxy(76,4);
    printf("Administration Section\n");
    gotoxy(76,9);
    printf("1.Login\n");
    gotoxy(76,10);
    printf("2.Back to Main Menu\n");
    gotoxy(76,12);
    printf("Enter your choice no.: ");
    scanf("%d",&n);
    printf("\n\n\n\n\n\n\n\n");
    if(n==1)
    {
      admin_login();
    }
    if(n==2)
    {
       system("cls");
       Login_Section();
    }
    if(n<1||n>2)
    {
        admin_section();
    }

}

   void admin_login()            //login function for admin
{

    char str_u[8],str_adm[]="Health",adm_p[]="happy",str_p[8];
    int t,s,i;
    gotoxy(59,26);
    printf("*******************************************************\n");
    for(i=27;i<=30;i++)
    {
        gotoxy(59, i);
        printf("*                                                     *\n");
    }
    gotoxy(59,31);
    printf("*******************************************************\n\n");
    gotoxy(76,28);
    printf("1. Enter Username : ");
    scanf("%s",str_u);
    t=strcmp(str_u,str_adm);
    int k=0;
    char p;
    if(t==0)
    {
        gotoxy(76,29);
        printf("2. Enter Password : ");
         while(p!=13)
    {
        p=getch();
        if(p!=13 && p!=8)
        {
            putch('*');
            str_p[k] = p;
            k++;
        }
    }
    str_p[k] = '\0';

        s=strcmp(str_p,adm_p);
        if(s==0)
        {
            system("cls");
            Shop_Name();
            timer();
            admin_choices();
        }
        else

        {   gotoxy(76,31);
            printf("Invalid Password,Try again :-(");
            sleep(2);
            system("cls");
            Shop_Name();
            timer();
            admin_section();

        }
    }
    else
    {   gotoxy(76,31);
    printf("Invalid username,try again :-(");
    sleep(2);
        system("cls");
        Shop_Name();
        timer();
        admin_section();
    }
}



void admin_choices()
{

    int n=0,i;
    gotoxy(59,5);
    printf("*******************************************************\n");
    for(i=6;i<=18;i++)
    {
        gotoxy(59, i);
        printf("*                                                     *\n");
    }
    gotoxy(59, 19);
    printf("*******************************************************\n\n");
    gotoxy(76,4);
    printf("Administration Section\n");
    gotoxy(76,9);
    printf("1.Bill Section\n");
    gotoxy(76,10);
    printf("2.Supplier Details\n");
    gotoxy(76,11);
    printf("3.Employee Details\n");
    gotoxy(76,12);
    printf("4.Stock Details\n");
    gotoxy(76,13);
    printf("5.Back to main menu\n");
    gotoxy(76,14);
    printf("6.Exit\n");
    gotoxy(76,16);
    printf("Enter your choice no.: ");
    scanf("%d",&n);
    if(n==1){
    	system("cls");
    	bill();
    	system("cls");
        Shop_Name();
        timer();
        admin_choices();
	}
	if(n==2)
    {
        system("cls");
        Shop_Name();
        timer();
        Supplier_Section();
    }
    if(n==3)
    {
        system("cls");
        Shop_Name();
        timer();
        Employee_Section();
    }
    if(n==4)
    {
        Stock_Section();
    }
    if(n<1||n>6)
    {
        admin_choices();
    }
    if(n==5)
    {
        system("cls");
        Shop_Name();
        timer();
        Login_Section();
    }
    return;
}

