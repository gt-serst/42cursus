/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:37 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/15 20:31:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_next_line(char	*content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '\0')
	{
		if (content[i] != '\n')
			i++;
		else
			return (i);
	}
	return (0);
}

char	*ft_file_read(char *str, char *stack, int fd, int size)
{
	int 			len;
	static char		buf[BUFFER_SIZE + 1];

	len = read(fd, buf, BUFFER_SIZE);
	size += len;
	if (ft_check_next_line(buf) == 0)
	{
		str = ft_strjoin(str, buf);
		ft_file_read(str, stack, fd, size);
	}
	str = ft_substr(buf, size - len, ft_check_next_line(buf) + 1);
	stack = ft_substr(buf, ft_check_next_line(buf) + 1, size);
	printf("Stack : %s", stack);
	return (str);
}

char	*ft_stack_read(char	*str, char *stack, int fd)
{
	int	len;

	printf("3");
	len = read(fd, stack, BUFFER_SIZE);
	if (ft_check_next_line(stack) == 0)
	{
		str = ft_strjoin(str, stack);
		free(stack);
		stack = NULL;
		printf("1");
		str = ft_file_read(str, stack, fd, 0);
	}
	else
	{
		printf("2");
		str = ft_substr(stack, 0, ft_check_next_line(stack) + 1);
		stack = ft_substr(stack, ft_check_next_line(stack) + 1, len);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char *stack;

	printf("Debut d'appel :\n");
	printf("%s\n", stack);
	str = NULL;
	if (fd < 0)
		return (NULL);
	if (stack)
		str = ft_stack_read(str, stack, fd);
	else
		str = ft_file_read(str, stack, fd, 0);
	printf("Str : %s", str);
	return (str);
}
