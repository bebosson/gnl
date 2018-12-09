/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:21:08 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/09 18:46:00 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		get_next_line1(const int fd, char **line, char *tmp[OPEN_MAX])
{
	int		i;
	char	*tmp2;

	i = 0;
	while (tmp[fd][i] && tmp[fd][i] != '\n')
		i++;
	*line = ft_strsub(tmp[fd], 0, i);
	if (ft_strlen(tmp[fd]))
	{
		tmp2 = tmp[fd];
		tmp[fd] = ft_strsub(tmp[fd], i + 1, ft_strlen(tmp[fd]) - i);
		free(tmp2);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*tmp[OPEN_MAX];
	char		*tmp2;

	if (fd < 0 || (read(fd, buff, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_memalloc(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp2 = tmp[fd];
		tmp[fd] = ft_strjoin(tmp[fd], buff);
		free(tmp2);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (get_next_line1(fd, &(*line), tmp));
}
