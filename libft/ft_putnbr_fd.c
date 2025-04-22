/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:02:12 by sisser            #+#    #+#             */
/*   Updated: 2023/12/24 21:38:38 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
		}
		else if (n >= 0 && n <= 9)
			ft_putchar_fd('0' + n, fd);
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
	}
}
