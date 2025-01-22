/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:16:44 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/21 20:56:03 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_add_node(t_list **stack_a, int content, int index)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->i = index;
	new_node->next = NULL;
	if (!(*stack_a))
		*stack_a = new_node;
	else
	{
		tmp = *stack_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
