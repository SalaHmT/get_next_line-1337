/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:45:31 by shamsate          #+#    #+#             */
/*   Updated: 2022/12/02 19:45:31 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (s);
	if ((unsigned char )c == 0)
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (*(s + (++i)))
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin_l(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (s1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s2);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!str)
		return (free(str), str = NULL, str);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str [i + j] = s2[j];
	str [i + j] = '\0';
	return (free(s1), str);
}

char	*get_ln(char *backup)
{
	char	*str;
	int		i;

	i = 0;
	if (*backup == 0)
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_sv_and_fr(char *backup)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
		return (free(backup), NULL);
	str = (char *)malloc((ft_strlen(backup) - i + 1) * sizeof(char));
	if (!str)
		return (str);
	i++;
	j = 0;
	while (backup[i])
	{
		str[j] = backup[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(backup), str);
}
