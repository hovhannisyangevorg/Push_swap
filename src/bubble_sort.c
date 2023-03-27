/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:19:09 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/26 19:01:18 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Sorts an array of integers in ascending order using 
* the Selection Sort algorithm.
* @param tab Pointer to the integer array to be sorted
* @param len Length of the array to be sorted
* @return void
*/
int	*ft_sorting_table(int *tab, size_t len)
{
	size_t	i;
	size_t	j;
	int		*new;

	i = -1;
	new = 0;
	new = (int *)malloc(sizeof(int) * len);
	while (++i < len)
		new[i] = tab[i];
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (new[i] > new[j])
				ft_swap(&new[i], &new[j]);
			else if (new[i] == new[j])
				panic ("error: stack shouldn't have dublicate numbers");
			j++;
		}
		i++;
	}
	return (new);
}
