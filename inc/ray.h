#ifndef RAY_H
# define RAY_H

# include "tuple.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

void	ray_init(t_ray *ray, t_tuple *origin, t_tuple *direction);
// void	position(t_tuple *result, t_ray *ray, double distance);

#endif