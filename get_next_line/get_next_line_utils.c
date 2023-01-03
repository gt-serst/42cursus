/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:12 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/03 19:43:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	tmp;

	if (!s)
		return (0);
	tmp = 0;
	while (s[tmp] != '\0')
		tmp++;
	return (tmp);
}

char	*ft_strdup(char *s)
{
	int		tmp;
	char	*ptr;

	tmp = 0;
	while (s[tmp] != '\0')
		tmp++;
	ptr = (char *)malloc(sizeof(char) * (tmp + 1));
	if (!ptr)
		return (NULL);
	tmp = 0;
	while (s[tmp] != '\0')
	{
		ptr[tmp] = s[tmp];
		tmp++;
	}
	ptr[tmp] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	int		tmp;
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	tmp = 0;
	while (tmp < len && s[start + tmp])
	{
		substr[tmp] = s[start + tmp];
		tmp++;
	}
	substr[tmp] = '\0';
	return (substr);
}

char	*ft_strjoin(char *str, char *stack)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (!str)
		return (ft_strdup(""));
	if (!str || !stack)
		return (NULL);
	strjoin = (char *)malloc(sizeof(char) * (ft_strlen(str)
				+ ft_strlen(stack)) + 1);
	if (!strjoin)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		strjoin[i] = str[i];
	j = -1;
	while (stack[++j] != '\0')
		strjoin[i + j] = stack[j];
	strjoin[ft_strlen(str) + ft_strlen(stack)] = '\0';
	free(str);
	return (strjoin);
}

int	ft_check_next_line(char	*buf)
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
