#include "tuple.h"

#include <stdlib.h>

t_tuple	*tuple_create(double x, double y, double z, double w)
{
	t_tuple	*t;

	t = malloc(sizeof(*t));
	if (!t)
		return (NULL);
	t->x = x;
	t->y = y;
	t->z = z;
	t->w = w;
	return (t);
}

void	tuple_destroy(t_tuple *t)
{
	free(t);
}
