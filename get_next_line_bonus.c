/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:14 by aball             #+#    #+#             */
/*   Updated: 2023/08/11 09:54:34 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	c_pos(const char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*ft_reading(int fd)
{
	char	*buf;
	char	*ret;
	int		rd;

	ret = NULL;
	rd = 1;
	while (rd > 0 && !gnl_strchr(ret, '\n'))
	{
		buf = (char *)malloc((size_t)((size_t)BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		rd = read(fd, &buf[0], BUFFER_SIZE);
		if (rd < 0)
		{
			ft_free(buf);
			return (NULL);
		}
		buf[rd] = 0;
		ret = gnl_strjoin(ret, buf);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*tmp;
	char		*ret;
	size_t		pos;

	tmp = ft_reading(fd);
	if (!tmp && !save[fd])
		return (NULL);
	tmp = gnl_strjoin(save[fd], tmp);
	pos = c_pos(tmp, '\n');
	if (!*tmp || pos == gnl_strlen(tmp))
	{
		if (!*tmp)
			ret = NULL;
		else
			ret = gnl_strdup(tmp, pos);
		ft_free(tmp);
		save[fd] = NULL;
		return (ret);
	}
	ret = gnl_strdup(tmp, pos);
	save[fd] = gnl_strdup(tmp + pos, gnl_strlen(tmp + pos));
	ft_free(tmp);
	return (ret);
}
