/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:57:18 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/19 17:41:19 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *message)
{
	write(2, "Error\n", 7);
	write(2, message, ft_strlen(message) + 1);
	write(2, "\n", 2);
	exit(EXIT_FAILURE);
}
