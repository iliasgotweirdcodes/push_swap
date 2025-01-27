/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:51:31 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/27 18:39:37 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_list	**stack_a, int i)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (i)
		ft_putstr("ra\n", 1);
}

void	ft_rb(t_list **stackb, int i)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stackb) || !(*stackb)->next)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	last = *stackb;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (i)
		ft_putstr("rb\n", 1);
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int i)
{
	ft_ra(&(*stack_a), 0);
	ft_rb(&(*stack_b), 0);
	if (i)
		ft_putstr("rr\n", 1);
}
