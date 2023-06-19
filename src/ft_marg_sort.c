/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_marg_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:19:09 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/19 20:19:22 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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



































































































// int leonardo_namber(int k)
// {
//     int a;
//     int b;
//     int c;
    
//     a = 1;
//     b = 1;
//     int i = 2;
    
//     while(i <= k)
//     {
//         c = a + b + 1;
//         a = b;
//         b = c;
//         i++;
//     }
//     return (b);
// }


// void    heapify(int *tab, int start, int end)
// {
//     int j = 0;
//     int k = 0;
//     int i = start;

//     while (k < (end - start + 1))
//     {
//         if (k & 0xAAAAAAAA)
//         {
//             j = j + i;
//             i = i >> 1;
//         }
//         else
//         {
//             i = i + j;
//             j = j >> 1;
//         }
//         k = k + 1;
//     }

//     while (i > 0)
//     {
//         j = j >> 1;
//         k = i + j;

//         while (k < end) {
//             if (tab[k] > tab[k - i]) {
//                 break;
//             }
//             ft_swap(&tab[k], &tab[k - i]);
//             k = k + i;
//         } 
//         i = j;
//     }
// }


// int *smooth_sort(int *tab, int len)
// {
//     int a;
//     int b;
//     int c;
//     int* res;

//     res = (int*)malloc(len * sizeof(int));
//     if (!res)
//         panic("error: Couldn't allocate memory");
//     ft_memmove(res, tab, len * sizeof(int));

//     a = len - 1;
//     b = a;
//     c = 0;
//     while (a >= 0)
//     {
//         if ((c & 3) == 0)
//             heapify(res, c, b);
//         if (leonardo_namber(c) == a)
//             c += 1;
//         else
//         {
//             c -= 1;
//             b = b - leonardo_namber(c);
//             heapify(res, c, b);
//             b = c - 1;
//             c += 1; 
//         }
//         ft_swap(&res[0], &res[a]);
//         a--;
//     }
    
//     for (int i = 0; i < (len - 1); i++)
//     {
//         int j = i + 1;
//         while (j > 0 && res[j] < res[j - 1]) 
//         {
//             ft_swap(&res[j], &res[j - 1]);
//             j -= 1;
//         }
//     }
//     return (res);
// }




// // int has_dublicate(int* tab, int len)
// // {
// // }

























/*
* RETURN int
*
* Sorts an array of integers in ascending order using 
* the Bubble Sort algorithm.
*/
// int	*ft_sorting_table(int *tab, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		*new;

// 	i = -1;
// 	new = (int *)malloc(sizeof(int) * len);
// 	if (!new)
// 		panic("error: Couldn't allocate memory");
// 	while (++i < len)
// 		new[i] = tab[i];
// 	i = -1;
// 	while (++i < len)
// 	{
// 		j = i;
// 		while (++j < len)
// 		{
// 			if (new[i] > new[j])
// 				ft_swap(&new[i], &new[j]);
// 			else if (new[i] == new[j])
// 				panic("error: stack shouldn't have dublicate numbers");
// 		}
// 	}
// 	return (new);
// }