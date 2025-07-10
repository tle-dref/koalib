/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:59:03 by tle-dref          #+#    #+#             */
/*   Updated: 2024/11/04 20:26:33 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_e(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		return (write(2, "-2147483648", 11));
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 2);
		n = -n;
		i++;
	}
	if (n > 9)
		i += ft_putnbr_e(n / 10);
	ft_putchar_fd((n % 10) + '0', 2);
	i++;
	return (i);
}

int	ft_putnbr_u_e(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putnbr_u_e(n / 10);
	ft_putchar_fd((n % 10) + '0', 2);
	i++;
	return (i);
}

int	ft_putnbru_scam_e(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_u_e(n));
}

int	ft_putnbr_scam_e(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (ft_putnbr_e(n));
}
