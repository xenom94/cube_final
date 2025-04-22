/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:30:09 by sisser            #+#    #+#             */
/*   Updated: 2023/12/24 21:32:47 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[len] && len < dstsize - 1)
	{
		dst[len] = src[len];
		len++;
	}
	if (len < dstsize)
	{
		dst[len] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}
