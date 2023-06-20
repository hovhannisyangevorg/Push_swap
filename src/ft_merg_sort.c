/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merg_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:19:09 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/20 14:26:16 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

static void	ft_tabcpy(int *tab1, int *tab2, int len, int point)
{
	int i;

	i = -1;
	while (++i < len)
		tab1[i] = tab2[point + i];
}

void	ft_merge(int *tab, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int	L[n1];
	int	R[n2];

	ft_tabcpy(L, tab, n1, l);
	ft_tabcpy(R, tab, n2, m+1);

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
	int	i;

	i = 1;
    while (i < size)
	{
        if (tab[i] == tab[i - 1])
        	ft_panic("Error: Duplicates found in the Stack.");
		i++;
    }
}
