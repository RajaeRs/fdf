/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:42:28 by rrasezin          #+#    #+#             */
/*   Updated: 2022/10/08 13:17:59 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_bzero(void *src, size_t len)
{
	unsigned char	*dest;

	dest = (unsigned char *)src;
	while (len)
	{
		*dest = 0;
		dest++;
		len--;
	}
}
