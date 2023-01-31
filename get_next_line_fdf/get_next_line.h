/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:06:51 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/20 20:42:50 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd, int buffer_size);
void	*ft_calloc_g(size_t count, size_t size);
char	*ft_strchr_g(const char *s, int c);
char	*ft_strjoin_g(char *s1, char *s2);
size_t	ft_strlen_g(const char *src);

#endif