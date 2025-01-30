/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:25:45 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/30 17:55:38 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_list **stack_a, int i)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (i)
		ft_putstr("sa\n", 1);
}

void	ft_sb(t_list **stack_b, int i)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (i)
		ft_putstr("sb\n", 1);
}

void	ft_ss(t_list **stack_a, t_list **stack_b, int i)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (i)
		ft_putstr("ss\n", 1);
}
