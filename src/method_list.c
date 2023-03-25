/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:27:12 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/25 16:01:43 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*
* PARAM void	
*
* This is an implementation of a function,
* that adds a new node to the end of a doubly-linked circular list.
*/
void ft_push_back(t_list_c *root, t_elem data)
{
	if(root == 0)
		return ;
	t_node *new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		return ;
	new->data = data;
	root->size++;
	if (root->head == 0)
	{
		root->head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	t_node *last = root->head->prev;
	last->next = new;
	new->prev = last;
	new->next = root->head;
	root->head->prev = new;	
}

/*
*
* PARAM void	
*
* RETURN void
* This is an implementation of a function,
* that removes the last node from a doubly-linked circular list.
*/
void	ft_push_front(t_list_c *root, t_elem data)
{
	if (root == 0)
		return ;
	t_node *new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		return ;
	root->size++;
	new->data = data;
	if (root->head == 0)
	{
		root->head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	t_node *last = root->head->prev;
	new->next = root->head;
	root->head->prev = new;
	new->prev = last;
	last->next = new;
	root->head = new;
}

/*
*
* PARAM void
*
* RETURN void
* This is an implementation of a function,
* that removes the last node from a doubly-linked circular list.
*/
void	ft_pop_back(t_list_c *root)
{
	if (root == 0 || root->head == 0)
		return ;
	if (root->head->next == root->head)
	{
		free(root->head);
		root->head = 0;
		return ;
	}
	t_node *last = root->head->prev;
	last->prev->next = root->head;
	root->head->prev = last->prev;
	free(last);
}

/*
*
* RETURN void
*
* This is an implementation of a function,
* that removes the first node from a doubly-linked circular list.
*/
void	ft_pop_front(t_list_c *root)
{
	if (root == 0 || root->head == 0)
		return ;
	if (root->head == root->head->prev)
	{
		free(root->head);
		root->head = 0;
		return ;
	}
	t_node *tmp = root->head;
	root->head->next->prev = root->head->prev;
	root->head->prev->next = root->head->next;
	root->head = root->head->next;
	free(tmp);
}

