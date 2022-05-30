#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

FILE *ptr;
void intro()
{
	cout<<"\n\n			PROJECT: TELEPHONE DIRECTORY\n";

	cout<<"\n\n			GROUP NAME: HURRICANES\n";
	cout<<"\n\n			GROUP MEMBERS\n";
	
	cout<<"\n\n			MUHAMMAD DAUD KHAN\n";
	cout<<"\n\n			SHAMEER JAWAID\n";
	cout<<"\n\n			WAQAS JAVED\n";
	cout<<"\n\n			SANAULLAH\n";


	
}


/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														structure

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

struct contact
{
	char name[100];
	char number[50];
	char email[100];
	char address[100];
}c;

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
													display function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


void display()
{
    cout<<"				1.create contact\n";
    cout<<"				2.modify contact\n";
    cout<<"				3.delete contact\n";
    cout<<"				4.search contact\n";
    cout<<"				5.show all contact\n";
    cout<<"				6.exit\n\n";
}
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
													functions

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void create();
void modify();
void delet();
void search();
void show_all();

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
											Main

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int main()
{
	intro();
	char o;
	cout<<"\npress any button to enter main screen\n";
	cin>>o;
	l:
	menu:
	system("cls");
    display();
	char ch;
    cout<<"\n				chose from 1 t0 6\n";
    cin>>ch;
    

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////
													while loop and switch statement

/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

while(1)

{
	
    switch(ch){
    case '1':
    {
    	loop1:
    	system("cls");
    	create();
    	cout<<"\n1.enter contact\n2.main menu\n";
    	char c;
    	cin>>c;
    	if(c=='1')
    	goto loop1;
    	else
    	goto menu;
    	break;
		}
		
    case '2':
    {
    	loop2:
    		system("cls");
    	modify();
    	cout<<"\n1.modify contact\n2.main menu\n";
    	char c;
    	cin>>c;
    	if(c=='1')
    	goto loop2;
    	else
    	goto menu;
    	break;
		}
		
    case '3':
    {
    	loop3:
    		system("cls");
    	delet();
    	cout<<"\n1.delete contact\n2.main menu\n";
    	char c;
    	cin>>c;
    	if(c=='1')
    	goto loop3;
    	else
    	goto menu;
		break;
		}
		
    case '4':
    {
    	loop4:
    		system("cls");
    	search();
    	cout<<"\n1.search contact\n2.main menu\n";
    	char c;
    	cin>>c;
    	if(c=='1')
    	goto loop4;
    	else
    	goto menu;
		break;
		}
		
    case '5':
    {
    	loop5:
    		system("cls");
    	show_all();
    	cout<<"\n1.once again show all\n2.main menu\n";
    	char c;
    	cin>>c;
    	if(c=='1')
    	goto loop5;
    	else
    	goto menu;
		break;
		}
		
    case '6':
    {
    	loop:
		system("cls");
    	exit(0);
    	
		}}
char m;
cout<<"You entered wrong number\nenter n or N to exit\nenter y or Y to main menu\n";
cin>>m;
if(m=='n' || m=='N')
break;
else
goto l;



}}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															create function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void create()
{
	
	ptr = fopen("contact.txt","ab");
    cout<<"\nenter contact information\nname: ";
    fflush(stdin);
	cin.getline(c.name,100);
	fflush(stdin);
    cout<<"\nphone number: ";
    fflush(stdin);
	cin.getline(c.number,50);
    cout<<"\nemail: ";
    fflush(stdin);
    cin.getline(c.email,100);
    cout<<"\naddress: ";
    fflush(stdin);
    cin.getline(c.address,100);
    fwrite(&c,sizeof(c),1,ptr);
    fclose(ptr);
}


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															modify function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void modify()
{
	char mname[100];
	bool found=false;
	fflush(stdin);
	cout<<"Enter Name for editing   ";
	cin.getline(mname,100);
	
	ptr=fopen("contact.txt","rb+");
	while(fread(&c,sizeof(c),1,ptr)==true)
	{
		if(strcmp(mname,c.name)==0)
		{
		cout<<"\n\n\t\t\t Contact information is available!  \n";
		
   	fflush(stdin);
	cout<<"Enter name:  ";
	cin.getline(c.name,100);
	fflush(stdin);
	cout<<"Enter phone number 03";
	cin>>c.number;
	fflush(stdin);
	cout<<"Enter email  ";
	cin.getline(c.email,100);
   fflush(stdin);
   cout<<"Enter Address:  ";
   cin.getline(c.address,100);
   cout<<"Record is updated!";
   fseek(ptr,ftell(ptr)-sizeof(c),0);
   fwrite(&c,sizeof(c),1,ptr);
   fclose(ptr);
   
   found = true;
	}
	}
	if(false)
	{
		cout<<"\t\t\t\n\n Information is not available   ";
	}
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															delete function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void delet()
{
	char name[50];
	system("cls");
	fflush(stdin);
	cout<<"\n\tEnter the Name of contact to delete:";
	cin.get(name,50);
	ptr=fopen("contact.txt","rb+");
	while(fread(&c,sizeof(c),1,ptr)==1)
	{
		if(strcmp(name,c.name)==0)
		{
				c.address[0] = '\0';
				c.email[0] = '\0';
				c.name[0] = '\0';
				c.number[0] = '\0';
				memset(c.name,0,strlen(c.name));
				memset(c.address,0,strlen(c.address));
				memset(c.email,0,strlen(c.email));
				memset(c.number,0,strlen(c.number));
				printf("The record is deleted");
				fseek(ptr,ftell(ptr)-sizeof(c),0);
				fwrite(&c,sizeof(c),1,ptr);
				fclose(ptr);
			}
			
}
}


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															search function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void search()
{
	char sname[100];
	bool found=false;
	fflush(stdin);
	cout<<"Enter contact name for searching     ";
	cin.getline(sname,100);
	ptr=fopen("contact.txt","rb");
	
	while(fread(&c,sizeof(c),1,ptr)==1)
	{
		if(strcmp(sname,c.name)==0)
		{
			found = true;
		cout<<"INFORMATION IS AVAILABE \n \n \n";
		cout<<"NAME            "<<c.name<<endl;
		cout<<"PHONE NUMBER    "<<c.number<<endl;
		cout<<"EMAIL           "<<c.email<<endl;
		cout<<"ADDRESS         "<<c.address<<endl;
		 fclose(ptr);
		 
       } 
}
fclose(ptr);

if(found==false)
{
	cout<<" Sorry information is not available!  "<<"\n \n \n";
  
}

}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															show all function

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void show_all()
{
	
    ptr=fopen("contact.txt","rb");
    printf("*****Display All Records*****\n");
    while(fread(&c,sizeof(c),1,ptr) == 1)
	{
    if(c.name[0] != '\0')
	{
    printf("\nName: %s\nPhone number: %s\nEmail: %s\nAdress: %s\n",c.name,c.number,c.email,c.address);		
    printf("\n=======================================================\n\n");
	}	   
    }
    fclose(ptr);	
    getch();
}
