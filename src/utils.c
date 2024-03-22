#include "utils.h"

#include <stdbool.h>

bool	double_eq(double x, double y)
{
	return (x < y + 0.0001 && x > y - 0.0001);
}