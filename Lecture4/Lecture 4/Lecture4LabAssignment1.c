/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 4-1 Due 10th September 2018
This program determine whether the input number is an odd or even number */
#include <stdio.h>
#include <math.h>
int main() {
	int input;
	printf("Input a number: ");
	scanf("%d", &input);
	if (input % 2 == 1) {
		printf("The number %d is an odd number\n", input);

	}
	else {
		printf("The number %d is an even number\n", input);
	}

	return 0;
}