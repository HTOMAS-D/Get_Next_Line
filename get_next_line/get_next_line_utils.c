/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:17:22 by htomas-d          #+#    #+#             */
/*   Updated: 2022/05/02 15:31:41 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while(str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;
	size_t j;

	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if(!str)
		return NULL;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	else if(!size)
		return (ft_strlen(src));
	while(src[i] && i < (size -1))
	{
		dest[i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}

char	*ft_strnldup(char *src)
{
	char *newstr;
	size_t	i;
	
	i = 0;
	if (!src)
		return (0);
	while (src[i] && src[i] != '\n')
		i++;
	if(src[i] == '\n')
		newstr = (char *)malloc(sizeof(char) * (i + 2));
	else
		newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, src, i + 2);
	if (newstr[0] == '\0')
	{
		free(newstr);
		return NULL;
	}
	return (newstr);
}
char	*ft_nextchr(char *str)
{
	int			i;
	char	*temp;

	i = 0;
	while(str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	temp = malloc ((ft_strlen(str) - i) + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, str + i + 1, ft_strlen(str) - i + 1);
	free(str);
	return (temp);
}
