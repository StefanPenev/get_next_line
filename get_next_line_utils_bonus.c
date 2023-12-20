#include "get_next_line_bonus.h"

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

void    copy_line(t_list *buff, char *line)
{
    int i;
    int j;

    if (!buff)
        return ;
    j = 0;
    while (buff)
    {
        i = 0;
        while (buff->buf[i])
        {
            if (buff->buf[i] == '\n')
            {
                line[j++] = '\n';
                line[j] = '\0';
                return ;
            }
            line[j] = buff->buf[i];
            j++;
            i++;
        }
        buff = buff->next;
    }
    line[j] = '\0';
}

int get_len_to_nl(t_list *buff)
{
    int i;
    int len;

    if (!buff)
        return (0);
    len = 0;
    while (buff)
    {
        i = 0;
        while (buff->buf[i])
        {
            if (buff->buf[i] == '\n')
            {
                len++;
                return (len);
            }
            len++;
            i++;
        }
        buff = buff->next;
    }
    return (len);
}

void    create_new_node(t_list **buff, char  *line)
{
    t_list  *new_node;
    t_list  *last_node;

    last_node = ft_lstlast(*buff);
    new_node = ft_lstnew(line);
    if (!new_node)
        return ;
    if (!last_node)
        *buff = new_node;
    else 
        last_node->next = new_node;
}

int found_nl(t_list *list)
{
    int i;

    if (!list)
        return (0);
    while (list)
    {
        i = 0;
        while (list->buf[i])
        {
            if (list->buf[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (0);
}

t_list	*ft_lstnew(char *content)
{
	t_list *list;

    list = (t_list *)malloc(sizeof(*list));
    if (!list)
        return (NULL);
    list->buf = content;
    list->next = NULL;
    return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
        return (NULL); 
     while (lst->next)
        lst = lst->next;
    return (lst);
}
