#include "mini_talk.h"

void	print_pid(pid_t pid, int fd)
{
	if (pid < 10)
		ft_putchar_fd(pid + '0', fd);
	else
	{
		print_pid(pid / 10, fd);
		ft_putchar_fd(pid % 10 + '0', fd);
	}
}

int	binary_to_decimal(int binary)
{
	int	decimal;
	int	base;
	int	rem;

	decimal = 0;
	base = 1;
	while (binary > 0)
	{
		rem = binary % 10;
		decimal = decimal + rem * base;
		binary = binary / 10 ;
		base = base * 2;
	}
	return (decimal);
}

void	string_creator(char *byte)
{
	int	letter;

	letter = binary_to_decimal(ft_atoi(byte));
	write(1, &letter, 1);
}

void	signal_handler(int signum)
{
	static int	x;
	static char	byte[9];

	if (signum == SIGUSR1)
		byte[x++] = '0';
	if (signum == SIGUSR2)
		byte[x++] = '1';
	if (x == 8)
	{
		byte[x] = '\0';
		x = 0;
		string_creator(byte);
	}
}

int	main(void)
{
	pid_t	pid;
	void	*handler;

	handler = &signal_handler;
	pid = getpid();
	write(1, "PID: ", 5);
	print_pid(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
