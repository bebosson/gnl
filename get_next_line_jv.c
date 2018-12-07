#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int            get_next_line(const int fd, char **line)
{
	int                ret;
	char            buff[BUFF_SIZE + 1];
	static char        *tmp;
	int                i = -1;

	if (fd < 0  || (read(fd, buff, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	if (!tmp)
		tmp = malloc(sizeof(*tmp) * 2);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(tmp, '\n'))
			break;
	}
	if (ret < 0)
		return (-1);
	while (tmp[++i])
		if (tmp[i] == '\n')
			break ;
	*line = ft_strsub(tmp, 0, i);
	if (ft_strlen(tmp))
	{    
		tmp = ft_strsub(tmp, i + 1, ft_strlen(tmp) - ft_strlen(*line));
		return (1);
	}
	return (0);
}
