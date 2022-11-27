/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:51:01 by shamsate          #+#    #+#             */
/*   Updated: 2022/11/26 15:31:29 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_ln(char *backup)
{
	int		len;
	int		c;
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
	c = 0;
	while (c < len)
	{
		line[c] = backup[c];
		c++;
	}
	line[c] = '\0';
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
	int		bloc;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	bloc = 1;
	while (bloc > 0 && ft_index(backup, '\n') == -1)
	{
		bloc = read(fd, buff, BUFFER_SIZE);
		if (bloc == 0)
			break ;
		if (bloc == -1)
		{
			return (free(buff), buff = NULL, NULL);
		}
		buff[bloc] = '\0';
		backup = ft_strjoin_l(backup, buff);
	}
	return (free(buff), buff = NULL, backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_ln(backup, fd);
	if (!backup)
		return (free(backup), backup = NULL, NULL);
	line = get_ln(backup);
	backup = get_bkandsv(backup);
	return (line);
}

// int	main(void)
// {
// 	char	*ln;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		ln = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, ln);
// 		free(ln);
// 		ln = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, ln);
// 		free(ln);
// 		ln = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, ln);
// 		free(ln);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// /
