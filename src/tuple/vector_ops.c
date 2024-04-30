#include "tuple.h"

#include <math.h>

double	vector_magnitude(t_tuple *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

void	vector_normalize(t_tuple *result, t_tuple *v)
{
	double	magnitude;

	magnitude = vector_magnitude(v);
	tuple_div(result, v, magnitude);
}

double	vector_dot(t_tuple *v1, t_tuple *v2)
{
	return (
		v1->x * v2->x
		+ v1->y * v2->y
		+ v1->z * v2->z
		+ v1->w * v2->w);
}

void	vector_cross(t_tuple *result, t_tuple *v1, t_tuple *v2)
{
	vector_set(
		result,
		v1->y * v2->z - v1->z * v2->y,
		v1->z * v2->x - v1->x * v2->z,
		v1->x * v2->y - v1->y * v2->x);
}
