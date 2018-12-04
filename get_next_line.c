/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:42:12 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/04 21:45:03 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int	ft_return_read2(char *tmp,int ret)
{
	int d;

	if (ft_strlen(tmp) > 0)
		d = 1;
	else if (ft_strlen(tmp) == 0 && ret < BUFF_SIZE)
		d = 0;
	return (d);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*tmp = NULL;
	char			*test;

	if (tmp == NULL)
		tmp = ft_strnew(1);
	ret = 1;
	while (ft_strchr(tmp, '\n') == NULL && ret > 0)
	{
		buff[ret] = '\0';
		ret = read(fd, buff, BUFF_SIZE);
		tmp = ft_strjoin(tmp, buff);
	}
	test = ft_strsub(tmp, 0, ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, '\n')));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	tmp = ft_strsub(tmp + 1, ft_strlen(test), ft_strlen(tmp) - ft_strlen(test));
	*line = test;
	printf("%s \n",tmp);
	printf("%s \n",test);
	printf("line = %d \n",ft_return_read2(tmp, ret));
	printf("toto");
	return (ft_return_read2(tmp, ret));
}
