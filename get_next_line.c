#include "get_next_line.h"

static char	*read_buff (int fd, char *nextl, char *buff)
{
	char	*temp;
	ssize_t	b_read;

	b_read = 1;
	while (b_read)
	{
		b_read = read (fd, buff, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buff[b_read] = '\0';
		if (!nextl)
			nextl = ft_strdup("");
		temp = nextl;
		nextl = ft_strjoin(nextl, buff);
		if (!nextl)
			return (NULL);
		free (temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (nextl);
}

static char	*remain_str (char *line)
{
	char	*nextl;
	int		i;
	
	i = 0;	
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	nextl = ft_strdup(&line[i + 1]);
	line[i + 1] = '\0';
	return (nextl);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*nextl;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	line = read_buff (fd, nextl, buff);
	if (!line)
		return (NULL);
	nextl = remain_str (line);
	return (line);
}

/* #include<stdio.h>
#include<fcntl.h>
int		main(void)
{
	int		fd;	
	char	*line;

	fd = 1;
	while (line)
	{
		line = get_next_line (fd);
		if (!line)
			break;
		printf ("%s", line);
		free (line);
	}
	close (fd);
} */