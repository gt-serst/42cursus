/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:12 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/16 18:26:00 by gt-serst         ###   ########.fr       */
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

char	*ft_strdup(char *s1)
{
	int	tmp;
	char	*ptr;
	
	tmp = 0;
	while (s1[tmp] != '\0')
		tmp++;
	ptr = malloc(sizeof(char) * (tmp + 1));
	if (!ptr)
		return (NULL);
	tmp = 0;
	while (s1[tmp] != '\0')
	{
		ptr[tmp] = s1[tmp];
		tmp++;
	}
	ptr[tmp] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	int		tmp;
	char		*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
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

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*str;
	
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}
