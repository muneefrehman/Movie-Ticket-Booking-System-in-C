#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

//Function Declarations
int changeprice(int);
void reservation(int *,int,int );
int choice1(void);
void cancel(int *);
void ticket1(int choice,char name[10],int id2,int price);
void ticket2(int choice,char name[10],int id2,int price);
void ticket3(int choice,char name[10],int id2,int price);
int cmovie(void);
int movie(void);

//Structure declaration to store customer's information
struct moviedetails {
    char name[25];
    int phone;
    int seat;
    int id;
};

struct moviedetails person[300]; //Creating a structure array
//variable and constant declaration
int count=0;
int id2=1000;

int main()
{
	int **seat,choice,price=1000,selection,i;
	seat=(int **)calloc(101,sizeof(int *)); // Allocating memory and initializing all spaces to zero
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int )); //Allocating memory in array form and initializing all spaces to zero
	int x;
	while(x!=5) //Starting while loop
	{
		choice=choice1();
		//Switch-Case used to take input from user and run the desired function
		switch(choice)
		{
            case 1:
                price = changeprice(price);
                break;
			case 2:
				selection=movie();
				reservation(seat[selection-1],price,selection);
				count++;
				break;
			case 3:
				selection=cmovie();
				cancel(seat[selection-1]);
				break;
			case 4:
				x=5;
				break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}
//Function defined to change price of tickets
int changeprice(int price)
{
    //Validation check for password
	char pass[10],pak[10]="pass",ch;
	printf("Enter the password to change price of ticket: ");
	for (int i=0; i<100; i++) {
        ch = getch();
        if (ch == 13)
            break;  //for loop used to mask password as it is entered
        pass[i] = ch;
        ch = '*';
        printf("%c", ch);
	}
	if (strcmp(pass,pak)==0)//Comparing entered password to password already stored
	{
		printf("\nPlease enter new price: ");
		scanf("%d",&price);
		system("PAUSE");
		system("CLS");
	}
	else
		printf("\nThe entered password is wrong! \n");
	return price;
}

//Function defined to book a ticket for user
void reservation(int *array,int price,int selection)
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)//Checking to see if seat is already booked or not
				printf("%d\t",i);
			else
				printf("*\t",i);//If seat is already booked, print a * in its place
			if(i%10==0)
				printf("\n\n");//Add a newline after 10 places
		}
		//Taking user's information and storing it in structure person
		printf("Please enter your name: ");
		scanf("%s",&person[count].name);
		printf("Please enter your phone number: ");
		scanf("%d",&person[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>100||j<1)//Validation for seat number entered by user
			{
				printf("Seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)//Validation for seat number entered by user
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;//Booking the seat number entered by user
		person[count].seat=j;//Adding the seat number to structure person
		//Running the ticket function based on movie selected by user
		if (selection==1)
			ticket1(j,person[count].name,id2,price);
		else if (selection==2)
			ticket2(j,person[count].name,id2,price);
		else
			ticket3(j,person[count].name,id2,price);
		id2++;
}

//Function defined for Main Menu
int choice1(void)
{
	int choice;
	printf("                 WELCOME TO M&M THEATER\n");
	printf(" ==================================================================\n");
	printf("||             1- To change ticket price (Admin only):            ||\n");
	printf("||             2- To purchase ticket:                             ||\n");
	printf("||             3- To cancel the seat:                             ||\n");
	printf("||             4- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);//Taking input form user about choice
	return choice;
}

//Function defined to cancel movie ticket
void cancel(int *array)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);//Taking input for user's ticket ID
	  //For loop to iterate through structure person to find matching ticket ID
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat %d is canceled\n",person[i].name,person[i].seat);
					 array[person[i].seat]=0;//Canceling booking corresponding to the entered ticket ID
					 i=300;
	  		}
	  }
	  if (stop!=5)//Validation for entered ticket ID
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}

//Function defined for first movie
void ticket1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: No Way Home\n",id2);//Printing booking ID and movie name
        printf("\t Customer  : %s\n",name);                                            //Printing customer's name
        printf("\t\t\t                              Date      : 04-03-2022\n");        //Printing date of show
        printf("\t                                              Time      : 08:00pm\n");//Printing time of show
        printf("\t                                              Hall      : 02\n");     //Printing hall no
        printf("\t                                              Seat No.  : %d  \n",choice);//Printing seat numeber
        printf("\t                                              Price     : %d  \n\n",price);//Printing price of ticket
		person[count].id=id2;
        printf("\t============================================================\n");
        return;
}

//Function defined to output movie options to customer
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\tWhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tPress 1 for Spider-Man: No Way Home\n\n");
	printf("\t\t\tPress 2 for The Matrix: Resurrections\n\n");
	printf("\t\t\tPress 3 for The King's Man\n");
	scanf("%d",&i);
	system("cls");
	return i;//Returning selected option by customer
}

//Function defined for second movie
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : The Matrix: Resurrections\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 07-03-2022\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              Seat No.  : %d  \n",choice);
        printf("\t                                              Price     : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}

//Function defined to output movie options for cancellation of ticket
int cmovie(void)
{
	int i;
	printf("\t\t\tWhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tPress 1 for Spider-Man: No Way Home\n\n");
	printf("\t\t\tPress 2 for The Matrix: Resurrections\n\n");
	printf("\t\t\tPress 3 for The King's Man\n");
	scanf("%d",&i);
	return i;//Returning selected option for cancellation of ticket
}

//Function defined for third movie
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : The King's Man \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 10-03-2022\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              Seat No.  : %d  \n",choice);
        printf("\t                                              Price     : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
