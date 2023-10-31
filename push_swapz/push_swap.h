/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:29:45 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/23 00:47:52 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				val;
	int				index;
	int				pos;
	struct s_list	*next;
}	t_list;

//PARSER - all from LIBFT

char	*ft_merge(char **array, char c, int len);
char	**ft_split(char const *s, char c);
int		ft_arr_islf(char **array);
ssize_t	ft_atoll(const char *str);
int		ft_arrnum(char **array);
void	ft_strdel(char **as);

//LIST UTILS

int		write_stack_a(t_list **lst, int val, int elements);
void	clear_stacks(t_list **stack_a, t_list **stack_b);
int		lst_is_sorted(t_list *stack_a);
t_list	*ft_lstlast(t_list *lst);					// LIBFT
int		ft_lstsize(t_list *lst);					// LIBFT

//OPERATIONS

void	push(t_list **src, t_list **dst, char c);
void	swap(t_list **lst, char c);
void	rotate(t_list **lst, char c);
void	rev_r(t_list **lst, char c);
void	multi_op(t_list **stack_a, t_list **stack_b, char *mode);
int		ft_strequ(char const *s1, char const *s2);	// LIBFT
int		ft_printf(char const *str, ...);			// LIBFT

//SORT_FUNCTIONS

void	sort_nums(t_list **stack_a, t_list **stack_b, int elements);
void	pos_update(t_list **stack_a, t_list **stack_b);
int		put_index(t_list **stack_a, int size);
int		get_min_val(t_list *stack);

#endif