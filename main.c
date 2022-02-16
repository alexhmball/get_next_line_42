/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:37:15 by aball             #+#    #+#             */
/*   Updated: 2022/02/03 20:35:36 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	char *s1;
	char *s2;
	// char scan;

	// scan = scanf()
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	s1 = get_next_line(fd1);
	s2 = get_next_line(fd2);
	while (s1 && s2)
	{
		printf("%s", s1);
		printf("%s", s2);
		free (s1);
		free (s2);
		s1 = get_next_line(fd1);
		s2 = get_next_line(fd2);
	}
	//free (s1);
	// while (s2)
	// {
	// 	printf("%s", s2);
	// 	free (s2);
	// 	s2 = get_next_line(fd2);
	// }
	return (0);
}