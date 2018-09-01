/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 5-2 Due 17th September 2018
This program the e value from given n */
#include <stdio.h>
#include <math.h>
#define E 2.718281828460
int main() {
	int input, i;
	double approxE = 1.0,p = 1.0;
	printf("Enter number of terms (n) :");
	scanf("%d", &input);
	for (i = 1; i <= input; i++) {
		double j = (double) i;
		p = j*p;
		approxE = approxE + (1.0 / p);
	}
	printf("The approximated value of e : %.12lf\n", approxE);
	printf("The given mathematical constant e = %.12lf\n", E);
	printf("The absolute difference between the two value : %.12lf\n", fabs(E-approxE));
}