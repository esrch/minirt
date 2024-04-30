#include "canvas.h"

#include <stdlib.h>

#include "color.h"
#include "libft.h"

t_canvas	*canvas_create(size_t width, size_t height)
{
	t_canvas	*canvas;
	size_t		pixel_count;

	canvas = malloc(sizeof(*canvas));
	if (!canvas)
		return (NULL);
	canvas->width = width;
	canvas->height = height;
	pixel_count = width * height;
	canvas->pixels = malloc(sizeof(t_color) * pixel_count);
	if (!canvas->pixels)
	{
		free(canvas);
		return (NULL);
	}
	ft_bzero(canvas->pixels, sizeof(t_color) * pixel_count);
	return (canvas);
}

void		canvas_destroy(t_canvas *c)
{
	free(c->pixels);
	free(c);
}

void	canvas_write_pixel(t_canvas *canvas, size_t x, size_t y,
	t_color *color)
{
	canvas->pixels[x * canvas->width + y] = *color;
}

/** Returns the address of the pixel at coordinates (x, y).
 * 
 * Doesn't do any bound checking.
*/
t_color		*canvas_pixel_at(t_canvas *canvas, size_t x, size_t y)
{
	return (canvas->pixels + canvas->width * x + y);
}