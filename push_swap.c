#include "push_swap.h"

void f()
{
    system("leaks push_swap");
}
int	main(int ac, char **av)
{
    //atexit(f);
    t_list  *stack_a;
    t_list  *stack_b;
    char    *str;
    char    **split_av;

    stack_a = NULL;
    stack_b = NULL;
	str = NULL;

    if (ac < 2)
        return (0);
    str = join_args(av, str);
    split_av = ft_split(str, ' ');
    free(str);
	ft_parsing_args(ft_strlen_stack(split_av), split_av, &stack_a);
    if (!stack_a)
    {
        ft_clean(split_av);
        write(2, "Error\n", 6);
        return (1);
    }
    if (stack_a)
        sort_stack(&stack_a, &stack_b);
    free(stack_a);
    free(stack_b);
	return (0);
}



