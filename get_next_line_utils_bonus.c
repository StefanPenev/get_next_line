/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:42:55 by spenev            #+#    #+#             */
/*   Updated: 2024/03/25 12:20:36 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(int size, int type_size)
{
	char	*temp;

	temp = (char *)malloc(size * type_size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (size * type_size));
	return (temp);
}

void	ft_bzero(char *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
		s[i++] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (s2);
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1, '\0') + \
	ft_strlen(s2, '\0') + 1), sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen(char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	find_nl(char *s)
{
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
