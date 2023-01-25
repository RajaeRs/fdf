/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:10:14 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/24 00:37:03 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "[!] write just the pathe of the map\n", 36);
		return (0);
	}
	i = open(argv[1], O_RDONLY);
	if (argc == 2 && i == -1)
	{
		write(1, "not valid map -_-\n", 18);
		return (0);
	}
	close (i);
	draw(argv[1]);
	return (0);
}
