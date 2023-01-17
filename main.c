/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:53 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/17 11:48:13 by itrueba-         ###   ########.fr       */
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
	int	*input;
	int	*index;

	argc -= 1;
	input = ft_calloc(sizeof(int), argc);
	ft_check_argv(argc, argv, input);
	index = ft_index(argc, input);
	ft_print(argc, index);
	return (0);
}
