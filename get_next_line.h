#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

size_t  ft_strlen(char *s);

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *left_str, char *buff);

char	*read_line(int fd, char *static_buf);

char	*get_line(char *statoc_buf);

char	*remove_line(char *static_buf);

char	*get_next_line(int fd);

#endif