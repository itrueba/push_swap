/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_radix_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:05:57 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/02 11:58:26 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_radix_5_0(t_push *push)
{
	ft_pb(push);
}

void	ft_small_radix_5_1(t_push *push)
{
	ft_sa(push, 1);
	ft_pb(push);
}

void	ft_small_radix_5_2(t_push *push)
{
	ft_rra(push, 1);
	ft_rra(push, 1);
	ft_rra(push, 1);
	ft_pb(push);
}

void	ft_small_radix_5_3(t_push *push)
{
	ft_rra(push, 1);
	ft_rra(push, 1);
	ft_pb(push);
}
void	ft_small_radix_5_4(t_push *push)
{
	ft_rra(push, 1);
	ft_pb(push);
}

void	ft_small_radix_5(t_push *push)
{
	int	count;

	count = ft_counter(push);
	if (count == 0)
		ft_small_radix_5_0(push);
	if (count == 1)
		ft_small_radix_5_1(push);
	if (count == 2)
		ft_small_radix_5_2(push);
	if (count == 3)
		ft_small_radix_5_3(push);
	if (count == 4)
		ft_small_radix_5_4(push);
	ft_small_radix_4(push);
}
