#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*nextl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nextl = read_buffer (fd, nextl);
	if (!nextl)
		return (NULL);
	line = get_line(nextl);
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