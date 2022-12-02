/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:45:08 by shamsate          #+#    #+#             */
/*   Updated: 2022/12/02 19:45:08 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_ln(int fd, char *line)
{
	char	*str;
	int		count;

	str = malloc(BUFFER_SIZE + 1 * sizeof(char ));
	if (!str)
		return (str);
	count = 1;
	while (!ft_strchr(line, '\n') && count != 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
			return (free(str), free(line), NULL);
		str[count] = '\0';
		line = ft_strjoin_l(line, str);
	}
	return (free(str), line);
}

char	*get_next_line(int fd)
{
	static char	*line[10240];
	char		*final;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = read_ln(fd, line[fd]);
	if (!line[fd])
		return (line[fd]);
	final = get_ln(line[fd]);
	line[fd] = get_sv_and_fr(line[fd]);
	return (final);
}
