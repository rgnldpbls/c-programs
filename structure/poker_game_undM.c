#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void sort(); 
int points();

struct hand{
    int value;
    char suit[8];
    char face[80];
}card[6];

int main()
{
    int a, b, c, result; char s;
    printf("POKER\n");

    for(a=0 ; a<5 ; a++){
        Einz:
        system("cls");
        printf("%d.) Enter card\n", a+1);
        printf("Values(1-13):\n1 -> Ace\t11 -> Jack\n12 -> Queen\t13 -> King\n");
        printf("Value: ");scanf("%d", &card[a].value);
        if(card[a].value < 1 || card[a].value >13){
            printf("\nInvalid Input\nPlease enter numbers 1-13 only\n");
            printf("Press any key to continue");getch();
            goto Einz;
        }

        printf("\nSuits:\nC -> Clubs\tD -> Diamonds\nH -> Hearts\tS -> Spades\n");
        printf("Suit: ");scanf(" %c", &s);

        switch(s)
        {
            case 'C': strcpy(card[a].suit, "Clubs");
                break;
            case 'D': strcpy(card[a].suit, "Diamonds");
                break;
            case 'H': strcpy(card[a].suit, "Hearts");
                break;
            case 'S': strcpy(card[a].suit, "Spades");
                break;
            default: printf("\nInvalid Input\nEnter letters 'C', 'D', 'H', and 'S' Only\n");
                printf("Press any key to continue"); getch(); goto Einz;
                break;

        }
        //if naulit yung card(same suit and value
        if(a!=0){
            for(b=0 ; b<5 ; b++){
                if(card[a].value == card[b].value && a!=b){//if same value
                    if( strcmp(card[a].suit, card[b].suit) == 0 ){//if same suit
                        printf("\nThis card is already entered\nAre you cheating?\n");
                        printf("Press any key to try again\n"); getch(); goto Einz;
                    }}}}}


    sort(); result = points();
    for(b=0 ; b<5 ; b++){
        printf("\n%d of %s\n", card[b].value, card[b].suit);
    }
    switch(result)
    {
        case 1: printf("\nYou have a Pair\n");
        break;
        case 2: printf("\n2 pair\n");
        break;
        case 3: printf("\n3 of a kind\n");
        break;
        case 4: printf("\nstraight\n");
        break;
        case 5: printf("\nflush\n");
        break;
        case 6: printf("\nfull house\n");
        break;
        case 7: printf("\n4 of a kind\n");
        break;
        case 8: printf("\nStraight Flush\n");
        break;
    }
    return 0;
}

void sort(){
	int i,j;
    for(i=0 ; i<5 ; i++){
        for(j=0 ; j<5 ; j++)
        {
            if(card[i].value<card[j].value)
            {
                card[6]=card[i];
                card[i]=card[j];
                card[j]=card[6];
            }
        }
    }
}

int points(){
    int i, j, k, l, pairs=0, tok=0, fok=0, consec=0, str8=0, sameS=0, flush=0;

    //pair count
    for(i=0; i<5; i++){
        for(j=i+1; j<5; j++){
            if(card[i].value == card[j].value){//num of pairs
                pairs++;
                if(pairs == 1){
                    for (k=j+1 ; k<5-j ; k++){//three of a kind
                        if(card[j].value==card[k].value){
                            tok = 1; pairs--;
                            if (tok == 1){
                                for(l=k+1 ; l<5 ; l++){//four of a kind
                                    if(card[j].value==card[k].value){
                                        fok=1;tok=0;pairs=0;
                                    }}}}}}}}}

    //straight
    for(i=0 ; i<5 ; i++){
        for(j=i+1 ; j<5 ; j++){
            if(card[i].value+1 == card[j].value){
                consec++;//pag magkakasunod
            }}}
    if(consec==4) {str8=1;}

    //flush
    for(i=1 ; i<5 ; i++){
        if(0 == strcmp(card[0].suit, card[i].suit)){//flush is lahat magkapareho so kung di agad pareho sa zero, edi hindi flush.
            sameS++;//pag magkaparehas
        }}
    if(sameS==4) {flush=1;}

    //eto na yung sa evaluation
    if(pairs==1){
        if(tok==1){
            return 6;
        }
        return 1;
    }
    else if(pairs==2){ return 2; }
    else if(tok==1){ return 3; }
    else if(str8==1){
        if(flush==1){
            return 8;
        }
        return 4;
    }
    else if(flush==1){ return 5;}
    else if(fok==1){ return 7; }

}
