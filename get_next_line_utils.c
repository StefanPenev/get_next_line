#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*str;

    if (!s1)
        return (s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
    free(s1);
	return (str);
}

int ft_strlen(char *s, char c)
{
    int    i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	char *result_ptr;

    if (!s)
        return (NULL);
	i = 1;
	result_ptr = (char *)s;
	if ((char)c == '\0')
	{	
		i = ft_strlen(s, '\n');
		return (result_ptr + i);
	}
	if (result_ptr[0] == (char)c)
		return (result_ptr);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return(result_ptr + i);
		i++;
	}
	return (NULL);
}