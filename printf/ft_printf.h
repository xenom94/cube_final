/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:24:54 by iabboudi          #+#    #+#             */
/*   Updated: 2024/01/09 02:30:47 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putaddress(void *ptr);
int	ft_putchar(char c);
int	ft_puthexalower(unsigned int nb);
int	ft_puthexaupper(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int n);
int	ft_printf(const char *format, ...);
int	ft_printarg(char format, va_list ap);

#endif