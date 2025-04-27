/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:38:14 by tleister          #+#    #+#             */
/*   Updated: 2025/04/25 22:39:34 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vect	ft_movecam(t_vect pos, t_vect dir)
{
	t_vect	temp;

	temp.x = dir.x;
	temp.y = 0;
	temp.z = dir.z;
	return (ft_vectadd(pos, ft_vectmult(ft_vectnorm(temp), MOVE_SPEED)));
}

void	ft_keyfunc(void *param)
{
	t_data	*d;
	bool	change;

	change = false;
	d = (t_data *)param;
	if (mlx_is_key_down(d->mlx, MLX_KEY_UP))
	{
		d->cam.pos = ft_movecam(d->cam.pos, d->cam.vec);
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_DOWN))
	{
		d->cam.pos = ft_movecam(d->cam.pos, ft_vectmult(d->cam.vec, -1));
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT))
	{
		d->cam.pos = ft_movecam(d->cam.pos, ft_vectrot(d->cam.vec, PI_2, 'y'));
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT))
	{
		d->cam.pos = ft_movecam(d->cam.pos, ft_vectrot(d->cam.vec, -PI_2, 'y'));
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_W))
	{
		d->cam.pos.y += 0.1;
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_S))
	{
		d->cam.pos.y -= 0.1;
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_A))
	{
		d->cam.vec = ft_vectrot(d->cam.vec, PI / 25, 'y');
		change = 1;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_D))
	{
		d->cam.vec = ft_vectrot(d->cam.vec, -PI / 25, 'y');
		change = 1;
	}
	if (change)
		ft_render(d);
}

void	esc(mlx_key_data_t keydata, void *param)
{
	t_data	*d;

	d = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(d->mlx);
}
