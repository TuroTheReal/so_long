/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:41:01 by artberna          #+#    #+#             */
/*   Updated: 2024/08/28 10:25:18 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_arg(int ac, char**av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (ac == 2 && ft_strncmp(av[1] + (i - 4), ".ber", 5) == 0
		&& ft_strlen(av[1]) > 4)
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_m_data	*m_data;

	if (check_arg(ac, av) == TRUE)
	{
		m_data = malloc(sizeof(t_m_data));
		ft_memset(m_data, 0, sizeof(t_m_data));
		if (manage_input(&m_data, av[1]) == FALSE)
			return (free(m_data), -1);
		if (render_game(m_data) == FALSE)
		{
			ft_printf("Error : Cannot display map.\n");
			free_struct(m_data->map, m_data);
			return (-1);
		}
	}
	else
		ft_printf("Error : Invalid file.\n");
	return (0);
}
