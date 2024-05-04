#include "ft_mlx.h"
#include "color.h"

t_ft_mlx	*ft_mlx_init(t_ft_mlx *mlx, size_t width, size_t height)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, "MiniRT");
	mlx->width = width;
	mlx->height = height;
	mlx->img.img = mlx_new_image(mlx->mlx, width, height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_px,
		&mlx->img.line_len, &mlx->img.endian);
	return (mlx);
}

void	ft_mlx_start(t_ft_mlx *mlx)
{
	mlx_loop(mlx->mlx);
}

void		ft_mlx_update(t_ft_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

void	ft_mlx_clear(t_ft_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

void	ft_mlx_put_px(t_ft_mlx *mlx, size_t x, size_t y, unsigned int color)
{
	char	*dst;

	if (x >= mlx->width || y >= mlx->height)
		return ;
	dst = mlx->img.addr + (y * mlx->img.line_len + x * (mlx->img.bits_per_px / 8));
	*(unsigned int *)dst = color;
}