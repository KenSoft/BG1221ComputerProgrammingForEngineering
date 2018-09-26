/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 5-2 Due 8th October 2018
This program calculate the value of e^x based on input value n term and x*/
#include <stdio.h>
#include <math.h>
int main() {
	int j, n, i;
	double eCal=0,factorialN=1;
	float x;
	printf("Enter value of x :");
	scanf("%f", &x);
	printf("Enter number of terms (n) :");
	scanf("%d", &n);
	for (j=n-1; j > 0; j--) {
		/*printf("%d", j); */
		factorialN = 1;
		for (i = j; i > 0; i--) {
			factorialN = factorialN* (double)i;
		}
		/*printf("%d %lf %d\n", n, factorialN, eCal);*/
		eCal = eCal + (pow(x, j) / (double) factorialN);
	}
	eCal = eCal + (double)1;
	printf("\nThe approximated value of ex : %.12lf\n", eCal);
	printf("The value of ex using C library function : %.12lf\n\n", exp(x));
	printf("The absolute difference between the two value : %.12lf\n", fabs(exp(x) - eCal));

	return 0;
}