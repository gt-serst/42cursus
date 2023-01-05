/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:20:33 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/05 18:50:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*content;
	char	*name;

	name = "empty.txt";
	fd = open(name, O_RDONLY);
	printf("fd:%d\n", fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
/*
	close(fd);
	fd = open(name, O_RDONLY);
	printf("fd:%d\n", fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
*/
	free(content);
	system("leaks a.out");
	return (0);
}
