/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:18:58 by artberna          #+#    #+#             */
/*   Updated: 2024/08/27 11:03:18 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_pec_n_readable(t_m_data **m_data, char specif)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while ((*m_data)->map[++i])
	{
		j = -1;
		while ((*m_data)->map[i][++j])
		{
			if ((*m_data)->map[i][j] == specif)
				count++;
			if ((*m_data)->map[i][j] != 'P' && (*m_data)->map[i][j] != 'E' &&
				(*m_data)->map[i][j] != 'C' && (*m_data)->map[i][j] != '1' &&
				(*m_data)->map[i][j] != '0')
				return (ft_printf("Error : Caracter not readable.\n"), FALSE);
		}
	}
	if (count < 1 || (count > 1 && (specif == 'P' || specif == 'E')))
		return (ft_printf("Error : %d specifier %c.\n", count, specif), FALSE);
	if (specif == 'C')
		(*m_data)->count = count;
	return (TRUE);
}

static int	has_wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		if (map[i][0] != '1')
			return (ft_printf("Error : Missing wall.\n"), FALSE);
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return (ft_printf("Error : Missing wall.\n"), FALSE);
			j++;
		}
		if (map[i][j - 1] != '1')
			return (ft_printf("Error : Missing wall.\n"), FALSE);
	}
	j = -1;
	while (map[i - 1][++j])
	{
		if (map[i - 1][j] != '1')
			return (ft_printf("Error : Missing wall.\n"), FALSE);
	}
	return (TRUE);
}

static int	is_rectangular(t_m_data **m_data)
{
	size_t	i;

	i = 0;
	(*m_data)->columns = ft_strlen((*m_data)->map[i]);
	while ((*m_data)->map[i])
	{
		if (ft_strlen((*m_data)->map[i]) != (*m_data)->columns)
			return (ft_printf("Error : Length's line not similar.\n"), FALSE);
		i++;
	}
	(*m_data)->rows = i;
	if (i == (*m_data)->columns)
	{
		if (i == 0)
			return (ft_printf("Error : Map empty.\n"), FALSE);
		ft_printf("Error : Map not rectangular.\n");
		return (FALSE);
	}
	return (TRUE);
}

int	check_map(t_m_data **m_data)
{
	if (is_rectangular(m_data) == FALSE)
		return (FALSE);
	if (has_wall((*m_data)->map) == FALSE)
		return (FALSE);
	if (has_pec_n_readable(m_data, 'P') == FALSE)
		return (FALSE);
	if (has_pec_n_readable(m_data, 'E') == FALSE)
		return (FALSE);
	if (has_pec_n_readable(m_data, 'C') == FALSE)
		return (FALSE);
	if (is_accessible(m_data) == FALSE)
		return (ft_printf("Error : Map not playable.\n"), FALSE);
	if ((*m_data)->rows > 32 || (*m_data)->columns > 60)
		return (ft_printf("Error : Map too big.\n"), FALSE);
	return (TRUE);
}
