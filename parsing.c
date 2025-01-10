/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:46:47 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 22:27:30 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicates(t_list *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return 0;
}
int	ft_validate_and_add(char *str, t_list **stack_a, int *index)
{
	int	error;
	int	num;

	num = ft_atoi(str, &error);
	if (error || has_duplicates(*stack_a, num))
		return (0);
	ft_add_node(stack_a, num, (*index)++);
	return (1);
}

// Helper function to parse string array
int	ft_parse_str_array(char **str, t_list **stack_a, int *index)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!ft_validate_and_add(str[j], stack_a, index))
			return (0);
		j++;
	}
	return (1);
}

// Main parsing function
void	ft_parsing_args(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		index;
	char	**str;

	i = 0;
	index = 0;
	while (++i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str || !str[0] || !ft_parse_str_array(str, stack_a, &index))
		{
			ft_free_when_error(stack_a, str);
			return ;
		}
		ft_clean(str);
	}
}


