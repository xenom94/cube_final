/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:37:39 by sisser            #+#    #+#             */
/*   Updated: 2023/12/24 21:33:35 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (s == d)
		return (dst);
	if (d < s)
		ft_memcpy(d, s, len);
	else
	{
		d += len;
		s += len;
		while (len > 0)
		{
			d--;
			s--;
			*d = *s;
			len--;
		}
	}
	return (dst);
}
