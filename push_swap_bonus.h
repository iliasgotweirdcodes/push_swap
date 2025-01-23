/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:30:35 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/01/23 22:27:05 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				i;
	struct s_list	*next;
}	t_list;

void	ft_parsing_args(int ac, char **av, t_list **stack_a);
void	ft_add_node(t_list **stack_a, int content, int index);
void	ft_free_when_error(t_list **stack, char **str);
void	free_stack(t_list **stack);
void	ft_clean(char **str);
int		ft_atoi(const char *str, int *error);
int		has_duplicates(t_list *stack, int num);
char	*join_args(char **av, char *str);
char	**ft_split(char *s, char c);
int		ft_atoi(const char *str, int *error);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_stack(char **s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	ft_putstr(const char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
int		initialize_stacks(char **av, t_list **stack_a);
void	ft_give_index(t_list **stack);
char	*ft_strchr(char *s, int c);
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
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_pivot(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
void	last_element(t_list **stack_a, t_list **last);
void	ft_rb_rrb(t_list **stacka, t_list **stackb, int content, t_list **last);

#endif
