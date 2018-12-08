/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:21:08 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/08 20:35:53 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/incs/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char		*ft_strsub2(const char *s,unsigned int start, size_t len)
{
	char	*new;
	if (!(new = ft_strsub(s,start,len)))
		return (NULL);
	free((char *)s);
	return (new);
}

char*ft_strjoin2(const char *s1, const char *s2)
{
	char	*new;
	if (!(new = ft_strjoin(s1,s2)))
		return (NULL);
	free((char *)s1);
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*tmp[4096];
	int			i;

	if (fd < 0 || (read(fd, buff, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = malloc(sizeof(*tmp) * 2);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp[fd] = ft_strjoin2(tmp[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	i = 0;
	while (tmp[fd][i] && tmp[fd][i] != '\n')
		i++;
	*line = ft_strsub(tmp[fd], 0, i);
	if (ft_strlen(tmp[fd]))
	{
		tmp[fd] = ft_strsub2(tmp[fd], i + 1, ft_strlen(tmp[fd]) - ft_strlen(*line));
		return (1);
	}
	return (0);
}
