/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 10-2 Due 12th November 2018
This program read student score and determine the average*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void main() {
	int score[5][3];
	double average[5];
	char studentInfo[5][2][20];
	double classAvg = 0;
	int count = 0;
	printf("%-5s %-4s %-5s %-5s %-5s %-10s\n", "ID No", "Name", "Test1", "Test2", "Test3", "Average");
	for (count = 0; count < 5; count++) {
		scanf("%s %s %d %d %d",&studentInfo[count][0], &studentInfo[count][1],&score[count][0],&score[count][1], &score[count][2]);
		average[count] = (double) (score[count][0] + score[count][1] + score[count][2]) / 3.0;
		printf("%-5s %-4s %-5s %-5s %-5s %-10lf\n","","","","","",average[count]);
	}
	printf("\n\n");
	for (count = 0; count < 5; count++) {
		classAvg = classAvg + average[count];
	}
	classAvg = classAvg / 5.0;
	printf("The overall class average is %lf\n", classAvg);

	FILE *file;
	file = fopen("testScore.txt", "w");
	fprintf(file, "%-5s %-4s %-5s %-5s %-5s %-10s\n", "ID No", "Name", "Test1", "Test2", "Test3", "Average");
	for (count = 0; count < 5; count++) {
		fprintf(file, "%-5s %-4s %-5d %-5d %-5d %-10lf\n", studentInfo[count][0], studentInfo[count][1], score[count][0], score[count][1], score[count][2], average[count]);
	}
	fprintf(file, "\n\n");
	fprintf(file, "The overall class average is %lf\n", classAvg);
	fclose(file);
}