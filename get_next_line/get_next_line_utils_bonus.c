#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x])
		x++;
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len, int to_free)
{
	char	*str;
	size_t	x[2];

	x[0] = 0;
	x[1] = 0;
	str = (char *)malloc(len + 1);
	if (!str && !to_free)
		return (NULL);
	else if (!str && to_free)
	{
		free((void *)s);
		return (NULL);
	}
	while (s[x[0]])
	{
		if (x[0] >= start && x[1] < len)
			str[x[1]++] = s[x[0]];
		x[0]++;
	}
	str[x[1]] = '\0';
	if (to_free)
		free((void *)s);
	return (str);
}

char	*ft_strdup(char *str, char *yes, int to_free, int again)
{
	char	*copy;
	int		length;
	int		x;

	length = ft_strlen(str);
	copy = (char *)malloc(length + 1);
	if (!copy)
	{
		free(str);
		return (NULL);
	}
	x = -1;
	while (str[++x] != '\0')
		copy[x] = str[x];
	copy[x] = '\0';
	if (to_free)
		free(str);
	if (again)
		free(yes);
	return (copy);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = ft_strlen(dest);
	y = ft_strlen(src);
	if (size == 0 || x > size)
		return (size + y);
	if (!src)
		return (x);
	y = 0;
	while (src[y] && (x + y < size - 1))
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = '\0';
	return (x + ft_strlen(src));
}

char	*ft_strjoin(const char *s1, char const *s2, int *y)
{
	char	*result;
	int		size;
	int		x;

	x = -1;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(size);
	if (!result)
	{
		free((void *)s1);
		free((void *)s2);
		*y = -1;
		return (NULL);
	}
	while (s1[++x] != '\0')
		result[x] = s1[x];
	result[x] = '\0';
	ft_strlcat(result, (char *)s2, size);
	free((void *)s1);
	free((void *)s2);
	return (result);
}
