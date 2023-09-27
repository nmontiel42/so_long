/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:16:54 by marvin            #+#    #+#             */
/*   Updated: 2023/09/21 17:16:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/so_long.h"

int	map_empty(char **map)
{
	if (map[0])
		return (TRUE);
	return (FALSE);
}

int	map_rect(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	map_components(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == '1' || map[i][o] == '0' || map[i][o] == 'P'
				|| map[i][o] == 'E' || map[i][o] == 'C'))
				return (FALSE);
			else
				o++;
		}
		i++;
	}
	return (TRUE);
}

int	map_wall_is_closed(char **map)
{
	size_t	i;
	size_t	o;
	size_t	len;

	len = 0;
	while (map[len])
		len++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[len - 1][i] != '1')
			return (FALSE);
		i++;
	}
	o = 0;
	while (i < (len - 1))
	{
		if (map[o][0] != '1' || map[ft_strlen(map[0])][0] != '1')
			return (FALSE);
		o++;
	}
	return (TRUE);
}

int	map_checker(char **map)
{
	if (map_empty(map) == FALSE)
		return (ft_printf("Error\nThe map is empty\n"), 1);
	if (map_rect(map) == FALSE)
		return (ft_printf("Error\nThe map is not rectangle\n"), 1);
	if (map_components(map) == FALSE)
		return (ft_printf("Error\nThe map has the wrong components\n"), 1);
	if (map_wall_is_closed(map) == FALSE)
		return (ft_printf("Error\nThe wall is not closed\n"), 1);
	if (map_min_tiles(map) == FALSE)
		return (ft_printf("Error\nYou dont have the correct components\n"),
			1);
	return (TRUE);
}
