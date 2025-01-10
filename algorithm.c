/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:43:43 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 21:46:00 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_positions(t_list *stack)
{
	int pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}

void	calculate_target_positions(t_list *stack_a, t_list *stack_b)
{
    t_list	*current_b;
    t_list	*current_a;
    int		target_pos;

    current_b = stack_b;
    while (current_b)
    {
        current_a = stack_a;
        target_pos = 0;
        while (current_a)
        {
            if (current_b->content < current_a->content)
                break;
            target_pos++;
            current_a = current_a->next;
        }
        current_b->target_pos = target_pos;
        current_b = current_b->next;
    }
}
int calculate_cost(int current_pos, int target_pos, int size)
{
    int forward_cost;
    int backward_cost;

    // Calculate the cost of moving forward
    if (target_pos >= current_pos)
        forward_cost = target_pos - current_pos;
    else
        forward_cost = (size - current_pos) + target_pos;

    // Calculate the cost of moving backward
    if (current_pos >= target_pos)
        backward_cost = current_pos - target_pos;
    else
        backward_cost = current_pos + (size - target_pos);

    // Return the smaller of the two costs
    return (forward_cost < backward_cost) ? forward_cost : backward_cost;
}
void calculate_costs(t_list *stack_a, t_list *stack_b, int size_a, int size_b)
{
    t_list *current_b;

    current_b = stack_b;
    while (current_b)
    {
        current_b->cost_a = calculate_cost(current_b->target_pos, stack_a->pos, size_a);
        current_b->cost_b = calculate_cost(current_b->pos, 0, size_b);
        current_b = current_b->next;
    }
}
t_list	*find_cheapest_element(t_list *stack_b)
{
    t_list *cheapest = stack_b;
    t_list *current = stack_b;

    while (current)
    {
        if ((current->cost_a + current->cost_b) < (cheapest->cost_a + cheapest->cost_b))
            cheapest = current;
        current = current->next;
    }
    return cheapest;
}
