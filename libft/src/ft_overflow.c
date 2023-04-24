/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:46 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/24 18:25:59 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ismultiply_overflow(int a, int b)
{
	int	result;

	if (a == 0 || b == 0)
		return (0);
	result = a * b;
	if (a == result || a == result / b)
		return (0);
	return (1);
}

int	ft_isadd_overflow(int a, int b, int sign)
{
	int	result;

	result = a + b;
	if (sign < 0 && result == INT_MIN)
		return (0);
	if (a > 0 && b > 0 && result < 0)
		return (1);
	if (a < 0 && b < 0 && result > 0)
		return (1);
	return (0);
}
