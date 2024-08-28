/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:41:04 by artberna          #+#    #+#             */
/*   Updated: 2024/06/20 09:58:15 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str || str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	int	i;
	char	*str;

	str = "hello mon GARS";
	i = ft_strlen(str);
	printf("%d\n", i);
}
*/
