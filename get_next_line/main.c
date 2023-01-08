/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:20:33 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/08 22:47:36 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*content;
	char	*name;

	name = "lines_around_10.txt";
	fd = open(name, O_RDONLY);
	i = 0;
	while (i < 10)
	{
		content = get_next_line(fd);
		printf("New line in main: %s\n", content);
		free(content);
		i++;
	}
	system("leaks a.out");
	return (0);
}
