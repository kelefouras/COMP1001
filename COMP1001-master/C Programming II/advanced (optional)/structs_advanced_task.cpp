/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

#include<stdio.h>
#include<string.h>
#include <windows.h> //this library is needed for pause() function
#define N 2

struct student
{
	char name[20];
	int module_code;
	float mark;
};

int main()
{
	struct student arr_student[N]; //this is an array of structs
	int i;

	for (i = 0; i < N; i++)
	{
		printf("\nEnter details of student %d\n\n", i + 1);

		printf("Enter name: ");
		scanf_s("%s", arr_student[i].name, sizeof(arr_student[i].name)); //scanf asks from the user to type a string of 20 characters long

		printf("Enter module code: ");
		scanf_s("%d", &arr_student[i].module_code, sizeof(arr_student[i].module_code)); //scanf asks from the user to type an integer

		printf("Enter mark: ");
		scanf_s("%f", &arr_student[i].mark, sizeof(arr_student[i].mark)); //scanf asks from the user to type an FP number
	}

	printf("\n");

	printf("Name\tModule\tMark\n");

	for (i = 0; i < N; i++)
	{
		printf("%s\t%d\t%.2f\n",
			arr_student[i].name, arr_student[i].module_code, arr_student[i].mark);
	}

	system("pause"); //this command does not let the output window to close
	// signal to operating system program ran fine
	return 0;
}


