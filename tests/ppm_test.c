#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "ppm.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "canvas.h"

static char	*pipe_to_str(int fd, size_t maxlen)
{
	char	*s;
	size_t	i;

	s = malloc(sizeof(*s) * maxlen);
	i = 0;
	while (read(fd, s + i, 1) == 1)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (s);
}

Test(PPM, canvas_to_ppm)
{
	t_canvas	*canvas;
	t_color		color;
	int			_pipe[2];
	char		*result;
	static char *expected =
		"P3\n"
		"10 2\n"
		"255\n"
		"255 0 0 0 128 0 0 0 255 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n";
	
	pipe(_pipe);

	canvas = canvas_create(10, 2);
	color_set(&color, 1.5, 0, 0);
	canvas_write_pixel(canvas, 0, 0, &color);
	color_set(&color, 0, 0.5, 0);
	canvas_write_pixel(canvas, 0, 1, &color);
	color_set(&color, -0.5, 0, 1);
	canvas_write_pixel(canvas, 0, 2, &color);

	ppm_canvas_write(canvas, _pipe[1]);
	write(_pipe[1], "", 1);

	result = pipe_to_str(_pipe[0], 4096);
	close(_pipe[0]);
	close(_pipe[1]);

	cr_assert(eq(str, result, expected));

	canvas_destroy(canvas);
	free(result);
}