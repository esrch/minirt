#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "matrix.h"
#include "tuple.h"

#include <stdio.h>

Test(Matrix44, create)
{
	t_matrix44	matrix;

	matrix44_init(&matrix,
		1.0, 2.0, 3.0, 4.0,
		5.0, 6.0, 7.0, 8.0,
		9.0, 10.0, 11.0, 12.0,
		13.0, 14.0, 15.0, 16.0);
	for (unsigned int i = 0; i != 16; ++i)
		cr_assert(eq(dbl, matrix44_get_at(&matrix, i / 4, i % 4), i + 1));
}

Test(Matrix44, equal)
{
	t_matrix44	m1;
	t_matrix44	m2;
	t_matrix44	m3;

	matrix44_init(&m1,
		1.0, 2.0, 3.0, 4.0,
		5.0, 6.0, 7.0, 8.0,
		9.0, 10.0, 11.0, 12.0,
		13.0, 14.0, 15.0, 16.0);
	matrix44_init(&m2,
		1.0, 2.0, 3.0, 4.0,
		5.0, 6.0, 7.0, 8.0,
		9.0, 10.0, 11.0, 12.0,
		13.0, 14.0, 15.0, 16.0);
	matrix44_init(&m3,
		1.0, 2.0, 3.0, 4.0,
		5.0, 6.0, 7.0, 8.0,
		9.0, 10.0, 11.0, 12.0,
		13.0, 14.0, 15.0, 17.0);

	cr_assert(matrix44_eq(&m1, &m2));
	cr_assert_not(matrix44_eq(&m1, &m3));
}

Test(Matrix44, multiplication)
{
	t_matrix44	m1;
	t_matrix44	m2;
	t_matrix44	result;
	t_matrix44	expected;

	matrix44_init(&m1,
		1.0, 2.0, 3.0, 4.0,
		5.0, 6.0, 7.0, 8.0,
		9.0, 8.0, 7.0, 6.0,
		5.0, 4.0, 3.0, 2.0);
	matrix44_init(&m2,
		-2.0, 1.0, 2.0, 3.0,
		3.0, 2.0, 1.0, -1.0,
		4.0, 3.0, 6.0, 5.0,
		1.0, 2.0, 7.0, 8.0);
	matrix44_init(&expected,
		20.0, 22.0, 50.0, 48.0,
		44.0, 54.0, 114.0, 108.0,
		40.0, 58.0, 110.0, 102.0,
		16.0, 26.0, 46.0, 42.0);
	result = matrix44_mult(&m1, &m2);
	cr_assert(matrix44_eq(&result, &expected));
}

Test(Matrix44, tuple_multiplication)
{
	t_matrix44	m;
	t_tuple		t;
	t_tuple		result;
	t_tuple		expected;

	matrix44_init(&m,
		1.0, 2.0, 3.0, 4.0,
		2.0, 4.0, 4.0, 2.0,
		8.0, 6.0, 4.0, 1.0,
		0.0, 0.0, 0.0, 1.0);
	tuple_set(&t, 1, 2, 3, 1);
	tuple_set(&expected, 18, 24, 33, 1);
	result = matrix44_mult_tuple(&m, &t);
	cr_assert(tuple_eq(&result, &expected));
}

Test(Matrix44, identity)
{
	t_matrix44	id;
	t_matrix44	m;
	t_matrix44	result;
	t_matrix44	expected;

	id = matrix44_identity();
	matrix44_init(&expected,
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
	cr_assert(matrix44_eq(&id, &expected));

	matrix44_init(&m,
		0.0, 1.0, 2.0, 4.0,
		1.0, 2.0, 4.0, 8.0,
		2.0, 4.0, 8.0, 16.0,
		4.0, 8.0, 16.0, 32.0);
	result = matrix44_mult(&m, &id);
	cr_assert(matrix44_eq(&result, &m));
}

Test(Matrix44, transpose)
{
	t_matrix44	m;
	t_matrix44	result;
	t_matrix44	expected;

	matrix44_init(&m,
		0.0, 9.0, 3.0, 0.0,
		9.0, 8.0, 0.0, 8.0,
		1.0, 8.0, 5.0, 3.0,
		0.0, 0.0, 5.0, 8.0);
	matrix44_init(&expected,
		0.0, 9.0, 1.0, 0.0,
		9.0, 8.0, 8.0, 0.0,
		3.0, 0.0, 5.0, 5.0,
		0.0, 8.0, 3.0, 8.0);
	matrix44_transpose(&result, &m);
	cr_assert(matrix44_eq(&result, &expected));

	// Can be applied to itself
	matrix44_transpose(&m, &m);
	cr_assert(matrix44_eq(&m, &expected));
}

Test(Matrix44, submatrix)
{
	t_matrix44	m;
	t_matrix33	result;
	t_matrix33	expected;

	matrix44_init(&m,
		-6.0, 1.0, 1.0, 6.0,
		-8.0, 5.0, 8.0, 6.0,
		-1.0, 0.0, 8.0, 2.0,
		-7.0, 1.0, -1.0, 1.0);
	matrix44_submatrix(&result, &m, 2, 1);
	matrix33_init(&expected,
		-6.0, 1.0, 6.0,
		-8.0, 8.0, 6.0,
		-7.0, -1.0, 1.0);
	cr_assert(matrix33_eq(&result, &expected));
}


Test(Matrix44, cofactor)
{
	t_matrix44	m;

	matrix44_init(&m,
		-2.0, -8.0, 3.0, 5.0,
		-3.0, 1.0, 7.0, 3.0,
		1.0, 2.0, -9.0, 6.0,
		-6.0, 7.0, 7.0, -9.0);
	cr_assert(eq(dbl, matrix44_cofactor(&m, 0, 0), 690.0));
	cr_assert(eq(dbl, matrix44_cofactor(&m, 0, 1), 447.0));
	cr_assert(eq(dbl, matrix44_cofactor(&m, 0, 2), 210.0));
	cr_assert(eq(dbl, matrix44_cofactor(&m, 0, 3), 51.0));
}

Test(Matrix44, determinant)
{
	t_matrix44	m;

	matrix44_init(&m,
		-2.0, -8.0, 3.0, 5.0,
		-3.0, 1.0, 7.0, 3.0,
		1.0, 2.0, -9.0, 6.0,
		-6.0, 7.0, 7.0, -9.0);
	cr_assert(eq(dbl, matrix44_determinant(&m), -4071.0));
}

Test(Matrix44, is_invertible)
{
	t_matrix44	m1;
	t_matrix44	m2;

	matrix44_init(&m1,
		6.0, 4.0, 4.0, 4.0,
		5.0, 5.0, 7.0, 6.0,
		4.0, -9.0, 3.0, -7.0,
		9.0, 1.0, 7.0, -6.0);
	matrix44_init(&m2,
		-4.0, 2.0, -2.0, -3.0,
		9.0, 6.0, 2.0, 6.0,
		0.0, -5.0, 1.0, -5.0,
		0.0, 0.0, 0.0, 0.0);
	cr_assert(matrix44_is_invertible(&m1));
	cr_assert_not(matrix44_is_invertible(&m2));
}

Test(Matrix44, inverse)
{
	t_matrix44	m;
	t_matrix44	result;
	t_matrix44	expected;

	matrix44_init(&m,
		-5.0, 2.0, 6.0, -8.0,
		1.0, -5.0, 1.0, 8.0,
		7.0, 7.0, -6.0, -7.0,
		1.0, -3.0, 7.0, 4.0);
	result = matrix44_inverse(&m);
	matrix44_init(&expected,
		0.21805, 0.45113, 0.24060, -0.04511,
		-0.80827, -1.45677, -0.44361, 0.52068,
		-0.07895, -0.22368, -0.05263, 0.19737,
		-0.52256, -0.81391, -0.30075, 0.30639);
	cr_assert(matrix44_eq(&result, &expected));

	matrix44_init(&m,
		8.0, -5.0, 9.0, 2.0,
		7.0, 5.0, 6.0, 1.0,
		-6.0, 0.0, 9.0, 6.0,
		-3.0, 0.0, -9.0, -4.0);
	result = matrix44_inverse(&m);
	matrix44_init(&expected,
		-0.15385, -0.15385, -0.28205, -0.53846,
		-0.07692, 0.12308, 0.02564, 0.03077,
		0.35897, 0.35897, 0.43590, 0.92308,
		-0.69231, -0.69231, -0.76923, -1.92308);
	cr_assert(matrix44_eq(&result, &expected));

	matrix44_init(&m,
		9.0, 3.0, 0.0, 9.0,
		-5.0, -2.0, -6.0, -3.0,
		-4.0, 9.0, 6.0, 4.0,
		-7.0, 6.0, 6.0, 2.0);
	result = matrix44_inverse(&m);
	matrix44_init(&expected,
		-0.04074, -0.07778, 0.14444, -0.22222,
		-0.07778, 0.03333, 0.36667, -0.33333,
		-0.02901, -0.14630, -0.10926, 0.12963,
		0.17778, 0.06667, -0.26667, 0.33333);
	cr_assert(matrix44_eq(&result, &expected));
}