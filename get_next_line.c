/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:40:53 by apommier          #+#    #+#             */
/*   Updated: 2020/12/15 08:40:46 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int			ft_strlen(char *s1)
{
	int i;
	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return(0);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (0);
	while (s1 && s1[i])
	{
		dest[j] = s1[i];
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

static char	*up_save(char *save, int fd, int *end)
{
	char		*dest;
	char		*delete;
	int			i;

	delete = save;
	if (!(dest = (char*)malloc(1 * (1 + BUFFER_SIZE))))
	{
		if (save)
			free(save);
		return (0);
	}
	i = read(fd, dest, BUFFER_SIZE);
	*end = i;
	dest[i] = 0;
	if (i < BUFFER_SIZE && dest[i - 1] != '\n')
	{
		dest[i + 1] = 0;
		dest[i] = '\n';
	}
	if (!(save = ft_strjoin(save, dest)))
	{
		free(dest);
		free(delete);
		return (0);
	}
	return (save);
}

int			is_line(char *save, int *end)
{
	int			i;
 
	i = 0;
	if (save == 0)
		return (0);
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

char		*is_next_line(char *save, int *end, int fd)
{
	char 		*delete;
	int			i;

	i = 0;
	delete = save;
	if (save)
	{
		while (save[i])
			i++;
		i++;
		if (save[i])
			if (!(save = ft_strjoin(save + i, 0)))
			{
				free(delete);
				return (0);
			}
	}
	i = 0;
	while (!(is_line(save, end)))
	{
		save = up_save(save, fd, end);
		if (!save)
		{
			free(delete);
			return (0);
		}
	}
	free(delete);
	return (save);
}

int			get_next_line(int fd, char **line)
{
	static char	*save;
	int			j;
	int			*end;

	end = &j;
	j = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	save = is_next_line(save, end, fd);
	if (!save)
		return (-1);
	*line = save;
	if (*end < BUFFER_SIZE)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *buff;
    int line;

    printf("DEFINE BUFFER_SIZE=%d\n", BUFFER_SIZE);
    line = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((ret = get_next_line(fd, &buff)) > 0)
        {
            printf("\033[38;5;2m" "[Return: %d] Line ->%d : '%s'\n", ret, ++line, buff);
            free(buff);
        }
        printf("\033[38;5;2m" "[Return: %d] Line ->%d : %s\n", ret, ++line, buff);
        close(fd);
    }
    if (argc == 1)
    {
        printf("No input file, read here\n");
        while ((ret = get_next_line(0, &buff)) > 0)
        {
            printf("\033[38;5;2m" "[Return: %d] Line ->%d: %s\n", ret, ++line, buff);
            free(buff);
        }
        close(fd);
        return (0);
    }
}
