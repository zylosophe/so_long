#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	*mlx;
void	*win;
void	*img[4];
int		i;

int	on_expose(void)
{
	printf("expose\n");
	mlx_put_image_to_window(mlx, win, img[i], 0, 0);
	return (0);
}

int on_loop(void)
{
	printf("loop\n");
	i++;
	if (i >= 4)
		i = 0;
	return (0);
}

int	on_close(void)
{
	printf("close window\n");
	mlx_destroy_window(mlx, win);
	return (0);
}

int	main(void)
{
	int		w;
	int		h;

	w = 150;
	h = 150;
	(void)img;(void)win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 400, "UNDRETALE");
	img[0] = mlx_xpm_file_to_image(mlx, "assets/object/snas/down.xpm", &w, &h);
	img[1] = mlx_xpm_file_to_image(mlx, "assets/object/snas/left.xpm", &w, &h);
	img[2] = mlx_xpm_file_to_image(mlx, "assets/object/snas/up.xpm", &w, &h);
	img[3] = mlx_xpm_file_to_image(mlx, "assets/object/snas/right.xpm", &w, &h);
	i = 0;
	printf("%i %i\n", w, h);
	mlx_expose_hook(win, on_expose, NULL);
	mlx_loop_hook(win, on_loop, NULL);
	mlx_hook(win, 17, 1L << 0, on_close, NULL);
	mlx_loop(mlx);
}
