/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:25:34 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 21:41:31 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handle_small_stacks(t_list **stack_a)
{
    int size_a = ft_lstsize(*stack_a);

    if (size_a == 2)
    {
        sort_two(stack_a);
    }
    else if (size_a == 3)
    {
        sort_three(stack_a);
    }
}




