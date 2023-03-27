/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:35:02 by gehovhan          #+#    #+#             */
/*   Updated: 2023/03/27 14:10:44 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac == 1)
		return 0;
	t_push_swap push_;
	push_.a = (t_list_c){0,0};
	push_.b = (t_list_c){0,0};
	ft_check_argv(av, &push_.a);
	print_stack(push_.a);
	printf("%d \n", push_.a.head->data.data);

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