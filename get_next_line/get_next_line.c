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

static int	ft_check_next_line(char	*buf)
{
	int	c;

	c = 0;
	while (buf[c] && buf[c] != '\0')
	{
		if (buf[c] != '\n')
			c++;
		else
			return (c + 1);
	}
	return (0);
}

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
		tmp = ft_substr(stack, ft_check_next_line(stack), \
				ft_strlen(stack));
		free(stack);
		stack = tmp;
	}
	return (stack);
}

static char	*ft_check_end_of_file(char *str)
{
	if (!(*str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static char	*ft_file_read(char *str, char **stack, int fd)
{
	int	len;
	char	buf[BUFFER_SIZE + 1];
	char	*substr;

	len = read(fd, buf, BUFFER_SIZE);
	//printf("Buf: %s\n", buf);
	if (len <= 0)
		return (ft_check_end_of_file(str));
	buf[len] = '\0';
	if (ft_check_next_line(buf) == 0)
	{
		//printf("Buf: %s\n", buf);
		str = ft_strjoin(str, buf);
		//printf("Str: %s\n", str);
		str = ft_file_read(str, stack, fd);
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

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stack;

	//printf("Lancement de la fonction :\n");
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
		//printf("La stack est vide\n");
		str = ft_file_read(str, &stack, fd);
	}
	//printf("Str: %s\n", str);
	//printf("Stack: %s\n", stack);
	//printf("Fin de la fonction\n\n");
	return (str);
}
