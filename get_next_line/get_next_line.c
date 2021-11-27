#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	if (c == 0)
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*loop(char **save, int fd, int *y, char *temp)
{
	char	*buffer;
	int		x;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		*y = -1;
		return (NULL);
	}
	x = read(fd, buffer, BUFFER_SIZE);
	if (x == -1)
	{
		free(buffer);
		free(temp);
		*y = -1;
		return (NULL);
	}
	if (!x)
	{
		*save = ft_strdup(temp, buffer, 1, 1);
		return (NULL);
	}
	buffer[x] = '\0';
	temp = ft_strjoin(temp, buffer, y);
	return (temp);
}

void	create_line(char **save, int fd, int *y, char **line)
{
	char	*temp;
	int		x;

	temp = ft_strdup(*save, *save, 1, 0);
	if (!temp)
	{
		*y = -1;
		return ;
	}
	while (!ft_strchr(temp, '\n'))
	{
		temp = loop(save, fd, y, temp);
		if (!temp)
		{
			*line = NULL;
			return ;
		}
	}
	x = 0;
	while (temp[x] != '\n')
		x++;
	*save = ft_substr(temp, x + 1, ft_strlen(temp), 0);
	*line = ft_substr(temp, 0, x, 1);
	if (!*save || !*line)
		*y = -1;
}

int	an_error_occured(char **line, char **save, int fd)
{
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (1);
	if (!*save)
	{
		*save = (char *)malloc(BUFFER_SIZE + 1);
		if (!*save)
			return (1);
		**save = '\0';
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*save;
	int				y;

	if (an_error_occured(line, &save, fd))
		return (-1);
	y = 0;
	create_line(&save, fd, &y, line);
	if (y == -1 || !save)
	{
		save = NULL;
		return (-1);
	}
	if (!*line)
	{
		*line = ft_strdup(save, save, 1, 0);
		if (!*line)
			return (-1);
		save = NULL;
	}
	return (save != NULL);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line;
	int fd;
	int y;

	fd = open("test.txt", O_RDONLY);
	while ((y = get_next_line(fd, &line)) == 1)
	{
		printf("%d -- |%s|\n", y, line);
		free(line);
	}
	if (y == -1)
		printf("%d -- error\n", y);
	else
	{
		printf("%d -- |%s|\n", y, line);
		free(line);
	}
	y = get_next_line(fd, &line);
	if (y == -1)
		printf("%d -- error\n", y);
	else
	{
		printf("%d -- |%s|\n", y, line);
		free(line);
	}
	return 0;
}
*/
