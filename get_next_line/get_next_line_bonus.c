/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/09 15:56:39 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_bytes(int fd, char *stack_fd)
{
	int		len;
	char	buf[BUFFER_SIZE + 1];

	len = 1;
	while (!ft_strchr(stack_fd, '\n') && len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(stack_fd);
			return (NULL);
		}
		buf[len] = '\0';
		stack_fd = ft_strjoin(stack_fd, buf);
	}
	return (stack_fd);
}

static char	*ft_get_line(char *stack_fd)
{
	char	*line;
	char	*substr;

	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (ft_strchr(stack_fd, '\n'))
	{
		substr = ft_substr(stack_fd, 0, ft_strchr(stack_fd, '\n'));
		free(line);
		line = substr;
	}
	else
		line = ft_strjoin(line, stack_fd);
	return (line);
}

static char	*ft_get_stack(char *stack_fd)
{
	char	*substr;

	if (ft_strchr(stack_fd, '\n'))
	{
		substr = ft_substr(stack_fd, ft_strchr(stack_fd, '\n'),
				ft_strlen(stack_fd));
		free(stack_fd);
		stack_fd = substr;
	}
	else
	{
		free(stack_fd);
		stack_fd = NULL;
	}
	return (stack_fd);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack[OPEN_MAX];
	char		*stack_fd;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (NULL);
	stack_fd = stack[fd];
	stack_fd = ft_get_bytes(fd, stack_fd);
	if (!stack_fd)
	{
		stack[fd] = stack_fd;
		return (NULL);
	}
	if (stack_fd[0] == '\0')
		line = NULL;
	else
		line = ft_get_line(stack_fd);
	stack_fd = ft_get_stack(stack_fd);
	stack[fd] = stack_fd;
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*content;
	char	*name;

	name = "text.txt";
	fd = open(name, O_RDONLY);
	content = get_next_line(fd);
	printf("New line in main: %s\n", content);
	free(content);
	close(fd);
	fd = open(name, O_RDONLY);
	content = get_next_line(fd);
	printf("New line in main: %s\n", content);
	free(content);
	content = get_next_line(fd);
	printf("New line in main: %s\n", content);
	free(content);
	return (0);
}
*/
