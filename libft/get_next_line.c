/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:04:30 by yewen             #+#    #+#             */
/*   Updated: 2017/07/16 22:31:52 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_getline(char **buf, char **line, char *pos)
{
	char	*tmp;

	if (pos != NULL)
	{
		tmp = *buf;
		if ((*line = ft_strndup(tmp, pos - tmp)) == NULL)
			return (-1);
		if ((*buf = ft_strdup(pos + 1)) == NULL)
			return (-1);
		free(tmp);
		return (1);
	}
	else if (**buf != '\0')
	{
		*line = *buf;
		*buf = NULL;
		return (1);
	}
	else
	{
		ft_strdel(buf);
		return (0);
	}
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	char		*tmp;
	char		*ptr;
	int			len;

	if ((tmp = ft_memalloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	while ((len = read(fd, tmp, BUFF_SIZE)) != -1)
	{
		if (buf != NULL)
		{
			ptr = buf;
			buf = ft_strjoin(ptr, tmp);
			free(ptr);
		}
		else
			buf = ft_strdup(tmp);
		if ((ptr = ft_strchr(buf, '\n')) != NULL || len != BUFF_SIZE)
		{
			free(tmp);
			return (ft_getline(&buf, line, ptr));
		}
	}
	return (-1);
}
