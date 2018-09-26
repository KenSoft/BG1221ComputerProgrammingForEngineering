/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 5-1 Due 8th October 2018
This program calculate the average exam score and determine how many students passed/failed the exam. */
#include <stdio.h>
#include <math.h>
int main() {
	int inputScore,totalScore=0,count=0,passCount=0,failCount=0;
	double averageScore;
	do {
		printf("Enter exam score (-1 to exit) :");
		scanf("%d", &inputScore);

		if (inputScore != -1) {
			
		
		if (inputScore > 100 || inputScore < 0) {
			printf("You have entered an invalid exam score.\n");
		}
		else if (inputScore >= 50) {
			passCount++;
			count++;
			totalScore = totalScore + inputScore;
			/* pass */
		}
		else if (inputScore < 50) {
			failCount++;
			count++;
			totalScore = totalScore + inputScore;
			/* fail */
		}
		}
	} while (inputScore != -1);

end:
	averageScore = (double) totalScore / (double) count;
	printf("The average of these exam scores : %.2lf\n", averageScore);
	printf("Number of students has exam score >= 50 : %d\n", passCount);
	printf("Number of students has exam score < 50 : %d\n", failCount);
	return 0;
}