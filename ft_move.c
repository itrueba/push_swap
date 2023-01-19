/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:48 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/19 12:51:05 by itrueba-         ###   ########.fr       */
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
	t_list	*aux;

	aux = push->stack_b->next;
	push->stack_b->next = push->stack_b->next->next;
	push->stack_b->next->next = aux;
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

void	ft_pa(t_push *push)
{
	t_list	*new;

	new = push->stack_b;
	push->stack_b = push->stack_b->next;
	new->next = NULL;
	ft_lstadd_front(&push->stack_a, new);
	push->size_b--;
	push->size_a++;
	push->head_a = new;
	push->head_b = push->stack_b;
	write(1, "pa\n", 3);
}

void	ft_pb(t_push *push)
{
	t_list	*new;

	new = push->stack_a;
	push->stack_a = push->stack_a->next;
	new->next = NULL;
	ft_lstadd_front(&push->stack_b, new);
	push->size_a--;
	push->size_b++;
	push->head_a = push->stack_a;
	push->head_b = new;
	write(1, "pb\n", 3);
}

void	ft_ra(t_push *push, int print)
{
	t_list	*first;

	first = push->stack_a;
	push->stack_a = push->stack_a->next;
	first->next = NULL;
	ft_lstadd_back(&push->stack_a, first);
	push->head_a = push->stack_a;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_push *push, int print)
{
	t_list	*first;

	first = push->stack_b;
	push->stack_b = push->stack_b->next;
	first->next = NULL;
	ft_lstadd_back(&push->stack_b, first);
	push->head_b = push->stack_b;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_push *push)
{
	ft_ra(push, 0);
	ft_rb(push, 0);
	write(1, "rr\n", 3);
}

void	ft_rra(t_push *push, int print)
{
	t_list	*pre_last;

	pre_last = ft_pre_lstlast(push->stack_a);
	ft_lstadd_front(&push->stack_a, pre_last->next);
	pre_last->next = NULL;
	push->head_a = push->stack_a;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_push *push, int print)
{
	t_list	*pre_last;

	pre_last = ft_pre_lstlast(push->stack_b);
	ft_lstadd_front(&push->stack_b, pre_last->next);
	pre_last->next = NULL;
	push->head_b = push->stack_b;
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_push *push)
{
	ft_rra(push, 0);
	ft_rrb(push, 0);
	write(1, "rrr\n", 4);
}