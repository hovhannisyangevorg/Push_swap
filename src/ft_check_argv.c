/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:29:27 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/27 14:06:26 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void ft_check_list_elem(char **sp, int len, t_list_c *list) 
{
	int i = 0;
	int j = 0;
	
	int *tab = (int*)malloc(sizeof(int) * len);
	if (!tab)
		panic("error: Array NULL");
	i = 0;
	while (sp && sp[i])
	{
		tab[j] = ft_atoi_push(sp[i]);
		i++;
		j++;
	}
	ft_if_sort(tab, len);
	int *tab2 = ft_sorting_table(tab, len);
	i = -1;
	while (++i < len)
	{
		int index = ft_find_index(tab2, len, tab[i]);
		ft_push_back (list, (t_elem){ tab[i] , index, 0 });
	}
	free(tab2);
}

/*
* This function ft_check_argv takes an array of strings av and a circular doubly linked list list,
* and creates a concatenated string arguments from the string array elements. It then splits the arguments
* @param av An array of strings containing integers to be sorted and assigned indices
* @param root A circular doubly linked list to be populated with sorted integers and their indices
* @return Void
*/
void	ft_check_argv(char **av, t_list_c *root)
{
	int		len = 0;
	char *tmp;
	char *args = 0;

	while (*(++av))
	{
		tmp = args;
		args = ft_strjoin(args, *av);
		if (tmp)
			free(tmp);
		tmp = args;
		args = ft_strjoin(args, " ");
		if (tmp)
			free(tmp);
	}
	if (args)
	{
		char **sp = ft_split(args, ' ');
		int i = -1;
		while (sp && sp[++i])
			++len;
		ft_check_list_elem(sp, len, root);
		ft_free_av(sp);
	}
}
	
