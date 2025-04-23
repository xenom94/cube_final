/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:33 by iabboudi          #+#    #+#             */
/*   Updated: 2025/04/23 11:41:44 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_left(char *result)
{
	int		i;
	char	*str;

	i = 0;
	if (!result || !result[i])
		return (NULL);
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	str = malloc (sizeof(char) * (i + 1 + (result[i] == '\n')));
	if (!str)
		return (NULL);
	i = 0;
	while (result[i] != '\0' && result[i] != '\n')
	{
		str[i] = result[i];
		i++;
	}
	if (result[i] == '\n')
	{
		str[i] = result[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_right(char *result)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(result) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (result[i] != '\0')
		str[j++] = result[i++];
	str[j] = '\0';
	free(result);
	return (str);
}

static char	*read_until_newline(char *str, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	while (ft_strchr1(str, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin1(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	result = read_until_newline(result, fd);
	if (!result)
	{
		return (NULL);
	}
	line = read_left(result);
	result = read_right(result);
	return (line);
}
