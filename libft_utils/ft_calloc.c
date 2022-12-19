/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:23:03 by rrasezin          #+#    #+#             */
/*   Updated: 2022/10/21 23:22:40 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*retval;
	size_t	t;

	t = count * size;
	retval = malloc(t);
	if (!retval)
		return (NULL);
	ft_bzero(retval, t);
	return (retval);
}
