/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/11 13:46:51 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_recursive(unsigned long nbr, char *base, int len)
{
	int	count;

	count = 0;
	if (nbr < (unsigned long)len)
	{
		write(1, &base[nbr], 1);
		return (1);
	}
	count = ft_recursive(nbr / len, base, len);
	return (count + ft_recursive(nbr % len, base, len));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format++;
		if (*format == 'c')
			ft_putchar(va_arg(args, int));
		else if (*format == 's')
			ft_putstr(va_arg(args, char*));
		else if (*format == 'p')
		{
			ft_putnbr(0);
			ft_putchar('x');
			ft_recursive(va_arg(args, unsigned long), "0123456789abcdef", 16);
		}
		else if (*format == 'd')
			ft_putnbr(va_arg(args, int));
		else if (*format == 'i')
			ft_recursive(va_arg(args, unsigned long), "0123456789", 10);
		format++;
	}
	va_end(args);
	return (0);
}

int	main()
{
	int	*p;
	int	x;

	x = 5;
	p = &x;
	printf("%p\n", p);
	ft_printf("%c%s%p%d%i", 'f', "salut", p, 06, 0x12);
	return (0);
}
