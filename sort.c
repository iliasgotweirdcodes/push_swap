/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:23:24 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 21:44:38 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    int first;
    int second;
    int third;

    first = (*stack)->content;
    second = (*stack)->next->content;
    third = (*stack)->next->next->content;

    if (first > second && second < third && first < third)
        ft_sa(stack, 1);
    else if (first > second && second > third)
    {
        ft_sa(stack, 1);
        ft_rra(stack, 1);
    }
    else if (first > second && second < third && first > third)
        ft_ra(stack, 1);
    else if (first < second && second > third && first < third)
    {
        ft_sa(stack, 1);
        ft_ra(stack, 1);
    }
    else if (first < second && second > third && first > third)
        ft_rra(stack, 1);
}
