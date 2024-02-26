#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 400, "UNDRETALE");
	(void)win;
	mlx_loop(mlx);
}
