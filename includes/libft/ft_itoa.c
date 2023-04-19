/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:39:36 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:20 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long number)
{
	int	count;

	count = 0;
	if (number <= 0)
		count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static void	ft_add_digit(long number, char *string, int index)
{
	if (number < 0)
		string[index] = ((number % 10) * -1) + '0';
	else
		string[index] = (number % 10) + '0';
}

char	*ft_itoa(int n)
{
	long	nb;
	int		intlen;
	int		i;
	char	*string;

	nb = (long)n;
	intlen = ft_intlen(nb);
	string = malloc(intlen + 1 * sizeof(char));
	i = intlen;
	if (!string)
		return (NULL);
	string[i] = '\0';
	i--;
	while (i >= 0)
	{
		ft_add_digit(nb, string, i);
		nb /= 10;
		i--;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
