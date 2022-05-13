/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:14:41 by htomas-d          #+#    #+#             */
/*   Updated: 2022/05/02 15:17:11 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlcpy(char *dest, char *src, size_t size);

char *ft_strnldup(char *src);

char	*ft_nextchr(char *str);
#endif