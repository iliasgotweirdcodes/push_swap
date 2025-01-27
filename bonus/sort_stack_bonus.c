/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:25:34 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/23 23:07:25 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	ft_give_index(stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size_a == 2)
		sort_two(stack_a);
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a == 5)
		sort_five(stack_a, stack_b);
	else if (is_sorted(*stack_a) == 0)
		sort_pivot(stack_a, stack_b);
}
