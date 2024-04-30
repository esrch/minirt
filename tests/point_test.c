#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tuple.h"

Test(Point, create_point)
{
	t_tuple	t;

	point_set(&t, 4.3, -4.2, 3.1);

	cr_assert(eq(dbl, t.x, 4.3));
	cr_assert(eq(dbl, t.y, -4.2));
	cr_assert(eq(dbl, t.z, 3.1));
	cr_assert(eq(dbl, t.w, 1.0));
}

Test(Point, tuple_is_point)
{
	t_tuple t1;
	t_tuple t2;

	tuple_set(&t1, 1, 1, 1, 1);
	tuple_set(&t2, 1, 1, 1, 0);

	cr_assert(is_point(&t1));
	cr_assert_not(is_point(&t2));
}
