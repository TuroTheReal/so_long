/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accesible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:23:26 by artberna          #+#    #+#             */
/*   Updated: 2024/08/27 11:20:34 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_fill(t_m_data *m_data, size_t i, size_t j)
{
	if (i < 0 || j < 0 || i >= m_data->rows
		|| j >= m_data->columns || m_data->map[i][j] == '1'
		|| m_data->map[i][j] == '.')
		return (10);
	if (m_data->map[i][j] == 'E' || m_data->map[i][j] == 'C')
		m_data->count--;
	if (m_data->map[i][j] != 'P')
		m_data->map[i][j] = '.';
	flood_fill(m_data, i + 1, j);
	flood_fill(m_data, i - 1, j);
	flood_fill(m_data, i, j + 1);
	flood_fill(m_data, i, j - 1);
	if (m_data->count != 0)
		return (FALSE);
	return (TRUE);
}

static char	**copy_map(t_m_data *m_data)
{
	char	**tmp_map;
	size_t	i;
	size_t	j;

	i = 0;
	tmp_map = ft_calloc(sizeof(char *), m_data->rows + 1);
	if (!tmp_map)
		return (NULL);
	while (i < m_data->rows)
	{
		tmp_map[i] = malloc(m_data->columns + 1);
		if (!tmp_map[i])
			return (free_double(tmp_map), NULL);
		j = 0;
		while (m_data->map[i][j])
		{
			tmp_map[i][j] = m_data->map[i][j];
			j++;
		}
		tmp_map[i][j] = '\0';
		i++;
	}
	return (tmp_map);
}

static t_m_data	*copy_m_data(t_m_data *m_data)
{
	t_m_data	*tmp;

	if (!m_data)
		return (NULL);
	tmp = malloc(sizeof(t_m_data));
	if (!tmp)
		return (NULL);
	tmp->rows = m_data->rows;
	tmp->columns = m_data->columns;
	tmp->count = m_data->count + 1;
	tmp->map = copy_map(m_data);
	if (!tmp->map)
		return (free(tmp), NULL);
	return (tmp);
}

int	is_accessible(t_m_data **m_data)
{
	t_m_data	*tmp_m_data;
	size_t		i;
	size_t		j;

	i = -1;
	tmp_m_data = copy_m_data(*m_data);
	while ((*m_data)->map[++i])
	{
		j = -1;
		while ((*m_data)->map[i][++j])
		{
			if ((*m_data)->map[i][j] == 'P')
			{
				(*m_data)->pos_y = i;
				(*m_data)->pos_x = j;
				break ;
			}
		}
		if ((*m_data)->map[i][j] == 'P')
			break ;
	}
	if (flood_fill(tmp_m_data, i, j) == FALSE)
		return (free_struct(tmp_m_data->map, tmp_m_data), FALSE);
	free_struct(tmp_m_data->map, tmp_m_data);
	return (TRUE);
}
