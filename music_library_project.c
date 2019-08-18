/* TITLE:- TO BUILD A PROJECT ON A MUSIC LIBRARY USING DATA FILE HANDLING IN C
   GROUP MEMEBERS:-  ADITYA PRAKASH
                     NARENDRA
                     KUNAL
    FILE NAME:- music_library_project.c
    SECTION :- CS-3
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int i,j,k,m,r,l;
struct music{
	char name[70];
	char len[10];
	char singer[50];
	char lyr_wri[50];
	char film_song[50];
	char lang[30];
	char type[30];
	int n,n1;
	
	
	
};
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void banner();
void search_box();
void footer_out();
void help();
void ex();
void opening();
void opening_con();
void calling();
void add();
void view_all();
void del();
void see();
void lyrics();
void gotoXY(int x, int y); 
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition); // Sets position for next thing to be printed 
}
void calling(){
	footer_out();banner();search_box();
}
/*------------------------------------banner  creation-------------------------------------*/

void banner(){
	system("COLOR F9");
	gotoXY(0,0);
	for(i=0;i<168;i++)
	{
		printf("-");
	}
	gotoXY(70,2.5);
	printf("WYNK  MUSIC  LIBRARY");
	gotoXY(0,4.5);
	for(i=0;i<168;i++)
	{
		printf("-");
	}
}

/*------------------------------------------------search box-------------------------------------------*/
// gotoXY(67,7):- it is permanent position for search bar for entering command!!

void search_box(){
	int a;
	char ch[30];
	printf("\n");
	gotoXY(65,6);
	for(i=0;i<30;i++){
		printf("=");
	}
	printf("\n\n");
	gotoXY(65,8.5);
	for(i=0;i<30;i++)
	{
		printf("=");
	}
	printf("\n");gotoXY(65,7);printf("=");
	gotoXY(94,7);printf("=");
	gotoXY(58,7);
	printf("SEARCH");
	
	printf("\n\n");
   printf("DISPLAY  AREA\n");
	for(i=0;i<168;i++)
	{
		printf("-");
	
	}
	gotoXY(67,7);
	gets(ch);	
	
	/*---------------------------------------------commands checking---------------------------------------*/
	
	if(strcmp(ch,"help")==0 || strcmp(ch,"HELP")==0 || strcmp(ch,"h")==0 || strcmp(ch,"H")==0){
		help();
	}
	else if(strcmp(ch,"exit")==0 || strcmp(ch,"EXIT")==0){
		ex();
	}
	else if(strcmp(ch,"")==0 || strcmp(ch," ")==0){
       calling();
	}
	else if(strcmp(ch,"add")==0 || strcmp(ch,"ADD")==0){
		add();
	}
	else if(strcmp(ch,"view")==0 || strcmp(ch,"VIEW")==0){
		view_all();
	}
	else if(strcmp(ch,"del")==0 || strcmp(ch,"delete")==0 || strcmp(ch,"DELETE")==0){
		del();
	}
	else if(strcmp(ch,"particular")==0 || strcmp(ch,"PARTICULAR")==0){
		see();
	}
	else if(strcmp(ch,"lyrics")==0 || strcmp(ch,"LYRICS")==0){
		lyrics();
	}
	else{
	gotoXY(0,15);
	printf("WRONG COMMAND");
	getch();
	system("cls");
	calling();
}
}
/*-----------------------------------------footer output screen-------------------------------------------------*/
void footer_out(){
		gotoXY(0,43);
	printf("** THIS MUSIC LIBRARY INCLUDES COMMAND LINE INTERFACE(CLI)");
	gotoXY(125,43);printf(" TYPE HELP TO SEE THE FOLLOWING COMMANDS **");
	gotoXY(67,7);
}

/*---------------------------------------------help command-------------------------------------------------------*/
void help(){
	int x=60;
	   printf("\n\n\n\n");
	   gotoXY(x,15);printf(" COMMAND\t\tINFORMATION\n");
	   gotoXY(x,16);printf("-------------------------------------------------\n");
	   gotoXY(x,17);printf("[ ADD ]       =   FOR ADDING A MUSIC TO LIBRARY\n");
	   gotoXY(x,18);printf("-------------------------------------------------\n");	
       gotoXY(x,19);printf("[ DELETE ]    =   FOR DELETE A PARTICULAR SONG\n");
       gotoXY(x,20);printf("-------------------------------------------------\n");
       gotoXY(x,21);printf("[ SEARCH_P ]  =   SEARCHING FOR A PARTICULAR SONG\n");
       gotoXY(x,22);printf("-------------------------------------------------\n");
       gotoXY(x,23);printf("[ VIEW ]      =   VIEW ALL SONG\n");
       gotoXY(x,24);printf("-------------------------------------------------\n");
       gotoXY(x,25);printf("[ LYRICS ]    =   TO FIND THE LYRICS OF ANY SONG\n");
       gotoXY(x,26);printf("-------------------------------------------------\n");
       gotoXY(x,27);printf("[ EXIT ]      =   EXIT FROM CONSOLE WINDOWS\n");
       gotoXY(x,28);printf("-------------------------------------------------\n\n");
       gotoXY(60,27);printf("\n\nenter any key to search again!!");
       getch();
       system("cls ");
       calling();
   }
   
/*--------------------------------------------------exit command---------------------------------------------------*/

void ex(){
	printf("\n\n");
	exit(0);
}

/*---------------------------------------------------opening screen--------------------------------------------------*/

void opening(){
	for(l=0;l<2;l++){
	opening_con();
	system("cls");
	
}
 system("cls");

}
void opening_con(){
	system("COLOR 1F");
	gotoXY(0,38);printf("GROUP MEMBERS\n 1. Aditya Prakash\n 2. Narendra\n 3. Kunal\n\n Guided By :- Umesh sahu Sir and Smriti Mam");
	gotoXY(75,15);
	printf("WELCOMES  TO  WYNK  MUSIC");
	gotoXY(80,17);
printf("PLEASE  WAIT");
	gotoXY(84,20);
for(i=0;i<4;i++){
	sleep(1);
		printf(".");
	}
	for(k=1;k<=2;k++){
		sleep(1);
		gotoXY(87,20+k);
		printf(".");
	}
	for(m=1;m<4;m++)
	{   sleep(1);
	    gotoXY(87-m,22);
		printf(".");
	}
	for(r=1;r<2;r++){
		sleep(1);
		gotoXY(84,22-r);
		printf(".");
}

}

/*------------------------------------------------------------------add music--------------------------------------------------------*/

void add(){
	struct music ad,check;
	int ag,cho;
	FILE*ptr;
	ptr=fopen("add.dat","a");
	//system("cls");
	gotoXY(0,15);
	printf("Enter the number of song                                                        :-  ");
	scanf("%d",&ad.n);
	/*if((n>='a' && n<='z') || (n>='A' && n<='Z') )
	{
		printf("\n\nYou entered a alaphaet!! Please enter the number!");
		getch();
		system("cls");
		calling();
	}*/
/*	while(fgets(data,1000,ptr)!=EOF)
	 {
        if (check.n==ad.n)
            {printf("This number is already in use!! Please use another number");
                //goto no;

            }
    }
    ad.n=check.n;*/
    gotoXY(0,16);printf("Enter the Name of the song                                                      :-  ");
    scanf("%s",&ad.name);
    gotoXY(0,17);printf("\nEnter the length of the song( format: x:y)                                      :-  ");
    scanf("%s",&ad.len);
    gotoXY(0,18);printf("\nEnter the name of the film that song belong to                                  :-  ");
    scanf("%s",&ad.film_song);
    gotoXY(0,19);printf("\nEnter the name of the lyrics writer                                             :-  ");
    scanf("%s",&ad.lyr_wri);
    gotoXY(0,20);printf("\nEnter the name of the singer                                                    :-  ");
    scanf("%s",&ad.singer);
    gotoXY(0,21);printf("\nEnter the languages of this song (English,Hindi,Others)                         :-  ");
    scanf("%s",&ad.lang);
    gotoXY(0,22);printf("\nEnter the type of this song (Hollywood,Bollywood,Tollywood,Kollywood,Others)    :-  ");
    scanf("%s",&ad.type);
    
	fprintf(ptr," %d               %s             %s             %s             %s             %s            %s            %s\n",ad.n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type);
	fclose(ptr);
	gotoXY(0,24);printf("\nAdd music successfully!!\n");
	getch();
       system("cls ");
       calling();
/*	gotoXY(0,26);printf("ARE YOU WANT TO ADD MORE MUSIC (1(yes)/2(no)):-");
	scanf("%d",&cho);
	if(cho==1){
		system("cls");
		calling();
	    add();
	}
	else if(cho==2)
	{   exit(0);
	
	}
	else{
		exit(0);
	}*/
}
/*----------------------------------------------------------view all songs-------------------------------------------------------------*/


void view_all()
{   struct music ad;
    FILE *view;
    char add[10],c;
    view=fopen("add.dat","r");
    int test=0;
    //system("cls");
    system("COLOR F9");
    gotoXY(0,10);
    gotoXY(73,11);printf("ALL  SONGS");
    gotoXY(0,12);
    for(i=0;i<168;i++){
    	printf("-");
	}
	gotoXY(0,14);
	c=fgetc(view);
	gotoXY(0,13);printf("S.no.             Name             Lenght             Film Name             Lyrics Writer             Singer             Languages             Types\n\n");
    gotoXY(0,14);
    for(i=0;i<168;i++){
    	printf("-");
	}
	while(c!=EOF)
       {
       	  
    //printf("S.no:-%c\nName:- %s\nlenght of song:- %s\nFilm name:- %s\nlyrics writer:- %s\nSinger:- %s\nLanguages:- %s\nType:- %s\n\n",n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type);
           printf("%c",c);
           c=fgetc(view);
		   test++;
       }

    fclose(view);
    if (test==0)
        {  system("cls");
            gotoXY(0,0);printf("\nNO RECORDS FOUND!!\n");
            getch();
            system("cls");
            calling();
			}

    //view_list_invalid:
     printf("\n\nPRESS ANY KEY TO SEARCH AGAIN!!");
     getch();
     system("cls");
     calling();
        
}
/*---------------------------------------------------------------------------DELETE A PARTICULAR SONG-----------------------------------------------------*/

void del(){
	struct music rem,ad;
	FILE *old,*newrec;
    int temp=1,n1;
    char remo[10],re;
    old=fopen("add.dat","r");
//    newrec=fopen("new.dat","w");
   // re=fgetc(old);

   gotoXY(1,13);
   while(re!=EOF)
       {
       	  
    //printf("S.no:-%c\nName:- %s\nlenght of song:- %s\nFilm name:- %s\nlyrics writer:- %s\nSinger:- %s\nLanguages:- %s\nType:- %s\n\n",n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type);
        
		   printf("%c",re);
           re=fgetc(old);
       }
       
       rewind(old);
       printf(" \nEnter the Serial number of the song want to delete:- ");
    scanf("%d",&ad.n);
    newrec=fopen("new.dat","w");
    re=getc(old);
    while(re!=EOF){
    	re=getc(old);
    	if(re=='\n')
    	temp++;
    	if(temp!=ad.n){
    		putc(re,newrec);
		}
		/*printf("Enter the serial number you want to delete a song:-");
		scanf("%d",&n1);
		while (fread(&ad,sizeof(struct music),1,old) != NULL) {
		if (ad.n==n1) {
			printf("A record with requested name found and deleted.\n\n");
			temp=1;
		} else {
			fwrite(&ad,sizeof(struct music), 1, newrec);
		}
	}*/
	/*if (!temp) {
		printf("No record(s) found with the requested serial number: %d\n\n", ad.n);
	}*/
	}
   fclose(old);
   fclose(newrec);
   remove("add.dat");
   rename("new.dat","add.dat");
   printf("\n\n Songs deleted successfully!!");
   getch();
   system("cls");
   calling();
	
}

/*---------------------------------------------------------------------------searching a particular  song----------------------------------------------------------------*/
void see(void)
{   struct music rem,ad;
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("add.dat","r");
    system("cls");
    printf(" Do you want to search by\n1. serial no.\n2. Name of song\n Enter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf(" Enter the serial number of song:");
        scanf("%d",&ad.n1);

        while (fscanf(ptr,"%d %s %s %s %s %s %s %s",&ad.n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type)!=EOF)
        {      
            if(ad.n1==ad.n)
            {   system("cls");
                test=1;
                printf("S.no.             Name             Lenght             Film Name             Lyrics Writer             Singer             Languages             Types\n\n");
               printf(" %d               %s             %s             %s             %s             %s            %s            %s\n\n",ad.n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type);
			   // printf("\n Account NO.: %d\n Name: %s \n DOB: %d/%d/%d \n Age: %d \n Address: %s \n Citizenship No: %s \n Phone number: %.0lf \n Type Of Account: %s \n Account Balance:$ %.2f \n Date Of Last Deposit: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                //add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    getch();
                    system("cls");
                    calling();
					     }
			else
			  { system("cls");
			  printf("Serial number not found!!");
			  getch();
			  calling();
		}
        }
    }
    else if (choice==2)
    {   printf(" Enter the name of the song:- ");
        scanf("%s",&rem.name);
        while (fscanf(ptr,"%d %s %s %s %s %s %s %s",&ad.n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type)!=EOF)
        {
            if(strcmpi(ad.name,rem.name)==0)
            {   system("cls");
                test=1;
                //printf("\n Account No.: %d\n Name: %s \n DOB: %d/%d/%d \n Age: %d \n Address: %s \n Citizenship No: %s \n Phone number: %.0lf \n Type Of Account: %s \n Account Balance: $%.2f \n Date Of Last Deposit: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                //add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                 printf("S.no.             Name             Lenght             Film Name             Lyrics Writer             Singer             Languages             Types\n\n");
               printf(" %d               %s             %s             %s             %s             %s            %s            %s\n\n",ad.n,ad.name,ad.len,ad.film_song,ad.lyr_wri,ad.singer,ad.lang,ad.type);
            }
        }
    }


    fclose(ptr);
}

void lyrics(){
	system("cls");
	/*FILE*ly;
	ly=fopen("lyr.dat","a");
	gotoXY(0,11);printf("Enter the name of the song:-");
	gotoXY(60,13);printf("Write down the lyrics of the song here");
	int x=5,y=15;
	gotoXY(x,y);
	for(i=1;i<70;i++){
		printf("#");
		gotoXY(x++,15);
	}
	gotoXY(72,16);
	for(i=1;i<28;i++)
	{
		printf("#");
		gotoXY(72,y++);
	}
    gotoXY(5,16);
    for(i=1;i<28;i++){
    	printf("#");
    	gotoXY(5,y++);
	}*/
	printf("lyrics is under construction!!");
	getch();
	calling();
	
}
/*----------------------------------------------------opening page---------------------------------------------------*/
int main(){
	opening();
    footer_out();
	banner();
	search_box();
	getch();
	return 0;
}

