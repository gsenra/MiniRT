/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:23:52 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 19:35:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void			rt_window(t_rt *rt)
{
	t_mlx	mlx;
	int		max_x;
	int		max_y;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx.mlx = mlx_init();
	mlx_get_screen_size(mlx.mlx, &max_x, &max_y);
	if (rt->reso.width > max_x)
		rt->reso.width = max_x;
	if (rt->reso.height > max_y)
		rt->reso.height = max_y;
	if (rt->reso.width < 1 || rt->reso.height < 1)
		errormsg(3);
	mlx.win = mlx_new_window(mlx.mlx, rt->reso.width,
	rt->reso.height, "MiniRT");
	mlx.img = mlx_new_image(mlx.mlx, rt->reso.width, rt->reso.height);
	mlx.address = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_leng, &mlx.endian);
	while (y <= rt->reso.height)
	{
		x = 0;
		while (x <= rt->reso.width)
		{
			ft_pixelput(&mlx, x, y, create_trgb(0, rt->ambi.color.r,
			rt->ambi.color.g, rt->ambi.color.b));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free_lists(rt);
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}
