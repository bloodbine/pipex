/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:24:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/16 16:23:29 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdec(long int num, int *count)
{
	if (num < 0)
	{
		ft_putchar('-', count);
		if (*count == -1)
			return ;
		ft_putdec(num * -1, count);
		return ;
	}
	if (num > 9)
	{
		ft_putdec(num / 10, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(((num % 10) + '0'), count);
}

void	ft_putunsdec(unsigned int num, int *count)
{
	if (num > 9)
	{
		ft_putdec(num / 10, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(((num % 10) + '0'), count);
}
