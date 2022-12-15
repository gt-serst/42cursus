/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:20:33 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/15 19:55:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	//char	*content;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//free(content);
	//system("leaks a.out");
	//printf("%s", content);
	return (0);
}
