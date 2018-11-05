/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 9-2 Due 12th November 2018
This program that read an integer number between 1 and 32767 and prints it as
a series of digits, each pair of which is separated by two spaces.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int quotient(int divider,int divisor);
int remainders(int divider, int divisor);
void main() {
	int input = 0, counter = 0, quotientResult, remainderResult, originalInput;
	printf("Enter –1 to end the program.\n");
	while (input != -1) {
		
		printf("Enter integer number between 1 to 32767 :");
		scanf(" %d", &input);
		if (input != -1) {
			originalInput = input;
			if (input < 1 || input>32767) {
				printf("Error ! Invalid Number.\n\n");
			}
			else {
				printf("The digits in the number are : ");
				for (counter = 0; counter < 4; counter++) {
					quotientResult = quotient(input, pow(10,4-counter));
					if (originalInput > pow(10, 4-counter)) {
						printf("%d ", quotientResult);
					}
					input = input - (quotientResult * pow(10,4-counter));
				}
				remainderResult = remainders(input, 10);
				printf("%d\n\n", remainderResult);
			}


		}
	}
}

int quotient(int divider, int divisor) {
	int result;
	result = divider / divisor;
	return result;
}

int remainders(int divider, int divisor) {
	int result;
	result = divider % divisor;
	return result;
}