#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "matrix.h"
#include "transform.h"
#include "tuple.h"

#include <math.h>

Test(Transform, point_translation)
{
	t_matrix44	transform;
	t_tuple		point;
	t_tuple		vector;
	t_tuple		result;
	t_tuple		expected;

	translation(&transform, 5, -3, 2);
	point_set(&point, -3, 4, 5);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 2, 1, 7);
	cr_assert(tuple_eq(&result, &expected));

	transform = matrix44_inverse(&transform);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, -8, 7, 3);
	cr_assert(tuple_eq(&result, &expected));

	// Vectors are not modified by the translation matrix
	vector_set(&vector, -3, 4, 5);
	result = matrix44_mult_tuple(&transform, &vector);
	cr_assert(tuple_eq(&result, &vector));
}

Test(Transform, scaling)
{
	t_matrix44	transform;
	t_tuple		point;
	t_tuple		vector;
	t_tuple		result;
	t_tuple		expected;

	scaling(&transform, 2, 3, 4);
	point_set(&point, -4, 6, 8);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, -8, 18, 32);
	cr_assert(tuple_eq(&result, &expected));

	vector_set(&vector, -4, 6, 8);
	result = matrix44_mult_tuple(&transform, &vector);
	vector_set(&expected, -8, 18, 32);
	cr_assert(tuple_eq(&result, &expected));

	// Inverse scaling
	transform = matrix44_inverse(&transform);
	result = matrix44_mult_tuple(&transform, &vector);
	vector_set(&expected, -2, 2, 2);
	cr_assert(tuple_eq(&result, &expected));
}

Test(Transform, rotation_x)
{
	t_matrix44	transform;
	t_tuple		point;
	t_tuple		result;
	t_tuple		expected;

	point_set(&point, 0, 1, 0);
	rotation_x(&transform, PI / 4);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 0, sqrt(2) / 2, sqrt(2) / 2);
	cr_assert(tuple_eq(&result, &expected));

	rotation_x(&transform, PI / 2);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 0, 0, 1);
	cr_assert(tuple_eq(&result, &expected));

	rotation_x(&transform, PI / 4);
	transform = matrix44_inverse(&transform);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 0, sqrt(2) / 2, -sqrt(2) / 2);
	cr_assert(tuple_eq(&result, &expected));
}

Test(Transform, rotation_y)
{
	t_matrix44	transform;
	t_tuple		point;
	t_tuple		result;
	t_tuple		expected;

	point_set(&point, 0, 0, 1);
	rotation_y(&transform, PI / 4);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, sqrt(2) / 2, 0, sqrt(2) / 2);
	cr_assert(tuple_eq(&result, &expected));

	rotation_y(&transform, PI / 2);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 1, 0, 0);
	cr_assert(tuple_eq(&result, &expected));
}

Test(Transform, rotation_z)
{
	t_matrix44	transform;
	t_tuple		point;
	t_tuple		result;
	t_tuple		expected;

	point_set(&point, 0, 1, 0);
	rotation_z(&transform, PI / 4);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, -sqrt(2) / 2, sqrt(2) / 2, 0);
	cr_assert(tuple_eq(&result, &expected));

	rotation_z(&transform, PI / 2);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, -1, 0, 0);
	cr_assert(tuple_eq(&result, &expected));
}

Test(Transform, shearing)
{
	t_matrix44	transform;
	t_tuple		point;
	t_tuple		result;
	t_tuple		expected;

	point_set(&point, 2, 3, 4);
	shearing(&transform, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 5, 3, 4);
	cr_assert(tuple_eq(&result, &expected));

	shearing(&transform, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 6, 3, 4);
	cr_assert(tuple_eq(&result, &expected));

	shearing(&transform, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 2, 5, 4);
	cr_assert(tuple_eq(&result, &expected));

	shearing(&transform, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 2, 7, 4);
	cr_assert(tuple_eq(&result, &expected));

	shearing(&transform, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 2, 3, 6);
	cr_assert(tuple_eq(&result, &expected));

	shearing(&transform, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	result = matrix44_mult_tuple(&transform, &point);
	point_set(&expected, 2, 3, 7);
	cr_assert(tuple_eq(&result, &expected));
}