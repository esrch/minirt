#include "tuple.h"

t_tuple	*tuple_add(t_tuple *t1, t_tuple *t2)
{
	return (tuple_create(
		t1->x + t2->x,
		t1->y + t2->y,
		t1->z + t2->z,
		t1->w + t2->w));
}

t_tuple	*tuple_subtract(t_tuple *t1, t_tuple *t2)
{
	return (tuple_create(
		t1->x - t2->x,
		t1->y - t2->y,
		t1->z - t2->z,
		t1->w - t2->w));
}

t_tuple	*tuple_mult(t_tuple *t, double scale)
{
	return (tuple_create(t->x * scale, t->y * scale, t->z * scale, t->w * scale));
}

t_tuple	*tuple_div(t_tuple *t, double scale)
{
	return (tuple_create(t->x / scale, t->y / scale, t->z / scale, t->w / scale));
}