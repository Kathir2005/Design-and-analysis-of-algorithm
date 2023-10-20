#include<stdio.h>

unsigned long long factorial(int n){
	if(n == 0 || n ==1){
		return 1;
	}else{
		return n * factorial(n-1);
	}
}

int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	unsigned long long result = factorial(n); 
	
	if(n < 0){
		printf("The number should be positive");
		
	}else{
		printf("The factorial of a given number %d is %llu",n,result);
	}
	return 0;
}
