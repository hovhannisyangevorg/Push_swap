/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:35:02 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/20 13:52:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN int
*
* Returns the integer value of the base 2 logarithm of the given integer.
*/
int	get_log2(int n)
{
	int	i;
	int	m;

	i = 2;
	m = 0;
	while (i <= n)
	{
		++m;
		i <<= 1;
	}
	return (m);
}

/*
* RETURN int
*
* Returns the integer square root of the given integer, rounded down
*/
int	get_sqrt(int n)
{
	int	i;
	int	num;

	num = n;
	i = 2;
	while (num > i * i)
		++i;
	return (i);
}

int	main(int ac, char **av)
{
	t_push_swap		push_;

	if (ac == 1)
		return (0);
	push_.a = (t_list_c){0, 0};
	push_.b = (t_list_c){0, 0};
	ft_check_argv(av, &push_.a);
	push_.ratio = get_sqrt(push_.a.size) + get_log2(push_.a.size) - 1;
	if (push_.a.size <= 5)
		sorting_stack_max_five(&push_);
	else
	{
		ft_create_butterfly(&push_);
		ft_butterfly_sort(&push_);
	}
	ft_list_clear(&push_.a, free);
	ft_list_clear(&push_.b, free);
	return (0);
}

#if 0

void	print_stack(t_list_c stack)
{
	t_node	*tmp;

	tmp = stack.head;
	while (tmp)
	{
		printf("%d[%d] ", tmp->data.data, tmp->data.index);
		tmp = tmp->next;
		if (tmp == stack.head)
			break ;
	}
	printf("\n");
}
#endif