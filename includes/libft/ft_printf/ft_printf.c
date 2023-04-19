/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:50:12 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/16 16:52:11 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_params(const char ch, va_list argsp, int *count)
{
	if (ch == 'c')
		ft_putchar(va_arg(argsp, int), count);
	else if (ch == 's')
		ft_putstr(va_arg(argsp, char *), count);
	else if (ch == 'd' || ch == 'i')
		ft_putdec(va_arg(argsp, int), count);
	else if (ch == 'u')
		ft_putunsdec(va_arg(argsp, unsigned int), count);
	else if (ch == 'x')
		ft_putlhex(va_arg(argsp, unsigned int), count);
	else if (ch == 'X')
		ft_putuhex(va_arg(argsp, unsigned int), count);
	else if (ch == 'p')
		ft_putptr(va_arg(argsp, unsigned long long), 0, count);
	else if (ch == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *str, ...)
{
	va_list	argsp;
	int		count;
	int		i;

	i = -1;
	count = 0;
	va_start(argsp, str);
	while (str[++i])
	{
		if (str[i] == '%')
			ft_check_params(str[++i], argsp, &count);
		else
			ft_putchar(str[i], &count);
		if (count < 0)
			return (va_end(argsp), -1);
	}
	return (va_end(argsp), count);
}
