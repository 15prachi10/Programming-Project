#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>


COORD coord={0,0};


void gotoab(int a, int b)
{
coord.X=a;
coord.Y=b;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



int main()
{
FILE *fp, *ft;
char another, choice;


struct cit
{
char name[40];
char fname[40];
char dob[40];
char sex[40];
char address[40];
};

struct cit c;

char citname[40];

long int recsize;





fp=fopen("CIT.DAT", "rb+");

if(fp == NULL)
{
fp = fopen("CIT.DAT", "wb+");
if (fp == NULL)
{
printf("Cannot open file");
exit(1);
}
}

recsize=sizeof(c);


while(1)
{
system("cls");
gotoab(30,10);
printf("1. Add Name");
gotoab(30,12);
printf("2. List Names");
gotoab(30,14);
printf("3. Modify Records");
gotoab(30,16);
printf("4. Delete Names");
gotoab(30,18);
printf("5. Exit");
gotoab(30,20);
printf("Your Choice : ");
fflush(stdin);
choice = getche();
switch(choice)
{
case '1' :
system("cls");
fseek(fp,0,SEEK_END);


another = 'y';
while(another == 'y')
{
printf("\nEnter Name: ");
scanf("%s", &c.name);
printf("\nEnter Father's Name: ");
scanf("%s", &c.fname);
printf("\nEnter Date Of Birth: ");
scanf("%s", &c.dob);
printf("\nEnter Sex: ");
scanf("%s", &c.sex);
printf("\nEnter Address: ");
scanf("%s", &c.address);

fwrite(&c,recsize,1,fp);

printf("\nAdd Another Record(y/n)");
fflush(stdin);
another = getche();
}
break;
case '2' :
system("cls");
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
printf("\n%s %s %s %s %s",c.name,c.fname,c.dob,c.sex,c.address);
}
getch();
break;

case '3' :
system("cls");
another = 'y';
while(another == 'y')
{
printf("Enter the citizen name to modify: ");
scanf("%s", citname);
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
if(strcmp(c.name,citname) == 0)
{
printf("\nEnter new name: ");
scanf("%s", &c.name);
printf("\nEnter father's' name: ");
scanf("%s", &c.fname);
printf("\nEnter date of birth: ");
scanf("%s", &c.dob);
printf("\nEnter sex: ");
scanf("%s", &c.sex);
printf("\nEnter new address: ");
scanf("%s", &c.address);

fseek(fp,-recsize,SEEK_CUR);
fwrite(&c,recsize,1,fp);
break;
}
}
printf("\nModify another record(y/n)");
fflush(stdin);
another = getche();
}
break;
case '4' :
system("cls");
another = 'y';
while(another == 'y')
{
printf("\nEnter name of citizen to delete: ");
scanf("%s",citname);
ft = fopen("Citn.dat","w");
rewind(fp);
while(fread(&c,recsize,1,fp) == 1)
{
if(strcmp(c.name,citname) != 0)
{
fwrite(&c,recsize,1,ft);
}
}
fclose(fp);
fclose(ft);
remove("CIT.DAT");
rename("Citn.dat","CIT.DAT");
fp = fopen("CIT.dat", "rb+");
printf("Delete from record(y/n)");
fflush(stdin);
another = getche();
}
break;
case '5' :
fclose(fp);
exit(0);
}
}
return 0;

}
