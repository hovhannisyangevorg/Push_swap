/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:47:13 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/12 21:58:24 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* PARAM
* This function takes a null-terminated
* array of strings (char **) and frees the memory allocated
* for each string and for the array itself.
*/
void ft_free_av(char **args)
{
	int i;

	i = -1;
	if (!args || !*args)
		return ;
	while (args[++i])
		free(args[i]);
	free(args);	
}

/*
*
* RETURN (int)
*
* Searches for the first occurrence of the specified,
* integer in an array of integers and returns its index.
*/
int ft_find_index(int *tab, int len, int data)
{
	int i;

	i = 0;
	while (tab && (i < len))
	{
		if (tab[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

/*
*
* RETURN (void)
*
* Checks if an array of integers is
* already sorted in increasing order.
*/
void	ft_if_sort(int *tab, int len)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (i < (len - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			flag = 0;
			break;
		}
		i++;
	}
	if (flag)
		exit(0);
}

void print_stack(t_list_c stack)
{
	t_node* tmp = stack.head;
	while(tmp)
	{
		ft_printf("%d[%d] ", tmp->data.data, tmp->data.index);
		tmp = tmp->next;
		if (tmp == stack.head)
			break;
	}
	ft_printf("\n");
	
}

int get_digits(int num)
{
	int i = 0;
	while (num)
	{
		num = num / 10;
		++i;
	}
	return i;	
}

/*
*
* RETURN (void)
*
* Swaps the values of two integer variables.
*/
void ft_swap(int *a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
















































































// void merge(int *arr, int *left, int leftSize, int *right, int rightSize) 
// {
//     int l, r, k;
//     l = 0;
//     r = 0;
//     k = 0;

//     while (l < leftSize && r < rightSize) {
//         if (left[l] <= right[r]) {
//             arr[k] = left[l];
//             l++;
//         } else {
//             arr[k] = right[r];
//             r++;
//         }
//         k++;
//     }
//     while (l < leftSize) {
//         arr[k] = left[l];
//         l++;
//         k++;
//     }
//     while (r < rightSize) {
//         arr[k] = right[r];
//         r++;
//         k++;
//     }
// }

// void mergeSort(int *arr, int size)
// {
//     if (size < 2)
//         return ;
	
// 	int i = 0;
//     int mid = size / 2;
//     int left[mid];
//     int right[size - mid];

// 	while (i < mid)
// 	{
// 		left[i] = arr[i];
// 		i++;
// 	}
// 	i = mid;
//     while (i < size)
// 	{
//         right[i - mid] = arr[i];
// 		i++;
//     }
//     mergeSort (left, mid);
//     mergeSort (right, size - mid);
//     merge(arr, left, mid, right, size - mid);
// }



// // int main() {
// //     mergeSort(arr, size);
// //     return 0;
// // }