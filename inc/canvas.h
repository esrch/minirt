#ifndef CANVAS_H
# define CANVAS_H

# include <stdlib.h>

# include "color.h"

typedef struct s_canvas
{
	size_t	width;
	size_t	height;
	t_color	*pixels;
}	t_canvas;

t_canvas	*canvas_create(size_t width, size_t height);
void		canvas_destroy(t_canvas *c);
void		canvas_write_pixel(t_canvas *canvas, size_t x, size_t y,
				t_color *color);
t_color		*canvas_pixel_at(t_canvas *canvas, size_t x, size_t y);

#endif