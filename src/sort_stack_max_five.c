/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:26:59 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/19 22:11:13 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*
* RETURN void
*
* Sorting stack for max  five (Hard Code).
*/
void	sorting_stack_max_five(t_push_swap *node)
{
	if (node->a.size == 2)
		sorting_stack_one_to_two(node);
	else if (node->a.size == 3)
		sorting_stack_one_to_three(node);
	else if (node->a.size == 4)
		sorting_stack_one_to_four(node);
	else
		sorting_stack_one_to_five(node);
}

/*
*
* RETURN void
*
* Sorting stack for one to two (Hard Code).
*/
void	sorting_stack_one_to_two(t_push_swap *node)
{
	if (node->a.head->data.index > node->a.head->next->data.index)
		rotate(&node->a, STACK_A);
}

/*
*
* RETURN void
*
* Sorting stack for one to three (Hard Code).
*/
void	sorting_stack_one_to_three(t_push_swap *node)
{
	int	a;
	int	b;
	int	c;

	a = node->a.head->data.index;
	b = node->a.head->next->data.index;
	c = node->a.head->prev->data.index;
	if ((a < b) && (a < c) && (b > c))
	{
		reverse_rotate(&node->a, STACK_A);
		swap (&node->a, STACK_A);
	}
	else if ((a > b) && (a < c))
		swap (&node->a, STACK_A);
	else if ((a < b) && (a > c))
		reverse_rotate(&node->a, STACK_A);
	else if ((a > b) && (a > c) && (b > c))
	{
		swap(&node->a, STACK_A);
		reverse_rotate(&node->a, STACK_A);
	}
	else if ((a > b) && (a > c) && (b < c))
		rotate(&node->a, STACK_A);
}

/*
*
* RETURN void
*
* Sorting stack for one to four (Hard Code).
*/
void	sorting_stack_one_to_four(t_push_swap *node)
{
	t_node	*max;

	max = ft_list_find(node->a, 3);
	if (node->a.head->data.index == max->data.index)
		push(&node->a, &node->b, STACK_A);
	else if (node->a.head->next->data.index == max->data.index)
	{
		rotate(&node->a, STACK_A);
		push(&node->a, &node->b, STACK_A);
	}
	else if (node->a.head->prev->data.index == max->data.index)
	{
		reverse_rotate(&node->a, STACK_A);
		push(&node->a, &node->b, STACK_A);
	}
	else if (node->a.head->prev->prev->data.index == max->data.index)
	{
		reverse_rotate(&node->a, STACK_A);
		reverse_rotate(&node->a, STACK_A);
		push(&node->a, &node->b, STACK_A);
	}
	sorting_stack_one_to_three(node);
	push(&node->b, &node->a, STACK_B);
	rotate(&node->a, STACK_A);
}

/*
*
* RETURN void
*
* Sorting stack for one to five (Hard Code).
*/
void	sorting_stack_one_to_five(t_push_swap *node)
{
	sorting_stack_one_to_five_helper(node, ft_list_find(node->a, 4));
	sorting_stack_one_to_four(node);
	push(&node->b, &node->a, STACK_B);
	rotate(&node->a, STACK_A);
}
