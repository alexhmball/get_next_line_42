/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:03:05 by aball             #+#    #+#             */
/*   Updated: 2022/02/03 17:55:54 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strcpy(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dest = (char *)malloc(position(src) + 2);
	if (!dest)
		return (0);
	while (src[i] && i < position(src) + 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free (src);
	return (dest);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	joint = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joint == NULL)
		return (0);
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joint[i++] = s2[j++];
	}
	joint[i] = '\0';
	free (s1);
	free (s2);
	return (joint);
}

int	position(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}
