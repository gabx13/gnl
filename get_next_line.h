/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:04:10 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/23 11:01:27 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line(int fd);
void		free_safe(char **str);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, char const *src);
char		*ft_strjoin(char *s1, char *s2);
int			check_newline(char *line);
char		*reset_line(char *line);
char		*return_fnc(char *line);
char		*check_line(char *line, int fd);

#endif
