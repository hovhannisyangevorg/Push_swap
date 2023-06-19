/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:02:12 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/19 21:45:36 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* This function checks if the character at the specified 
* index in a string is a digit or not.
*/
void	ft_error_not_digit(const char *str, size_t index )
{
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			ft_panic("error: Not a Number");
		index++;
	}
}

/*
* RETURN int
*
* Convert argument string to integer
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
* RETURN size_t
*
* Check every operation 
*/
size_t	ft_support_atoi(const char *nptr, int sign, size_t i)
{
	int		mult;
	size_t	res;

	res = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (ft_ismultiply_overflow(res, 10))
			ft_panic ("error: Overflow error");
		mult = res * 10;
		if (ft_isadd_overflow(mult, (nptr[i] - '0'), sign))
			ft_panic ("add Overflow error");
		res = res * 10 + (nptr[i] - '0');
		++i;
	}
	if (ft_ismultiply_overflow(res, sign))
		ft_panic ("error: Overflow error");
	res *= sign;
	return (res);
}
