/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:51:44 by aball             #+#    #+#             */
/*   Updated: 2023/08/11 00:19:32 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *freeme)
{
	if (freeme)
		free(freeme);
	freeme = NULL;
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = (char *)malloc(gnl_strlen(str1) + gnl_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
		ret[i++] = str2[j++];
	ft_free(str1);
	ft_free(str2);
	ret[i] = 0;
	return (ret);
}

char	*gnl_strchr(char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*gnl_strdup(const char *str, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	while (str && str[i] && i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
