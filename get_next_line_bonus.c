#include "get_next_line_bonus.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->buf[i] && last_node->buf[i] != '\n')
		++i;
	while (last_node->buf[i] && last_node->buf[++i])
		buf[k++] = last_node->buf[i];
	buf[k] = '\0';
	clean_node->buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char    *extract_line(t_list *buff)
{
    int     len;
    char    *line;

    if (!buff)
        return (NULL);
    len = get_len_to_nl(buff);
    line = malloc(sizeof(char) * (len + 1));
    if (!line)
        return (NULL);
    copy_line(buff, line);
    return (line);
}

void    read_line(int fd, t_list **buff)
{
    char    *line;
    int bytes_read;

    while (!found_nl(*buff))
    {
        line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!line)
            return ;
        bytes_read = read(fd, line, BUFFER_SIZE);
        if (!bytes_read)
        {
            free(line);
            return ;
        }
        line[bytes_read] = '\0';
        create_new_node(buff, line);
    }
}

char	*get_next_line(int fd)
{
    static t_list   *buff;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (NULL);
    read_line(fd, &buff);
    if (buff == NULL)
        return (NULL);
    line = extract_line(buff);
    polish_list(&buff);
    return (line);
}
