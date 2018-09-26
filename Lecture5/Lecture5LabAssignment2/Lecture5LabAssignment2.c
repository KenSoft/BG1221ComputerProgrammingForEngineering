/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 5-2 Due 17th September 2018
This program the e value from given n */
#include <stdio.h>
#include <math.h>
#define E 2.718281828459
int main() {
	int input, i;
	double j,approxE = 1.0,p = 1.0;
	printf("Enter number of terms (n) :");
	scanf("%d", &input);
	for (i = 1; i < input; i++) {
		j = (double) i;
		p = j*p;
		approxE = approxE + (1.0 / p);
	}
	printf("\nThe approximated value of e : %.12lf\n", approxE);
	printf("The given mathematical constant e = %.12lf\n", E);
	printf("\nThe absolute difference between the two value : %.12lf\n", fabs(E-approxE));
	return 0;
}