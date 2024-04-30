#include "tuple.h"

#include <stdbool.h>

#include "utils.h"

void	vector_set(t_tuple *t, double x, double y, double z)
{
	tuple_set(t, x, y, z, 0);
}

t_tuple	*vector_create(double x, double y, double z)
{
	return (tuple_create(x, y, z, 0));
}

bool	is_vector(t_tuple *t)
{
	return (double_eq(t->w, 0.0));
}
