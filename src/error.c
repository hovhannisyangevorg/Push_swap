/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:12:31 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/13 14:48:57 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*
* RETURN void
*
* Structure NameThe code provided defines a function called "panic".
* That takes a string (char*) argument named "str".
* The function writes the contents of the string to standard error (file descriptor 2) 
*/
void panic(char* str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}