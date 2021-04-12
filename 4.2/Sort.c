#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

// Сортировка вставкой
void  insertionSort(int* array, int firstElement, int lastElement)
{
	int sizeOfArray = lastElement - firstElement + 1;
	// Что мы будем двигать
	int temp = 0;
	// С какого места мы это будем двигать
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

// Быстрая сортировка
void qSort(int* array, int firstElement, int lastElement)
{
	// Прописываем условие сортировки куска вставкой
	if (firstElement - lastElement + 1 <= 10 && firstElement < lastElement)
	{
		insertionSort(array, firstElement, lastElement - 1);
	}
	// Сама сортировка qSort
	else {
		if (firstElement < lastElement)
		{
			int i = firstElement;
			int j = lastElement;
			// Выбор "Рандомного" элемента из середины массива
			int middleElementInArray = array[(i + j) / 2];
			// Поделилим массив на две части так, что каждый элемент массива из первой части меньше любого элемента из второй
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
			// Аналогия для двух получившихся частей исхлдного массива и так делее
			qSort(array, firstElement, i);
			qSort(array, j, lastElement);
		}
	}
}

// Тесты 

// Один элемент в массиве
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

// Все элементы одинаковые
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

// Тест с произвольным заполнением массива
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

// Функция для прохождения теста
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

// Фуункция для прохождения тестов
void checkTests()
{
	printf("Test with 1 element \n");
	checkTest(testWithOneElement());
	printf("Test with equal elements \n");
	checkTest(testWithEqualElements());
	printf("Test with random elements \n");
	checkTest(testWithRandomElements());
}
