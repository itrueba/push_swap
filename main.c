/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:53 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/17 18:18:42 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_push *push)
{
	printf("Argumentos STACK_A: %d \n", push->size_a);
	printf("Argumentos STACK_B: %d \n", push->size_b);
	while (push->stack_a)
	{
		printf("-> %d ", push->stack_a->content);
		push->stack_a = push->stack_a->next;
	}
	push->stack_a = push->head_a;
	printf("\n");
	while (push->stack_b)
	{
		printf("-> %d ", push->stack_b->content);
		push->stack_b = push->stack_b->next;
	}
	push->stack_b = push->head_b;
	printf("\n");
}

t_push	*ft_init_push(int argc)
{
	t_push	*push;

	push = malloc(sizeof(t_push));
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->size_a = argc;
	push->size_b = 0;
	return (push);
}

int	main(int argc, char **argv)
{
	int *index;
	int *input;
	t_push *push;

	input = ft_check_argv(argc - 1, argv);
	index = ft_index(argc - 1, input);
	push = ft_init_push(argc - 1);
	ft_init(index, push);
	free(push);
	ft_print(push);
	ft_pb(push);
	ft_pb(push);
	ft_pb(push);
	ft_print(push);	
	ft_rrr(push);
	ft_rrr(push);
	ft_print(push);
	return (0);
}