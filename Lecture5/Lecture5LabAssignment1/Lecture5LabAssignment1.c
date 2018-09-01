/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 5-1 Due 17th September 2018
This program calculate the miles/gallon (fuel efficiency) for given distance and gallon values */
#include <stdio.h>
#include <math.h>
int main() {
	double mile = 0, gallon = 0, rate, tankRate, totalMiles = 0, totalGallon = 0;
	do {
		printf("Enter the gallons used (-1 to end) :");
		scanf("%lf", &gallon);
		if (gallon == -1) {
			goto endPg;
		}
		printf("Enter the miles driven :");
		scanf("%lf", &mile);
		totalMiles = totalMiles + mile;
		totalGallon = totalGallon + gallon;
		tankRate = mile / gallon;
		printf("The miles/gallon for this tank was : %lf\n", tankRate);
		
	} while (gallon != -1);

endPg:
	rate = totalMiles / totalGallon;
	printf("The overall average miles/gallon was %lf\n", rate);

	return 0;
}