/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:46 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/15 19:51:40 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_ismultiply_overflow(int a, int b)
{
   if (a == 0 || b == 0)
      return 0;
   int result = a * b;
   if (a == result / b)
      return 0;
	return 1;
}

int ft_isadd_overflow(int a, int b)
{
   int result = a + b;
   if (a > 0 && b > 0 && result < 0)
		return 1;
	if (a < 0 && b < 0 && result > 0)
		return 1;
	return 0;
}