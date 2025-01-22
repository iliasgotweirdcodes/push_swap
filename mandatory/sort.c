/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:23:24 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/21 20:55:33 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_two(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		ft_sa(stack, 1);
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	if (a > b && b < c && a < c)
		ft_sa(stack, 1);
	else if (a > b && b > c)
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack, 1);
		ft_ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack, 1);
}
