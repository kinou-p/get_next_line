/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 05:58:49 by apommier          #+#    #+#             */
/*   Updated: 2020/12/16 08:44:39 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
int		get_next_line(int fd, char **line);
int		is_line(char *save, int *end);
char	*up_save(char **save, int fd, int *end);
char	*ft_strjoin(char *savee, char *s2);
int		ft_strlen(char *s1);
char	*is_nex_line(char **save, int *end, int fd);

#endif
