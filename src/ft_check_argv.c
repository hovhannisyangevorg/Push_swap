/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:29:27 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/16 19:42:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* Create stack 'a' list full elements and check elements error.
*/
void	ft_check_list_elem(char **sp, int len, t_list_c *list, int is_checker)
{
	int		i;
	int		j;
	int		index;
	int		*tab;
	int		*tab2;

	i = -1;
	j = 0;
	tab = (int *) malloc(sizeof(int) * len);
	if (!tab)
		panic("error: Array NULL");
	while (sp && sp[++i])
		tab[j++] = ft_atoi_push(sp[i]);
	if (!is_checker)
		ft_if_sort(tab, len);
	tab2 = ft_sorting_table(tab, len);
	i = -1;
	while (++i < len)
	{
		index = ft_find_index(tab2, len, tab[i]);
		ft_push_back (list, (t_elem){tab[i], index});
	}
	free(tab2);
}

/*
* RETURN void
*
* create <av> list full elements and check elements error
*/
void	ft_check_argv(char **av, t_list_c *root)
{
	int		len;
	char	*tmp;
	char	*argv;

	len = 0;
	argv = 0;
	while (*(++av))
	{
		tmp = argv;
		argv = ft_strjoin(argv, *av);
		if (tmp)
			free(tmp);
		tmp = argv;
		argv = ft_strjoin(argv, " ");
		if (tmp)
			free(tmp);
	}
	if (argv)
		ft_split_argc(argv, len, root);
}

/*
* RETURN void
*
* Splits a given string by space delimiter and stores the 
* Result as elements in a linked list.
*/
void	ft_split_argc(char *argv, int len, t_list_c *root)
{
	int		i;
	char	**sp;

	sp = ft_split(argv, ' ');
	if (!sp || !sp[0])
		panic("error: no enough arguments");
	i = -1;
	while (sp && sp[++i])
		++len;
	ft_check_list_elem(sp, len, root, CHECKER);
	ft_free_av(sp);
}
