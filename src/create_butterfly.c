/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_butterfly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:07 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/12 18:53:30 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*
* Create Butterfly from a stack
* 
*/
void	create_butterfly(t_push_swap *node)
{
	int i = 0;
	int index;
	int len = node->a.size;

	while ( i < len )
	{
		index = node->a.head->data.index;
		if (index <= i)
		{

			push(&node->a, &node->b);
			rotate(&node->b);
			++i;
		}
		else if (index <= (i + node->ratio))
		{
			push (&node->a, &node->b);
			++i;
		}
		else
			rotate(&node->a);
	}
}





