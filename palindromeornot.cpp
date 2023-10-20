#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool ispalindrome(const char *str){
	int left = 0;
	int right = strlen(str) - 1;
	
	while (left < right){
		if (str[left] != str[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}

int main(){
	char input[100];
	printf("Enter a string:");
	scanf("%s", input);
	
	if(ispalindrome(input)){
		printf("The string is a palindrome.\n");
	}else{
		printf("It is not a palindrome.\n");
	}
	return 0;
}
