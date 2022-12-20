/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:37 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/16 16:56:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_next_line(char	*buf)
{
	int	c;

	c = 0;
	while (buf[c] && buf[c] != '\0')
	{
		if (buf[c] != '\n')
			c++;
		else
			return (c);
	}
	return (0);
}

char	*ft_str_read(char	*str, char *stack)
{
	if (ft_check_next_line(stack) == 0)
		str = ft_strjoin(str, stack);
	else
		str = ft_substr(stack, 0, ft_check_next_line(stack) + 1);
	return (str);
}

char	*ft_stack_read(char *stack)
{
	if (ft_check_next_line(stack) == 0)
	{
		free(stack);
		stack = NULL;
	}
	else
		stack = ft_substr(stack, ft_check_next_line(stack) + 1, \
				ft_strlen(stack));
	return (stack);
}

char	*ft_file_read(char *str, char **stack, int fd, int size)
{
	int				len;
	char			buf[BUFFER_SIZE + 1];
	char			*substr;

	len = read(fd, buf, BUFFER_SIZE);
	printf("Ce que je lis: %s", buf);
	if (len == 0)
		return (NULL);
	size += len;
	if (ft_check_next_line(buf) == 0)
	{
		str = ft_strjoin(str, buf);
		str = ft_file_read(str, stack, fd, size);
	}
	else
	{
		printf("Ce qui va être envoyé: %s", buf);
		substr = ft_substr(buf, 0, ft_check_next_line(buf) + 1);
		str = ft_strjoin(str, substr);
		printf("Size: %d\n", size);
		*stack = ft_substr(buf, ft_check_next_line(buf) + 1, ft_strlen(buf));
		printf("Ce qui sort de la fonction: %s", *stack);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stack;

	printf("Lancement de la fonction :\n");
	str = malloc(sizeof(char));
	if  (!str)
		return (NULL);
	str[0] = '\0';
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (stack)
	{
		str = ft_str_read(str, stack);
		stack = ft_stack_read(stack);
	}
	if (!stack)
	{
		printf("La stack est vide\n");
		str = ft_file_read(str, &stack, fd, 0);
	}
	printf("Str: %s", str);
	printf("Stack: %s", stack);
	printf("Fin de la fonction\n");
	return (str);
}

