/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:26:50 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/16 16:48:24 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlhex(unsigned int num, int *count)
{
	if (num > 16)
	{
		ft_putlhex(num / 16, count);
		if (*count == -1)
			return ;
	}
	if (num == 16)
		ft_putstr("10", count);
	else if (num % 16 < 10)
		ft_putchar(((num % 16) + '0'), count);
	else
		ft_putchar(((num % 16) - 10 + 'a'), count);
}

void	ft_putuhex(unsigned int num, int *count)
{
	if (num > 16)
	{
		ft_putuhex(num / 16, count);
		if (*count == -1)
			return ;
	}
	if (num == 16)
		ft_putstr("10", count);
	else if (num % 16 < 10)
		ft_putchar((num % 16) + '0', count);
	else
		count += ft_putchar(((num % 16) - 10 + 'A'), count);
}

int	ft_putptr(unsigned long long ptr, int ptrcount, int *count)
{
	if (ptr > 16)
		ptrcount += ft_putptr(ptr / 16, ptrcount, count);
	if ((ptr / 16 == 0 || ptr % 16 == 0) && ptrcount == 0)
		ptrcount += ft_putstr("0x", count);
	if (*count == -1)
		return (-1);
	if (ptr == 16)
		ptrcount += ft_putstr("10", count);
	else if (ptr % 16 < 10)
		ptrcount += ft_putchar(((ptr % 16) + '0'), count);
	else
		ptrcount += ft_putchar(((ptr % 16) - 10 + 'a'), count);
	if (*count == -1)
		return (-1);
	return (ptrcount);
}
