#include<stdio.h>

int main(){
	int num,remainder,originalnum,sum=0;
	
	printf("Enter a number:");
	scanf("%d", &num);
	
	originalnum = num;
	
	if(num <= 0){
		printf("The number should not be negative");
	}else{
		while(originalnum != 0){
			remainder = originalnum % 10;
			sum += remainder;
			originalnum /= 10;
		}
		printf("The sum of digits of %d is %d",num,sum);
	}
	return 0;
}
