#include "NameAndTimer.h"

// structure

struct supplier
{
   char Supplier_Name[30];
   char Field_Name[15];
   char Supplier_Code[8];
   long long int Contact_Number;
   char Email_Address[30];
   char Address[40];
};

// function declaration

void Supplier_Section();
void Supplier_Info();
void Add_Supplier_Info();
void Employee_Section();
void Employee_Profile();
void Add_Employee_Profile();

// functions implementation

void Supplier_Section()
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
    gotoxy(79,4);
    printf("Supplier Section\n");
    gotoxy(76,9);
    printf("1.View Info\n");
    gotoxy(76,10);
    printf("2.Add Info\n");
    gotoxy(76,11);
    printf("3.Go Back");
    gotoxy(76,13);
    printf("Enter your choice no.: ");
    scanf("%d",&i);
    if(i==1)
    {
        system("cls");
        Shop_Name();
        timer();
        Supplier_Info();
    }
    if(i==2)
    {
        system("cls");
        Shop_Name();
        timer();
        Add_Supplier_Info();
    }
    if(i==3)
    {
        admin_choices();
    }
    if(i<1||i>3)
    {
        Supplier_Section();
    }
}

void Supplier_Info()
{
    int ch;
    char ans;
    FILE* fs;
    fs=fopen("Supplier_Info.txt","r");
    while((ch=fgetc(fs))!=EOF)
    {
        printf("%c",ch);
    }
    printf("\n\nDO YOU WANT TO GO BACK?(Y/N)");
    ans=getch();
    if(ans == 'y'||ans == 'Y')
    {
        system("cls");
        Shop_Name();
        timer();
        Supplier_Section();
    }
    fclose(fs);
    return;
}


void Add_Supplier_Info()
{
    struct supplier s1;
    int c;
    FILE* fs;
    fs=fopen("Supplier_Info.txt","a+");
    if(fs==NULL)
    {
        printf("\nError in writing Employee data");
        return;
    }
    while(1)
    {
        printf("\n\n\n\n\n\nEnter Supplier Name: ");
        scanf("%s",&s1.Supplier_Name);
        printf("\nEnter Field Name: ");
        scanf("%s",&s1.Field_Name);
        printf("\nEnter Supplier Code: ");
        scanf("%s",&s1.Supplier_Code);
        printf("\nEnter Contact Number: ");
        scanf("%lld",&s1.Contact_Number);
        printf("\nEnter Email Address: ");
        scanf("%s",&s1.Email_Address);
        printf("\nEnter Address: ");
        scanf("%s",&s1.Address);

        fprintf(fs,"\n\n   Supplier Name: %s",s1.Supplier_Name);
        fprintf(fs,"\n   Field Name: %s",s1.Field_Name);
        fprintf(fs,"\n   Supplier Code: %s",s1.Supplier_Code);
        fprintf(fs,"\n   Contact Number: %lld",s1.Contact_Number);
        fprintf(fs,"\n   Email Address: %s",s1.Email_Address);
        fprintf(fs,"\n   Address: %s",s1.Address);

        printf("\nContinue? (Y/N)");
        char ch = getch();
        if(ch == 'N'|| ch == 'n')
        {
            printf("\n\nPRESS 'b' TO GO BACK");
            char ans= getch();
            if(ans== 'b'|| ans== 'B')
            {
                system("cls");
                Shop_Name();
    			timer();
                fclose(fs);
                Supplier_Section();
                break;
            }
        }
    }


	return;
}


void Employee_Section()
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
    gotoxy(79,4);
    printf("Employee Section\n");
    gotoxy(76,9);
    printf("1.View Profile\n");
    gotoxy(76,10);
    printf("2.Add Profile\n");
    gotoxy(76,11);
    printf("3.Go Back");
    gotoxy(76,13);
    printf("Enter your choice no.: ");
    scanf("%d",&i);
    if(i==1)
    {
        system("cls");
        Shop_Name();
        timer();
        Employee_Profile();
    }
    if(i==2)
    {
        system("cls");
        Shop_Name();
        timer();
        Add_Employee_Profile();

    }
    if(i==3)
    {
        admin_choices();
    }
    if(i<1||i>3)
    {
        Employee_Section();
    }
}

void Employee_Profile()
{
    int ch;
    char ans;
    FILE* fe;
    fe=fopen("Employee_Profile.txt","r");
    while((ch=fgetc(fe))!=EOF)
    {
        printf("%c",ch);
    }
    printf("\n\nDO YOU WANT TO GO BACK?(Y/N)");
    ans=getch();
    if(ans == 'y'||ans == 'Y')
    {
        system("cls");
        Shop_Name();
        timer();
        Employee_Section();
    }
    fclose(fe);
    return;
}

struct employee
{
   char Name[30];
   int Age;
   int Salary;
   long long int Mobile_Number;
   char Email_Address[30];
   char Address[40];
};

void Add_Employee_Profile()
{
    struct employee e1;
    int c;
    FILE* fe;
    fe=fopen("Employee_Profile.txt","a+");
    if(fe==NULL)
    {
        printf("\nError in writing Employee data");
        return ;
    }
    while(1)
    {
        printf("\n\n\n\n\n\nEnter Name: ");
        scanf("%s",&e1.Name);
        printf("\nEnter Age: ");
        scanf("%d",&e1.Age);
        printf("\nEnter Salary: ");
        scanf("%d",&e1.Salary);
        printf("\nEnter Mobile Number: ");
        scanf("%lld",&e1.Mobile_Number);
        printf("\nEnter Email Address: ");
        scanf("%s",&e1.Email_Address);
        printf("\nEnter Address: ");
        scanf("%s",&e1.Address);

        fprintf(fe,"\n\n   Name: %s",e1.Name);
        fprintf(fe,"\n   Age: %d",e1.Age);
        fprintf(fe,"\n   Salary: %d",e1.Salary);
        fprintf(fe,"\n   Mobile Number: %lld",e1.Mobile_Number);
        fprintf(fe,"\n   Email Address: %s",e1.Email_Address);
        fprintf(fe,"\n   Address: %s",e1.Address);

        printf("\nContinue? (Y/N)");
        char ch = getch();
        if(ch == 'N'|| ch == 'n')
        {
            printf("\n\nPRESS 'b' TO GO BACK");
            char ans= getch();
            if(ans== 'b'|| ans== 'B')
            {
                system("cls");
				Shop_Name();
    			timer();
                fclose(fe);
				Employee_Section();
				break;
            }
        }
    }

	return;
}

