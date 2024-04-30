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

Test(Tuple, init_tuple)
{
	t_tuple t;
	
	tuple_set(&t, 4.3, -4.2, 3.1, 1.0);

	cr_assert(eq(dbl, t.x, 4.3));
	cr_assert(eq(dbl, t.y, -4.2));
	cr_assert(eq(dbl, t.z, 3.1));
	cr_assert(eq(dbl, t.w, 1.0));
}

Test(Tuple, tuple_equals)
{
	t_tuple t1;
	t_tuple t2;
	t_tuple t3;
	t_tuple t4;

	tuple_set(&t1, 1, 2, 3, 0);
	tuple_set(&t2, 1, 2, 3, 0);
	tuple_set(&t3, 2, 2, 3, 0);
	tuple_set(&t4, 1, 2, 3, 1);

	cr_assert(tuple_eq(&t1, &t2));
	cr_assert_not(tuple_eq(&t1, &t3));
	cr_assert_not(tuple_eq(&t1, &t4));
}

Test(Tuple, tuple_add)
{
	t_tuple	t1;
	t_tuple	t2;
	t_tuple	t3;
	t_tuple	expected;
	t_tuple	result;

	tuple_set(&t1, 3, -2, 5, 1);
	tuple_set(&t2, -2, 3, 1, 0);
	tuple_set(&t3, 2, 3, 1, 0);
	tuple_set(&expected, 1, 1, 6, 1);

	tuple_add(&result, &t1, &t2);
	cr_assert(tuple_eq(&result, &expected));

	tuple_add(&result, &t1, &t3);
	cr_assert_not(tuple_eq(&result, &expected));
}

Test(Tuple, subtract_tuples)
{
	t_tuple t1;
	t_tuple t2;
	t_tuple t3;
	t_tuple expected;
	t_tuple	result;

	tuple_set(&t1, 3, 2, 1, 0);
	tuple_set(&t2, 5, 6, 7, 0);
	tuple_set(&t3, 5, 6, 8, 0);
	tuple_set(&expected, -2, -4, -6, 0);

	tuple_subtract(&result, &t1, &t2);
	cr_assert(tuple_eq(&result, &expected));

	tuple_subtract(&result, &t1, &t3);
	cr_assert_not(tuple_eq(&result, &expected));
}

Test(Tuple, tuple_multiply)
{
	t_tuple	t;
	t_tuple	result;
	t_tuple	expected;

	tuple_set(&t, 1, -2, 3, -4);
	tuple_set(&expected, 3.5, -7, 10.5, -14);

	tuple_mult(&result, &t, 3.5);
	tuple_set(&expected, 3.5, -7, 10.5, -14);
	cr_assert(tuple_eq(&result, &expected));

	tuple_mult(&result, &t, 0.5);
	tuple_set(&expected, 0.5, -1, 1.5, -2);
	cr_assert(tuple_eq(&result, &expected));
}

Test(Tuple, tuple_divide)
{
	t_tuple	t;
	t_tuple result;
	t_tuple expected;

	tuple_set(&t, 1, -2, 3, -4);
	tuple_div(&result, &t, 2);
	tuple_set(&expected, 0.5, -1, 1.5, -2);

	cr_assert(tuple_eq(&result, &expected));
}
