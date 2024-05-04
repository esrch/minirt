#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "matrix.h"

Test(Matrix33, create)
{
	t_matrix33	matrix;

	matrix33_init(&matrix,
		1.0, 2.0, 3.0,
		4.0, 5.0, 6.0,
		7.0, 8.0, 9.0);
	for (unsigned int i = 0; i != 9; ++i)
		cr_assert(eq(dbl, matrix33_get_at(&matrix, i / 3, i % 3), i + 1));
}

Test(Matrix33, equal)
{
	t_matrix33	m1;
	t_matrix33	m2;
	t_matrix33	m3;

	matrix33_init(&m1,
		1.0, 2.0, 3.0,
		4.0, 5.0, 6.0,
		7.0, 8.0, 9.0);
	matrix33_init(&m2,
		1.0, 2.0, 3.0,
		4.0, 5.0, 6.0,
		7.0, 8.0, 9.0);
	matrix33_init(&m3,
		1.0, 2.0, 3.0,
		4.0, 5.0, 6.0,
		7.0, 8.0, 10.0);

	cr_assert(matrix33_eq(&m1, &m2));
	cr_assert_not(matrix33_eq(&m1, &m3));
}

Test(Matrix33, submatrix)
{
	t_matrix33	m;
	t_matrix22	result;
	t_matrix22	expected;

	matrix33_init(&m,
		1.0, 5.0, 0.0,
		-3.0, 2.0, 7.0,
		0.0, 6.0, -3.0);
	matrix33_submatrix(&result, &m, 0, 2);
	matrix22_init(&expected,
		-3.0, 2.0,
		0.0, 6.0);
	cr_assert(matrix22_eq(&result, &expected));
}

Test(Matrix33, minor)
{
	t_matrix33	m;

	matrix33_init(&m,
		3.0, 5.0, 0.0,
		2.0, -1.0, -7.0,
		6.0, -1.0, 5.0);
	cr_assert(eq(dbl, matrix33_minor(&m, 1, 0), 25.0));
}

Test(Matrix33, cofactor)
{
	t_matrix33	m;

	matrix33_init(&m,
		3.0, 5.0, 0.0,
		2.0, -1.0, -7.0,
		6.0, -1.0, 5.0);
	cr_assert(eq(dbl, matrix33_cofactor(&m, 0, 0), -12.0));
	cr_assert(eq(dbl, matrix33_cofactor(&m, 1, 0), -25.0));
}

Test(Matrix33, determinant)
{
	t_matrix33	m;

	matrix33_init(&m,
		1.0, 2.0, 6.0,
		-5.0, 8.0, -4.0,
		2.0, 6.0, 4.0);
	cr_assert(eq(dbl, matrix33_determinant(&m), -196.0));
}