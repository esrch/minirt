#include "tuple.h"

#include <stdbool.h>

#include "utils.h"

t_tuple	*point_create(double x, double y, double z)
{
	return (tuple_create(x, y, z, 1));
}

bool	is_point(t_tuple *t)
{
	return (double_eq(t->w, 1.0));
}