#include "get_next_line.h"

static char	*read_until_newline(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}


static char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		line = (char *)malloc(i + 2);
		if (!line)
			return (NULL);
		i = 0;
		while (stash[i] != '\0' && stash[i] != '\n')
		{
			line[i] = stash[i];
			i++;
		}
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
	{
		line = (char *)malloc(i + 1);
		if (!line)
			return (NULL);
		i = 0;
		while (stash[i] != '\0')
		{
			line[i] = stash[i];
			i++;
		}
		line[i] = '\0';
	}
	return (line);
}


static char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = (char *)malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i + j] != '\0')
	{
		new_stash[j] = stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_until_newline(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}
