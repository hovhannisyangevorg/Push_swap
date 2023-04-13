/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:48:33 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/13 15:42:30 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_sort(t_push_swap *node)
{
	int index;
	

	while(node->b.head)
	{
		index = node->b.size - 1;
		if(list_find_max_index(node) == 1)
		{
			while (node->b.head && node->b.head->data.index != index)
				rotate(&node->b);
			push(&node->b, &node->a);
		}
		else 
		{
			while (node->b.head && node->b.head->data.index != index)
			{
				reverse_rotate(&node->b);
			}
			push(&node->b, &node->a);
		}
	}
}

int	list_find_max_index(t_push_swap *node)
{
	int len = 0;
	int max_index = (node->b.size - 1);

	while(len < (node->b.size / 2))
	{
		if (node->b.head->data.index == max_index)
			return (1);
		len++;
	}
	return(0);
}