/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:20:25 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/14 22:05:59 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_gnl_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_move_start(char *start);
char	*ft_readed_line(char *src);
char	*ft_gnl_strchr(char *string, int searchedChar);
char	*ft_gnl_strjoin(char *start, char *buff);
char	*ft_join(char *dest, char *s1, char *s2);

#endif