/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 9-2 Due 5th November 2018
This program convert Celcius to Fahrenheit and vise versa*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double Celcius();
double Fahrenheit();
void main() {
	FILE *file;
	file = fopen("temperature.txt", "w");
	int C = 0, F = 32;
	double Ctemp, Ftemp;
	printf("Fahrenheit equivalents of Celsius temperatures:\n");
	printf("%-15s %-15s\n", "Celcius", "Fahrenheit");
	fprintf(file, "Fahrenheit equivalents of Celsius temperatures:\n");
	fprintf(file, "%-15s %-15s\n", "Celcius", "Fahrenheit");
	for (C; C <= 100; C = C + 10) {
		Ftemp = Celcius(C);
		
		printf("%-15d %-15.2lf\n", C, Ftemp);
		fprintf(file, "%-15d %-15.2lf\n", C, Ftemp);
	}

	printf("\n");

	printf("Celcius equivalents of Fahrenheit temperatures:\n");
	printf("%-15s %-15s\n", "Fahrenheit", "Celcius");
	fprintf(file,"\n");

	fprintf(file, "Celcius equivalents of Fahrenheit temperatures:\n");
	fprintf(file, "%-15s %-15s\n", "Fahrenheit", "Celcius");
	for (F; F <= 212; F = F + 20) {
		Ctemp = Fahrenheit(F);
		printf("%-15d %-15.2lf\n", F, Ctemp);
		fprintf(file,"%-15d %-15.2lf\n", F, Ctemp);
	}
	fclose(file);
}

double Celcius(int C) {
	double F;
	F = (C*(9.0 / 5.0)) + 32;
	return F;

}

double Fahrenheit(int F) {
	double C;
	C = (F - 32)*(5.0 / 9.0);
	return C;
}