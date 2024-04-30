#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "color.h"
#include "canvas.h"
#include "ppm.h"

int main(void)
{
	size_t		w = 50;
	size_t		h = 50;
	t_canvas	*canvas = canvas_create(w, h);
	size_t		i;
	t_color		*red = color_create(1, 0, 0);
	int			fd;

	i = 0;
	while (i < w * h)
	{
		canvas_write_pixel(canvas, i / canvas->width, i % canvas->width, red);
		i++;
	}
	fd = open("img.ppm", O_CREAT | O_WRONLY, 0644);
	if (fd > 0)
	{
		ppm_canvas_write(canvas, fd);
		close(fd);
	}
	else
		printf("Error opening the file.\n");
	canvas_destroy(canvas);
	color_destroy(red);
}