#include<stdio.h>

#define START 700
#define FINISH 1100

int prime(int n);
void goldbach(int g);

int main()
{
    int x;
    for(x=START;x<=FINISH;x++){
        if(x%2==0){
            goldbach(x);
        }
    }
    return 0;
}
int prime(int n)
{
    int k;
    for(k=2;k<n/2;k++){
        if(n%k==0){
            return 0;
        }
    }return 1;
}
void goldbach(int g)
{
    int k, i=2;
    for(k=g-i;k>2; k--){
        if(prime(i)== 1 && prime(k)==1){
            printf("%d = %d + %d\n",g,i,k);
            break;
        }i++;
    }
}
