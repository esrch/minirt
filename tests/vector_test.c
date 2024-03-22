#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tuple.h"

#include <math.h>

Test(Vector, create_vector)
{
	t_tuple *t = vector_create(4.3, -4.2, 3.1);

	cr_assert(eq(dbl, t->x, 4.3));
	cr_assert(eq(dbl, t->y, -4.2));
	cr_assert(eq(dbl, t->z, 3.1));
	cr_assert(eq(dbl, t->w, 0.0));

	tuple_destroy(t);
}

Test(Vector, tuple_is_vector)
{
	t_tuple *t1 = tuple_create(1, 1, 1, 0);
	t_tuple *t2 = tuple_create(1, 1, 1, 1);

	cr_assert(is_vector(t1));
	cr_assert_not(is_vector(t2));

	tuple_destroy(t1);
	tuple_destroy(t2);
}

Test(Vector, magnitude)
{
	t_tuple	*v;

	v = vector_create(1, 0, 0);
	cr_assert(eq(dbl, vector_magnitude(v), 1));
	tuple_destroy(v);

	v = vector_create(0, 1, 0);
	cr_assert(eq(dbl, vector_magnitude(v), 1));
	tuple_destroy(v);

	v = vector_create(0, 0, 1);
	cr_assert(eq(dbl, vector_magnitude(v), 1));
	tuple_destroy(v);

	v = vector_create(1, 2, 3);
	cr_assert(eq(dbl, vector_magnitude(v), sqrt(14)));
	tuple_destroy(v);

	v = vector_create(-1, -2, -3);
	cr_assert(eq(dbl, vector_magnitude(v), sqrt(14)));
	tuple_destroy(v);
}

Test(Vector, normalize)
{
	t_tuple	*v;
	t_tuple	*result;
	t_tuple	*expected;

	v = vector_create(4, 0, 0);
	result = vector_normalize(v);
	expected = vector_create(1, 0, 0);
	cr_assert(tuple_eq(result, expected));
	cr_assert(eq(dbl, vector_magnitude(result), 1));
	tuple_destroy(v);
	tuple_destroy(result);
	tuple_destroy(expected);

	v = vector_create(1, 2, 3);
	result = vector_normalize(v);
	expected = vector_create(1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
	cr_assert(tuple_eq(result, expected));
	cr_assert(eq(dbl, vector_magnitude(result), 1));
	tuple_destroy(v);
	tuple_destroy(result);
	tuple_destroy(expected);
}

Test(Vector, dot_product)
{
	t_tuple	*v1 = vector_create(1, 2, 3);
	t_tuple	*v2 = vector_create(2, 3, 4);

	cr_assert(eq(dbl, vector_dot(v1, v2), 20));

	tuple_destroy(v1);
	tuple_destroy(v2);
}

Test(Vector, cross_product)
{
	t_tuple	*result;
	t_tuple	*expected;

	t_tuple	*v1 = vector_create(1, 2, 3);
	t_tuple	*v2 = vector_create(2, 3, 4);

	result = vector_cross(v1, v2);
	expected = vector_create(-1, 2, -1);
	cr_assert(tuple_eq(result, expected));
	tuple_destroy(result);
	tuple_destroy(expected);

	result = vector_cross(v2, v1);
	expected = vector_create(1, -2, 1);
	cr_assert(tuple_eq(result, expected));
	tuple_destroy(result);
	tuple_destroy(expected);

	tuple_destroy(v1);
	tuple_destroy(v2);
}