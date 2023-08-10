/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:52:44 by aball             #+#    #+#             */
/*   Updated: 2023/08/11 00:14:00 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4200000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*gnl_strdup(const char *str, size_t len);
char	*gnl_strchr(char *str, const char c);
char	*gnl_strjoin(char *str1, char *str2);
size_t	gnl_strlen(char *str);
void	ft_free(char *freeme);

#endif
