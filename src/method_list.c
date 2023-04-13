/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:27:12 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/13 14:49:07 by gehovhan         ###   ########.fr       */
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
	if (root == 0)
		return;
	t_node *new = (t_node *)malloc(sizeof(t_node));
	++root->size;
	if (new == 0)
		return ;
	new->data = data;
	if (root->head == 0)
	{
		root->head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	t_node* last = root->head->prev;
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

/*
* Creates a deep copy of a circular linked list.
* @param list The circular linked list to be copied.
* @return A pointer to the head of the copied list.
*/
t_list_c ft_deep_copy_list(t_list_c lst)
{
	t_list_c copy = (t_list_c){0, 0};

	t_node* tmp = lst.head;
	while (tmp)
	{
		ft_push_back(&copy, tmp->data);
		tmp = tmp->next;
		if (tmp == lst.head)
			break;
	}
	
	return copy;
}


/*
*
* RETURN int
*
* @brief Searches for the first occurrence of a node in a linked list with a given index.
*/
t_node *ft_list_find(t_list_c lst, int index)   /////////////////// popoxutyun funkciai het
{
	t_node *tmp = lst.head;
	int max = 0;
	
	while (tmp)
	{
		tmp = tmp->next;
		++max;
		if(tmp == lst.head || tmp->data.index == index)
			break;		
	}
	return (tmp);	
}

/*
* iterator
*/
// t_node*	ft_iterate(t_node* it, int n)
// {
// 	t_node* tmp = it;
// 	if (n > 0)
// 	{
// 		while (tmp && n--)
// 			tmp = tmp->next;
// 	}
// 	else if (n < 0)
// 	{
// 		while (tmp && n++)
// 			tmp = tmp->prev;
// 	}
// 	return tmp;
// }
