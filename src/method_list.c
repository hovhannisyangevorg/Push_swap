/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:27:12 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/25 10:42:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_c *ft_push_back(t_list_c *root, t_elem data)
{
	if (root == 0)
		return ;
	t_node *new = (t_node *)malloc(sizeof(t_node));;
	if (new == 0)
		return ;
	root->size++;
	if ()
}
