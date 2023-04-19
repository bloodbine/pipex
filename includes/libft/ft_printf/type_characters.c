/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:34:23 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/16 15:25:57 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch, int *count)
{
	int	status;

	status = 0;
	status += write(1, &ch, 1);
	if (status == -1)
		*count = -1;
	else
		*count += status;
	return (status);
}

int	ft_putstr(char *str, int *count)
{
	int	i;

	i = -1;
	if (!str)
	{
		i += ft_putstr("(null)", count);
		return (i);
	}
	while (str[++i])
	{
		ft_putchar(str[i], count);
		if (*count == -1)
			return (-1);
	}
	return (i);
}
