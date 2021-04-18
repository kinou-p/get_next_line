/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:40:53 by apommier          #+#    #+#             */
/*   Updated: 2020/12/18 10:05:11 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdio.h>

char	*ft_strjoin(char *save, char *s2)
{
	char		*dest;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!save && !s2)
		return(0);
	if(!(dest = (char*)malloc(ft_strlen(save) + ft_strlen(s2) + 1)))
		return (0);
	while (save && save[i])
	{
		dest[j] = save[i];
		j++;
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		dest[j] = s2[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest);
}

char	*up_save(char **save, int fd, int *end)
{
	char		*dest;
	char		*delete;

	dest = 0;
	delete = *save;
	if (!(dest = (char*)malloc(1 + BUFFER_SIZE)))
	{
		if (*save)
			free(*save);
		return (0);
	}
	*end = read(fd, dest, BUFFER_SIZE);
	if (*end == -1)
		return (0);
	dest[*end] = 0;
	if (!(*save = ft_strjoin(*save, dest)))
	{
		free(dest);
		free(delete);
		return (0);
	}
	free(delete);
	free(dest);
	return (*save);
}

int		is_line(char *save, int *end)
{
	int		i;

	i = 0;
	if (save == 0)
		return (1);
	if (*end < BUFFER_SIZE)
	{
		while (save[i] && save[i] != '\n')
			i++;
		if (save[i] == '\n')
			*end = BUFFER_SIZE;
	}
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			save[i] = 0;
			return (1);
		}
		i++;
	}
	if (*end < BUFFER_SIZE)
		return (1);
	return (0);
}

char	*is_next_line(char **save, int *end, int fd)
{
	char		*delete;
	int		i;

	i = 0;
	delete = *save;
	while (*save && (*save)[i])
		i++;
	if (*save && !(*save = ft_strjoin(*save + i + 1, 0)))
	{
		free(delete);
		return (0);
	}
	up_save(save, fd, end);
	while (!is_line(*save, end))
	{
		up_save(save, fd, end);
		if (!(*save))
		{
		    free(delete);
		    return (0);
		}
	}
	free(delete);
	return (*save);
}


int		get_next_line(int fd, char **line)
{
	int			end;
	static char	**save;

	if (!save)
	{
		if(!(save = malloc(sizeof(char*))))
			return (-1);
		*save = 0;
	}
	else if (*save == 0)
	{
	    *line = *save;
	    free(*save);
	    free(save);
	    return (0);
	}
	end = BUFFER_SIZE;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
	    return (-1);
	is_next_line(save, &end, fd);
	if (!(*save))
		return (-1);
	free(*line);
	*line = ft_strjoin(*save, 0);
	if (!(*line))
	{
		free(*save);
		return (-1);
	}
	if (end < BUFFER_SIZE)
	{
	    free(*save);
	    free(save);	
	    return (0)`;
	}
	return (1);
}
