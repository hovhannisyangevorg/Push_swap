/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:23:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/13 15:44:36 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
*
* RETURN void
*
*  Swap the first 2 elements at the top of stack.
*/
void	swap(t_list_c *stack)
{
	if ( stack == 0 || stack->head == 0 || stack->head == stack->head->next )
		return ;
	t_node* first = stack->head;
	t_node* second = first->next;
	t_node* thrid = second->next;
	t_node* last = first->prev;
	last->next = second;
	second->prev = last;
	first->next = thrid;
	thrid->prev = first;
	first->prev = second;
	second->next = first;
	stack->head = second;
}

/*
*
* RETURN void
*
* Swap the first 2 elements at the top of stack stack_a and stack_b same time.
*/
void ss(t_list_c *stack_a, t_list_c *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

/*
*
* RETURN void
*
* Take the first element at the top of stack_a and put it at the top of stack_b.
*/
void	push(t_list_c *stack_a, t_list_c *stack_b)
{
	if (stack_a == 0 || stack_a->head == 0)     //|| stack_a->head == 0
		return ;
	t_node* elem = stack_a->head;
	t_node* last = stack_a->head->prev;
	--stack_a->size;
	++stack_b->size;
	last->next = stack_a->head->next;
	stack_a->head->next->prev = last;
	stack_a->head = stack_a->head->next;

	if ( stack_b->head == 0 )
	{
		elem->next = elem;
		elem->prev = elem;
		stack_b->head = elem;
	}
	else
	{
		last = stack_b->head->prev;
		elem->next = stack_b->head;
		stack_b->head->prev = elem;
		elem->prev = last;
		last->next = elem;
		stack_b->head = elem;
	}
	if ( stack_a->size == 0)
		stack_a->head = 0;
}


/*
*
* RETURN void
*
* Move all elements of the stack up by 1
* The first element becomes the last.
*/
void	rotate(t_list_c *stack)
{
	if (stack == 0 || stack->head == 0)
		return ;
	stack->head = stack->head->next;
}

/*
*
* RETURN void
*
* Move all elements of the stacks up by 1
* The first element becomes the last same time.
*/
void	rr(t_list_c *stack_a, t_list_c *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

/*
*
* RETURN void
*
* Move all elements of the stack down by 1.
* The last element becomes the first.
*/
void	reverse_rotate(t_list_c *stack)
{
	if (stack == 0 || stack->head == 0)
		return ;
	stack->head = stack->head->prev;
}

/*
*
* RETURN void
*
* reverse_rotate at the same time.
*/
void	rrr(t_list_c *stack_a, t_list_c *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}