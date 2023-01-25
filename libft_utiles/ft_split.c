/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:30:17 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/20 18:17:48 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != '\0' && s[i] != c)
		count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**new_s;
	int		i_word;
	int		i_char;
	int		start;

	i_char = 0;
	i_word = 0;
	if (!s)
		return (NULL);
	new_s = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!new_s)
		return (NULL);
	while (s[i_word] != '\0')
	{
		while (s[i_word] == c && s[i_word] != '\0')
			i_word++;
		start = i_word;
		while (s[i_word] != c && s[i_word] != '\0')
			i_word++;
		if (i_char < (word_count(s, c)))
			new_s[i_char++] = ft_substr(s, start, (i_word - start));
	}
	free(s);
	return (new_s);
}
