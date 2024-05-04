#include "criterion/criterion.h"
#include "criterion/new/assert.h"

#include "ray.h"
#include "tuple.h"

Test(Ray, init)
{
	t_ray	ray;
	t_tuple	origin;
	t_tuple	direction;

	point_set(&origin, 1, 2, 3);
	vector_set(&direction, 4, 5, 6);
	ray_init(&ray, &origin, &direction);
	cr_assert(tuple_eq(&ray.origin, &origin));
	cr_assert(tuple_eq(&ray.direction, &direction));
}

/*
Test(Ray, position)
{
	t_tuple	origin;
	t_tuple	direction;
	t_ray	ray;
	t_tuple	result;
	t_tuple	expected;

	point_set(&origin, 2, 3, 4);
	vector_set(&direction, 1, 0, 0);
	ray_init(&ray, &origin, &direction);
	position(&result, &ray, 0);
	point_set(&expected, 2, 3, 4);
	cr_assert(tuple_eq(&result, &expected));

	position(&result, &ray, 1);
	point_set(&expected, 3, 3, 4);
	cr_assert(tuple_eq(&result, &expected));

	position(&result, &ray, -1);
	point_set(&expected, 1, 3, 4);
	cr_assert(tuple_eq(&result, &expected));

	position(&result, &ray, 2.5);
	point_set(&expected, 4.5, 3, 4);
	cr_assert(tuple_eq(&result, &expected));
}
*/