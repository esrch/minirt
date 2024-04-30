#include "color.h"

#include <stdlib.h>

#include "utils.h"

void	color_set(t_color *c, double red, double green, double blue)
{
	c->red = red;
	c->green = green;
	c->blue = blue;
}

t_color	*color_create(double red, double green, double blue)
{
	t_color	*c;

	c = malloc(sizeof(*c));
	if (!c)
		return (NULL);
	color_set(c, red, green, blue);
	return (c);
}

void	color_destroy(t_color *c)
{
	free(c);
}

bool	color_eq(t_color *c1, t_color *c2)
{
	return (
		double_eq(c1->red, c2->red)
		&& double_eq(c1->green, c2->green)
		&& double_eq(c1->blue, c2->blue));
}