/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:46:01 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/21 20:55:25 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (i)
		ft_putstr("pa\n", 1);
}

void	ft_pb(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (i)
		ft_putstr("pb\n", 1);
}
