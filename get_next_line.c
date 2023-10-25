/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:53:14 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/23 11:01:12 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*reset_line(char *line)
{
	char	*return_line;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(line);
	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (free_safe(&line), NULL);
	i++;
	return_line = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!return_line)
		return (free_safe(&line), NULL);
	while (i < len)
		return_line[j++] = line[i++];
	return_line[j] = '\0';
	return (free_safe(&line), return_line);
}

char	*return_fnc(char *line)
{
	char	*return_line;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	return_line = (char *)malloc(sizeof(char) * i + 1);
	if (!return_line)
		return (free_safe(&line), NULL);
	return_line[i] = '\0';
	while (--i > -1)
		return_line[i] = line[i];
	return (return_line);
}

char	*check_line(char *line, int fd)
{
	int		rd;
	char	*buff;
	char	*tmp;

	if (check_newline(line))
		return (line);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free_safe(&line), NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free_safe(&buff), free_safe(&line), NULL);
		buff[rd] = '\0';
		tmp = ft_strjoin(line, buff);
		free_safe(&line);
		line = tmp;
		if (!line)
			return (free_safe(&buff), NULL);
		if (check_newline(buff))
			break ;
	}
	return (free_safe(&buff), line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		if (!line)
			return (free_safe(&line), NULL);
		line[0] = '\0';
	}
	line = check_line(line, fd);
	if (!line)
		return (free_safe(&line), NULL);
	return_line = return_fnc(line);
	if (!return_line)
		return (free_safe(&line), free_safe(&return_line), NULL);
	line = reset_line(line);
	return (return_line);
}

// int	main()
// {
// 	int fd = open("w2.txt", O_RDONLY );
// 	if (fd < 0)
// 		return(printf("error opening file\n"), 13);
// 	char *str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		free_safe(&str);
// 		str = get_next_line(fd);
// 	}
// 	return (0);
// }
