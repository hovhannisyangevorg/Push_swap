/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:02:12 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/27 00:34:21 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_not_digit(const char *str, size_t index )
{
	while (str[index] != '\0')
	{
		if(!ft_isdigit(str[index]))
			panic ("error: Not a Number");
		index++;
	}
}

/*
*
* convert argument string to integer
*
*/
int	ft_atoi_push(const char *nptr)
{
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	j = i;
	ft_error_not_digit(&nptr[i], j);
	while (nptr[i] == '0')
		++i;
	return (ft_support_atoi(nptr, sign, i));
}

/*
* check every operation 
*/
size_t	ft_support_atoi(const char *nptr, int sign, size_t i)
{
	int		mult;
	size_t	res;

	res = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (ft_ismultiply_overflow(res, 10))
			panic ("error: Overflow error");
		mult = res * 10;
		if (ft_isadd_overflow(mult, (nptr[i] - '0')))
			panic ("add Overflow error");
		res = res * 10 + (nptr[i] - '0');
		++i;
	}
	if (ft_ismultiply_overflow(res, sign))
		panic ("error: Overflow error");
	res *= sign;
	return (res);
}
