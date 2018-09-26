/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 4-2 Due 17th September 2018
This program find the maximum and minimum value for given number list */
#include <stdio.h>
#include <math.h>
int main() {
	int max, min, i = 0, input = 0;
	while (i < 10) {
		if (i == 0) {
			printf("Enter the first number :");
			scanf("%d", &input);
			max = min = input;
		}
		else {
			printf("Enter the next number :");
			scanf("%d", &input);
		}

		if (input >= max) {
			max = input;
		}

		if (input <= min) {
			min = input;
		}


		i++;


	}
	printf("The largest number is %d\n", max);
	printf("The smallest number is %d\n", min);


	return 0;
}