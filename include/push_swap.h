/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:49:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/25 10:47:43 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
#define PUSH_SWAP.H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
* STRUCT
*
* int data;
* int index;
* int	boolean;
*/
typedef struct s_elem
{
	int data;
	int index;
	int	boolean;
} t_elem;

/*
* STRUCT
*
* t_elem data;
* struct s_node *next;
* struct s_node *prev;
*/
typedef struct s_node
{
	t_elem data;
	struct s_node *next;
	struct s_node *prev;
} t_node;

/*
* STRUCT
*
* t_node	*head;
* int	size;
*/
typedef struct s_list_c
{
	t_node *head;
	int size;
} t_list_c;

/*
* STRUCT
*
* t_list_c a;
* t_list_c b;
*/
typedef struct s_push_swap
{
	t_list_c a;
	t_list_c b;
} t_push_swap;






#endif