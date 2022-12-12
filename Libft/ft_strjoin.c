/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:34:30 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/01 10:31:03 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	str[tmp + len] = '\0';
	return (str);
}

/*
int main()
{
	char	s1[] = "\0";
	char	s2[] = "\0";
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}
*/
