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
