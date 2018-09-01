/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 5-2 Due 8th October 2018
This program calculate the value of e^x based on input value n term and x*/
#include <stdio.h>
#include <math.h>
int main() {
	int n, x, i;
	double eCal=0,factorialN=1;
	printf("Enter value of x :");
	scanf("%d", &x);
	printf("Enter number of terms (n) :");
	scanf("%d", &n);
	for (n; n > 0; n--) {
		
		factorialN = 1;
		for (i = n; i > 0; i--) {
			factorialN = factorialN* (double)i;
		}
		/*printf("%d %lf %d\n", n, factorialN, eCal);*/
		eCal = eCal + (pow(x, n) / (double) factorialN);
	}
	eCal = eCal + (double)1;
	printf("\nThe approximated value of ex : %.12lf\n", eCal);
	printf("The value of ex using C library function : %.12lf\n\n", exp(x));
	printf("The absolute difference between the two value : %.13lf\n", fabs(exp(x) - eCal));

	return 0;
}