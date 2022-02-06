#include "so_long.h"

static size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}
static void	ft_strcat(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char c)
{
	int		s1l;
	char	*s;

	if (!s1)
		return (NULL);
	s1l = ft_strlen(s1);
	s = (char *) malloc (sizeof (char) * (s1l + 2));
	if (!s)
		return (NULL);
	s[0] = '\0';
	ft_strcat(s, s1);
	if (c == '\n')
	{
		s[s1l] = '\0';
		free(s1);
		return (s);
	}
	s[s1l] = c;
	s[s1l + 1] = '\0';
	free(s1);
	return (s);
}

static void	ft_strcpy(char	*s1, const char	*s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_strdup(const char	*s1)
{
	int		i;
	char	*scpy;

	i = ft_strlen(s1);
	scpy = (char *) malloc (sizeof (char) * (i + 1));
	if (!scpy)
		return (NULL);
	ft_strcpy(scpy, s1);
	return (scpy);
}

