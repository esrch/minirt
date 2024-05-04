#include "transform.h"
#include "matrix.h"

#include <math.h>
#include <stdarg.h>

void	translation(t_matrix44 *result, double x, double y, double z)
{
	matrix44_init(result,
		1.0, 0.0, 0.0, x,
		0.0, 1.0, 0.0, y,
		0.0, 0.0, 1.0, z,
		0.0, 0.0, 0.0, 1.0);
}

void	scaling(t_matrix44 *result, double x, double y, double z)
{
	matrix44_init(result,
		x, 0.0, 0.0, 0.0,
		0.0, y, 0.0, 0.0,
		0.0, 0.0, z, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

void	rotation_x(t_matrix44 *result, double rad)
{
	matrix44_init(result,
		1.0, 0.0, 0.0, 0.0,
		0.0, cos(rad), -sin(rad), 0.0,
		0.0, sin(rad), cos(rad), 0.0,
		0.0, 0.0, 0.0, 1.0);
}

void	rotation_y(t_matrix44 *result, double rad)
{
	matrix44_init(result,
		cos(rad), 0.0, sin(rad), 0.0,
		0.0, 1.0, 0.0, 0.0,
		-sin(rad), 0.0, cos(rad), 0.0,
		0.0, 0.0, 0.0, 1.0);
}

void	rotation_z(t_matrix44 *result, double rad)
{
	matrix44_init(result,
		cos(rad), -sin(rad), 0.0, 0.0,
		sin(rad), cos(rad), 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

/** Creates a shearing matrix.
 * 
 * Takes six parameters to define the shear transformation:
 * - Change in x in proportion to y
 * - Change in x in proportion to z
 * - Change in y in proportion to x
 * - Change in y in proportion to z
 * - Change in z in proportion to x
 * - Change in z in proportion to y
 * 
*/
void	shearing(t_matrix44 *result, ...)
{
	va_list			args;
	double			factors[6];
	unsigned int	i;

	va_start(args, result);
	i = 0;
	while (i < 6)
	{
		factors[i] = va_arg(args, double);
		i++;
	}
	matrix44_init(result,
		1.0, factors[0], factors[1], 0.0,
		factors[2], 1.0, factors[3], 0.0,
		factors[4], factors[5], 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);
	va_end(args);
}