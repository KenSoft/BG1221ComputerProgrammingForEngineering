/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Project Due 26th November 2018
Just Another Car Parking Management System by KenSoftTH */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void configIO();
int checkConfigExist();

int checkConfigExist() {
	//Check if config.txt exists or not
	FILE *file;
	file = fopen("config.txt", "r");
	if (file)
	{
		fclose(file);
		return 1;
	}
	else {
		return 0;
	}
}

void configIO() {
	// This function read and write the config file
	printf("%d", checkConfigExist());
}


void main() {
	configIO();

}