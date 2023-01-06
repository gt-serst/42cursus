/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:20:33 by gt-serst          #+#    #+#             */
/*   Updated: 2023/01/06 18:02:31 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*content;
	char	*conten;
	char	*conte;
	char	*cont;
	char	*con;
	char	*co;
	char	*name;

	name = "lines_around_10.txt";
	fd = open(name, O_RDONLY);
	//printf("fd:%d\n", fd);
	content = get_next_line(fd);
	printf("%s", content);
	free(content);
	conten = get_next_line(fd);
	printf("%s", conten);
	free(conten);
	conte = get_next_line(fd);
	printf("%s", conte);
	free(conte);
	cont = get_next_line(fd);
	printf("%s", cont);
	free(cont);
	con = get_next_line(fd);
	printf("%s", con);
	free(con);
	co = get_next_line(fd);
	printf("%s", co);
	free(co);
/*
	close(fd);
	fd = open(name, O_RDONLY);
	printf("fd:%d\n", fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
	content = get_next_line(fd);
*/
	//system("leaks a.out");
	return (0);
}
