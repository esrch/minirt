#ifndef FT_MLX
# define FT_MLX

# include "color.h"
# include "mlx.h"
# include <stdlib.h>

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
}	t_mlx_img;

typedef struct s_ft_mlx
{
	void		*mlx;
	void		*win;
	size_t		width;
	size_t		height;
	t_mlx_img	img;
}	t_ft_mlx;

t_ft_mlx	*ft_mlx_init(t_ft_mlx *mlx, size_t width, size_t height);
void		ft_mlx_start(t_ft_mlx *mlx);
void		ft_mlx_update(t_ft_mlx *mlx);
void		ft_mlx_clear(t_ft_mlx *mlx);
void		ft_mlx_put_px(t_ft_mlx *mlx, size_t x, size_t y,
				unsigned int color);

#endif