/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:25:56 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 21:48:42 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves(t_list **stack_a, t_list **stack_b, t_list *element)
{
    // Rotate `stack A` to align target position
    while ((*stack_a)->pos != element->target_pos)
    {
        if (element->cost_a > 0)
            ft_ra(stack_a, 1);
        else
            ft_rra(stack_a, 1);
    }

    // Rotate `stack B` to bring the element to the top
    while ((*stack_b)->pos != element->pos)
    {
        if (element->cost_b > 0)
            ft_rb(stack_b, 1);
        else
            ft_rrb(stack_b, 1);
    }

    // Push the element to `stack A`
    ft_pa(stack_a, stack_b, 1);
}

void sort_stack(t_list **stack_a, t_list **stack_b)
{
    if (is_sorted(*stack_a))
        return;
	handle_small_stacks(stack_a);
    if (ft_lstsize(*stack_a) > 3)
    {
        process_large_stack(stack_a, stack_b);
    }
    finalize_stack_a(stack_a, ft_lstsize(*stack_a));
}
void	finalize_stack_a(t_list **stack_a, int size_a)
{
    int min_pos;
    t_list *current;

	current = *stack_a;
	min_pos = 0;
    while (current)
    {
        if (current->content < (*stack_a)->content)
            min_pos = current->pos;
        current = current->next;
    }
    // Rotate to ensure smallest element is at the top
    while ((*stack_a)->pos != min_pos)
    {
        if (min_pos > size_a / 2)
            ft_rra(stack_a, 1);
        else
            ft_ra(stack_a, 1);
    }
}
void	process_large_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest;

    while (*stack_b) // Continue until stack_b is empty
    {
        calculate_positions(*stack_a);
        calculate_positions(*stack_b);
        calculate_target_positions(*stack_a, *stack_b);
        calculate_costs(*stack_a, *stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b));

        cheapest = find_cheapest_element(*stack_b);
        if (cheapest)
        {
            execute_moves(stack_a, stack_b, cheapest);
        }
    }
}
