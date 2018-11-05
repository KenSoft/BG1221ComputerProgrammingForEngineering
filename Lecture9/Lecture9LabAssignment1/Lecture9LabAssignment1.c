/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 9-1 Due 5th November 2018
This program take 2 integers and raised the power*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int integerPower();
void main() {
	int base, exponent, run;
	long result;
	do {
		printf("Enter Integer Base : ");
		scanf(" %d", &base);
		printf("Enter Integer Exponent : ");
		scanf(" %d", &exponent);
		result = integerPower(base, exponent);
		printf("%d raised to the power of %d = %d\n\n", base, exponent, result);
		printf("If you like to run this program again, Enter 1.\n");
		printf("If you like to end this program, Enter 0.\n");
		printf("What would you like to do? : ");
		scanf(" %d", &run);
		printf("\n");
	} while (run == 1);

	printf("Goodbye, Have a nice day!\n");

}

int integerPower(int base, int exponent) {
	long result = 1, count;
	for (count = 0; count < exponent; count++) {
		result = result * base;

	}

	return result;
}