/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:43:23 by spenev            #+#    #+#             */
/*   Updated: 2024/03/25 12:25:26 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*remove_line(char *buff)
{
	int		i;
	int		j;
	char	*temp;

	if (find_nl(buff) < 0 || !buff)
	{
		free(buff);
		return (NULL);
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	temp = ft_calloc((ft_strlen(buff, '\0') - i + 2), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		temp[j++] = buff[i++];
	free(buff);
	return (temp);
}

char	*get_linee(char *buff)
{
	char	*line;
	int		i;

	if (!*buff)
		return (NULL);
	line = ft_calloc((ft_strlen(buff, '\n') + 2), sizeof(char));
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

char	*read_file(int fd, char *buff)
{
	int		bytes_read;
	char	*buffer;

	if (!buff)
		buff = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (find_nl(buff) < 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(buff);
			buff = NULL;
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
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff[fd])
		{
			free(buff[fd]);
			buff[fd] = NULL;
		}
		return (NULL);
	}
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = get_linee(buff[fd]);
	buff[fd] = remove_line(buff[fd]);
	return (line);
}
