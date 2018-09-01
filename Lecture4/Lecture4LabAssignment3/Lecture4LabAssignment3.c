/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 4-3 Due 10th September 2018
This program find the average of 5 numbers using while loop */
#include <stdio.h>
#include <math.h>
int main() {
	double k, i, j;
	char r;
	do {
		j = 1;
		k = 0;
		while (j <= 5) {
			printf("Enter the number : ");
			scanf("%lf", &i);
			k = k + i;
			j++;
		}
		k = k / 5;
		printf("The average of a list of numbers = %lf\n", k);
		printf("Do you want to find the average of another list of numbers (Y/N) :");
		r = getchar();
		
	} while (getchar() != 'N');
}