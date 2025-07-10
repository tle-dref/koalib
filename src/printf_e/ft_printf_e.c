/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:59:33 by tle-dref          #+#    #+#             */
/*   Updated: 2024/11/04 20:26:33 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	select_ft_e(va_list args, char c)
{
	static int	(*ft[256])(va_list args) = {
	['c'] = ft_putchar_e,
	['s'] = ft_putstr_e,
	['p'] = ft_printhex_e,
	['d'] = ft_putnbr_scam_e,
	['i'] = ft_putnbr_scam_e,
	['u'] = ft_putnbru_scam_e,
	['x'] = ft_lower_printhex_e,
	['X'] = ft_upper_printhex_e,
	['%'] = ft_percent_e,
	};

	if (ft[(unsigned char)c] == NULL)
		return (0);
	return (ft[(unsigned char)c](args));
}

int	ft_printf_e(const char *format, ...)
{
	va_list	args;
	int		res;

	res = 0;
	if (format == NULL)
		return (0);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			res += select_ft_e(args, *format);
		}
		else if (*format == '%' && !*(format + 1))
			break ;
		else
			res += write(2, format, 1);
		format++;
	}
	va_end(args);
	return (res);
}
