/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 6-2 Due 15th October 2018
This program counts each letter grade entered and determine how many people pass/fail */
#include <stdio.h>
#include <math.h>
int main() {
	int aCount, bCount, cCount, dCount, fCount;
	aCount = bCount = cCount = dCount = fCount = 0;
	char letterGrade;
	printf("Enter End of File (EOF) to end input\n");
	printf("Enter the letter Grades :\n");
	do {
		letterGrade = getchar();
		if (letterGrade == 'a') {
			letterGrade = 'A';
		}
		else if (letterGrade == 'b') {
			letterGrade = 'B';
		}
		else if (letterGrade == 'c') {
			letterGrade = 'C';
		}
		else if (letterGrade == 'd') {
			letterGrade = 'D';
		}
		else if (letterGrade == 'f') {
			letterGrade = 'F';
		}

		/*printf("%c", letterGrade); */
		switch (letterGrade) {
			case 'A':
				aCount++;
				break;
			case 'B':
				bCount++;
				break;
			case 'C':
				cCount++;
				break;
			case 'D':
				dCount++;
				break;
			case 'F':
				fCount++;
				break;
			case EOF:
				goto End;
				break;
			default:
				printf("Invalid Letter Grade Entered! Enter a new letter grade :\n");
				break;
		}

	} while (getchar() != EOF);
	End:
	printf("\nTotals for each letter grade are :\nA : %d\nB : %d\nC : %d\nD : %d\nF : %d\nNumber of students pass the exam : %d\nNumber of students fail the exam : %d\n",aCount,bCount,cCount,dCount,fCount, (aCount + bCount + cCount), (dCount+fCount));
	return 0;


}