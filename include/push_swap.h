/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:49:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/12 20:48:38 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

/*
* STRUCT
*{
* int data;
* int index;
* int	boolean;
*}
*/
typedef struct s_elem
{
	int data;
	int index;
} t_elem;

/*
* STRUCT
*{
* t_elem data;
* struct s_node *next;
* struct s_node *prev;
*}
*/
typedef struct s_node
{
	t_elem data;
	struct s_node *next;
	struct s_node *prev;
} t_node;

/*
* STRUCT
*{
* t_node	*head;
* int	size;
*}
*/
typedef struct s_list_c
{
	t_node *head;
	int size;
} t_list_c;

/*
* STRUCT
*{
* t_list_c a;
* t_list_c b;
* int ratio;
*}
*/
typedef struct s_push_swap
{
	int ratio;
	t_list_c a;
	t_list_c b;
} t_push_swap;

/*
path method_list.c 
*/

void 	ft_push_back(t_list_c *root, t_elem data);
void	ft_push_front(t_list_c *root, t_elem data);
void	ft_pop_back(t_list_c *root);
void	ft_pop_front(t_list_c *root);
t_list_c ft_deep_copy_list(t_list_c lst);
t_node*	ft_iterate(t_node* it, int n);
int ft_list_find(t_list_c lst, int index);

/*
path util.c 
*/

void 	ft_free_av(char **args);
int 	ft_find_index(int *tab, int len, int data);
void	ft_if_sort(int *tab, int len);
void 	print_stack(t_list_c stack);
int get_digits(int num);
void 	ft_swap(int *a, int* b);

/*
path error.c 
*/

void panic(char* str);

/*
path bubble_sort.c
*/

int		*ft_sorting_table(int *tab, size_t len);
size_t	ft_support_atoi(const char *nptr, int sign, size_t i);

/*
* path atoi_push_swap.c
*/

size_t	ft_support_atoi(const char *nptr, int sign, size_t i);
int		ft_atoi_push(const char *nptr);
void	ft_error_not_digit(const char *str, size_t index);

/*
* path ft_check_argv.c
*/

void 	ft_check_list_elem(char **sp, int len, t_list_c *list);
void	ft_check_argv(char **av, t_list_c *root);
void 	ft_split_argc(char *argv, int len, t_list_c *root);

/*
* path method_stack.c
*/

void	swap(t_list_c *stack);
void 	ss(t_list_c *stack_a, t_list_c *stack_b);
void	push(t_list_c *stack_a, t_list_c *stack_b);
void	rotate(t_list_c *stack);
void	rr(t_list_c *stack_a, t_list_c *stack_b);
void	reverse_rotate(t_list_c *stack);
void	rrr(t_list_c *stack_a, t_list_c *stack_b);

/*
* path create_butterfly.c
*/

void	create_butterfly(t_push_swap *node);

/*
* path sorting_stack.c
*/

void	sorting_stack_one_to_two(t_push_swap *node);


#endif