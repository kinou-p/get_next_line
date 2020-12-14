/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:40:53 by apommier          #+#    #+#             */
/*   Updated: 2020/12/14 21:31:17 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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
	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (0);
	while (s1[i] && s1)
	{
		dest[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest);
}

int			ft_free(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (0);
}

static char	*up_save(char *save, int index, int fd)
{
	char		*dest;
	char		*delete;
	int			i;

	delete = save;
	if (index)
		save += index;
	if (!(dest = (char*)malloc(BUFFER_SIZE)))
	{
		ft_free(dest, delete, save);
		return (0);
	}
	i = read(fd, dest, BUFFER_SIZE);
	if (!i)
	{
		ft_free(dest, delete, save);
		return (0);
	}
	if (!(save = ft_strjoin(save, dest)))
	{
		ft_free(dest, delete, save);
		return (0);
	}
	free(delete);
	return (save);
}

int			is_line(char *save, char **line)
{
	int			i;

	i = 0;
	if (save == 0)
		return (0);
	while (save[i] && i < BUFFER_SIZE)
	{
		if (save[i] == '\n')
		{
			save[i] = 0;
			return (1);
		}
		i++;
	}
	if (save[i] == 0)
	{
		return (2);
		*line = save;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*save;
	int			i;

	i = 0;
	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	if (is_line(save, line))
	{
		while (save[i] != 0)
			i++;
		if (!(save = up_save(save, i, fd)))
			return (-1);
	}
	else
	{
		if (!(save = up_save(save, 0, fd)))
			return (-1);
	}
	while (!is_line(save, line))
	{
		if (is_line(save, line) == 2)
			return (0);
		if (!(save = up_save(save, 0, fd)))
			return (-1);
	}
	*line = save;
	return (1);
}
