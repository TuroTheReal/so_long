/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:41:42 by artberna          #+#    #+#             */
/*   Updated: 2024/08/28 10:29:44 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_game_with_error(t_m_data *m_data, char *message)
{
	ft_printf("%s\n", message);
	close_game(m_data);
}

static void	init_img(t_m_data *m_data)
{
	m_data->bground = mlx_xpm_file_to_image (m_data->mlx_ptr, \
	m_data->path_bground, &(m_data->img_width), &(m_data->img_height));
	if (!m_data->bground)
		close_game_with_error(m_data, "Cannot load sprites.\n");
	m_data->wall = mlx_xpm_file_to_image (m_data->mlx_ptr, \
	m_data->path_wall, &(m_data->img_width), &(m_data->img_height));
	if (!m_data->wall)
		close_game_with_error(m_data, "Cannot load sprites.\n");
	m_data->player_start = mlx_xpm_file_to_image (m_data->mlx_ptr, \
	m_data->path_player_start, &(m_data->img_width), &(m_data->img_height));
	if (!m_data->player_start)
		close_game_with_error(m_data, "Cannot load sprites.\n");
	m_data->collect = mlx_xpm_file_to_image (m_data->mlx_ptr, \
	m_data->path_collect, &(m_data->img_width), &(m_data->img_height));
	if (!m_data->collect)
		close_game_with_error(m_data, "Cannot load sprites.\n");
	m_data->exit = mlx_xpm_file_to_image (m_data->mlx_ptr, \
	m_data->path_exit, &(m_data->img_width), &(m_data->img_height));
	if (!m_data->exit)
		close_game_with_error(m_data, "Cannot load sprites.\n");
}

static void	init_path(t_m_data *m_data)
{
	m_data->img_height = 32;
	m_data->img_width = 32;
	m_data->path_bground = "./rsrcs/bg.xpm";
	m_data->path_wall = "./rsrcs/wall.xpm";
	m_data->path_player_start = "./rsrcs/p_start.xpm";
	m_data->path_collect = "./rsrcs/clctbl.xpm";
	m_data->path_exit = "./rsrcs/exit.xpm";
}

void	init_sprites(t_m_data *m_data)
{
	init_path(m_data);
	init_img(m_data);
}
