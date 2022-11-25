/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:54:52 by shamsate          #+#    #+#             */
/*   Updated: 2022/11/22 23:12:58 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*ft_strjoin_l(char *s1, char const *s2);
unsigned int	ft_strlen(const char *str);
int				ft_index(const char *s, char c);
char			*ft_strdup(const char *s1);

#endif
