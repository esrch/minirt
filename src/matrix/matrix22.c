#include "matrix.h"

#include <stdarg.h>
#include <stdio.h>

void	matrix22_init(t_matrix22 *m, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, m);
	i = 0;
	while (i < 4)
	{
		m->values[i] = va_arg(args, double);
		i++;
	}
	va_end(args);
}

double	matrix22_get_at(t_matrix22 *m, size_t row, size_t col)
{
	if (row > 1 || col > 1)
		return 0.0;
	return (m->values[row * 2 + col]);
}

void	matrix22_set_at(t_matrix22 *m, size_t row, size_t col, double val)
{
	if (row > 1 || col > 1)
		return ;
	m->values[row * 2 + col] = val;
}

bool	matrix22_eq(t_matrix22 *m1, t_matrix22 *m2)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		if (m1->values[i] != m2->values[i])
			return (false);
		i++;
	}
	return (true);
}

void	matrix22_print(t_matrix22 *m)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < 2)
	{
		col = 0;
		while (col < 2)
		{
			printf("%f ", matrix22_get_at(m, row, col));
			col++;
		}
		printf("\n");
		row++;
	}
}

double	matrix22_determinant(t_matrix22 *m)
{
	return (matrix22_get_at(m, 0, 0) * matrix22_get_at(m, 1, 1)
		- matrix22_get_at(m, 0, 1) * matrix22_get_at(m, 1, 0));
}