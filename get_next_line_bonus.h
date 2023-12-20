#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(char *content);

t_list	*ft_lstlast(t_list *lst);

int 	found_nl(t_list *list);

void    create_new_node(t_list **buff, char  *line);

int 	get_len_to_nl(t_list *buff);

void    copy_line(t_list *buff, char *line);

void	dealloc(t_list **list, t_list *clean_node, char *buf);

char    *extract_line(t_list *buff);

void    read_line(int fd, t_list **buff);

void	polish_list(t_list **list);

char	*get_next_line(int fd);

#endif
