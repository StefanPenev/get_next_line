#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *s1, char *s2);

int ft_strlen(char *s, char c);

char	*get_next_line(int fd);

char    *read_file(int fd, char *buff);

char    *get_line(char *buff);

char	*remove_line(char *static_buf);

#endif