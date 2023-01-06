/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:37 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/06 18:18:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
static char	*ft_get_line(char *str, char *stack)
{
	char	*substr;

	if (!ft_strchr(stack, '\n'))
	{
		str = ft_strjoin(str, stack);
	}
	else
	{
		substr = ft_substr(stack, 0, ft_strchr(stack, '\n') - stack + 1);
		free(str);
		str = substr;
	}
	return (str);
}

static char	*ft_get_stack(char *stack)
{
	char	*substr;

	if (!ft_strchr(stack, '\n'))
	{
		free(stack);
		stack = NULL;
	}
	else
	{
		substr = ft_substr(stack, ft_strchr(stack, '\n') - stack + 1,
				ft_strlen(stack));
		free(stack);
		stack = substr;
	}
	return (stack);
}
*/

/*
static char	*ft_check_end_of_file(char *str, int len)
{
	if (!(*str) && len == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
*/

static char *ft_read_file(int fd, char *str, char **stack)
{
	int		len;
	char	buf[BUFFER_SIZE + 1];

	len = 1;
	while (!ft_strchr(*stack, '\n') && len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(*stack);
			free(str);
			return (NULL);
		}
		buf[len] = '\0';
		*stack = ft_strjoin(*stack, buf);
	}
	if (*stack == NULL)
		return (NULL);
	if (ft_strchr(*stack, '\n'))
	{
		str = ft_substr(*stack, 0, ft_strchr(*stack, '\n') + 1);
		*stack = ft_substr(*stack, ft_strchr(*stack, '\n') + 1, ft_strlen(*stack));
	}
	else
	{
		//printf("Fin de fichier");
		printf("stackfin:|%s|", *stack);
		//str = ft_strjoin(str, *stack);
		str[0] = 'a';
		free(*stack);
	}
	return (str);
}

/*
static char	*ft_read_file(char *str, char **stack, int fd)
{
	int		len;
	char	buf[BUFFER_SIZE + 1];
	char	*substr;

	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
		return (ft_check_end_of_file(str, len));
	buf[len] = '\0';
	if (ft_check_next_line(buf) == 0)
	{
		str = ft_strjoin(str, buf);
		str = ft_read_file(str, stack, fd);
	}
	else
	{
		substr = ft_substr(buf, 0, ft_check_next_line(buf));
		str = ft_strjoin(str, substr);
		free(substr);
		*stack = ft_substr(buf, ft_check_next_line(buf), BUFFER_SIZE);
	}
	return (str);
}
*/

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stack;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	/*if (!stack)
	{
		stack = malloc(sizeof(char));
		if (!stack)
			return (NULL);
		stack[0] = '\0';
	}*/
	str = ft_read_file(fd, str, &stack);
	//printf("New line: %s\n", str);
	//printf("Stack: %s\n", stack);
	return (str);
}
