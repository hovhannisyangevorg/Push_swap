/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_marg_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:19:09 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/20 13:42:18 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void ft_merge(int *tab, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = tab[l + i];
	for (j = 0; j < n2; j++)
		R[j] = tab[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) 
    {
		if (L[i] <= R[j])
        {
			tab[k] = L[i];
			i++;
		}
		else 
        {
			tab[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
    {
		tab[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
    {
		tab[k] = R[j];
		j++;
		k++;
	}
}

void	ft_merge_sort(int *tab, int l, int r)
{
	if (l < r)
    {
		int m = l + (r - l) / 2;
		ft_merge_sort(tab, l, m);
		ft_merge_sort(tab, m + 1, r);

		ft_merge(tab, l, m, r);
	}
}

int	*ft_sort_with_merg(int *tab, int len)
{
	int i = -1;
	int	*res = malloc(len * sizeof(int));
	while (++i < len)
		res[i] = tab[i];
	ft_merge_sort(res, 0, len - 1);
	return (res);	
}

void	ft_find_duplicat(int *tab, int size) 
{
	int i;
	
	i = 1;
    while (i < size)
	{
        if (tab[i] == tab[i - 1])
        	ft_panic("Error: Duplicates found in the Stack.");
		i++;
    }
}
