/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:30:02 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/30 19:42:03 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_checker(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(stack_a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(stack_b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(stack_a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(stack_b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(stack_a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(stack_b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

void	reading(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_checker(str, stack_a, stack_b) == 0)
			ft_free_when_error(stack_a, NULL);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (ac < 2)
		return (0);
	(1) && (i = 1, stack_a = NULL, stack_b = NULL);
	while (ac > i)
	{
		if (is_empty(av[i++]))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
	if (!initialize_stack(av, &stack_a))
		return (1);
	reading(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
