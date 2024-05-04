#ifndef COLOR_H
# define COLOR_H

# include <stdbool.h>

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

// Color
void			color_set(t_color *c, double red, double green, double blue);
t_color			*color_create(double red, double green, double blue);
void			color_destroy(t_color *c);
bool			color_eq(t_color *c1, t_color *c2);

// Color ops
void			color_add(t_color *result, t_color *c1, t_color *c2);
void			color_subtr(t_color *result, t_color *c1, t_color *c2);
void			color_mult_scalar(t_color *result, t_color *c, double x);
void			color_mult_color(t_color *result, t_color *c1, t_color *c2);
unsigned int	color_to_uint(t_color *color);

#endif