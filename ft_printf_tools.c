/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:48:06 by paapahid          #+#    #+#             */
/*   Updated: 2025/12/05 19:24:58 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_printc((int)str[i]);
		i++;
	}
	return (i);
}

int	ft_pointers(long nbr, int base, int upper)
{
	int				size;
	unsigned long	lnbr;

	size = 0;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	else if (nbr == LONG_MIN)
		return (write(1, "0x8000000000000000", 18));
	else if (nbr == LONG_MAX)
		return (write(1, "0x7fffffffffffffff", 18));
	else
	{
		lnbr = (unsigned long)nbr;
		if (lnbr == ULONG_MAX)
			return (write(1, "0xffffffffffffffff", 18));
		else if (lnbr == -ULONG_MAX)
			return (write(1, "0x1", 3));
	}
	size += write(1, "0x", 2);
	size += ft_putnbr_base(nbr, base, upper);
	return (size);
}

int	ft_putnbr_base(long nbr, int base, int upper)
{
	int		size;
	char	*hex;
	char	*hex_lo;
	char	*hex_up;

	hex_lo = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	hex = hex_lo;
	if (upper)
		hex = hex_up;
	size = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr_base(-nbr, base, upper) + 1);
	}
	if (nbr < base)
		return (ft_printc(hex[nbr]));
	else
	{
		size += ft_putnbr_base(nbr / base, base, upper);
		return (size += ft_putnbr_base(nbr % base, base, upper));
	}
}
