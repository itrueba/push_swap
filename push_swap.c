/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:53 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/20 10:53:21 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_print(t_push *push)
// {
// 	while (push->stack_a || push->stack_b)
// 	{
// 		if (push->stack_a)
// 		{
// 			printf("%d -", push->stack_a->content);
// 			push->stack_a = push->stack_a->next;
// 		}
// 		else
// 		{
// 			printf("  -");
// 		}
// 		if (push->stack_b)
// 		{
// 			printf(" %d", push->stack_b->content);
// 			push->stack_b = push->stack_b->next;
// 		}
// 		printf("\n");
// 	}
// 	push->stack_a = push->head_a;
// 	push->stack_b = push->head_b;
// 	printf("A - B\n");
// 	printf("%d - %d\n", push->size_a, push->size_b);
// }

void	ft_correct(t_push *push)
{
	int	counter;

	counter = 0;
	while (push->stack_a)
	{
		if (counter != push->stack_a->content)
		{
			push->stack_a = push->head_a;
			return ;
		}
		counter++;
		push->stack_a = push->stack_a->next;
	}
	push->stack_a = push->head_a;
	exit(1);
}

int	main(int argc, char **argv)
{
	int		*index;
	int		*input;
	t_push	*push;

	input = ft_check_argv(argc - 1, argv);
	index = ft_index(argc - 1, input);
	push = ft_init_push(argc - 1);
	ft_init(index, push);
	ft_radix(push, 0);
	free(push);
	return (0);
}