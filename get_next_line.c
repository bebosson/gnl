/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:42:12 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/07 18:46:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/incs/libft.h"

int			ft_return_read2(char *t, int fd)
{
	(void)t;
	(void)fd;
	int d;

	if (fd < 0)
		d = -1;
	else
		d = 1;
	return (d);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*tmp = NULL;
	char			*t;

	if (tmp == NULL)
		tmp = ft_strnew(1);
	if (fd < 0)
		return (ft_return_read2(NULL,fd));
	ret = 1;
	while ((ret > 0))
	{
		ret = read(fd, buff, BUFF_SIZE); 
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);

		if (ft_strchr(tmp, '\n') != NULL)
			break;
	}
	if (ret < 0)
		return (-1);
	if (ft_strchr(tmp,'\n') != NULL)
		t = ft_strsub(tmp, 0, ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, '\n')));
	else
		t = ft_strdup(tmp);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	if (!*tmp)
	{
		*line = "\0";
		return (0);
	}
	if (tmp != NULL && t != NULL)
		tmp = ft_strsub(tmp + 1, ft_strlen(t), ft_strlen(tmp) - ft_strlen(t));
	*line = t;
	return (ft_return_read2(t,fd));
}
