#include "ppm.h"

#include <stdlib.h>

#include "canvas.h"
#include "color.h"
#include "libft.h"

static void	ppm_canvas_write_header(t_canvas *canvas, int fd)
{
	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(canvas->width, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(canvas->height, fd);
	ft_putstr_fd("\n", fd);
	ft_putendl_fd("255", fd);
}

void	ppm_canvas_write_pixel(t_color *pixel, int fd)
{
	int		colors[3];	
	size_t	i;

	colors[0] = pixel->red * 255 + 0.5;
	colors[1] = pixel->green * 255 + 0.5;
	colors[2] = pixel->blue * 255 + 0.5;
	i = 0;
	while (i < 3)
	{
		if (i > 0)
			ft_putstr_fd(" ", fd);
		if (colors[i] < 0)
			ft_putstr_fd("0", fd);
		else if (colors[i] > 255)
			ft_putstr_fd("255", fd);
		else
			ft_putnbr_fd(colors[i], fd);
		i++;
	}
}

void	ppm_canvas_write(t_canvas *canvas, int fd)
{
	size_t	i;

	ppm_canvas_write_header(canvas, fd);
	i = 0;
	while (i < canvas->width * canvas->height)
	{
		ppm_canvas_write_pixel(canvas->pixels + i, fd);
		if (i % 5 == 4)
			ft_putchar_fd('\n', fd);
		else
			ft_putchar_fd(' ', fd);
		i++;
	}
}