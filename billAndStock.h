#include "NameAndTimer.h"


// These are all the functions of the stock section

void Stock_Section();
int searchid(int t);
void Update_med();
void Stock_Info();
void Add_med();
int searchname(char *s);
void Required_med();

// Global declaration of the file pointer
FILE *fp;

// Billing section functions
void bill();
int compare_strings(char a[], char b[]);

// Medicine structure for storing all the information
struct medicine
{
    int id;
    char name[20];
    int quantity;
    int price;
    int boxno;
    char exp[10];
};
struct medicine a;


// Bill section starts here
void bill(){
	int choice, quantity, price, total = 0;
	char medicine[25], str[25];
	int length;

	system("clear");

	printf("\n***************************************\n");
	printf("\n\tBilling Section\n");
	printf("\n***************************************\n");

	printf("\nEnter your choice:\n");
	printf("1.Add Medicine\n2.Exit\n");
	scanf("%d", &choice);
	if(choice == 1){

		FILE *fp;
	fp = fopen("MED.DAT", "rb+");

	if(fp == NULL)
	{
	  	puts ( "Cannot open file");
	  	exit (1);
	}

REPEAT:         printf("\nEnter the name of the medicine.\n");
                printf("---------------------------------------------------\n");

                scanf("%s", medicine);
                length = strlen(medicine);

            while(fread(&a, sizeof(a), 1, fp) == 1 ){
                if(compare_strings(a.name, medicine)){

                    printf("\n%d Rs. per unit\n",a.price);
                    printf("\nEnter the quantity of the medicine to be purchased.\n");
                    scanf("%d", &quantity);
                    if(a.quantity - quantity >=0){
                    	a.quantity = a.quantity - quantity;
                        }
                      else{
						printf("\n!!The required quantity is not available!!");
						printf("\nAvailable stock quantity is %d unit only.",a.quantity);
						goto CHOICE;
					}

                    price = a.price;

					fseek(fp,ftell(fp)-sizeof(a),0);  // updating the stock
                	fwrite(&a,sizeof(a),1,fp);

					printf("_______________");
                    printf("\nAmount = %d Rs\n", price*quantity);
                    printf("---------------------------------------------------\n");

                    total += price*quantity;

					fseek(fp,ftell(fp)-sizeof(a),0);
                	fwrite(&a,sizeof(a),1,fp);
CHOICE:             printf("\n\t\t\t\t\tPress   1 To add another medicine\n\t\t\t\t\t\t2 Total.\n");
                    scanf("\n%d", &choice);

                    if(choice == 1){
                        fseek(fp, 0, SEEK_SET);       // This is will set the postion of
                        goto REPEAT;                  // file pointer to beginnng
                    }else{
                        goto FINISH;
                    }
			}

		}
		fseek(fp, 0, SEEK_SET);
		printf("Medicine not found.\n");
		goto REPEAT;
FINISH:	fclose(fp);
		fp = NULL;
		printf("\n____________________________________\n");
		printf("Total = %d Rs", total);
		printf("\n____________________________________\n");
		printf("\n\nPress any key to exit.\n");
		getch();
	}

}

// string comparison function
int compare_strings(char a[], char b[]){
    int c = 0;
    while(a[c] == b[c]){
        if(a[c] == '\0' || b[c] == '\0'){
            break;
        }
        c++;
    }

    if(a[c] == '\0' && b[c] == '\0')
        return 1;
    else
        return 0;
}


// stock section starts here
void Stock_Section()
{
	system("cls");
	Shop_Name();
	timer();

	char choice;

  int i;
   gotoxy(59,5);
    printf("*********************STOCK SECTION*********************");
    gotoxy(59,7);
    printf("*******************************************************\n");
    for(i=8;i<=18;i++)
    {
        gotoxy(59, i);
        printf("*                                                     *\n");
    }
    gotoxy(59, 19);
    printf("*******************************************************\n\n");
gotoxy ( 61, 9);
printf ("1. Add Item");
gotoxy ( 61, 10);
printf ("2. List Items");
gotoxy ( 61, 11);
printf ("3. Modify Item");
gotoxy ( 61, 12);
printf ("4. Item Require");
gotoxy ( 61, 13);
printf ("0. Exit" );
gotoxy ( 61,15);
printf ("Your choice:");

scanf("%c",&choice);




switch ( choice )
{
  case '1':

    Add_med();
	break;

  case '2':

	Stock_Info();
	break;

  case '3':

    Update_med();
	break;

  case '4':

    Required_med();
	break;

  case '0':
     admin_choices();
	  break;
	 default:
        {
            gotoxy(61,16);
            printf("!! Invalid input...Wait while redirecting you again");
            Sleep(1);
            Stock_Section();


        }
  	}
   }



void Add_med()
{

char ans;
char another;

fp = fopen("MED.DAT", "ab+");

if(fp == NULL)
{
	fp = fopen ("MED.DAT", "wb+");

	if ( fp == NULL)
	{
	  puts ( "Cannot open file");
	  exit (1);
	}
}

	another = 'Y';
	     while(another=='y'|| another=='Y')
    {
    		system("cls");
    		 Shop_Name();
           timer();

	 gotoxy(59,6);printf("\xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2    \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2");
    gotoxy(73,6);printf(" Enter the Information Below ");
    gotoxy(114,6);printf("\xB2");
    gotoxy(59,7);
    printf("\xB2");gotoxy(114,7);printf("\xB2");
    gotoxy(59,8);
    printf("\xB2");gotoxy(114,8);printf("\xB2");
    gotoxy(59,9);
    printf("\xB2");gotoxy(114,9);printf("\xB2");
    gotoxy(59,10);
    printf("\xB2");gotoxy(114,10);printf("\xB2");
    gotoxy(59,11);
    printf("\xB2");gotoxy(114,11);printf("\xB2");
    gotoxy(59,12);
    printf("\xB2");gotoxy(114,12);printf("\xB2");
    gotoxy(59,13);
    printf("\xB2");gotoxy(114,13);printf("\xB2");
    gotoxy(59,14);
     printf("\xB2");gotoxy(114,14);printf("\xB2");
    gotoxy(59,15);
    printf("\xB2");gotoxy(114,15);printf("\xB2");
    gotoxy(59,16);
    printf("\xB2");gotoxy(114,16);printf("\xB2");
    gotoxy(59,17);
    printf("\xB2");gotoxy(114,17);printf("\xB2");
    gotoxy(59,18);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2B2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2B2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

  int d;
		 gotoxy(61,9);
    printf("Medicine ID to be added:");
    scanf("%d",&d);
    if(searchid(d) == 0)
    {
        gotoxy(61,21);
        printf("\aThe medicine id already exists\a");
         printf("\n\nDO YOU WANT TO GO BACK?(Y/N)");
        ans=getch();
       if(ans == 'y'||ans == 'Y')
    {
    	fclose(fp);

        Stock_Section();
    }

        Add_med();
    }

    a.id=d;
     char medname[20];
     gotoxy(61,10);
    printf("Medicine name to be added:");
    scanf("%s",medname);
    if(searchname(medname) == 0)
    {
        gotoxy(61,21);
        printf("\aThe medicine name already exists\a");
         printf("\n\nDO YOU WANT TO GO BACK?(Y/N)");
        ans=getch();
       if(ans == 'y'||ans == 'Y')
    {
    	fclose(fp);

        Stock_Section();
    }

        Add_med();
    }

    strcpy(a.name,medname);


    gotoxy(61,11);
    printf("Quantity:");
    scanf("%d",&a.quantity);
    gotoxy(61,12);
    printf("Price per unit:");
    scanf("%d",&a.price);
    gotoxy(61,13);
    printf("Box No:");
    scanf("%d",&a.boxno);
    gotoxy(61,14);
    printf("Exp. date:");
    scanf("%s",a.exp);
      fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(61,20);
        printf("The record is successfully saved");
        gotoxy(61,21);
        	printf ( "Add another Record (Y/N)");
	fflush(stdin);
	another = getche();
}
    	fclose(fp);

        Stock_Section();

	}



int searchid(int t)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;
    return 1;
}


int searchname(char *s)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(strcmp(s,a.name)==0)
            return 0;
    return 1;
}


void Stock_Info()
{
	system("cls");
	Shop_Name();
	timer();


    char ans;
    FILE* fp;
    fp=fopen("MED.DAT","rb");

	printf("\n\n\n\n\n\n\n\n        ************************* STOCK INFORMATION *************************\n");

	  while( fread(&a, sizeof(a), 1, fp) == 1 )
    {
         printf("		Medicine ID: %d\n", a.id);
        printf("		Name: %s \n", a.name);
          printf("		Quantity: %d\n", a.quantity);
           printf("		Price per unit: %d\n", a.price);
        printf("		Box No.: %d\n", a.boxno);
         printf("		Exp. date: %s\n\n", a.exp);
    }
     printf("\n\nPRESS 'Y' TO GO BACK");
    ans=getch();
    if(ans == 'y'||ans == 'Y')
    {
       fclose(fp);
        Stock_Section();
    }



}

void Update_med()
{

	char another='y';
    while(another=='y'|| another=='Y')
    {
    		system("cls");
          Shop_Name();
          timer();

	 int c=0;
    int d=0;

	 gotoxy(59,6);printf("\xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2    \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2 \xB2");
    gotoxy(73,6);printf(" Enter the Information Below ");
    gotoxy(114,6);printf("\xB2");
    gotoxy(59,7);
    printf("\xB2");gotoxy(114,7);printf("\xB2");
    gotoxy(59,8);
    printf("\xB2");gotoxy(114,8);printf("\xB2");
    gotoxy(59,9);
    printf("\xB2");gotoxy(114,9);printf("\xB2");
    gotoxy(59,10);
    printf("\xB2");gotoxy(114,10);printf("\xB2");
    gotoxy(59,11);
    printf("\xB2");gotoxy(114,11);printf("\xB2");
    gotoxy(59,12);
    printf("\xB2");gotoxy(114,12);printf("\xB2");
    gotoxy(59,13);
    printf("\xB2");gotoxy(114,13);printf("\xB2");
    gotoxy(59,14);
     printf("\xB2");gotoxy(114,14);printf("\xB2");
    gotoxy(59,15);
    printf("\xB2");gotoxy(114,15);printf("\xB2");
    gotoxy(59,16);
    printf("\xB2");gotoxy(114,16);printf("\xB2");
    gotoxy(59,17);
    printf("\xB2");gotoxy(114,17);printf("\xB2");
    gotoxy(59,18);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2B2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2B2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(61,7);
        printf("Enter Medicine Id to be updated:");
        scanf("%d",&d);
        fp=fopen("MED.DAT","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(searchid(d)==0)
            {

                gotoxy(61,8);
                printf("Name of medicine:%s",a.name);
                gotoxy(61,9);
                printf("Enter updated name:");
                	scanf("%s",a.name);
                 gotoxy(61,10);
                printf("Enter current quantity:");
                	scanf("%d",&a.quantity);
				gotoxy(61,11);
				 printf("Enter new price:");
				scanf("%d",&a.price);
                gotoxy(61,12);
                printf("Enter new box no.:");
				scanf("%d",&a.boxno);
                gotoxy(61,13);
                printf("Enter new exp. date:");
				scanf("%s",a.exp);
                gotoxy(61,16);
                printf("Details are updated");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(76,12);
                printf("No record found");
            }
        }
        gotoxy(61,20);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    fclose(fp);
    Stock_Section();
}
void Required_med()
{
    system("cls");
	Shop_Name();
	timer();


    char ans;
    FILE* fp;
    fp=fopen("MED.DAT","rb");

	printf("\n\n\n\n\n\n\n\n        ************************* STOCK REQUIRED *************************\n");

	  while( fread(&a, sizeof(a), 1, fp) == 1 )
    {
        if(a.quantity<=50)
        {
              printf("		Medicine ID: %d\n", a.id);
            printf("		Name: %s \n", a.name);
          printf("		Quantity: %d\n", a.quantity);
        }

    }
     printf("\n\nPRESS 'Y' TO GO BACK");
    ans=getch();
    if(ans == 'y'||ans == 'Y')
    {
       fclose(fp);
        Stock_Section();
    }

}

