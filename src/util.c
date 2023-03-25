/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:47:13 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/25 15:25:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*
* RETURN void
*
* This function takes a null-terminated
* array of strings (char **) and frees the memory allocated
* for each string and for the array itself.
*/
void	ft_free_argv(char **argv)
{
	int i;
	
	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);	
}
/*
*
*/
int ft_find_index(int *tab, size_t len, int data)
{
	int i;

	i = 0;
	while (tab && i < len)
	{
		if (tab[i] == data)
			return i;
		i++;
	}
	return(-1);
}