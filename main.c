/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:17:35 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/06 20:47:43 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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
	//	printf("ret = %d \n",ret);
	//	printf("line = [%s] \n",line);
		printf("%s\n",line);
	}
	//printf("line = [%s]",line);
	//printf("ret = %d \n",ret);
}
