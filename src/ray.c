#include "ray.h"
#include "tuple.h"

void	ray_init(t_ray *ray, t_tuple *origin, t_tuple *direction)
{
	ray->origin = *origin;
	ray->direction = *direction;
}