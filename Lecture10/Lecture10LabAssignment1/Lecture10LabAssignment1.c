/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 10-1 Due 12th November 2018
This program read the string and determine its character*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void main() {
	char string[80];
	int count = 0, vowel = 0, consonants = 0, digits = 0, others =0;
	printf("Enter a line of text : ");
	scanf("%80[^\n]", &string);
	for (count = 0; count < 80; count++) {
		//printf("%c", string[count]);
		if (string[count] == '\0') {
			break;
		}
		else if (isdigit(string[count])) {
			digits++;
		}
		else if (isalpha(string[count])) {
			if (toupper(string[count]) == 'A' || toupper(string[count]) == 'E' || toupper(string[count]) == 'I' || toupper(string[count]) == 'O' || toupper(string[count]) == 'U') {
				vowel++;
			}
			else {
				consonants++;
			}
		}
		else {
			others++;
		}
	}
	printf("No. of vowels : %d\n", vowel);
	printf("No. of consonants : %d\n", consonants);
	printf("No. of digits : %d\n", digits);
	printf("No. of other characters : %d\n", others);


}