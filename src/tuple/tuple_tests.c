#include "tuple.h"

#include <stdbool.h>

#include "utils.h"

bool	tuple_eq(t_tuple *t1, t_tuple *t2)
{
	return (
		double_eq(t1->x, t2->x)
		&& double_eq(t1->y, t2->y)
		&& double_eq(t1->z, t2->z)
		&& double_eq(t1->w, t2->w));
}
