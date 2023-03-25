/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:49:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/25 17:15:18 by gehovhan         ###   ########.fr       */
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
	int	boolean;
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
*}
*/
typedef struct s_push_swap
{
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
t_list_c	*ft_deep_copy_list(t_list_c list);

/*
path util.c 
*/
void	ft_free_argv(char **argv);
int 	ft_find_index(int *tab, int len, int data);
void 	if_sort(int *tab, int len);
void 	ft_swap(int *a, int* b);

/*
path error.c 
*/
void panic(char* str);

#endif