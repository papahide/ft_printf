/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:48:06 by paapahid          #+#    #+#             */
/*   Updated: 2025/12/03 21:55:44 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

int	ft_printc(int c)
{
	return(write(1, &c, 1));
}
int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return(6);
	}
	while (str[i])
	{
		ft_printc((int)str[i]);
		i++;
	}
	return(i);
}

int	ft_putnbr_base(long nbr, int base)
{
	int		size;
	char	*hex;
	
	hex = "0123456789abcdef";
	size = 0;
	if (nbr < 0)
	{
		size += write(1, "-", 1);
		return (ft_putnbr_base(-nbr, base));
	}
	if (nbr < base)
		return (ft_printc(hex[nbr]));
	else
	{
		size += ft_putnbr_base(nbr / base, base);
		return (size += ft_putnbr_base(nbr % base, base));
	}
}
