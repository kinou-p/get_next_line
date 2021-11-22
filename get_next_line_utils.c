/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 06:05:54 by apommier          #+#    #+#             */
/*   Updated: 2020/12/16 08:36:15 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s1)
{
	int		i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *save, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save && !s2)
		return (0);
	dest = malloc(ft_strlen(save) + ft_strlen(s2) + 1);
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

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return ("no s");
	str = (char *)s;
	while ((*str != c) && (*str != 0))
		str++;
	if (*str == c)
		return ((char *)str);
	else
		return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(size * nmemb);
	if (new)
	{
		while (size * nmemb - i)
		{
			new[i] = 0;
			i++;
		}
	}
	return ((void *)new);
}
