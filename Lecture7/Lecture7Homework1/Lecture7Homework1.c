/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 7-1 Due 22th October 2018
This program calculate voltage, and power for a given resistance, and current values */
#include <stdio.h>
#include <math.h>
int main() {
	int resistance[5] = { 16,27,39,56,81 }, current[5],i;
	double voltage[5], power[5], totalPower=0;
/*	for (i = 0; i < 5; i++) {
		printf("Enter Current for value number %d :", i+1);
		scanf("%d", &current[i]);
		voltage[i] = current[i] * resistance[i];
		power[i] = pow(current[i], 2)*resistance[i];
	} */
	printf("\n%-12s %-12s %-12s %-12s\n", "Resistance", "Current", "Voltage", "Power");
	for (i = 0; i < 5; i++) {
		printf("%-12d ", resistance[i]);
		scanf("%d", &current[i]);
		voltage[i] = current[i] * resistance[i];
		power[i] = pow(current[i], 2)*resistance[i];
		printf("%-12s %-12s %-12lf %-12lf\n", "", "", voltage[i], power[i]);
		totalPower = power[i] + totalPower;
	}
	printf("%-12s %-12s %-12s %-12lf\n", "", "", "Total", totalPower);
	return 0;
}