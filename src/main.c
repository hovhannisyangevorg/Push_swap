/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:35:02 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/25 14:38:27 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac == 2)
		panic("error: No arguments");
	t_push_swap stack;
	stack.a = (t_list_c){0, 0};
	stack.b = (t_list_c){0, 0};
	ft_check_argv(av, &stack.a);
	return(0);
}











































































































// int main()
// {
// 	t_push_swap stack;
// 	stack.a = (t_list_c){0, 0};
// 	stack.b = (t_list_c){0, 0};

// 	t_list_c list1 = stack.a;
// 	t_list_c list2 = stack.b;
// 	ft_push_front(&list1, (t_elem){10, 0, 0});
// 	ft_push_front(&list1, (t_elem){20, 0, 0});
// 	ft_push_front(&list1, (t_elem){30, 0, 0});
// 	ft_push_front(&list1, (t_elem){40, 0, 0});
// 	ft_push_front(&list1, (t_elem){50, 0, 0});
// 	t_node *tab = list1.head;
// 	while (tab)
// 	{
// 		printf("%d, ", tab->data.data);
// 		tab = tab->next;
// 		if (tab == list1.head)
// 			break;
// 	}
	
// 	return(0);
// }






















// int main(int ac, char **av)
// {
// 	t_push_swap stack;
// 	stack.a = (t_list_c){0, 0};
// 	stack.b = (t_list_c){0, 0};

// 	t_list_c list1 = stack.a;

// 	ft_push_back(&list1, (t_elem){10, 0, 0});
// 	ft_push_back(&list1, (t_elem){20, 0, 0});
// 	ft_push_back(&list1, (t_elem){30, 0, 0});
// 	ft_push_back(&list1, (t_elem){40, 0, 0});
// 	ft_push_back(&list1, (t_elem){50, 0, 0});
	
// 	t_node *tab = list1.head;
// 	while (tab)
// 	{
// 		printf("%d, ", tab->data.data);
// 		tab = tab->next;
// 		if (tab == list1.head)
// 			break;
// 	}
	
// 	return(0);
// }