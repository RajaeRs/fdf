/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:43:05 by rrasezin          #+#    #+#             */
/*   Updated: 2022/10/08 18:56:58 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_n;

	i = 0;
	len_n = ft_strlen(needle);
	if (!haystack && len == 0)
		return (0);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == *needle && len_n <= (len - i))
		{
			if (ft_strncmp(haystack + i, needle, len_n) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
