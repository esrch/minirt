#include "color.h"

void	color_add(t_color *result, t_color *c1, t_color *c2)
{
	color_set(result,
		c1->red + c2->red,
		c1->green + c2->green,
		c1->blue + c2->blue);
}

void	color_subtr(t_color *result, t_color *c1, t_color *c2)
{
	color_set(result,
		c1->red - c2->red,
		c1->green - c2->green,
		c1->blue - c2->blue);
}

void	color_mult_scalar(t_color *result, t_color *c, double x)
{
	color_set(result,
		c->red * x,
		c->green * x,
		c->blue * x);
}

void	color_mult_color(t_color *result, t_color *c1, t_color *c2)
{
	color_set(result,
		c1->red * c2->red,
		c1->green * c2->green,
		c1->blue * c2->blue);
}

unsigned int	color_to_uint(t_color *color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = color->red * 255 + 0.5;
	g = color->green * 255 + 0.5;
	b = color->blue * 255 + 0.5;
	return (0 | (r << 16) | (g << 8) | b);
}