/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:22 by iabboudi          #+#    #+#             */
/*   Updated: 2025/04/22 20:17:40 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strchr1(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin1(char *result, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!result)
	{
		result = (char *)malloc(1 * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
	}
	if (!result || !buffer)
		return (NULL);
	line = malloc(ft_strlen(result) + ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	i = -1;
	j = 0;
	while (result[++i] != '\0')
		line[i] = result[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[ft_strlen(result) + ft_strlen(buffer)] = '\0';
	free(result);
	return (line);
}
