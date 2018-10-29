/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 8-2 Due 5th November 2018
This program selection sort an Array*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main() {
	int account[8] = {0};
	double balance[8] = { 0 };
	char name[8][30] = { '\0' };
	int count = 0, placeholder;
	printf("File Existed!\n");
	FILE *file;
	file = fopen("client.txt", "r");
	for (count = 0; count < 8; count++) {
		fscanf(file, "%d", &account[count]);
		fgets(name[count], 30, file);
		fscanf(file, "%lf", &balance[count]);
		printf("Read line %d value %d %s %lf\n", count + 1, account[count], name[count], balance[count]);
	}
	fclose(file);


}