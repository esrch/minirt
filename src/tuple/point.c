#include "tuple.h"

#include <stdbool.h>

#include "utils.h"

void	point_set(t_tuple *t, double x, double y, double z)
{
	tuple_set(t, x, y, z, 1);
}

t_tuple	*point_create(double x, double y, double z)
{
	return (tuple_create(x, y, z, 1));
}

bool	is_point(t_tuple *t)
{
	return (double_eq(t->w, 1.0));
}