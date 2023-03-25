/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:21:55 by gehovhan          #+#    #+#             */
/*   Updated: 2023/02/05 20:21:57 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(const char *str);

void	ft_putstr(char *str);
int		ft_printnbr(int n);
int		ft_nbrlen(int n);
char	*ft_itoa(int n);
int		ft_print_ptr(unsigned long long ptr);
void	ft_put_ptr(unsigned long long num);
int		ft_ptr_len(unsigned long long num);
int		ft_print_u_nbr(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_unum_len(unsigned int num);
int		ft_print_hex(unsigned int num, const char format);
void	ft_put_hex(unsigned int num, const char format);
void	ft_putchar_fd(char c, int fd);
int		ft_hex_len(unsigned	int num);

#endif