#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "canvas.h"

#include "color.h"

Test(Canvas, create_canvas)
{
	int			i;
	t_canvas	*canvas = canvas_create(10, 20);
	t_color		black;

	color_set(&black, 0, 0, 0);

	cr_assert(eq(i32, canvas->width, 10));
	cr_assert(eq(i32, canvas->height, 20));
	i = 0;
	while (i < 10 * 20)
	{
		cr_assert(color_eq(canvas->pixels + i, &black));
		i++;
	}

	canvas_destroy(canvas);
}

Test(Canvas, write_pixel)
{
	t_color		color;
	t_color		*result;
	t_canvas	*canvas = canvas_create(10, 20);

	color_set(&color, 1, 0, 0);

	canvas_write_pixel(canvas, 2, 3, &color);
	result = canvas_pixel_at(canvas, 2, 3);
	cr_assert(color_eq(result, &color));

	canvas_destroy(canvas);
}