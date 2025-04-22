/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:26:47 by iabboudi          #+#    #+#             */
/*   Updated: 2024/01/09 18:35:52 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_lowh(unsigned long nb)
{
	int		count;
	char	*s;

	count = 0;
	s = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_print_lowh(nb / 16);
		count += ft_putchar(s[nb % 16]);
	}
	if (nb < 16)
		count += ft_putchar(s[nb]);
	return (count);
}

int	ft_putaddress(void *ptr)
{
	unsigned long	num;
	int				count;

	count = 0;
	num = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_print_lowh(num);
	return (count);
}
