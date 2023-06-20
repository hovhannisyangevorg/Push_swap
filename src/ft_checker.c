/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:23:34 by gehovhan          #+#    #+#             */
/*   Updated: 2023/06/20 14:24:38 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* RETURN void
*
* Executes the appropriate operation on the stacks 
* Based on the provided command string.
*/
void	ft_checker_next_bonus(t_push_swap *root, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(&root->a, CHECKER);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(&root->b, CHECKER);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(&root->a, &root->b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(&root->b, &root->a, CHECKER);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(&root->a, &root->b, CHECKER);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(&root->a, CHECKER);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(&root->b, CHECKER);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(&root->b, &root->b);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(&root->a, CHECKER);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(&root->b, CHECKER);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(&root->a, &root->b);
	else
		ft_panic("error: command not found");
}

int	main(int ac, char **av)
{
	char		*line;
	t_push_swap	push_;

	if (ac == 1)
		return (0);
	push_.a = (t_list_c){0, 0};
	push_.b = (t_list_c){0, 0};
	ft_check_argv(av, &push_.a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_checker_next_bonus(&push_, line);
		free(line);
	}
	if (if_sort_list(&push_))
		printf("OK");
	else
		printf("KO");
	return (0);
}
