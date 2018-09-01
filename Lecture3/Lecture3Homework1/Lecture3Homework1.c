/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework Assignment 3-1 Due 10th September 2018
This program read 4 different floating number from keyboard then find summation, product, and average of them */
#include <stdio.h>
#include <math.h>
int main() {
	double a, b, c, d, sum, product, avg;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("a is %lf b is %lf c is %lf d is %lf\n", a, b, c, d);
	sum = a + b + c + d;
	product = a*b*c*d;
	avg = (sum / 2);

	printf("sum is %.3lf product is %.3lf average is %.3lf\n", sum, product, avg);

	return 0;
}