/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:20:33 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/16 17:37:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;
	char	*content;
	
	fd = open("text.txt", O_RDONLY);
	i = 0;
	//system("leaks a.out");
	while (i < 12)
	{
		content = get_next_line(fd);
		printf("New line: %s\n", content);
		free(content);
		i++;
	}
	system("leaks a.out");
	return (0);
}
