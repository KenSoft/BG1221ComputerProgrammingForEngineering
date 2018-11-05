/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 9-1 Due 12th November 2018
This program read the file and find maximum, minimum, and average of the dataset*/
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
	FILE *output;
	file = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	printf("Dataset = ");
	while (!feof(file))
	{
		if (count != 0) {
			printf(", ");
			fprintf(output ,", ");
		}
		fscanf(file, "%d", &inputArray[count]);
		printf("%d", inputArray[count]);
		fprintf(output, "%d", inputArray[count]);
		count++;
	}
	printf("\n");
	fprintf(output, "\n");
	max = maximum(inputArray);
	min = minimum(inputArray);
	avg = average(inputArray);

	printf("Maximum = %d\nMinimum = %d\nAverage = %lf\n", max, min, avg);
	fprintf(output, "Maximum = %d\nMinimum = %d\nAverage = %lf\n", max, min, avg);
	fclose(file);
	fclose(output);
}

int maximum(int inputArray[100]) {
	int temp = inputArray[0], counter = 1;
	for (counter; counter < count; counter++) {
		if (temp < inputArray[counter]) {
			temp = inputArray[counter];
		}

	}
	return temp;
}

int minimum(int inputArray[100]) {
	int temp = inputArray[0], counter = 1;
	for (counter; counter < count; counter++) {
		if (temp > inputArray[counter]) {
			temp = inputArray[counter];
		}

	}
	return temp;
}

double average(int inputArray[100]) {
	int average = 0, counter = 0;
	for (counter; counter < count; counter++) {
		average = inputArray[counter] + average;
	}
	average = average / (double) count;
	return average;

}