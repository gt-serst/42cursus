/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/10 19:46:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(void *addr)
{
	char	*str;

	str = (char*)addr;
	printf("%p\n", (void*)str);
	return (0);
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
			ft_print_memory(va_arg(args, void*));
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
	printf("%p\n", &x);
	ft_printf("%c%s%p", 'f', "salut", p);
	return (0);
}

