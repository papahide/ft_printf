/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:10:01 by paapahid          #+#    #+#             */
/*   Updated: 2025/12/03 21:20:56 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

int	ft_printf(const char *form, ...);
int	ft_putnbr_base(long nbr, int base);
int	ft_putstr(char *str);
int	ft_printc(int c);
int	ft_toupper(int c);
int	ft_putnbr_base(long nbr, int base);
int	ft_putnbr_base_up(long nbr, int base);

#endif