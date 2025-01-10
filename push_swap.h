/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:57:54 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/10 22:24:54 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_list
{
	int		content;
	int		i;
	int		pos;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	struct s_list	*next;
}	t_list;

// Parsing functions
void	ft_parsing_args(int ac, char **av, t_list **stack_a);
void	ft_add_node(t_list **stack_a, int content, int index);
void	ft_free_when_error(t_list **stack, char **str);
void	free_stack(t_list **stack);
void	ft_clean(char **str);
int		ft_atoi(const char *str, int *error);
int		has_duplicates(t_list *stack, int num);
char	*join_args(char **av, char *str);

// Utility functions
char	**ft_split(char *s, char c);
int		ft_atoi(const char *str, int *error);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_stack(char **s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr(const char *str, int fd);

// actoins
void	ft_pa(t_list **stack_a, t_list **stack_b, int i);
void	ft_pb(t_list **stack_a, t_list **stack_b, int i);
void	ft_sa(t_list **stack_a, int i);
void	ft_sb(t_list **stack_b, int i);
void	ft_ss(t_list **stack_a, t_list **stack_b, int i);
void	ft_ra(t_list	**stack_a, int i);
void	ft_rb(t_list **stack_b, int i);
void	ft_rr(t_list **stack_a, t_list **stack_b, int i);
void	ft_rra(t_list **stack_a, int i);
void	ft_rrb(t_list **stack_b, int i);
void	ft_rrr(t_list **stack_a, t_list **stack_b, int i);

// algo
void	handle_small_stacks(t_list **stack_a);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	calculate_positions(t_list *stack);
void	calculate_costs(t_list *stack_a, t_list *stack_b, int size_a, int size_b);
void	calculate_costs(t_list *stack_a, t_list *stack_b, int size_a, int size_b);
void	calculate_target_positions(t_list *stack_a, t_list *stack_b);
t_list	*find_cheapest_element(t_list *stack_b);
void	execute_moves(t_list **stack_a, t_list **stack_b, t_list *element);
void	finalize_stack_a(t_list **stack_a, int size_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	process_large_stack(t_list **stack_a, t_list **stack_b);

#endif
