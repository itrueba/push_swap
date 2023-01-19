/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:53 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/19 14:02:56 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_correct(t_push *push)
{
	int counter;

		
	counter = 0;
	while (push->stack_a)
	{
		if (counter != push->stack_a->content)
			return(0);
		counter++;
		push->stack_a = push->stack_a->next;
	}
	push->stack_a = push->head_a;
	exit (1);
	return (1);
}

void	ft_print(t_push *push)
{
	while (push->stack_a || push->stack_b)
	{
		if (push->stack_a)
		{
			printf("%d -", push->stack_a->content);
			push->stack_a = push->stack_a->next;
		}
		else
		{
			printf("  -");
		}
		if (push->stack_b)
		{
			printf(" %d", push->stack_b->content);
			push->stack_b = push->stack_b->next;
		}
		printf("\n");
	}
	push->stack_a = push->head_a;
	push->stack_b = push->head_b;
	printf("A - B\n");
	printf("%d - %d\n", push->size_a, push->size_b);
}

t_push	*ft_init_push(int argc)
{
	t_push	*push;

	push = malloc(sizeof(t_push));
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->size_a = argc;
	push->size_b = 0;
	push->bit_size = argc>>1;
	push->head_b = NULL;
	return (push);
}

void ft_radix(t_push *push, int bit)
{
	int	size;
	int	count;

	size = 0;
	count = 0;
	while (size <= push->size_a)
	{
		if (((push->stack_a->content)>>bit&1) == 0)
		{
			ft_pb(push);
			count++;
		}	
		else
			ft_ra(push, 1);
		size++;
	}
	while (count--)
		ft_pa(push);
	ft_correct(push);		
	if (bit <= push->bit_size)
	{
		bit++;
		ft_radix(push, bit);
	}
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