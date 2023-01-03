/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:37 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/03 20:30:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_str_read(char	*str, char *stack)
{
	char	*tmp;

	if (ft_check_next_line(stack) == 0)
		str = ft_strjoin(str, stack);
	else
	{
		tmp = ft_substr(stack, 0, ft_check_next_line(stack));
		free(str);
		str = tmp;
	}
	return (str);
}

static char	*ft_stack_read(char *stack)
{
	char	*tmp;

	if (ft_check_next_line(stack) == 0)
	{
		free(stack);
		stack = NULL;
	}
	else
	{
		tmp = ft_substr(stack, ft_check_next_line(stack),
				ft_strlen(stack));
		free(stack);
		stack = tmp;
	}
	return (stack);
}

static char	*ft_file_read(char *str, char **stack, int fd)
{
	int		len;
	char	buf[BUFFER_SIZE + 1];
	char	*substr;

	len = read(fd, buf, BUFFER_SIZE);
	buf[len] = '\0';
	while (ft_check_next_line(buf) == 0 && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(str);
			return (NULL);
		}
		buf[len] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (ft_check_next_line(buf) == 1)
	{
		substr = ft_substr(buf, 0, ft_check_next_line(buf));
		str = ft_strjoin(str, substr);
		free(substr);
		*stack = ft_substr(buf, ft_check_next_line(buf), BUFFER_SIZE);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stack;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(str);
		return (NULL);
	}
	if (stack)
	{
		str = ft_str_read(str, stack);
		stack = ft_stack_read(stack);
	}
	if (!stack)
		str = ft_file_read(str, &stack, fd);
	return (str);
}
