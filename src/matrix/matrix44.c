#include "matrix.h"
#include "tuple.h"
#include "utils.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

void	matrix44_init(t_matrix44 *m, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, m);
	i = 0;
	while (i < 16)
	{
		m->values[i] = va_arg(args, double);
		i++;
	}
	va_end(args);
}

double	matrix44_get_at(t_matrix44 *m, size_t row, size_t col)
{
	if (row > 3 || col > 3)
		return 0.0;
	return (m->values[row * 4 + col]);
}

void	matrix44_set_at(t_matrix44 *m, size_t row, size_t col, double value)
{
	if (row > 3 || col > 3)
		return ;
	m->values[row * 4 + col] = value;
}

bool	matrix44_eq(t_matrix44 *m1, t_matrix44 *m2)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (!double_eq(m1->values[i], m2->values[i]))
			return (false);
		i++;
	}
	return (true);
}

void	matrix44_print(t_matrix44 *m)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			printf("%f ", matrix44_get_at(m, row, col));
			col++;
		}
		printf("\n");
		row++;
	}
}

t_matrix44	matrix44_identity(void)
{
	static t_matrix44	id
		= { .values = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
	
	return (id);
}

t_matrix44	matrix44_mult(t_matrix44 *m1, t_matrix44 *m2)
{
	t_matrix44		result;
	unsigned int	i;
	unsigned int	j;
	double			total;

	i = 0;
	while (i < 16)
	{
		total = 0.0;
		j = 0;
		while (j < 4)
		{
			total += matrix44_get_at(m1, i / 4, j) * matrix44_get_at(m2, j, i % 4);
			j++;
		}
		result.values[i] = total;
		i++;
	}
	return (result);
}

t_tuple	matrix44_mult_tuple(t_matrix44 *m, t_tuple *t)
{
	t_tuple	result;

	result.x =
		m->values[0] * t->x + m->values[1] * t->y
		+ m->values[2] * t->z + m->values[3] * t->w;
	result.y =
		m->values[4] * t->x + m->values[5] * t->y
		+ m->values[6] * t->z + m->values[7] * t->w;
	result.z =
		m->values[8] * t->x + m->values[9] * t->y
		+ m->values[10] * t->z + m->values[11] * t->w;
	result.w =
		m->values[12] * t->x + m->values[13] * t->y
		+ m->values[14] * t->z + m->values[15] * t->w;
	return (result);
}

void	matrix44_transpose(t_matrix44 *result, t_matrix44 *m)
{
	unsigned int	i;
	unsigned int	j;
	double			tmp;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			tmp = matrix44_get_at(m, i, j);
			matrix44_set_at(result, i, j, matrix44_get_at(m, j, i));
			matrix44_set_at(result, j, i, tmp);
			j++;
		}
		matrix44_set_at(result, i, i, matrix44_get_at(m, i, i));
		i++;
	}
}

void	matrix44_submatrix(t_matrix33 *result, t_matrix44 *m,
	size_t row, size_t col)
{
	size_t	i;
	size_t	i_shift;
	size_t	j;
	size_t	j_shift;

	if (row >= 4 || col >= 4)
		return ;
	i = 0;
	i_shift = 0;
	while (i + i_shift < 4)
	{
		if (i + i_shift == row)
		{
			i_shift++;
			continue ;
		}
		j = 0;
		j_shift = 0;
		while (j + j_shift < 4)
		{
			if (j + j_shift == col)
			{
				j_shift++;
				continue ;
			}
			matrix33_set_at(result, i, j,
				matrix44_get_at(m, i + i_shift, j + j_shift));
			j++;
		}
		i++;
	}
}

double	matrix44_minor(t_matrix44 *m, size_t row, size_t col)
{
	t_matrix33	submatrix;

	matrix44_submatrix(&submatrix, m, row, col);
	return (matrix33_determinant(&submatrix));
}

double	matrix44_cofactor(t_matrix44 *m, size_t row, size_t col)
{
	if ((row + col) % 2 == 0)
		return (matrix44_minor(m, row, col));
	return (-matrix44_minor(m, row, col));
}

double	matrix44_determinant(t_matrix44 *m)
{
	unsigned int	i;
	double			total;

	i = 0;
	total = 0.0;
	while (i < 4)
	{
		total += matrix44_get_at(m, 0, i) * matrix44_cofactor(m, 0, i);
		i++;
	}
	return (total);

}

bool	matrix44_is_invertible(t_matrix44 *m)
{
	return (!double_eq(matrix44_determinant(m), 0.0));
}

t_matrix44	matrix44_inverse(t_matrix44 *m)
{
	t_matrix44		result;
	unsigned int	row;
	unsigned int	col;
	double			cof;
	double			det;

	det = matrix44_determinant(m);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			cof = matrix44_cofactor(m, row, col);
			matrix44_set_at(&result, col, row, cof / det);
			col++;
		}
		row++;
	}
	return (result);
}