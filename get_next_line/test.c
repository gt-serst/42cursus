/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:37 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/06 18:18:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_file(int fd, char *stack, int *len)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*len = 1;
	while (!ft_strchr(stack, '\n') && *len != 0)
	{
		*len = read(fd, buf, BUFFER_SIZE);
		if (*len == -1)
		{
			free(buf);
			free(stack);
			return (NULL);
		}
		//pouvoir dire SI la len est plus petite que le BUFFER_SIZE && qu'il n'y a plus de \n dans la stack alors
		//fin de fichier donc stack = NULL et free(stack)
		buf[*len] = '\0';
		stack = ft_strjoin(stack, buf);
	}
	free(buf);
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stack;
	int			len;

	len = 0;
	//possible de faire une protection au départ pour remettre la stack à nulle
	//si elle ne l'est pas lors du prochain appel de la fonction
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stack = ft_read_file(fd, stack, &len);
	if (!stack)
		return (NULL);
	str = ft_get_line(stack);
	// ICI IL FAUT QU'IL SUCE
	//printf("Len : %d\n", len);
	stack = ft_get_stack(stack);
	//printf("New line: %s\n", str);
	//printf("Stack: %s\n", stack);
	return (str);
}
