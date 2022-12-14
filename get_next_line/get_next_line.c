/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:45:37 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/14 19:03:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcpy(char *dest, char *src);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

int	ft_check_char(char c)
{
	if (c != '\n')
		return (1);
	return (0);
}

char	*ft_chars_add(char *content, char *buf, int index)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (index + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_strncpy(tmp, content, index);
	free(content);
	ft_strcpy(tmp + index, buf);
	content = tmp;
	content[index] = '\0';
	//printf("2");
	//printf("%s", content);
	return (content);
}

char	*ft_chars_read(int fd)
{
	static char	buf[1];
	char		*content;
	int			index;

	read(fd, buf, 1);
	if (buf[0] == '\0')
		return (NULL);
	content = malloc(sizeof(char));
	if (!content)
		return (NULL);
	index = 0;
	while (ft_check_char(buf[0]) == 1)
	{
		//printf("1");
		content = ft_chars_add(content, buf, index);
		//printf("%s", content);
		index++;
		read(fd, buf, 1);
	}
	if (ft_check_char(buf[0] == 0))
		content = ft_chars_add(content, buf, index);
	//printf("%s", content);
	return (content);
}

char	*get_next_line(int fd)
{
	char	*content;

	if (fd < 0)
		return (NULL);
	content = ft_chars_read(fd);
	//printf("%s", content);
	return (content);
}
