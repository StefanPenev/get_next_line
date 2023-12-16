#include "get_next_line.h"

size_t  ft_strlen(char *s)
{
    size_t    i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	char *result_ptr;

    if (!s)
        return (0);
	i = 1;
	result_ptr = (char *)s;
	if ((char)c == '\0')
	{	
		i = ft_strlen(s);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

    if (!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	len_s;
// 	char	*str;

// 	if (!s)
// 		return (NULL);
// 	len_s = ft_strlen(s);
// 	if (start > len_s)
// 		len = 0;
// 	else if (len > (len_s - start))
// 		len = len_s - start;
// 	str = (char*)malloc(sizeof(*s) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }