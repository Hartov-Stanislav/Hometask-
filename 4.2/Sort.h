#pragma once

void  insertionSort(int* array, int firstElement, int lastElement);

// Быстрая сортировка
void qSort(int* array, int firstElement, int lastElement);

// Тесты 

// Один элемент в массиве
int testWithOneElement();

// Все элементы одинаковые
int testWithEqualElements();

// Тест с произвольным заполнением массива
int testWithRandomElements();

// Функция для прохождения теста
void checkTest(int a);

// Фуункция для прохождения тестов
void checkTests();