// Simple program about converting Roman Numeral to Integer

#include<stdio.h>
#include<string.h>
#include<math.h>

static int val(char a){
	switch(a){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int conv(char *s){
	int i, num = val(s[0]);
	
	for(i=1;s[i]!='\0';i++){
		int prev_num = val(s[i-1]);
		int cur_num = val(s[i]);
		if(prev_num < cur_num){
			num = (num - prev_num) + (cur_num - prev_num); 
		}else{
			num+=cur_num;
		}
	}
	return num;
}
int main(){
	char str[20];
	printf("Input: ");
	scanf("%s",&str);
	printf("%s to integer is %d",str,conv(str));
	
	return 0;
}
