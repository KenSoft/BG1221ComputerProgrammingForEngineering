/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 9-1 Due 12th November 2018
This program take 2 integers and raised the power*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int maximum();
int minimum();
double average();
int count = 0;
void main() {
	int inputArray[100];
	int max, min;
	double avg;
	FILE *file;
	file = fopen("input.txt", "r");
	while (!feof(file))
	{
		fscanf(file, "%d", &inputArray[count]);
		printf("%d\n", inputArray[count]);
		count++;
	}
	max = maximum(inputArray);
	fclose(file);
}

int maximum(int inputArray[100]) {
	int temp = inputArray[0], counter = 1;
	for (counter; counter < count; counter++) {


	}
}