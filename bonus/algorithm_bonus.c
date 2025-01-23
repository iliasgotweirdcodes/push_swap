/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:43:43 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/23 21:15:31 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	last_element(t_list **stack_a, t_list **last)
{
	*last = (*stack_a);
	while ((*last)->next)
		*last = (*last)->next;
}

void	ft_rb_rrb(t_list **stacka, t_list **stackb, int content, t_list **last)
{
	if (find_position(stackb, (*stacka)->i - 1) > ft_lstsize(*stackb) / 2)
	{
		if (((*last)->i < (*stackb)->i || (*last)->i == content))
		{
			ft_pa(stacka, stackb, 1);
			ft_ra(stacka, 1);
			last_element(stacka, last);
		}
		else if (stackb)
			ft_rrb(stackb, 1);
	}
	else
	{
		if ((*last)->i < (*stackb)->i || (*last)->i == content)
		{
			ft_pa(stacka, stackb, 1);
			ft_ra(stacka, 1);
			last_element(stacka, last);
		}
		else if (stackb)
			ft_rb(stackb, 1);
	}
}

void	sort_pivot(t_list **stack_a, t_list **stack_b)
{
	int	last_pivot;
	int	pivot_one;
	int	pivot_two;

	last_pivot = -1;
	pivot_one = ft_lstsize(*stack_a) / 3;
	pivot_two = ft_lstsize(*stack_a) / 6;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->i < pivot_one)
			ft_pb(stack_a, stack_b, 1);
		else
			ft_ra(stack_a, 1);
		if ((*stack_b) && ft_lstsize(*stack_b) > 1
			&& ((*stack_b)->i >= last_pivot && (*stack_b)->i >= pivot_two))
			ft_rb(stack_b, 1);
		if (ft_lstsize(*stack_b) == pivot_one)
		{
			last_pivot = pivot_one;
			pivot_one = ft_lstsize(*stack_a) / 3 + pivot_one;
			pivot_two = ft_lstsize(*stack_a) / 6 + last_pivot;
		}
	}
	sort_three(stack_a);
	sort_pivot_b(stack_a, stack_b);
}

void	sort_pivot_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		content;

	last_element(stack_a, &tmp);
	content = tmp->i;
	while (stack_b)
	{
		while ((*stack_b) && (*stack_b)->i + 1 != (*stack_a)->i)
			ft_rb_rrb(stack_a, stack_b, content, &tmp);
		while (*stack_b && (*stack_b)->i == (*stack_a)->i - 1)
			ft_pa(stack_a, stack_b, 1);
		if ((*stack_a)->i -1 == tmp->i)
		{
			while ((*stack_a)->i - 1 == tmp->i)
			{
				ft_rra(stack_a, 1);
				last_element(stack_a, &tmp);
			}
		}
		if (is_sorted(*stack_a) && (ft_lstsize(*stack_b) == 0))
			break ;
	}
}
