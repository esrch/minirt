#include "tuple.h"

void	tuple_add(t_tuple *result, t_tuple *t1, t_tuple *t2)
{
	result->x = t1->x + t2->x;
	result->y = t1->y + t2->y;
	result->z = t1->z + t2->z;
	result->w = t1->w + t2->w;
}

void	tuple_subtract(t_tuple *result, t_tuple *t1, t_tuple *t2)
{
	result->x = t1->x - t2->x;
	result->y = t1->y - t2->y;
	result->z = t1->z - t2->z;
	result->w = t1->w - t2->w;
}

void	tuple_mult(t_tuple *result, t_tuple *t, double scale)
{
	result->x = t->x * scale;
	result->y = t->y * scale;
	result->z = t->z * scale;
	result->w = t->w * scale;
}

void	tuple_div(t_tuple *result, t_tuple *t, double scale)
{
	result->x = t->x / scale;
	result->y = t->y / scale;
	result->z = t->z / scale;
	result->w = t->w / scale;
}