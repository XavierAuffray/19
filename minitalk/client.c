#include "mini_talk.h"

char	*chartobin(unsigned char c)
{
	static char	bin[CHAR_BIT + 1];
	int			i;

	i = CHAR_BIT - 1;
	while (i >= 0)
	{
		bin[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	return (bin);
}

void	launcher(char *str, int pid)
{
	char	*binary;
	int		x;

	while (*str)
	{
		x = 0;
		binary = chartobin(*str);
		str++;
		while (binary[x])
		{
			if (binary[x] == '0')
				kill(pid, SIGUSR1);
			else if (binary[x] == '1')
				kill(pid, SIGUSR2);
			x++;
			usleep(150);
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	launcher(str, pid);
	return (0);
}
