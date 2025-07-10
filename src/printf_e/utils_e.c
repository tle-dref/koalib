/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 06:03:50 by tle-dref          #+#    #+#             */
/*   Updated: 2024/11/04 20:26:33 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_e(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(2, &c, 1);
	return (1);
}

int	ft_putstr_e(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		return (write(2, "(null)", 6));
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_percent_e(va_list args)
{
	(void)args;
	write(2, "%", 1);
	return (1);
}
