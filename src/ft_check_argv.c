/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:29:27 by gehovhan          #+#    #+#             */
/*   Updated: 2023/04/24 18:23:06 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* Create stack 'a' list full elements and check elements error.
*/

void	ft_stack_initialize(t_list_c *list, int len, int *tab, int *tab2)
{
	int	i;
	int	index;

	i = -1;
	while (++i < len)
	{
		index = ft_find_index(tab2, len, tab[i]);
		ft_push_back (list, (t_elem){tab[i], index});
	}
	free(tab2);
	free(tab);
}

void	ft_check_list_elem(char **sp, int len, t_list_c *list, int is_checker)
{
	int		i;
	int		j;
	int		*tab;
	int		*tab2;
	int		is_sorted;

	i = -1;
	j = 0;
	is_sorted = 1;
	tab = (int *) malloc(sizeof(int) * len);
	if (!tab)
		panic("error: Couldn't allocate memory");
	while (sp && sp[++i])
		tab[j++] = ft_atoi_push(sp[i]);
	if (!is_checker)
		is_sorted = ft_if_sort(tab, len);
	tab2 = ft_sorting_table(tab, len);
	if (!is_checker && is_sorted)
	{
		free(tab);
		free(tab2);
		exit(EXIT_SUCCESS);
	}
	ft_stack_initialize(list, len, tab, tab2);
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
	{
		ft_split_argc(argv, len, root);
		free(argv);
	}
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
