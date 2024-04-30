#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tuple.h"

#include <math.h>

Test(Vector, create_vector)
{
	t_tuple t;

	vector_set(&t, 4.3, -4.2, 3.1);

	cr_assert(eq(dbl, t.x, 4.3));
	cr_assert(eq(dbl, t.y, -4.2));
	cr_assert(eq(dbl, t.z, 3.1));
	cr_assert(eq(dbl, t.w, 0.0));
}

Test(Vector, tuple_is_vector)
{
	t_tuple	t1;
	t_tuple	t2;

	tuple_set(&t1, 1, 1, 1, 0);
	tuple_set(&t2, 1, 1, 1, 1);

	cr_assert(is_vector(&t1));
	cr_assert_not(is_vector(&t2));
}

Test(Vector, magnitude)
{
	t_tuple	v;

	vector_set(&v, 1, 0, 0);
	cr_assert(eq(dbl, vector_magnitude(&v), 1));

	vector_set(&v, 0, 1, 0);
	cr_assert(eq(dbl, vector_magnitude(&v), 1));

	vector_set(&v, 0, 0, 1);
	cr_assert(eq(dbl, vector_magnitude(&v), 1));

	vector_set(&v, 1, 2, 3);
	cr_assert(eq(dbl, vector_magnitude(&v), sqrt(14)));

	vector_set(&v, -1, -2, -3);
	cr_assert(eq(dbl, vector_magnitude(&v), sqrt(14)));
}

Test(Vector, normalize)
{
	t_tuple	v;
	t_tuple	result;
	t_tuple	expected;

	vector_set(&v, 4, 0, 0);
	vector_normalize(&result, &v);
	vector_set(&expected, 1, 0, 0);
	cr_assert(tuple_eq(&result, &expected));
	cr_assert(eq(dbl, vector_magnitude(&result), 1));

	vector_set(&v, 1, 2, 3);
	vector_normalize(&result, &v);
	vector_set(&expected, 1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
	cr_assert(tuple_eq(&result, &expected));
	cr_assert(eq(dbl, vector_magnitude(&result), 1));
}

Test(Vector, dot_product)
{
	t_tuple	v1;
	t_tuple	v2;

	vector_set(&v1, 1, 2, 3);
	vector_set(&v2, 2, 3, 4);

	cr_assert(eq(dbl, vector_dot(&v1, &v2), 20));
}

Test(Vector, cross_product)
{
	t_tuple	v1;
	t_tuple	v2;
	t_tuple	result;
	t_tuple	expected;

	vector_set(&v1, 1, 2, 3);
	vector_set(&v2, 2, 3, 4);

	vector_cross(&result, &v1, &v2);
	vector_set(&expected, -1, 2, -1);
	cr_assert(tuple_eq(&result, &expected));

	vector_cross(&result, &v2, &v1);
	vector_set(&expected, 1, -2, 1);
	cr_assert(tuple_eq(&result, &expected));
}