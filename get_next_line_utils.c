/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:29:27 by shamsate          #+#    #+#             */
/*   Updated: 2022/11/21 21:29:32 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_l(char *l_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!l_str)
	{
		l_str = (char *)malloc(1 * sizeof(char));
		l_str[0] = '\0';
	}
	if (!l_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(l_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (l_str)
		while (l_str[++i] != '\0')
			str[i] = l_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(l_str) + ft_strlen(buff)] = '\0';
	free(l_str);
	return (str);
}

char	*ft_get_line(char *l_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!l_str[i])
		return (NULL);
	while (l_str[i] && l_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (l_str[i] && l_str[i] != '\n')
	{
		str[i] = l_str[i];
		i++;
	}
	if (l_str[i] == '\n')
	{
		str[i] = l_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_l_str(char *l_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (l_str[i] && l_str[i] != '\n')
		i++;
	if (!l_str[i])
	{
		free(l_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(l_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (l_str[i])
		str[j++] = l_str[i++];
	str[j] = '\0';
	free(l_str);
	return (str);
}
