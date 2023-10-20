#include<stdio.h>
int main(){
	char str[100];
	int length = 0;
	printf("Enter a string:");
	scanf("%s", str);
	
	while (str[length] != '\0'){
		length++;
	}
	printf("The length of a string is %d",length);
	return 0;
}
