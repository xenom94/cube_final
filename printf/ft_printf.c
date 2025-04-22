/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:19:59 by iabboudi          #+#    #+#             */
/*   Updated: 2024/01/09 02:24:30 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		i;
	int		count;

	va_start(argp, format);
	i = 0;
	count = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && ft_strchr("csdiXxpu%", format[i + 1]))
		{
			count += ft_printarg(format[i + 1], argp);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(argp);
	return (count);
}
