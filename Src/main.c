/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:17:06 by marvin            #+#    #+#             */
/*   Updated: 2023/09/21 17:17:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	initialize_game(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->mlx = mlx_init(game->mline, game->mcolumn, "so_long", false);
	if (!(game->mlx))
		return (FALSE);
	obt_textures(game);
	obt_image(game);
	show_map(game, game->img);
	mlx_key_hook(game->mlx, &keys_and_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	freemap(game->map);
	free(game->textu);
	free(game->img);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nIncorrect number of parameters\n"), FALSE);
	if (check_map_name(argv[1]) == FALSE)
		return (ft_printf("Error\nInvalid file extension\n"), FALSE);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	if (map_checker(game.map) == FALSE)
		return (freemap(game.map), FALSE);
	map_size(&game, game.map);
	if (path_is_valid(&game, argv[1]) == FALSE)
		return (freemap(game.map), 1);
	if (initialize_game(&game) == FALSE)
		return (FALSE);
	return (TRUE);
}