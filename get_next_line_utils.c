#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_str;
	size_t	i;

	i = 0;
	tmp_str = (char *) malloc ((ft_strlen (s1) + 1) * sizeof(char));
	if (tmp_str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		tmp_str[i] = s1[i];
		i++;
	}
	tmp_str[i] = '\0';
	return (tmp_str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = 0;
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		str[i] = s2[n];
		n++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	n;

	i = 0;
	n = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == n)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == n)
		return ((char *) &s[i]);
	return (NULL);
}