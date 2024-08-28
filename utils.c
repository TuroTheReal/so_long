/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:17:55 by artberna          #+#    #+#             */
/*   Updated: 2024/08/28 10:20:33 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**free_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

void	free_struct(char **tab, void *content)
{
	free_double(tab);
	free(content);
}

void	destroy_all_img(t_m_data *m_data)
{
	if (m_data->bground != NULL)
		mlx_destroy_image(m_data->mlx_ptr, m_data->bground);
	if (m_data->wall != NULL)
		mlx_destroy_image(m_data->mlx_ptr, m_data->wall);
	if (m_data->player_start != NULL)
		mlx_destroy_image(m_data->mlx_ptr, m_data->player_start);
	if (m_data->exit != NULL)
		mlx_destroy_image(m_data->mlx_ptr, m_data->exit);
	if (m_data->collect != NULL)
		mlx_destroy_image(m_data->mlx_ptr, m_data->collect);
}

int	close_game(t_m_data *m_data)
{
	int	i;

	i = -1;
	if (m_data->map != NULL)
	{
		free_double(m_data->map);
		destroy_all_img(m_data);
	}
	if (m_data->mlx_win != NULL)
		mlx_destroy_window(m_data->mlx_ptr, m_data->mlx_win);
	if (m_data->mlx_ptr != NULL)
	{
		mlx_destroy_display(m_data->mlx_ptr);
		free(m_data->mlx_ptr);
	}
	free(m_data);
	exit (0);
}

void	to_img(t_m_data *m_data, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(m_data->mlx_ptr, m_data->mlx_win, \
		img, m_data->img_width * x, m_data->img_height * y);
}
