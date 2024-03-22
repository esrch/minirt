#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tuple.h"

Test(Point, create_point)
{
	t_tuple *t = point_create(4.3, -4.2, 3.1);

	cr_assert(eq(dbl, t->x, 4.3));
	cr_assert(eq(dbl, t->y, -4.2));
	cr_assert(eq(dbl, t->z, 3.1));
	cr_assert(eq(dbl, t->w, 1.0));

	tuple_destroy(t);
}

Test(Point, tuple_is_point)
{
	t_tuple *t1 = tuple_create(1, 1, 1, 1);
	t_tuple *t2 = tuple_create(1, 1, 1, 0);

	cr_assert(is_point(t1));
	cr_assert_not(is_point(t2));

	tuple_destroy(t1);
	tuple_destroy(t2);
}
