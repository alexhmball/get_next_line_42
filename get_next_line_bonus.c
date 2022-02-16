/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:14 by aball             #+#    #+#             */
/*   Updated: 2022/02/03 18:36:21 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_strchr(char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return (&ptr[i + 1]);
		i++;
	}
	if (c == '\0')
		return (&ptr[i]);
	return (0);
}

static char	*save_line(char *s)
{
	int		pos;
	int		i;
	char	*save;

	i = 0;
	if (!s)
		return (NULL);
	pos = position(s);
	save = (char *)malloc(sizeof(char) * (ft_strlen(s) - pos + 1));
	if (!save)
		return (NULL);
	if (s[pos])
	{
		while (s[++pos])
			save[i++] = s[pos];
	}
	save[i] = '\0';
	free (s);
	if (ft_strlen(save) == 0)
	{
		free (save);
		return (0);
	}
	return (save);
}

static char	*reading(char *temp, char *s[1048], int fd, int rd)
{
	char	*buf;

	while (gnl_strchr(temp, '\n') == 0 && rd != 0)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		s[fd] = gnl_strjoin(temp, buf);
		temp = ft_strdup(s[fd]);
	}
	return (temp);
}

static char	*gnl_free(char *s, char *nextline, char *temp)
{
	if (ft_strlen(nextline) == 0 || !nextline)
	{
		free(s);
		free(nextline);
		free (temp);
		return (NULL);
	}
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*nextline;
	char		*temp;
	char		*buf;
	int			rd;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd = read(fd, buf, BUFFER_SIZE);
	if (rd < 0 || (rd == 0 && ft_strlen(s[fd]) == 0))
	{
		free (buf);
		return (NULL);
	}
	buf[rd] = '\0';
	if (!s[fd])
		temp = ft_strdup(buf);
	else
		temp = gnl_strjoin(s[fd], buf);
	temp = reading(temp, s, fd, rd);
	nextline = gnl_strcpy(temp);
	s[fd] = save_line(temp);
	nextline = gnl_free(s[fd], nextline, temp);
	return (nextline);
}
