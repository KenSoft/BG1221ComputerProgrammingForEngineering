/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert 6116803
Lab Assignment 2-2*/
#include <stdio.h>
#define TAX_RATE 0.15

int main() {
	float income = 920.50;
	double tax;
	
	tax = TAX_RATE*income;
	printf("Tax = %f\n", tax);
	return 0;
}