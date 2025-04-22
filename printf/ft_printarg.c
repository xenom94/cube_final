/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:16:24 by iabboudi          #+#    #+#             */
/*   Updated: 2024/01/09 02:25:41 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_putchar('%');
	else if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'x')
		count += ft_puthexalower(va_arg(ap, unsigned int));
	else if (format == 'X')
		count += ft_puthexaupper(va_arg(ap, unsigned int));
	else if (format == 'p')
		count += ft_putaddress(va_arg(ap, void *));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	return (count);
}
