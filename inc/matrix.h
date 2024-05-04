#ifndef MATRIX_H
# define MATRIX_H

# include "tuple.h"

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_matrix44
{
	double	values[16];
}	t_matrix44;

typedef struct s_matrix33
{
	double	values[9];
}	t_matrix33;

typedef struct s_matrix22
{
	double	values[4];
}	t_matrix22;

// Matrix 4x4
void		matrix44_init(t_matrix44 *m, ...);
double		matrix44_get_at(t_matrix44 *m, size_t row, size_t col);
void		matrix44_set_at(t_matrix44 *m, size_t row, size_t col, double val);
bool		matrix44_eq(t_matrix44 *m1, t_matrix44 *m2);
void		matrix44_print(t_matrix44 *m);
t_matrix44	matrix44_identity(void);
t_matrix44	matrix44_mult(t_matrix44 *m1, t_matrix44 *m2);
t_tuple		matrix44_mult_tuple(t_matrix44 *m, t_tuple *t);
void		matrix44_transpose(t_matrix44 *result, t_matrix44 *m);
void		matrix44_submatrix(t_matrix33 *result, t_matrix44 *m,
				size_t row, size_t col);
double		matrix44_minor(t_matrix44 *m, size_t row, size_t col);
double		matrix44_cofactor(t_matrix44 *m, size_t row, size_t col);
double		matrix44_determinant(t_matrix44 *m);
bool		matrix44_is_invertible(t_matrix44 *m);
t_matrix44	matrix44_inverse(t_matrix44 *m);

// Matrix 3x3
void		matrix33_init(t_matrix33 *m, ...);
double		matrix33_get_at(t_matrix33 *m, size_t row, size_t col);
void		matrix33_set_at(t_matrix33 *m, size_t row, size_t col, double val);
bool		matrix33_eq(t_matrix33 *m1, t_matrix33 *m2);
void		matrix33_print(t_matrix33 *m);
void		matrix33_submatrix(t_matrix22 *result, t_matrix33 *m,
				size_t row, size_t col);
double		matrix33_minor(t_matrix33 *m, size_t row, size_t col);
double		matrix33_cofactor(t_matrix33 *m, size_t row, size_t col);
double		matrix33_determinant(t_matrix33 *m);

// Matrix 2x2
void		matrix22_init(t_matrix22 *m, ...);
double		matrix22_get_at(t_matrix22 *m, size_t row, size_t col);
void		matrix22_set_at(t_matrix22 *m, size_t row, size_t col, double val);
bool		matrix22_eq(t_matrix22 *m1, t_matrix22 *m2);
void		matrix22_print(t_matrix22 *m);
double		matrix22_determinant(t_matrix22 *m);

#endif