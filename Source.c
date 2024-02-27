﻿#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define rows 20
#define characters 129
//count vowels in the string and add this number in start of it
int arraySize;

char* userArray[rows][characters]; //массив строк, >=20 строк
//char userString[129];

int main()
{
	input();

	//output();
	printf("\n");
	vowels();

	return 0;
}

int input(void) //esc = break;  
{
	char character;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < characters; j++)
		{
			character = getch();
			
			//to see

			if (character != 13 && character != 27)
			{
				userArray[i][j] = character;
				fprintf(stdout, "%c", character);
			}
			else if (character == 27)
			{
				return 0;
			}
			else
			{
				printf("\n");
				break;
			}
		} 
	}
}

int output(void)
{
	printf("\n\n");
	for (int i = 0; i < rows; i++)
	{
		if (userArray[i][0] != '\0')
		{
			for (int j = 0; j < characters; j++)
			{
				printf("%c", userArray[i][j]);
			}
		}
		else
		{
			printf("\n");
			return 0;
		}

		printf("\n");
	}
}

int vowels(void)
{
	char MyStr[100], ModString[250]; //ModString в 2.5 раза > MyStr -> чтобы вместить в себя число гласных и MyStr
	char EnDisowels[] = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM"; //Английские гласные
	int CountDisowels = 0; 

	int i = 0;

	for (i; i < rows; i++)
	{
		CountDisowels = 0;

		for (int j = 0; j < characters; j++)
		{

			for (int k = 0; k < strlen(EnDisowels); k++)
			{
				if (userArray[i][j] == EnDisowels[k])
				{
					CountDisowels += 1;
				}
			}
		}

		sprintf(ModString, "%d %c", CountDisowels, ' ');

		if (userArray[i][0] != '\0')
		{
			printf("\n");
			printf("%s", ModString);
			for (int c = 0; c < characters; c++) //
			{
				printf("%c", userArray[i][c]);
			}
		}
		else
		{
			printf("\n");
			return 0;
		}
	}

	
}
