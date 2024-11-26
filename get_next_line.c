#include "get_next_line.h"

char	*read_buffer (fd, char *nextl);
{
	char	*buffer;
	int		i;
	size_t	b_read;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read (fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[b_read] = '\0';
		nextl = ft_strjoin(nextl, buffer);
		if (ft_strchr(nextl, '\n'))
			break ;
	}
	free (buffer);
	return (nextl);
}

char	*get_line(char *nextl)
{
	int		i;
	char	*line;

	i = 0;
	while (nextl[i] != '\n')
		i++;
	line = malloc ((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (nextl[i] != '\n')
	{
		line[i] = nextl[i];
		i++;
	}
	line[i] = '\0'
	return (line);
}

/* char	*remainig_str (char *nextl)
{
	int		i;
	int		n;

	i = 0;
	while (nextl[i] != '\n')
		i++;
	nextl[i] = '\0';
	n = i - 1;
	i = strlen(nextl);
	while (n >= 0)
	{
		nextl[n] = nextl[i];
		i--;
		n--;
	}
	return (nextl);
} */

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
	fd = open ("test.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line (fd);
		printf ("%s", line);
		free (line);
		i++;
	}
	close (fd);
}