/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:30:01 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/16 19:59:23 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* Move all elements of the stack up by 1
* The first element becomes the last.
*/
void	rotate(t_list_c *stack, int which)
{
	if (stack == 0 || stack->head == 0)
		return ;
	stack->head = stack->head->next;
	if (which == STACK_A && !CHECKER)
		write(1, "ra\n", 3);
	else if (which == STACK_B && !CHECKER)
		write(1, "rb\n", 3);
}

/*
* RETURN void
*
* Move all elements of the stacks up by 1
* The first element becomes the last same time.
*/
void	rr(t_list_c *stack_a, t_list_c *stack_b)
{
	rotate(stack_a, STACK_A);
	rotate(stack_b, STACK_B);
	if (!CHECKER)
		write(1, "rr\n", 3);
}

/*
* RETURN void
*
* Move all elements of the stack down by 1.
* The last element becomes the first.
*/
void	reverse_rotate(t_list_c *stack, int which)
{
	if (stack == 0 || stack->head == 0)
		return ;
	stack->head = stack->head->prev;
	if (which == STACK_A && !CHECKER)
		write(1, "rra\n", 4);
	else if (which == STACK_B && !CHECKER)
		write(1, "rrb\n", 4);
}

/*
* RETURN void
*
* reverse_rotate at the same time.
*/
void	rrr(t_list_c *stack_a, t_list_c *stack_b)
{
	reverse_rotate(stack_a, STACK_A);
	reverse_rotate(stack_b, STACK_B);
	if (!CHECKER)
		write(1, "rrr\n", 4);
}
