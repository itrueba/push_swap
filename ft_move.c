/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:48 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/17 16:38:39 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_push *push, int print)
{
	int	aux;

	aux = push->stack_a->content;
	push->stack_a->content = push->stack_a->next->content;
	push->stack_a->next->content = aux;
    if (print)
        write(1, "sa\n", 3);
}

void	ft_sb(t_push *push, int print)
{
	int	aux;

	aux = push->stack_b->content;
	push->stack_b->content = push->stack_b->next->content;
	push->stack_b->next->content = aux;
    if (print)
        write(1, "sb\n", 3);
}

void	ft_ss(t_push *push, int print)
{
	ft_sa(push, 0);
	ft_sb(push, 0);
    if (print)
        write(1, "ss\n", 3);
}
