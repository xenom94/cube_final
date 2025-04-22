/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:35:52 by sisser            #+#    #+#             */
/*   Updated: 2023/12/23 03:54:29 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	length;
	int	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length) + 1);
	if (!str)
		return (NULL);
	while (i < length)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
