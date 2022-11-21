/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:15:52 by shamsate          #+#    #+#             */
/*   Updated: 2022/11/21 21:15:58 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_l_str(int fd, char *l_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_l(char *l_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *l_str);
char	*ft_new_l_str(char *l_str);

#endif
