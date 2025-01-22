/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:37:13 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/22 20:37:21 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

char	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		if (str[i] == ' ')
			return (32);
		if (str[i] == '\t')
			return (9);
	}
	return (0);
}

int	initialize_stacks(char **av, t_list **stack_a)
{
	char	*str;
	char	**split_av;

	str = join_args(av, NULL);
	if (!str)
		return (0);
	split_av = ft_split(str, is_space(str));
	free(str);
	if (!split_av)
		return (0);
	ft_parsing_args(ft_strlen_stack(split_av), split_av, stack_a);
	if (!stack_a)
	{
		ft_free_when_error(stack_a, split_av);
		return (1);
	}
	ft_clean(split_av);
	return (*stack_a != NULL);
}
