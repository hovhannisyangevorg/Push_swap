/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:55:13 by gehovhan          #+#    #+#             */
/*   Updated: 2023/02/06 13:55:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	num;
	size_t	numlen;
	char	*str;

	num = n;
	numlen = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (NULL);
	str[numlen] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		num = -num;
	}
	else if (n == 0)
		str[--numlen] = '0';
	while (num)
	{
		n = num % 10;
		num /= 10;
		str[--numlen] = (n + '0');
	}
	return (str);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
