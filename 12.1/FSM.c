#include "FSM.h"
#include <stdbool.h>
#include <ctype.h>

enum States {
	start,
	seenFirstDigit,
	seenPoint,
	seenSecondDigit,
	seenE,
	seenSign,
	seenThirdDigit
};

bool isRealNumber(char* string)
{
	enum States state = start;
	int current = 0;
	while (true)
	{
		char token = string[current];
		switch (state)
		{
		case start:
			if (isdigit(token))
			{
				state = seenFirstDigit;
				break;
			}
			return false;
		case seenFirstDigit:
			if (isdigit(token))
			{
				break;
			}
			if (token == '.')
			{
				state = seenPoint;
				break;
			}
			else if (token == 'E')
			{
				state = seenE;
				break;
			}
			else if (token == '\0' || token == '\n')
			{
				return true;
			}
			return false;
		case seenPoint:
			if (isdigit(token))
			{
				state = seenSecondDigit;
				break;
			}
			return false;
		case seenSecondDigit:
			if (isdigit(token))
			{
				break;
			}
			else if (token == '\0' || token == '\n')
			{
				return true;
			}
			if (token == 'E')
			{
				state = seenE;
				break;
			}
			return false;
		case seenE:
			if (isdigit(token))
			{
				state = seenThirdDigit;
				break;
			}
			if (token == '-' || token == '+')
			{
				state = seenSign;
				break;
			}
			return false;
		case seenSign:
			if (isdigit(token))
			{
				state = seenThirdDigit;
				break;
			}
			return false;
		case seenThirdDigit:
			if (isdigit(token))
			{
				break;
			}
			else if (token == '\0' || token == '\n')
			{
				return true;
			}
			return false;
		default:
			break;
		}
		current++;
	}
}