/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:51:55 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/21 20:55:30 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_list **stack_a, int i)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
		last = last->next;
	before_last = *stack_a;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (i)
		ft_putstr("rra\n", 1);
}

void	ft_rrb(t_list **stack_b, int i)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
		last = last->next;
	before_last = *stack_b;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (i)
		ft_putstr("rrb\n", 1);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, int i)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (i)
		ft_putstr("rrr\n", 1);
}
