/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:22:31 by aball             #+#    #+#             */
/*   Updated: 2023/08/11 09:48:31 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*save;
	char		*tmp;
	char		*ret;
	size_t		pos;

	tmp = ft_reading(fd);
	if (!tmp && !save)
		return (NULL);
	tmp = gnl_strjoin(save, tmp);
	pos = c_pos(tmp, '\n');
	if (!*tmp || pos == gnl_strlen(tmp))
	{
		if (!*tmp)
			ret = NULL;
		else
			ret = gnl_strdup(tmp, pos);
		ft_free(tmp);
		save = NULL;
		return (ret);
	}
	ret = gnl_strdup(tmp, pos);
	save = gnl_strdup(tmp + pos, gnl_strlen(tmp + pos));
	ft_free(tmp);
	return (ret);
}
