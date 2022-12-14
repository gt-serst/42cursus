/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:20:33 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/14 19:03:47 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*content;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		content = NULL;
		ft_putstr_fd("Error\n", 1);
	}
	else
	{
		content = get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		//get_next_line(fd);
		//get_next_line(fd);
	}
	free(content);
	//system("leaks a.out");
	//printf("%s", content);
	return (0);
}
