/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:06:08 by artberna          #+#    #+#             */
/*   Updated: 2024/08/27 10:46:27 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move(int keysym, t_m_data *m_data)
{
	if ((m_data->pos_x > 0 && m_data->pos_x < (int)m_data->columns) || \
		(m_data->pos_y > 0 && m_data->pos_y < (int)m_data->rows))
	{
		if (keysym == XK_w && m_data->map \
			[m_data->pos_y - 1][m_data->pos_x] != '1')
			m_data->pos_y--;
		else if (keysym == XK_s && m_data->map \
			[m_data->pos_y + 1][m_data->pos_x] != '1')
			m_data->pos_y++;
		else if (keysym == XK_a && m_data->map \
			[m_data->pos_y][m_data->pos_x - 1] != '1')
			m_data->pos_x--;
		else if (keysym == XK_d && m_data->map \
			[m_data->pos_y][m_data->pos_x + 1] != '1')
			m_data->pos_x++;
		return (1);
	}
	return (0);
}

static void	count_move(int keysym, t_m_data *m_data)
{
	if ((m_data->pos_x > 0 && m_data->pos_x < (int)m_data->columns) || \
		(m_data->pos_y > 0 && m_data->pos_y < (int)m_data->rows))
	{
		if (keysym == XK_w && m_data->map \
			[m_data->pos_y - 1][m_data->pos_x] != '1')
			ft_printf("Count = %d\n", ++m_data->coups);
		else if (keysym == XK_s && m_data->map \
			[m_data->pos_y + 1][m_data->pos_x] != '1')
			ft_printf("Count = %d\n", ++m_data->coups);
		else if (keysym == XK_a && m_data->map \
			[m_data->pos_y][m_data->pos_x - 1] != '1')
			ft_printf("Count = %d\n", ++m_data->coups);
		else if (keysym == XK_d && m_data->map \
			[m_data->pos_y][m_data->pos_x + 1] != '1')
			ft_printf("Count = %d\n", ++m_data->coups);
	}
	return ;
}

int	handle_input(int keysym, t_m_data *m_data)
{
	if (keysym == XK_Escape)
		close_game(m_data);
	else
	{
		count_move(keysym, m_data);
		move(keysym, m_data);
		render_sprites(m_data);
	}
	return (0);
}
