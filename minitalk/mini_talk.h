#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <limits.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

void	ft_putchar_fd(char c, int fd);
void	print_pid(int pid, int fd);
int		ft_isnum(char c);
int		ft_iswhitespace(char c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);

#endif
