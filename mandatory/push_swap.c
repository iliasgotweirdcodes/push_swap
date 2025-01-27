/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:57:19 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/27 18:44:21 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	initialize_stack(char **av, t_list **stack_a)
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
void f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	// atexit(f);
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (ac < 2)
		return (0);
	i = 1;
	while (ac > i)
	{
		if (is_empty(av[i++]))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
	stack_a = NULL;
	stack_b = NULL;
	if (!initialize_stack(av, &stack_a))
		return (1);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
