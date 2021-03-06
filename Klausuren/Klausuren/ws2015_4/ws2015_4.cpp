// ws2015_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

unsigned int numberSort(unsigned int* numbers, unsigned int elements, unsigned int * defizient, unsigned int*abundant);

void printArray(unsigned int * feld, int count);

unsigned int elements = 20;

int main()
{
	int i = 'A' - '0';
	unsigned int numbers[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	unsigned int * numbers_ptr = &numbers[0];
	unsigned int *defizient = new unsigned int[elements];
	unsigned int *abundant = new unsigned int[elements];

	numberSort(numbers, elements, defizient, abundant);
	
	cout << "numbers: " << endl;
	printArray(numbers_ptr, elements);

	cout << "numbers: " << endl;
	printArray(defizient, elements);

	cout << "numbers: " << endl;
	printArray(abundant, elements);

	int j = 0;
	cin >> j;
	return 0;
}

void printArray(unsigned int * feld, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << (int)feld[i] << endl;
	}
}

unsigned int numberSort(unsigned int* numbers, unsigned int elements, unsigned int * defizient, unsigned int*abundant)
{
	int wederAnochD = 0, countA = 0, countD = 0;

	for (int i = 0; i < elements; i++)
	{
		int summeTeiler = 0;
		for (int j = 1; j < numbers[i]; j++)
		{
			if ((numbers[i]%j) == 0)
				summeTeiler += j;
			if (numbers[i] > summeTeiler)
			{
				defizient[countD] = numbers[i];
				countD++;
			}
			else if (numbers[i] < summeTeiler)
			{
				abundant[countA] = numbers[i];
				countA++;
			}
			else {
				wederAnochD++;
			}
		}
	}
	return wederAnochD;
}

