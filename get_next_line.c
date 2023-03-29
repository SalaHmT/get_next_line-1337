/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:46:16 by shamsate          #+#    #+#             */
/*   Updated: 2022/12/02 19:46:16 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_ln(int fd, char *backup)
{
	char	*str;
	int		count;

	str = malloc(BUFFER_SIZE + 1 * sizeof(char ));
	if (!str)
		return (str);
	count = 1;
	while (!ft_strchr(backup, '\n') && count != 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
			return (free(str), free(backup), NULL);
		str[count] = '\0';
		backup = ft_strjoin_l(backup, str);
	}
	return (free(str), backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*final;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	final = 0;
	backup = read_ln(fd, backup);
	if (!backup)
		return (backup);
	final = get_ln(backup);
	backup = get_sv_and_fr(backup);
	return (final);
}
