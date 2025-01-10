/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:51:55 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 21:33:32 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, int i)
{
	t_list *tmp;
	t_list *last;

	if (!(*stack_a) || !(*stack_a)->next)
		return;
		last = *stack_a;
	while (last->next)
	last = last->next;
	tmp = *stack_a;
	*stack_a = last;
	last->next = tmp;
	while (last->next != tmp)
		last = last->next;
	last->next = NULL;
	if (i)
		ft_putstr("rra\n", 1);
}
void	ft_rrb(t_list **stack_b, int i)
{
	t_list *tmp;
	t_list *last;

	if (!(*stack_b) || !(*stack_b)->next)
		return;
	last = *stack_b;
	while (last->next)
		last = last->next;
	tmp = *stack_b;
	*stack_b = last;
	last->next = tmp;
	while (last->next != tmp)
		last = last->next;
	last->next = NULL;
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
