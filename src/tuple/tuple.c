#include "tuple.h"

#include <stdlib.h>

void	tuple_set(t_tuple *tuple, double x, double y, double z, double w)
{
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
}

t_tuple	*tuple_create(double x, double y, double z, double w)
{
	t_tuple	*t;

	t = malloc(sizeof(*t));
	if (!t)
		return (NULL);
	tuple_set(t, x, y, z, w);
	return (t);
}

void	tuple_destroy(t_tuple *t)
{
	free(t);
}
