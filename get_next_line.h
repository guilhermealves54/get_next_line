#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_buffer (int fd, char *nextl);
char	*get_line(char *nextl);
char	*remaining_str (char *nextl);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

#endif