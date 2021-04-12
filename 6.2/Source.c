#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"
#include <string.h>

int searchSafePlace(const int ammountOfHumans,const int periodicity)
{
	struct List* list = createList();
	for (int i = 1; i <= ammountOfHumans; ++i)
	{
		addValue(list, i);
	}
	while (!(headIsTail(list)))
	{
		deleteValue(list, periodicity);
	}
	const int survivedWarrior = headValue(list);
	deleteList(list);
	return survivedWarrior;
}

bool tests()
{
	return (searchSafePlace(1, 5) == 1) && (searchSafePlace(10, 2) == 5) && (searchSafePlace(3, 2) == 3);
}

int main(){
	if (!tests())
	{
		printf("Tests failed\n");
		return 1;
	}
	printf("Enter the number of humans: ");
	int ammountOfHumans = 0;
	scanf("%d", &ammountOfHumans);
	printf("Enter killing periodicity: ");
	int periodicity = 0;
	scanf("%d", &periodicity);
	const int survivedWarrior = searchSafePlace(ammountOfHumans, periodicity);
	printf("Position of survived warrior: %d\n", survivedWarrior);
	return 0;
}