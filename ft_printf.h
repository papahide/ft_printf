/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:10:01 by paapahid          #+#    #+#             */
/*   Updated: 2025/12/05 19:14:57 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *form, ...);
int	ft_putnbr_base(long nbr, int base, int upper);
int	ft_pointers(long nbr, int base, int upper);
int	ft_putstr(char *str);
int	ft_printc(int c);

#endif