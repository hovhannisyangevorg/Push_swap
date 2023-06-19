/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_butterfly.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:07 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/19 22:05:22 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* Creates a butterfly pattern in the stacks using the input t_push_swap node.
* The function operates on the stack 'a' of the node, 
* And pushes elements to the stack 'b', as required by the butterfly pattern.
* The sub-sections of the top and bottom sections alternate, 
* Creating a pattern that resembles a butterfly.
*/
void	ft_create_butterfly(t_push_swap *node)
{
	int	i;
	int	index;
	int	len;

	i = 0;
	len = node->a.size;
	while (i < len)
	{
		index = node->a.head->data.index;
		if (index <= i)
		{
			push(&node->a, &node->b, STACK_A);
			rotate(&node->b, STACK_B);
			++i;
		}
		else if (index <= (i + node->ratio))
		{
			push (&node->a, &node->b, STACK_A);
			++i;
		}
		else
			rotate(&node->a, STACK_A);
	}
}
