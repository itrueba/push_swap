/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:09:34 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/20 11:26:18 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_a(t_push *push, int bit)
{
	int	size;
	int	sa;

	sa = push->size_a;
	size = 0;
	while (size++ < sa)
	{
		if (((push->stack_a->content) >> bit & 1) == 0)
		{
			ft_pb(push);
		}
		else
			ft_ra(push, 1);
	}
}

void	ft_radix_b(t_push *push, int bit)
{
	int	size;
	int	sb;

	sb = push->size_b;
	size = 0;
	while (size++ < sb)
	{
		if (((push->stack_b->content) >> bit & 1) == 0 && bit < push->bit_size)
		{
			ft_rb(push, 1);
		}
		else
			ft_pa(push);
	}
}

void	ft_correct_b(t_push *push)
{
	int	counter;

	counter = push->stack_b->content;
	while (push->stack_b)
	{
		if (counter != push->stack_b->content)
		{
			push->stack_b = push->head_b;
			return ;
		}
		counter--;
		push->stack_b = push->stack_b->next;
	}
	push->stack_b = push->head_b;
	while (push->stack_b)
		ft_pa(push);
	exit(0);
}

void	ft_correct_a(t_push *push)
{
	int	counter;

	counter = push->stack_a->content;
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
	ft_correct_b(push);
}

void	ft_radix(t_push *push, int bit)
{
	ft_radix_a(push, bit);
	ft_correct_a(push);
	ft_radix_b(push, bit + 1);
	if (bit < push->bit_size)
	{
		bit++;
		ft_radix(push, bit);
	}
}
