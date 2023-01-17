/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:53 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/17 12:29:11 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(int argc, int *index)
{
	int	c;

	c = 0;
	while (c < argc)
	{
		printf("%d  ", index[c]);
		c++;
	}
}



int	main(int argc, char **argv)
{
	int		*index;
	int		*input;
	t_list	*stack_a;

	argc -= 1;
	input = ft_calloc(sizeof(int), argc);
	ft_check_argv(argc, argv, input);
	index = ft_index(argc, input);
	ft_init(argc, index, &stack_a);
	while (stack_a)
	{
		printf("-> %d ", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}