/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_stack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:39:45 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/16 19:58:50 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
*  Swap the first 2 elements at the top of stack.
*/
void	swap(t_list_c *stack, int which)
{
	t_node	*first;
	t_node	*second;
	t_node	*thrid;
	t_node	*last;

	if (stack == 0 || stack->head == 0 || stack->head == stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	thrid = second->next;
	last = first->prev;
	last->next = second;
	second->prev = last;
	first->next = thrid;
	thrid->prev = first;
	first->prev = second;
	second->next = first;
	stack->head = second;
	if (which == STACK_A && !CHECKER)
		write(1, "sa\n", 3);
	else if (which == STACK_B && !CHECKER)
		write(1, "sb\n", 3);
}

/*
* RETURN void
*
* Swap the first 2 elements at the top of
* Stack stack_a and stack_b same time.
*/
void	ss(t_list_c *stack_a, t_list_c *stack_b)
{
	swap(stack_a, STACK_A);
	swap(stack_b, STACK_B);
	if (!CHECKER)
		write(1, "ss\n", 3);
}

/*
* RETURN void
*
* Take the first element at the top of stack_a and put it at the top of stack_b.
*/
void	push(t_list_c *stack_a, t_list_c *stack_b, int which)
{
	t_node	*elem;
	t_node	*last;

	if (stack_a == 0 || stack_a->head == 0)
		return ;
	elem = stack_a->head;
	last = stack_a->head->prev;
	--stack_a->size;
	++stack_b->size;
	last->next = stack_a->head->next;
	stack_a->head->next->prev = last;
	stack_a->head = stack_a->head->next;
	push_helper(stack_b, &elem, &last);
	if (stack_a->size == 0)
		stack_a->head = 0;
	if (which == STACK_A && !CHECKER)
		write(1, "pb\n", 3);
	else if (which == STACK_B && !CHECKER)
		write(1, "pa\n", 3);
}
