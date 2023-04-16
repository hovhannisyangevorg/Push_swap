/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:48:33 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/16 19:20:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* This function implements the butterfly sorting algorithm 
* For a stack of integers. It moves the elements from Stack B to 
* Stack A in sorted order using a combination of push, 
* rotate and reverse_rotate operations.
*/
void	butterfly_sort(t_push_swap *node)
{
	int	index;

	while (node->b.head)
	{
		index = node->b.size - 1;
		if (list_find_max_index(node) == 1)
		{
			while (node->b.head && node->b.head->data.index != index)
				rotate(&node->b, STACK_B);
			push(&node->b, &node->a, STACK_B);
		}
		else
		{
			while (node->b.head && node->b.head->data.index != index)
				reverse_rotate(&node->b, STACK_B);
			push(&node->b, &node->a, STACK_B);
		}
	}
}

/*
* RETURN int
*
* This function finds the index of the maximum element in stack B. 
* If the maximum index is found in the first half of the stack, 
* It returns 1. Otherwise, it returns 0.
*/
int	list_find_max_index(t_push_swap *node)
{
	int		len;
	int		max_index;
	t_node	*tmp;

	len = 0;
	tmp = node->b.head;
	max_index = (node->b.size - 1);
	while (len < (node->b.size / 2))
	{
		if (tmp->data.index == max_index)
			return (1);
		len++;
		tmp = tmp->next;
	}
	return (0);
}
