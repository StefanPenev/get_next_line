#include "get_next_line.h"

char	*read_line(int fd, char *static_buf)
{
	char	*buf;
	char	*temp;
	int 	bytes_rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_rd = 1;
	while (!ft_strchr(static_buf, '\n') && bytes_rd)
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_rd] = '\0';
		temp = ft_strjoin(static_buf, buf);
		static_buf = temp;
	}
	free(buf);
	return (static_buf);
}

char	*get_line(char *static_buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!static_buf[i])
		return (NULL);
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (static_buf[i] && static_buf[i] != '\n')
	{
		str[i] = static_buf[i];
		i++;
	}
	if (static_buf[i] == '\n')
	{
		str[i] = static_buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*remove_line(char *static_buf)
{
	int 	i;
	int 	j;
	char	*temp;

	if (!ft_strchr(static_buf, '\n') || !static_buf)
	{
		free(static_buf);
		return (NULL);
	}
	i = 0;
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(static_buf) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while(static_buf[i])
		temp[j++] = static_buf[i++];
	free(static_buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buf = read_line(fd, static_buf);
	if (!static_buf)
		return (NULL);
	line = get_line(static_buf);
	static_buf = remove_line(static_buf);
	return (line);
}