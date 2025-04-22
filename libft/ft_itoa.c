/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:32:58 by sisser            #+#    #+#             */
/*   Updated: 2023/12/22 02:01:24 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(long num)
{
	int	i;

	i = 1;
	if (num < 0)
	{
		num = -num;
		i++;
	}
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;
	int		nb;

	nbr = n;
	nb = counter(n);
	str = (char *)malloc(nb + 1);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = nb - 1;
	while (i >= 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[nb] = '\0';
	return (str);
}
