/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:10:01 by paapahid          #+#    #+#             */
/*   Updated: 2025/12/03 16:48:32 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(unsigned char spec, va_list ap)
{
	int	size;

	size = 0;
	if(spec == 'c')
		size += ft_printc(va_arg(ap, int));
	else if(spec == 's')
		size += ft_putstr(va_arg(ap, char *));
	else if(spec == 'p')
	{
		size += write(1, "0x", 2);
		size += ft_putnbr_base((va_arg(ap, unsigned long)), 16);
	}
	else if(spec == 'd' || spec == 'i')
		size += ft_putnbr_base(((long)va_arg(ap, int)), 10);
	else if(spec == 'u')
		size += ft_putnbr_base(((long)va_arg(ap, unsigned int)), 10);
	else if(spec == 'x')
		size += ft_putnbr_base(((long)va_arg(ap, unsigned int)), 16);
	else if(spec == 'X')
		size += ft_toupper(ft_putnbr_base(((long)va_arg(ap, unsigned int)), 16));
	else if(spec == '%' && (spec + 1) == '%')
		size += write(1, "%%", 1);
	else
		size += write(1, &spec, 1);
	return(size);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	int		size;
	va_list ap;

	i = 0;
	size = 0;
	va_start(ap, form);
	while (form[i])
	{
		if(form[i] == '%')
		{
			size += ft_format(form[++i], ap);
		}
		else
			size += write(1, &form[i], 1);
		i++;
	}
	va_end(ap);
	return(size);
}

// int main(void)
// {
//     char    c = 'A';
//     char    *s = "Hola, mundo";
//     void    *p = s;
//     int     d = -42;
//     int     i = 1337;
//     unsigned int u = 424242;
//     unsigned int x = 0xabcdef;
//     unsigned int X = 0x123456;

//     /* MI PRINTF */
//     ft_printf("MI PRINTF:\n");

//     ft_printf("%%c: %c\n", c);
//     ft_printf("%%s: %s\n", s);
//     ft_printf("%%p: %p\n", p);
//     ft_printf("%%d: %d\n", d);
//     ft_printf("%%i: %i\n", i);
//     ft_printf("%%u: %u\n", u);
//     ft_printf("%%x: %x\n", x);
//     ft_printf("%%X: %X\n", X);
//     ft_printf("%%%%: %%\n");

//     ft_printf("\nPRINTF ORIGINAL:\n");

//     /* PRINTF ORIGINAL */
//     printf("%%c: %c\n", c);
//     printf("%%s: %s\n", s);
//     printf("%%p: %p\n", p);
//     printf("%%d: %d\n", d);
//     printf("%%i: %i\n", i);
//     printf("%%u: %u\n", u);
//     printf("%%x: %x\n", x);
//     printf("%%X: %X\n", X);
//     printf("%%%%: %%\n");

//     return 0;
// }
