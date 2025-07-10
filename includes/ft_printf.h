/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 04:19:58 by tle-dref          #+#    #+#             */
/*   Updated: 2024/11/12 19:49:51 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>

int		ft_printf(const char *format, ...);
int		select_ft(va_list args, char c);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_printhex(va_list args);
int		ft_lower_printhex(va_list args);
int		ft_upper_printhex(va_list args);
int		ft_putnbr(int n);
int		ft_putnbr_scam(va_list args);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbru_scam(va_list args);
int		ft_percent(va_list args);
void	ft_putchar_fd(char c, int fd);

// Printf_e functions (stderr versions)
int		ft_printf_e(const char *format, ...);
int		select_ft_e(va_list args, char c);
int		ft_putchar_e(va_list args);
int		ft_putstr_e(va_list args);
int		ft_printhex_e(va_list args);
int		ft_lower_printhex_e(va_list args);
int		ft_upper_printhex_e(va_list args);
int		ft_putnbr_e(int n);
int		ft_putnbr_scam_e(va_list args);
int		ft_putnbr_u_e(unsigned int n);
int		ft_putnbru_scam_e(va_list args);
int		ft_percent_e(va_list args);