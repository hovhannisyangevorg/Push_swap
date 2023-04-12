/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack_one_to_five.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:26:59 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/12 20:49:12 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
*
* RETURN void
*
* Sorting stack for one to two (hard coded)
*/
void	sorting_stack_one_to_two(t_push_swap *node) //
{
	if ((node->a.size == 2) && (node->a.head->data.index > node->a.head->next->data.index))
		if(node->a.head->data.index > node->a.head->next->data.index)
			rotate(&node->a);
}

