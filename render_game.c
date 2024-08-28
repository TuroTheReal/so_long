/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:03:12 by artberna          #+#    #+#             */
/*   Updated: 2024/08/27 11:18:20 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_player(t_m_data *m_data)
{
	to_img(m_data, m_data->player_start, m_data->pos_x, m_data->pos_y);
	if (m_data->map[m_data->pos_y][m_data->pos_x] == 'C')
	{
		m_data->map[m_data->pos_y][m_data->pos_x] = '0';
		m_data->count--;
	}
}

static void	render_clctb(t_m_data *m_data)
{
	int	i;
	int	j;

	i = 0;
	while (m_data->map[i] != NULL)
	{
		j = 0;
		while (m_data->map[i][j] != '\0')
		{
			if (m_data->map[i][j] == 'C')
				to_img(m_data, m_data->collect, j, i);
			j++;
		}
		i++;
	}
}

static void	render_bwe(t_m_data *m_data)
{
	int	i;
	int	j;

	i = 0;
	while (m_data->map[i] != NULL)
	{
		j = 0;
		while (m_data->map[i][j] != '\0')
		{
			to_img(m_data, m_data->bground, j, i);
			if (m_data->map[i][j] == 'E')
				to_img(m_data, m_data->exit, j, i);
			if (m_data->map[i][j] == '1')
				to_img(m_data, m_data->wall, j, i);
			j++;
		}
		i++;
	}
}

int	render_sprites(t_m_data *m_data)
{
	render_bwe(m_data);
	render_clctb(m_data);
	render_player(m_data);
	if (m_data->map[m_data->pos_y][m_data->pos_x] == 'E' \
		&& m_data->count == 0)
	{
		ft_printf("You win!\n");
		return (close_game(m_data), 0);
	}
	return (0);
}

int	render_game(t_m_data *m_data)
{
	m_data->mlx_ptr = mlx_init();
	if (!m_data->mlx_ptr)
		return (FALSE);
	init_sprites(m_data);
	m_data->mlx_win = mlx_new_window(m_data->mlx_ptr, \
	m_data->columns * WIDTH, m_data->rows * HEIGHT, "so_long");
	if (!m_data->mlx_win)
		return (mlx_destroy_display(m_data->mlx_ptr), FALSE);
	mlx_loop_hook(m_data->mlx_ptr, render_sprites, m_data);
	mlx_key_hook(m_data->mlx_win, handle_input, m_data);
	mlx_hook(m_data->mlx_win, 17, 0, close_game, m_data);
	mlx_loop(m_data->mlx_ptr);
	close_game(m_data);
	return (TRUE);
}
