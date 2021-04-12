#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

// ���������� ��������
void  insertionSort(int* array, int firstElement, int lastElement)
{
	int sizeOfArray = lastElement - firstElement + 1;
	// ��� �� ����� �������
	int temp = 0;
	// � ������ ����� �� ��� ����� �������
	int location = 0;
	for (int i = firstElement; i < sizeOfArray; i++)
	{
		temp = array[i + 1];
		location = i;
		while (location >= firstElement && array[location] > temp)
		{
			array[location + 1] = array[location];
			location--;
		}
		array[location + 1] = temp;
	}
}

// ������� ����������
void qSort(int* array, int firstElement, int lastElement)
{
	// ����������� ������� ���������� ����� ��������
	if (firstElement - lastElement + 1 <= 10 && firstElement < lastElement)
	{
		insertionSort(array, firstElement, lastElement - 1);
	}
	// ���� ���������� qSort
	else {
		if (firstElement < lastElement)
		{
			int i = firstElement;
			int j = lastElement;
			// ����� "����������" �������� �� �������� �������
			int middleElementInArray = array[(i + j) / 2];
			// ��������� ������ �� ��� ����� ���, ��� ������ ������� ������� �� ������ ����� ������ ������ �������� �� ������
			do
			{
				while (array[i] < middleElementInArray)
				{
					i++;
				}
				while (array[j] < middleElementInArray)
				{
					j--;
				}
				if (i <= j)
				{
					int tempForSwap = array[i];
					array[i] = array[j];
					array[j] = tempForSwap;
					i++;
					j--;
				}
			} while (i <= j);
			// �������� ��� ���� ������������ ������ ��������� ������� � ��� �����
			qSort(array, firstElement, i);
			qSort(array, j, lastElement);
		}
	}
}

// ����� 

// ���� ������� � �������
int testWithOneElement()
{
	int array[1] = { 1 };
	qSort(array, 0, 0);
	if (array[0] != 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// ��� �������� ����������
int testWithEqualElements()
{
	int array[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	qSort(array, 0, 12);
	int mistakes = 0;
	for (int i = 0; i < 13; i++)
	{
		if (array[i] != 1)
		{
			mistakes++;
		}
	}
	return mistakes == 0;
}

// ���� � ������������ ����������� �������
int testWithRandomElements()
{
	int sizeOfArray = 100;
	int* array = (int*)malloc(sizeOfArray * sizeof(int));
	for (int i = 0; i < sizeOfArray; i++)
	{
		array[i] = rand();
	}
	qSort(array, 0, sizeOfArray - 1);
	int mistakes = 0;
	for (int i = 1; i < sizeOfArray; i++)
	{
		if (array[i] < array[i - 1])
		{
			mistakes++;
		}
	}
	free(array);
	return mistakes == 0;
}

// ������� ��� ����������� �����
void checkTest(int a)
{
	if (a == 0)
	{
		printf("Test failed\n");
	}
	else
	{
		printf("Test completed\n");
	}
}

// �������� ��� ����������� ������
void checkTests()
{
	printf("Test with 1 element \n");
	checkTest(testWithOneElement());
	printf("Test with equal elements \n");
	checkTest(testWithEqualElements());
	printf("Test with random elements \n");
	checkTest(testWithRandomElements());
}
