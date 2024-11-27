#include "get_next_line.h"

char	*read_buffer (int fd, char *nextl)
{
	char	*buffer;
	char	*temp;
	size_t	b_read;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read (fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
		{
			return (free (buffer), NULL);
		}
		buffer[b_read] = '\0';
		temp = nextl;
		nextl = ft_strjoin(temp, buffer);
		free (temp);
		if (ft_strchr(nextl, '\n'))
			break ;
	}
	if (b_read == 0 && !*nextl)
		return (free(nextl), NULL);
	return (free (buffer), nextl);
}

char	*get_line(char *nextl)
{
	int		i;
	char	*line;

	i = 0;
	while (nextl[i] != '\0' && nextl[i] != '\n')
		i++;
	line = malloc ((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (nextl[i] != '\n')
	{
		line[i] = nextl[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remaining_str (char *nextl)
{
	int		i;
	int		n;
	char	*remain;

	i = 0;
	while (nextl[i] != '\0' && nextl[i] != '\n')
		i++;
	if (nextl[i] == '\0')
		return (free (nextl), NULL);
	n = ft_strlen(nextl) - i;
	remain = malloc (sizeof(char) * (n + 1));
	if (!remain)
		return (NULL);
	remain[n] = '\0';
	n -= 1;
	while (n >= 0)
	{
		remain[n] = nextl[i];
		n--;
		i--;
	}
	free (nextl);
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*nextl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nextl = read_buffer (fd, nextl);
	if (!nextl)
		return (NULL);
	line = get_line (nextl);
	nextl = remaining_str (nextl);
	return (line);
}

#include<stdio.h>
#include<fcntl.h>
int		main(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 1;
	fd = open ("test", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line (fd);
		printf ("%s", line);
		free (line);
		i++;
	}
	close (fd);
}