#include "get_next_line_bonus.h"

char	*remove_line(char *static_buf)
{
	int 	i;
	int 	j;
	char	*temp;

	if (!strchr(static_buf, '\n') || !static_buf)
	{
		free(static_buf);
		return (NULL);
	}
	i = 0;
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(static_buf, '\0') - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while(static_buf[i])
		temp[j++] = static_buf[i++];
	free(static_buf);
	return (temp);
}

char    *get_line(char *buff)
{
    char    *line;
    int     i;

    if (!*buff)
        return (NULL);
    line = (char *)malloc(sizeof(char) * (ft_strlen(buff, '\n') + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (buff[i] && buff[i] != '\n')
    {
        line[i] = buff[i];
        i++;
    }
    if (buff[i] && buff[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *read_file(int fd, char *buff)
{
    int     bytes_read;
    char    *buffer;

    if(!buff)
        buff = (char *)malloc(sizeof(char));
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!strchr(buff, '\n') && bytes_read)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(buff);
            buffer = NULL;
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        buff = ft_strjoin(buff, buffer);
    }
    free (buffer);
    return (buff);
}

char	*get_next_line(int fd)
{
    static char *buff[1024];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        if(buff[fd])
        {
            free(buff[fd]);
            buff[fd] = NULL;
        }
         return (NULL);
    }
    buff[fd] = read_file(fd, buff[fd]);
    if (!buff[fd])
        return (NULL);
    line = get_line(buff[fd]);
    buff[fd] = remove_line(buff[fd]);
    return (line);
}