#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*gnl_get_line(char *stash)
{
	size_t	len;
	size_t	i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_get_rest(char *stash)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*rest;

	len = ft_strlen(stash);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i >= len)
		return (NULL);
	rest = (char *)malloc(len - i + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (stash[i])
	{
		rest[j] = stash[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	return (rest);
}
