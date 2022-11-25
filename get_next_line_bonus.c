/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:58:24 by shamsate          #+#    #+#             */
/*   Updated: 2022/11/22 21:58:27 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_ln(char *backup)
{
	int		len;
	int		x;
	char	*line;

	len = 0;
	if (*backup == '\0')
		return (NULL);
	while (backup[len] && backup[len] != '\n')
		len++;
	if (backup[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	x = 0;
	while (x < len)
	{
		line[x] = backup[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

static char	*get_bkandsv(char *backup)
{
	char	*str;
	int		start;
	int		i;

	start = 0;
	while (backup[start] && backup[start] != '\n')
		start++;
	if (backup[start] == '\n')
		start++;
	if (backup[start] == '\0')
		return (free(backup), backup = NULL, NULL);
	str = malloc(sizeof(char) * (ft_strlen(backup) - start + 1));
	if (!str)
		return (free(backup), backup = NULL, NULL);
	i = 0;
	while (backup[start])
		str[i++] = backup[start++];
	str[i] = '\0';
	return (free(backup), backup = NULL, str);
}

static char	*read_ln(char *backup, int fd)
{
	int		byte;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (byte > 0 && ft_index(backup, '\n') == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
			return (free(buff), buff = NULL, NULL);
		buff[byte] = '\0';
		backup = ft_strjoin_l(backup, buff);
	}
	return (free(buff), buff = NULL, backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = read_ln(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	line = get_ln(backup[fd]);
	backup[fd] = get_bkandsv(backup[fd]);
	return (line);
}
