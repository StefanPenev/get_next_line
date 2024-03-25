/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:40:18 by spenev            #+#    #+#             */
/*   Updated: 2024/03/25 12:12:33 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		find_nl(char *s);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strlen(char *s, char c);

char	*get_next_line(int fd);

char	*read_file(int fd, char *buff);

char	*get_linee(char *buff);

char	*remove_line(char *static_buf);

char	*ft_calloc(int size, int type_size);

void	ft_bzero(char *s, int size);

#endif