/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:47:13 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/24 18:23:32 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* PARAM
* This function takes a null-terminated
* array of strings (char **) and frees the memory allocated
* for each string and for the array itself.
*/
void	ft_free_av(char **args)
{
	int	i;

	i = -1;
	if (!args)
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
int	ft_find_index(int *tab, int len, int data)
{
	int		i;

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
int	ft_if_sort(int *tab, int len)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (i < (len - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			flag = 0;
			break ;
		}
		i++;
	}
	return (flag);
}

/*
* RETURN int
*
* This function takes an integer as input and
* Calculates the number of digits in it.
*/
int	get_digits(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num = num / 10;
		++i;
	}
	return (i);
}

/*
*
* RETURN (void)
*
* Swaps the values of two integer variables.
*/
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
