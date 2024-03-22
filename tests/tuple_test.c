#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "tuple.h"

Test(Tuple, create_tuple)
{
	t_tuple *t = tuple_create(4.3, -4.2, 3.1, 1.0);

	cr_assert_not_null(t);
	cr_assert(eq(dbl, t->x, 4.3));
	cr_assert(eq(dbl, t->y, -4.2));
	cr_assert(eq(dbl, t->z, 3.1));
	cr_assert(eq(dbl, t->w, 1.0));

	tuple_destroy(t);
}

Test(Tuple, tuple_equals)
{
	t_tuple *t1 = tuple_create(1, 2, 3, 0);
	t_tuple *t2 = tuple_create(1, 2, 3, 0);
	t_tuple *t3 = tuple_create(2, 2, 3, 0);
	t_tuple *t4 = tuple_create(1, 2, 3, 1);

	cr_assert(tuple_eq(t1, t2));
	cr_assert_not(tuple_eq(t1, t3));
	cr_assert_not(tuple_eq(t1, t4));

	tuple_destroy(t1);
	tuple_destroy(t2);
	tuple_destroy(t3);
	tuple_destroy(t4);
}

Test(Tuple, tuple_add)
{
	t_tuple	*result;

	t_tuple *t1 = tuple_create(3, -2, 5, 1);
	t_tuple *t2 = tuple_create(-2, 3, 1, 0);
	t_tuple *t3 = tuple_create(2, 3, 1, 0);
	t_tuple	*expected = tuple_create(1, 1, 6, 1);

	result = tuple_add(t1, t2);
	cr_assert(tuple_eq(result, expected));
	tuple_destroy(result);

	result = tuple_add(t1, t3);
	cr_assert_not(tuple_eq(result, expected));
	tuple_destroy(result);

	tuple_destroy(t1);
	tuple_destroy(t2);
	tuple_destroy(t3);
	tuple_destroy(expected);
}

Test(Tuple, subtract_tuples)
{
	t_tuple	*result;

	t_tuple *t1 = tuple_create(3, 2, 1, 0);
	t_tuple *t2 = tuple_create(5, 6, 7, 0);
	t_tuple *t3 = tuple_create(5, 6, 8, 0);
	t_tuple *expected = tuple_create(-2, -4, -6, 0);

	result = tuple_subtract(t1, t2);
	cr_assert(tuple_eq(result, expected));
	tuple_destroy(result);

	result = tuple_subtract(t1, t3);
	cr_assert_not(tuple_eq(result, expected));
	tuple_destroy(result);

	tuple_destroy(t1);
	tuple_destroy(t2);
	tuple_destroy(t3);
	tuple_destroy(expected);
}

Test(Tuple, tuple_multiply)
{
	t_tuple	*result;
	t_tuple	*expected;

	t_tuple *t = tuple_create(1, -2, 3, -4);

	result = tuple_mult(t, 3.5);
	expected = tuple_create(3.5, -7, 10.5, -14);
	cr_assert(tuple_eq(result, expected));
	tuple_destroy(result);
	tuple_destroy(expected);

	result = tuple_mult(t, 0.5);
	expected = tuple_create(0.5, -1, 1.5, -2);
	cr_assert(tuple_eq(result, expected));
	tuple_destroy(result);
	tuple_destroy(expected);

	tuple_destroy(t);
}

Test(Tuple, tuple_divide)
{
	t_tuple *t = tuple_create(1, -2, 3, -4);
	t_tuple	*result = tuple_div(t, 2);
	t_tuple	*expected = tuple_create(0.5, -1, 1.5, -2);

	cr_assert(tuple_eq(result, expected));

	tuple_destroy(t);
	tuple_destroy(result);
	tuple_destroy(expected);
}
