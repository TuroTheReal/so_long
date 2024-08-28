/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:51:52 by artberna          #+#    #+#             */
/*   Updated: 2024/08/27 11:20:49 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_tab(char **tab, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tab[i] = ft_strtrim(line, "\n");
		free(line);
		if (!tab[i])
		{
			free_double(tab);
			return ;
		}
		i++;
		line = get_next_line(fd);
	}
}

static char	**get_map(char *str)
{
	char	**map;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		return (NULL);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	map = ft_calloc(i + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		return (NULL);
	copy_tab(map, fd);
	return (close(fd), map);
}

static void	init_strk(t_m_data **m_data)
{
	(*m_data)->rows = 0;
	(*m_data)->columns = 0;
	(*m_data)->count = 0;
	(*m_data)->coups = 0;
	(*m_data)->map = NULL;
}

int	manage_input(t_m_data	**m_data, char *str)
{
	init_strk(m_data);
	(*m_data)->map = get_map(str);
	if (!(*m_data)->map)
		return (FALSE);
	if (check_map(m_data) == FALSE)
		return (free_double((*m_data)->map), FALSE);
	return (TRUE);
}
