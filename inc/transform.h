#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "matrix.h"

# include <stdarg.h>

# define PI 3.14159265358979323846

void	translation(t_matrix44 *result, double x, double y, double z);
void	scaling(t_matrix44 *result, double x, double y, double z);
void	rotation_x(t_matrix44 *result, double rad);
void	rotation_y(t_matrix44 *result, double rad);
void	rotation_z(t_matrix44 *result, double rad);
void	shearing(t_matrix44 *result, ...);

#endif