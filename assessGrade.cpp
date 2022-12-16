#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "assessGrade.h"
#include <math.h>

#pragma warning(disable: 4996)


/*
* Function: assessGrade()
* Description:  this function will display a single numerical grade as a floating point number
				that represents the student's final mark and decide the student that is PASS or FAIL.
* Parameters: a double
* Returns: int: 0 if the function is successful
*/
int assessGrade(double numberGrade)
{
	double roundUp = 0;
	
	// Round the number 2 places after the decimal point
	roundUp = round(numberGrade * 100) / 100;

	// Check numberGrade in rage of a PASS condition
	if (roundUp >= 54.50 && roundUp <= 100)
	{
		printf("Student achieved %.2f %% which is a PASS condition.\n", roundUp);
	}
	// Check numberGrade in rage of a FAIL condition
	else if (roundUp >= 0 && roundUp < 54.50)
	{
		printf("Student achieved %.2f %% which is a FAIL condition.\n", roundUp);
	}
	// If numberGrade is not in PASS or FAIL condition, display an error message
	else
	{
		printf("**ERROR : Invalid Input\n");
	}
	return 0;
}

/*
* Function: assessGrade()
* Description:  this function will calculate interger values and display a single final grade as a floating point number
				that represents the student's final mark and decide the student that is PASS or FAIL.
* Parameters: five integers
* Returns: int: 0 if the function is successful
*/
int assessGrade(int arr[])
{
	int i = 0;
	int j = 0;
	int check = 1;
	double sum = 0;
	double finalMark = 0;

	// Check valid intergers (In rage of 0 - 100)
	for (j = 0; j < MAX_ARR; j++)
	{
		if (arr[j] < 0 || arr[j] > 100)
		{
			check = 0;
		}
	}
	// If integers is valid
	if (check != 0)
	{
		for (i = 0; i < MAX_ARR; i++)
		{
			// Calculate sum of integers
			sum = sum + arr[i];
		}

		// Calculate final mark
		finalMark = sum / MAX_ARR;

		// Check numberGrade in rage of a PASS condition
		if (finalMark >= 54.50 && finalMark <= 100)
		{
			printf("Student achieved %.2f %% which is a PASS condition.\n", finalMark);
		}
		// Check numberGrade in rage of a FAIL condition
		if (finalMark >= 0 && finalMark < 54.50)
		{
			printf("Student achieved %.2f %% which is a FAIL condition.\n", finalMark);
		}
	}
	// If there is invalid integers
	else
	{
		printf("**ERROR : Invalid Input\n");
	}
	// Set the array that contains integers to 0
	memset(arr, 0, MAX_ARR * sizeof(int));

	return 0;
}

/*
* Function: assessGrade()
* Description:  this function will calculate and display a letter Grade as a floating point number
				that represents the student's final mark and decide the student that is PASS or FAIL.
* Parameters: a pointer to char
* Returns: int: 0 if the function is successful
*/
int assessGrade(char* letterGrade)
{
	// If the letterGrade is equal to A+
	if (strcmp("A+", letterGrade) == 0)
	{
		printf("Student achieved 95.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("A", letterGrade) == 0)
	{
		printf("Student achieved 85.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("B+", letterGrade) == 0)
	{
		printf("Student achieved 77.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("B", letterGrade) == 0)
	{
		printf("Student achieved 72.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("C+", letterGrade) == 0)
	{
		printf("Student achieved 67.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("C", letterGrade) == 0)
	{
		printf("Student achieved 62.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("D", letterGrade) == 0)
	{
		printf("Student achieved 57.00 %% which is a PASS condition.\n");
	}
	else if (strcmp("F", letterGrade) == 0)
	{
		printf("Student achieved 50.00 %% which is a FAIL condition.\n");
	}
	else if (strcmp("I", letterGrade) == 0)
	{
		printf("Student has Special Situation : I (Incomplete)\n");
	}
	else if (strcmp("Q", letterGrade) == 0)
	{
		printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
	}
	else if (strcmp("AU", letterGrade) == 0)
	{
		printf("Student has Special Situation : AU (Audit Condition)\n");
	}
	else if (strcmp("DNA", letterGrade) == 0)
	{
		printf("Student has Special Situation : DNA (Did Not Attend)\n");
	}
	else if (strcmp("I/P", letterGrade) == 0)
	{
		printf("Student has Special Situation : I/P (In Process)\n");
	}
	else
	{
		printf("**ERROR : Invalid Input\n");
	}

	return 0;
}

/*
* Function: parseUserInput()
* Description:  this function will determines what kind of input the user entered and extracted
				the data from the user’s input string
* Parameters: 5 parameters
			  1 pointer to char (the user's input string) 
			  1 double (a single numerical grade as a floating point number)
			  1 pointer to char (a letter grade which is meant to represent the student’s final grade)
			  1 array of integers (contain 5 integers)
			  1 pointer to char (contain file name from user's input)
* Returns: int: 0 if the function is successful
*/
int parseUserInput(char* inputInfo, double& numberGrade, char* letterGrade, int arrNumber[], char filename[])
{
	size_t length = 0;
	int checkCharater = 1;
	int checkDigit = 0;
	int i = 0;
	int checkTotal = 0;
	char userInput[MAX_LENGTH] = { 0 };
	int check = 1;
	int k = 0;

	// Get rid of newline
	inputInfo[strcspn(inputInfo, "\n")] = 0;

	// Copy string
	strcpy(userInput, inputInfo);

	// Calculate the length of string
	length = strlen(userInput);

	// Check whether a character is a white-space character or not.
	for (k = 0; k < length; k++)
	{
		if (isspace(userInput[k]) != 0)
		{
			check = 0;
		}
	}

	// Check user's input is Z as a first character and is a space character
	if (userInput[0] == 'Z' && userInput[1] == ' ')
	{
		int j = 0;

		for (i = 2; i < length; i++)
		{
			// copy file name
			filename[j] = userInput[i];
			j++;
		}

		return 3;
	}
	// Check if user's input contains a '.' character
	else if (strchr(userInput, '.') != NULL)
	{
		checkDigit = sscanf(userInput, "%lf", &numberGrade);

		for (i = 0; i < length; i++)
		{
			// Check if user's input contain any character except for '-' and '.' character
			if (userInput[i] != '.' && isdigit(userInput[i]) == 0 && userInput[i] != '-')
			{
				checkCharater = 0;
			}
		}
		// If the string contains any character except for '-' and '.' character 
		if (checkCharater == 0 || checkDigit == 0)
		{
			// Assign -1 to numberGrade
			numberGrade = -1;
		}
		return 1;

	}
	// Check the X character from the user
	else if (!strcmp(userInput, "X"))
	{
		return 2;
	}
	// Check if user inputs letter grade
	else if (check == 1 && sscanf(userInput, "%d", &arrNumber[0]) == 0)
	{
		strcpy(letterGrade, userInput);

		return 4;
	}
	else
	{
		int m = 0;
		int check1 = 1;
		int check2 = 0;

		for (i = 0; i < length; i++)
		{
			// Check space character
			if (isspace(userInput[i]))
			{
				m++;
			}

			if (userInput[i] != ' ' && isdigit(userInput[i]) == 0 && userInput[i] != '-')
			{
				check1 = 0;
			}
			// Check if the string contains both digit and alphabet
			if (isalnum(userInput[i]))
			{
				check2 = 1;
			}
			
		}
		// Check the string contains character and exceeds 4 space character allowed
		if (m > 4 || check1 == 0 || check2 == 0)
		{
			arrNumber[0] = -1;

		}
		else
		{
			// Get five integers from the user's input
			checkTotal = sscanf(userInput, "%d %d %d %d %d", &arrNumber[0], &arrNumber[1], &arrNumber[2], &arrNumber[3], &arrNumber[4]);
		}


		return 5;
	}

	return 0;
}
