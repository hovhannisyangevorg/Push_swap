/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:49:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/20 14:25:12 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define STACK_A 2
# define STACK_B 4

# ifdef ISCHECKER
#  define CHECKER 1
# else
#  define CHECKER 0
# endif

typedef struct s_elem		t_elem;
typedef struct s_node		t_node;
typedef struct s_list_c		t_list_c;
typedef struct s_push_swap	t_push_swap;

/*
*
* list cleanup function declaration
*
*/
typedef void				(*t_list_cleanup)();

/*
* STRUCT
*{
* int data;
* int index;
* int	boolean;
*}
*/
struct s_elem
{
	int	data;
	int	index;
};

/*
* STRUCT
*{
* t_elem data;
* struct s_node *next;
* struct s_node *prev;
*}
*/
struct s_node
{
	t_elem			data;
	struct s_node	*next;
	struct s_node	*prev;
};

/*
* STRUCT
*{
* t_node	*head;
* int	size;
*}
*/
struct s_list_c
{
	int		size;
	t_node	*head;
};

/*
* STRUCT
*{
* t_list_c a;
* t_list_c b;
* int ratio;
*}
*/
struct s_push_swap
{
	int			ratio;
	t_list_c	a;
	t_list_c	b;
};

/*
path method_list.c 
*/

void		ft_push_back(t_list_c *root, t_elem data);
void		ft_push_front(t_list_c *root, t_elem data);
void		ft_pop_back(t_list_c *root, t_list_cleanup cleanup);
void		ft_pop_front(t_list_c *root, t_list_cleanup cleanup);
t_node		*ft_iterate(t_node *it, int n);
t_node		*ft_list_find(t_list_c lst, int index);
t_list_c	ft_deep_copy_list(t_list_c lst);
void		ft_list_clear(t_list_c *lst, t_list_cleanup cleanup);

/*
path util.c 
*/

void		sorting_stack_max_five(t_push_swap *node);
void		sorting_stack_one_to_two(t_push_swap *node);
void		sorting_stack_one_to_three(t_push_swap *node);
void		sorting_stack_one_to_four(t_push_swap *node);
void		sorting_stack_one_to_five(t_push_swap *node);


int			ft_find_index(int *tab, int len, int data);
int			ft_get_digits(int num);
void		ft_free_av(char **args);
void		ft_print_stack(t_list_c stack);
void		ft_swap(int *a, int *b);
int			ft_if_sort(int *tab, int len);
void		ft_panic(char *str);

size_t		ft_support_atoi(const char *nptr, int sign, size_t i);
int			ft_atoi_push(const char *nptr);
void		ft_error_not_digit(const char *str, size_t index);
void		ft_check_list_elem(char **sp, int len, \
			t_list_c *list, int is_checker);
void		ft_check_argv(char **av, t_list_c *root);
void		ft_split_argc(char *argv, int len, t_list_c *root);
void		sorting_stack_one_to_five_helper(t_push_swap *node, t_node *max);



void		ft_create_butterfly(t_push_swap *node);
void		ft_butterfly_sort(t_push_swap *node);
int			ft_list_find_max_index(t_push_swap *node);
int			if_sort_list(t_push_swap *root);
void		ft_push_helper(t_list_c *stack_b, t_node **elem, t_node **last);

//
void 		ft_merge_sort(int *tab, int l, int r);
void 		ft_merge(int *tab, int l, int m, int r);
int			*ft_sort_with_merg(int *tab, int len);
void		ft_find_duplicat(int *arr, int size);

//
void		swap(t_list_c *stack, int is_stack_a);
void		ss(t_list_c *stack_a, t_list_c *stack_b);
void		push(t_list_c *stack_a, t_list_c *stack_b, int is_stack_a);
void		rotate(t_list_c *stack, int is_stack_a);
void		rr(t_list_c *stack_a, t_list_c *stack_b);
void		rrr(t_list_c *stack_a, t_list_c *stack_b);
void		reverse_rotate(t_list_c *stack, int is_stack_a);

#endif