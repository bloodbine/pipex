/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:07:55 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/17 12:28:59 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
//character type
int		ft_putchar(char ch, int *count);
int		ft_putstr(char *str, int *count);
//decimal type
void	ft_putdec(long int num, int *count);
void	ft_putunsdec(unsigned int num, int *count);
//hexadecimal type
void	ft_putlhex(unsigned int num, int *count);
void	ft_putuhex(unsigned int num, int *count);
int		ft_putptr(unsigned long long ptr, int ptrcount, int *count);

#endif
