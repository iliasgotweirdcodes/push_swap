/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:54:46 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/21 20:59:07 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_give_index(t_list **stacka)
{
	t_list	*current;
	t_list	*tmp;
	int		index;

	current = *stacka;
	index = 0;
	while (current)
	{
		tmp = *stacka;
		index = 0;
		while (tmp)
		{
			if (current->content > tmp->content)
				index++;
			tmp = tmp->next;
		}
		current->i = index;
		current = current->next;
	}
}

int	find_min_index(t_list *stack)
{
	int	min_index;

	min_index = stack->i;
	while (stack)
	{
		if (stack->i < min_index)
			min_index = stack->i;
		stack = stack->next;
	}
	return (min_index);
}

int	find_position(t_list **stack_a, int index)
{
	t_list	*current;
	int		position;

	current = *stack_a;
	position = 0;
	while (current && current->i != index)
	{
		current = current->next;
		position++;
	}
	return (position);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	pushed_to_b;
	int	min_index;
	int	pos;

	pos = 0;
	pushed_to_b = 0;
	while (pushed_to_b < 2)
	{
		min_index = find_min_index(*stack_a);
		pos = find_position(stack_a, min_index);
		if (pos > ft_lstsize(*stack_a) / 2)
			while ((*stack_a)->i != min_index)
				ft_rra(stack_a, 1);
		else
			while ((*stack_a)->i != min_index)
				ft_ra(stack_a, 1);
		ft_pb(stack_a, stack_b, 1);
		pushed_to_b++;
	}
	sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b, 1);
}
