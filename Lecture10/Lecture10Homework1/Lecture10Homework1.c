/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 10-1 Due 19th November 2018
This program read three lines of string and determine its character*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void countChar(int address);
char string[3][80];
int count = 0, vowel = 0, consonants = 0, digits = 0, others = 0, nCount = 0;
void main() {

	printf("Enter three line of text : ");
	scanf("%80[^\n] %80[^\n] %80[^\n]", &string[0], &string[1], &string[2]);
	
	countChar(0);
	countChar(1);
	countChar(2);

	printf("No. of vowels : %d\n", vowel);
	printf("No. of consonants : %d\n", consonants);
	printf("No. of digits : %d\n", digits);
	printf("No. of other characters : %d\n", others);
	printf("No. of occurrences for letter n : %d\n", nCount);


}
void countChar(int address) {
	for (count = 0; count < 80; count++) {
		//printf("%c", string[count]);
		if (string[address][count] == '\0') {
			break;
		}
		else if (isdigit(string[address][count])) {
			digits++;
		}
		else if (isalpha(string[address][count])) {
			if (toupper(string[address][count]) == 'A' || toupper(string[address][count]) == 'E' || toupper(string[address][count]) == 'I' || toupper(string[address][count]) == 'O' || toupper(string[address][count]) == 'U') {
				vowel++;
			}
			else {
				consonants++;
			}

			if (toupper(string[address][count]) == 'N') {
				nCount++;
			}
		}
		else {
			others++;
		}
	}


}