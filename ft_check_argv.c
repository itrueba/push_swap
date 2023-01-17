/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:47 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/17 11:48:58 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int *input)
{
	printf("Entrada KO.");
	free(input);
	exit(0);
}

void	ft_all_zero(char *str, int *input)
{
	while (*str)
	{
		if (*str != '0')
			ft_error(input);
		str++;
	}
}

void	ft_duplicate_nbr(int *input, int nbr, int len)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return ;
	while (count < len)
	{
		if (input[count] == nbr)
			ft_error(input);
		count++;
	}
}

void	ft_input_zero(int *input, int len)
{
	int	count;
	int	trigger;

	trigger = 0;
	count = 0;
	while (count < len)
	{
		if (input[count] == 0)
			trigger++;
		if (trigger == 2)
			ft_error(input);
		count++;
	}
}

void	ft_check_argv(int argc, char **argv, int *input)
{
	int	count;
	int	nbr;

	count = 0;
	while (count < argc)
	{
		nbr = ft_atoi(argv[count + 1]);
		if (nbr == 0)
			ft_all_zero(argv[count + 1], input);
		ft_duplicate_nbr(input, nbr, argc);
		input[count] = nbr;
		count++;
	}
	ft_input_zero(input, argc);
}
