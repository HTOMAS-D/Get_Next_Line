/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:13:35 by htomas-d          #+#    #+#             */
/*   Updated: 2022/05/02 15:25:37 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s +i);
	return NULL;
}

static char	*ft_nl(int fd, char *next, char *buffer, char *save)
{
	int i;
	
	i = 1;
	while(!ft_strchr(next, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return NULL;
		if (!next)
		{
			next = (char *)malloc(1);
			next[0] = '\0';
		}
		buffer[i] = '\0';
		save = next;
		next = ft_strjoin(save, buffer);
		free(save);
	}
	return (next);
}

char	*get_next_line(int fd)
{
	static char *next;
	char *buffer;
	char *save;

	if(read(fd, 0, 0) == -1)
		return NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return NULL;
	save = NULL;
	next = ft_nl(fd, next, buffer, save);
	free(buffer);
//	printf("%s", next);
	save = ft_strnldup(next);
	next = ft_nextchr(next);
	return (save);
}

int main()
{
	int	fd;
	char *line;

	fd = open("cenas.txt", O_RDONLY);
	line = get_next_line(fd);
	//printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
