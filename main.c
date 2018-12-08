/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:17:35 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/08 19:29:53 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/incs/libft.h"
int get_next_line(int fd, char **line);

int main(int ac, char **av)
{
	int fd;
	int ret;
	char *line = NULL;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		//printf("ret = %d \n",ret);
		printf("%s\n",line);
	}
	//printf("ret = %d \n",ret);
}
