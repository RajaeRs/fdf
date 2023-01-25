/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:17:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/20 23:17:13 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	poww(int num, int pow)
{
	int	tmp;

	tmp = num;
	if (pow == 0)
		return (1);
	while (pow - 1)
	{
		num = tmp * num;
		pow--;
	}
	return (num);
}

int	hex_to_int(const char *hex_str)
{
	int	color;
	int	tmp;
	int	size;
	int	i;

	color = 0;
	i = 0;
	if (hex_str == NULL)
		return (16777215);
	hex_str = hex_str + 2;
	size = ft_strlen(hex_str) - 1;
	while (size + 1)
	{
		if (hex_str[size] >= 'a' && hex_str[size] <= 'f')
			tmp = hex_str[size] - 87;
		else if (hex_str[size] >= 'A' && hex_str[size] <= 'F')
			tmp = hex_str[size] - 55;
		else
			tmp = hex_str[size] - '0';
		color = color + tmp * poww(16, i);
		size--;
		i++;
	}
	return (color);
}
