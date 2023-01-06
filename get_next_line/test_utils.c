/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:12 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/06 14:38:18 by gt-serst         ###   ########.fr       */
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
		left_str = (char *)malloc(sizeof(char));
	left_str = NULL;
	if (!left_str || !buff)
	{
		free(left_str);
		printf("Hello\n");
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	left_str[0] = '\0';
	while (left_str[++i] != '\0')
		str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
/*
char	*ft_strjoin(char *stack, char *buf)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (!stack)
	{
		stack = (char *)malloc(sizeof(char) * 1);
		if (!stack)
			return (NULL);
		stack[0] = '\0';
		//si le malloc n'est pas protégé, la fonction seg fault
		//si on le protège le test NULL est KO
	}

	if (!stack || !buf)
		return (NULL);
	strjoin = (char *)malloc(sizeof(char) * (ft_strlen(stack)
				+ ft_strlen(buf)) + 1);
	if (!strjoin)
		return (NULL);
	i = -1;
	while (stack[++i] != '\0')
			strjoin[i] = stack[i];
	j = -1;
	while (buf[++j] != '\0')
		strjoin[i + j] = buf[j];
	strjoin[ft_strlen(stack) + ft_strlen(buf)] = '\0';
	free(stack);
	return (strjoin);
}
*/

char	*ft_get_stack(char *stack)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
/*
	if(*len < BUFFER_SIZE && !ft_strchr(stack, '\n'))
	{
		str = NULL;
		free(stack);
		return (str);
		printf("stack = NULL et free(stack)");
	}
*/
	while (stack[i] && stack[i] != '\n')
		i++;
	//proctection si la ligne finit par '\0' mais attention !!!
	//si la ligne finit par '\n' alors un malloc de taille 1 sera alloué dans la stack et la stack finale
	//vaudra '\0', ne sera pas free et ne vaudra pas null
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		str[j++] = stack[i++];
	str[j] = '\0';
	//la fonction ne rentre pas dans le while mais place un '\0'
	//dans la stack alors qu'elle devrait être nulle -> en conséquence
	//un élément ne sera pas free à la fin du programme
	free(stack);
	return (str);
}

char	*ft_get_line(char *stack)
{
	int		i;
	char	*str;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	//condition de malloc si le dernier char est un '\n' ou '\0'
	str = (char *)malloc(sizeof(char) * (i + 2));
/*
	if (stack[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
*/
	if (!str)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		str[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		str[i] = stack[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
