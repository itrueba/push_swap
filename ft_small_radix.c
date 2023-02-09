/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_radix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:28:17 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/02 11:54:11 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_counter(t_push *push)
{
	int	count;

	count = 0;
	while (push->stack_a)
	{
		if (push->total_size - push->size_a == push->stack_a->content)
			break ;
		push->stack_a = push->stack_a->next;
		count++;
	}
	push->stack_a = push->head_a;
	return (count);
}

void	ft_small_radix(t_push *push)
{
	if (push->total_size == 2)
		ft_sa(push, 1);
	if (push->total_size == 3)
		ft_small_radix_3(push);
	if (push->total_size == 4)
		ft_small_radix_4(push);
	if (push->total_size == 5)
		ft_small_radix_5(push);
}
