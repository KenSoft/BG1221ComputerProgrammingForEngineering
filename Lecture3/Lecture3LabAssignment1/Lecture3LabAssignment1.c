/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803
Lab Assignment 3-1*/
#include <stdio.h>
#include <math.h>
int main() {
	int a, b;
	double sum, product, difference, quotient, remain;
	scanf("%d %d", &a, &b);
	sum = a + b;
	product = a*b;
	difference = a - b;
	quotient = a / b;
	remain = a%b;
	printf("Sum is %g Product is %g Difference is %g Quotient is %g, and Remainder is %g\n", sum, product, difference, quotient, remain);


	return 0;
}