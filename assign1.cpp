/*
* Project:	    A-01 : OVERLOADED FUNCTIONS
* By :			Hoang Phuc Tran
* Student ID :  8789102
* Date :		April 21, 2022
* Description : This program calculate either from the user (at the keyboard) or from an input test 
				file and determine if the student passed or failed the course.
*/



#include <stdio.h>
#include <string.h>
#include "assessGrade.h"


#pragma warning(disable: 4996)



int main()
{
	char inputInfo[MAX_LENGTH] = { 0 };
	char letterGrade[MAX_LENGTH] = { 0 };
	char filename[MAX_LENGTH] = { 0 };
	double numberGrade = 0;
	int arrNumber[MAX_ARR] = { 0 };
	int returnValue = 0;
	FILE* fp = NULL;
	
	// Loop until the user enters 'X' character
	while (returnValue != 2)
	{
		printf("Enter Student's Grade(s) >>> ");

		// Get input from the user
		fgets(inputInfo, sizeof(inputInfo), stdin);

		returnValue = parseUserInput(inputInfo, numberGrade, letterGrade, arrNumber, filename);

		// Check if the return value from pareseUserInput is 1 then Call assessGrade with double
		if (returnValue == 1)
		{
			assessGrade(numberGrade);
		}
		// Check if the return value from pareseUserInput is 3 then Process and Open file 
		if (returnValue == 3)
		{
			// Open file
			fp = fopen(filename, "r");

			// Check If the user chooses 'Z' option but not input the file name
			if (filename[0] == '\0')
			{
				printf("Pls! Enter the file name.\n");
			}
			else
			{
				// Check if opening file fails
				if (fp == NULL)
				{
					printf("Can't open \"%s\" file.\n", filename);
					return -2;

				}
				else
				{
					// Read information from the file
					while (fgets(inputInfo, sizeof(inputInfo), fp) != 0)
					{
						// Get rid of newline character
						inputInfo[strcspn(inputInfo, "\n")] = 0;

						// Get return value from the parseUserInput function
						returnValue = parseUserInput(inputInfo, numberGrade, letterGrade, arrNumber, filename);

						// Check if end of file
						if (feof(fp))
						{
							break;
						}
						if (returnValue == 1)
						{
							assessGrade(numberGrade);
						}
						if (returnValue == 4)
						{
							assessGrade(letterGrade);
						}
						if (returnValue == 5)
						{
							assessGrade(arrNumber);
						}

					}
				}
				// Check if any error happens
				if (ferror(fp))
				{
					printf("**File I/O ERROR\n");
					// Check closing file
					if (fclose(fp) != 0)
					{
						printf("Can't close the \"%s\" file.\n", filename);
					}
					return -5;
				}


			}
		}
		// Check if the return value from pareseUserInput is 4 then Call assessGrade with a parameter is a pointer to char
		if (returnValue == 4)
		{
			assessGrade(letterGrade);
		}
		// Check if the return value from pareseUserInput is 5 then Call assessGrade with a parameter is an array of integers
		if (returnValue == 5)
		{
			assessGrade(arrNumber);
		}
	}

	return 0;
}