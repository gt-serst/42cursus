/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:12 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/15 19:26:55 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	tmp;

	tmp = 0;
	while (s[tmp] != '\0')
		tmp++;
	return (tmp);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (*(src + i) != '\0' && i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}	
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		tmp;
	char	*substr;

	if (!s)
		return (NULL);
	substr = malloc(sizeof(char) * (len - start + 1));
	if (!substr)
		return (NULL);
	tmp = 0;
	while (tmp < len && s[start])
		substr[tmp++] = s[start++];
	substr[tmp] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tmp;
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	tmp = 0;
	while (s2[tmp] != '\0')
	{
		str[len + tmp] = s2[tmp];
		tmp++;
	}
	str[tmp + len] = '\0';
	return (str);
}
