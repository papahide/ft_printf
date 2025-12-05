/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:10:01 by paapahid          #+#    #+#             */
/*   Updated: 2025/12/05 19:19:50 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(unsigned char spec, va_list ap)
{
	int	size;

	size = 0;
	if (spec == 'c')
		size += ft_printc(va_arg(ap, int));
	else if (spec == 's')
		size += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		size += ft_pointers((va_arg(ap, unsigned long)), 16, 0);
	else if (spec == 'd' || spec == 'i')
		size += ft_putnbr_base(((long)va_arg(ap, int)), 10, 0);
	else if (spec == 'u')
		size += ft_putnbr_base(((long)va_arg(ap, unsigned int)), 10, 0);
	else if (spec == 'x')
		size += ft_putnbr_base(((long)va_arg(ap, unsigned int)), 16, 0);
	else if (spec == 'X')
		size += ft_putnbr_base(((long)va_arg(ap, unsigned int)), 16, 1);
	else if (spec == '%' && (spec + 1) == '%')
		size += write(1, "%%", 1);
	else
		size += write(1, &spec, 1);
	return (size);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	int		size;
	va_list	ap;

	i = 0;
	size = 0;
	va_start(ap, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			size += ft_format(form[++i], ap);
		}
		else
			size += write(1, &form[i], 1);
		i++;
	}
	va_end(ap);
	return (size);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main(void)
// {
//     // char    c = 'A';
//     // char    *s = "Hola, mundo";
//     // void    *p = s;
//     // int     d = -1;
//     // int     i = 1337;
//     // unsigned int u = 424242;
//     // unsigned int x = 0xabcdef;
//     // unsigned int X = 0x123456;
// 	int		counter;

//     /* MI PRINTF */
// 	ft_printf("MI PRINTF:\n");
//     counter = ft_printf("%p\n", ULONG_MAX);
// 	ft_printf("COUNTER: %d \n", counter);

// 	/* PRINTF ORIGINAL */
// 	printf("------------------------------------------------\n");
// 	printf("\nPRINTF ORIGINAL:\n");
// 	counter = printf("%p\n", ULONG_MAX);
// 	printf("COUNTER: %d \n", counter);

//     return 0;
// }
