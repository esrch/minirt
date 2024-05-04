#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "matrix.h"

Test(Matrix22, create)
{
	t_matrix22	matrix;

	matrix22_init(&matrix,
		1.0, 2.0,
		3.0, 4.0);
	for (unsigned int i = 0; i != 4; ++i)
		cr_assert(eq(dbl, matrix22_get_at(&matrix, i / 2, i % 2), i + 1));
}

Test(Matrix22, equal)
{
	t_matrix22	m1;
	t_matrix22	m2;
	t_matrix22	m3;

	matrix22_init(&m1,
		1.0, 2.0,
		3.0, 4.0);
	matrix22_init(&m2,
		1.0, 2.0,
		3.0, 4.0);
	matrix22_init(&m3,
		1.0, 2.0,
		3.0, 5.0);

	cr_assert(matrix22_eq(&m1, &m2));
	cr_assert_not(matrix22_eq(&m1, &m3));
}

Test(Matrix22, determinant)
{
	t_matrix22	m;

	matrix22_init(&m,
		1.0, 5.0,
		-3.0, 2.0);
	cr_assert(eq(dbl, matrix22_determinant(&m), 17.0));
}