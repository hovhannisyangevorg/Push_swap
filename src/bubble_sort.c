/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:19:09 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/24 18:24:48 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN int
*
* Sorts an array of integers in ascending order using 
* the Bubble Sort algorithm.
*/
int	*ft_sorting_table(int *tab, size_t len)
{
	size_t	i;
	size_t	j;
	int		*new;

	i = -1;
	new = (int *)malloc(sizeof(int) * len);
	if (!new)
		panic("error: Couldn't allocate memory");
	while (++i < len)
		new[i] = tab[i];
	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (new[i] > new[j])
				ft_swap(&new[i], &new[j]);
			else if (new[i] == new[j])
				panic("error: stack shouldn't have dublicate numbers");
		}
	}
	return (new);
}
