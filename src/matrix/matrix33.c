#include "matrix.h"

#include <stdarg.h>
#include <stdio.h>

void	matrix33_init(t_matrix33 *m, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, m);
	i = 0;
	while (i < 9)
	{
		m->values[i] = va_arg(args, double);
		i++;
	}
	va_end(args);
}

double	matrix33_get_at(t_matrix33 *m, size_t row, size_t col)
{
	if (row > 2 || col > 2)
		return 0.0;
	return (m->values[row * 3 + col]);
}

void	matrix33_set_at(t_matrix33 *m, size_t row, size_t col, double val)
{
	if (row > 2 || col > 2)
		return ;
	m->values[row * 3 + col] = val;
}

bool	matrix33_eq(t_matrix33 *m1, t_matrix33 *m2)
{
	unsigned int	i;

	i = 0;
	while (i < 9)
	{
		if (m1->values[i] != m2->values[i])
			return (false);
		i++;
	}
	return (true);
}

void	matrix33_print(t_matrix33 *m)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			printf("%f ", matrix33_get_at(m, row, col));
			col++;
		}
		printf("\n");
		row++;
	}
}

void	matrix33_submatrix(t_matrix22 *result, t_matrix33 *m,
	size_t row, size_t col)
{
	size_t	i;
	size_t	i_shift;
	size_t	j;
	size_t	j_shift;

	if (row >= 3 || col >= 3)
		return ;
	i = 0;
	i_shift = 0;
	while (i + i_shift < 3)
	{
		if (i + i_shift == row)
		{
			i_shift++;
			continue ;
		}
		j = 0;
		j_shift = 0;
		while (j + j_shift < 3)
		{
			if (j + j_shift == col)
			{
				j_shift++;
				continue ;
			}
			matrix22_set_at(result, i, j,
				matrix33_get_at(m, i + i_shift, j + j_shift));
			j++;
		}
		i++;
	}
}

double	matrix33_minor(t_matrix33 *m, size_t row, size_t col)
{
	t_matrix22	submatrix;

	matrix33_submatrix(&submatrix, m, row, col);
	return (matrix22_determinant(&submatrix));
}

double	matrix33_cofactor(t_matrix33 *m, size_t row, size_t col)
{
	if ((row + col) % 2 == 0)
		return (matrix33_minor(m, row, col));
	return (-matrix33_minor(m, row, col));
}

double	matrix33_determinant(t_matrix33 *m)
{
	unsigned int	i;
	double			total;

	i = 0;
	total = 0.0;
	while (i < 3)
	{
		total += matrix33_get_at(m, 0, i) * matrix33_cofactor(m, 0, i);
		i++;
	}
	return (total);
}