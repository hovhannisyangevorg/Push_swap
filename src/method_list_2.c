/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:28:02 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/16 19:52:16 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN t_node
*
* @brief Searches for the first occurrence of 
* a node in a linked list with a given index.
*/
t_node	*ft_list_find(t_list_c lst, int index)
{
	int		max;
	t_node	*tmp;

	max = 0;
	tmp = lst.head;
	while (tmp)
	{
		tmp = tmp->next;
		++max;
		if (tmp == lst.head || tmp->data.index == index)
			break ;
	}
	return (tmp);
}
/*
* RETURN int
*
* Check if the linked list of integers in ascending order.
* Root A pointer to a t_push_swap struct representing the stack.
*/
int	if_sort_list(t_push_swap *root)
{
	int		flag;
	t_node	*tmp1;

	flag = 1;
	tmp1 = root->a.head;
	if (root->b.size)
		return (0);
	while (tmp1->next != root->a.head)
	{
		if (tmp1->data.index > (tmp1->next->data.index))
		{
			flag = 0;
			return (flag);
		}
		tmp1 = tmp1->next;
		if (tmp1 == root->a.head)
			break ;
	}
	return (flag);
}
