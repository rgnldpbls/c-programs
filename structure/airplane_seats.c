#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct airplaneSeats {
    char letters[4];
}seats[5];

int checkMark(int seatN, char seatL);
int checkAvailability();
void printSeats();

int main() {
    int x;
	char choice, tempSeatL;
    int tempSeatN;
    char name[80];
    system("color f0");

    for(x=0; x<5; x++) { //assigning letters to every row
        seats[x].letters[0]='A';
        seats[x].letters[1]='B';
        seats[x].letters[2]='C';
        seats[x].letters[3]='D';
    }
    printf("\n\t\t\t\t\t    *****************************************");
   	printf("\n\t\t\t\t\t    *           P H I L I P P I N E\t    *\n \t\t\t\t\t    *             A I R L I N E S\t    *\n");
   	printf("\t\t\t\t\t    *****************************************");
    printf("\n\n");
    printf("\t\t\t\t\tInstruction: ");
    printf("\n\t\t\t\t\t1.The format in input is first the number");
    printf("\n\t\t\t\t\t   followed by the letter.(ex.1A/3D)");
    printf("\n\n\t\t\t\t\t2.Wrong input means Invalid format and you");
    printf("\n\t\t\t\t\t   will retry to input again");
    printf("\n\n\n");
	printf("\t\t\t\t\tPlease enter your username: ");
	scanf("%[^\n]s",&name);
	system("cls");
	
    do{
		printf("\n\t\t\t\t\t    *****************************************");
   		printf("\n\t\t\t\t\t    *           P H I L I P P I N E\t    *\n \t\t\t\t\t    *             A I R L I N E S\t    *\n");
   		printf("\t\t\t\t\t    *****************************************");
   		printf("\n\n\t\t\t\t\t\t       ~ W E L C O M E ~");
        printSeats();
        printf("\n\t\t\t\t\t__________________________________________________");
        printf("\n\t\t\t\t\tChoose a seat,Mr./Ms.%s (Ex.1A/2B/3C): ",name);


        if(scanf("%d%c",&tempSeatN, &tempSeatL)==2 && (tempSeatN>=1 && tempSeatN<=5)
           && (tempSeatL=='A' || tempSeatL=='B' || tempSeatL=='C' || tempSeatL=='D')){
               if(checkMark(tempSeatN, tempSeatL)<4) {
                   printf("\n\t\t\t\t\t\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*");
                    printf("\n\t\t\t\t\t\t*   Success! Seat %d%c is booked.   *",tempSeatN,tempSeatL);
                    printf("\n\t\t\t\t\t\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*");
					seats[tempSeatN-1].letters[checkMark(tempSeatN, tempSeatL)] = 'X';
                    printSeats();	
						if(checkAvailability()==0) {
         			   		printf("\n\n\n\t\t\t\t\tNo Available Seats.\n");
            				exit(0);
        				}
					printf("\n\t\t\t\t\t _______________________________________________");
                    printf("\n\t\t\t\t\t\tDo you want to book again?(Y-N): ");
                    scanf(" %c",&choice);
                    system("cls");
               }
               else {
                    printf("\n\t\t\t\t\t\tSeat Unavailable. Please try again.\n\t\t\t\t\t\t");
                    sleep(2);
                    choice='y';
                    system("cls");
               }
           }
        else {
            scanf("%*[^\n]");
			printf("\n\n\t\t\t\t\t\t\tInvalid Format.\n\t\t\t\t\t\t");
			sleep(2);
            choice='y';
            system("cls");
        }

    }while(choice=='Y' || choice=='y');
}

void printSeats() {
	int x;
   	printf("\n\n");
   	printf("\t\t\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   	printf("\n\t\t\t\t\t     |      A V A I L A B L E   S E A T S    |");
	printf("\n\t\t\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for(x=0; x<5; x++) {
        printf("\n\t\t\t\t\t     |   %d   |   %c   |   %c   |   %c   |   %c   |\n",x+1, seats[x].letters[0], seats[x].letters[1], seats[x].letters[2], seats[x].letters[3]);
        printf("\t\t\t\t\t     -----------------------------------------");
    }
}

int checkMark(int seatN, char seatL) {
    int x;
	for(x=seatN-1; x<seatN; x++) {
        switch(seatL){
        case 'A':
            if(seats[x].letters[0]=='A')
                return 0;
            break;
        case 'B':
            if(seats[x].letters[1]=='B')
                return 1;
            break;
        case 'C':
            if(seats[x].letters[2]=='C')
                return 2;
            break;
        case 'D':
            if(seats[x].letters[3]=='D')
                return 3;
            break;
        }
    }
    return 4;
}

int checkAvailability() {
    int x, y;
	for(x=0; x<5; x++){
        for(y=0; y<4; y++) {
            if(seats[x].letters[y]!='X')
                return 1; //seat available
        }
    }
    return 0; //no available seats
}
