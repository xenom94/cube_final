/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:02:21 by sisser            #+#    #+#             */
/*   Updated: 2023/12/24 21:38:09 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_free(char **str, int n)
{
	while (n > 0)
	{
		free(str[--n]);
	}
	free(str);
	return (0);
}

static char	**do_split(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != '\0' && s[i] != c && j++ >= 0)
			i++;
		tab[n++] = ft_substr(s, i - j, j);
		if (!tab[n - 1])
			return (ft_free(tab, n));
	}
	tab[n] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_count((char *)s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (do_split(tab, s, c));
}
