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

int	ft_strlen(const char *s)
{
	int	tmp;

	if (!s)
		return (0);
	tmp = 0;
	while (s[tmp] != '\0')
		tmp++;
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		tmp;
	unsigned int	srclen;
	char		*substr;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > srclen)
		len = srclen - start;
	substr = malloc(sizeof(char) * (len + 1));
	printf("Taille du malloc: %d\n", len + 1);
	if (!substr)
		return (NULL);
	tmp = 0;
	while (tmp < len && s[start + tmp])
	{
		substr[tmp] = s[start + tmp];
		tmp++;
	}
	substr[tmp] = '\0';
	printf("Substr: %s\n", substr);
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
	while (s1[tmp] != '\0')
	{
		str[tmp] = s1[tmp];
		tmp++;
	}
	tmp = 0;
	while (s2[tmp] != '\0')
	{
		str[len + tmp] = s2[tmp];
		tmp++;
	}
	str[len + tmp] = '\0';
	return (str);
}
