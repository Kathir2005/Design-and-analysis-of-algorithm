#include<stdio.h>

int isperfect(int num){
	int sum = 0;
	
	if (num <= 0){
		return 0;
	}else{
		for(int i = 1;i <= num; i++){
			if (num % i == 0){
				sum += i;
			}
			
		}
	}
	return (sum = num);
	
}

int main(){
	int num;
	printf("Enter the number:");
	scanf("%d", &num);
	
	if(isperfect(num)){
		printf("%d is a perfect number:",num);
	}else{
		printf("%d is not a perfect number",num);
	}
	return 0;
}
