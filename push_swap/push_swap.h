#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_value
{
	long		value;
	int			index;
	long long	binary;	
}				t_value;

void	push(t_value **stack_src, t_value **stack_dest, int ref);
void	rotate(t_value **stack, int ref);
void	reverse_rotate(t_value **stack, int ref);
void	swap(t_value **stack, int ref);
t_value	*create_stack_a(int counter, char **argv);
t_value	*create_stack_b(int counter);
int		free_stacks(t_value **stack_a, t_value **stack_b);
int		free_stack_a(t_value **stack);
void	swap_values(long *x, long *y);
t_value	*bbsort_list(t_value *stack);
int		stack_is_ordered(t_value *stack_a);
t_value	*dup_list(t_value *stack);
void	assign_index(t_value *stack_a);
int		get_number_of_bits(t_value *stack_a);
void	radix(t_value **stack_a, t_value **stack_b);
int		an_error_occured(char **argv, int argc);
int		doublon_in_stack(t_value *stack);
int		over_min_max_values(t_value *stack);
void	make_a_magic_trick(t_value **stack_a, t_value **stack_b);
void	handle_three(t_value **stack_a, t_value **stack_b, int ref);
void	rr_and_p(t_value **stack_a, t_value **stack_b, int rr, int p);
void	s_and_p(t_value **stack_a, t_value **stack_b, int s, int p);

#endif
