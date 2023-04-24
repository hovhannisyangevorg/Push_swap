/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:45:04 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/24 18:24:18 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* Helper this function sorting_stack_one_to_five().
*/
void	sorting_stack_one_to_five_helper(t_push_swap *node, t_node *max)
{
	if (node->a.head->data.index == max->data.index)
		push(&node->a, &node->b, STACK_A);
	else if (node->a.head->next->data.index == max->data.index)
	{
		rotate(&node->a, STACK_A);
		push(&node->a, &node->b, STACK_A);
	}
	else if (node->a.head->next->next->data.index == max->data.index)
	{
		rotate(&node->a, STACK_A);
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
}

/*
* RETURN void
*
* Helper this function push().
*/
void	push_helper(t_list_c *stack_b, t_node **elem, t_node **last)
{
	if (stack_b->head == 0)
	{
		(*elem)->next = (*elem);
		(*elem)->prev = (*elem);
		stack_b->head = (*elem);
	}
	else
	{
		(*last) = stack_b->head->prev;
		(*elem)->next = stack_b->head;
		stack_b->head->prev = (*elem);
		(*elem)->prev = (*last);
		(*last)->next = (*elem);
		stack_b->head = (*elem);
	}
}
