#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "color.h"
#include "canvas.h"
#include "ft_mlx.h"
#include "libft.h"
#include "ppm.h"

void	draw_rectangle(t_ft_mlx *mlx)
{
	static int i = 0;
	static unsigned int colors[] = {0x00FF0000, 0x0000FF00, 0x000000FF};

	unsigned int color = colors[i];
	i = (i + 1) % 3;
	for (size_t i = 0; i < 100; ++i)
		for (size_t j = 0; j < 50; ++j)
			ft_mlx_put_px(mlx, i, j, color);
}

int	handle_key_press(int keycode, t_ft_mlx *mlx)
{
	t_color	green;

	(void) keycode;
	color_set(&green, 0, 1, 0);
	draw_rectangle(mlx);
	ft_mlx_update(mlx);
	return (0);
}

int main(void)
{
	t_color		blue;
	t_ft_mlx	mlx;

	color_set(&blue, 0, 0, 1);
	ft_mlx_init(&mlx, 800, 600);
	
	draw_rectangle(&mlx);
	
	ft_mlx_update(&mlx);

	mlx_hook(mlx.win, 2, 1L<<0, handle_key_press, &mlx);

	ft_mlx_start(&mlx);
}