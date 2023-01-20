/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:47 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/20 13:57:58 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int *input)
{
	write(1, "Error\n", 6);
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

int	*ft_check_argv(int argc, char **argv)
{
	int	count;
	int	nbr;
	int	*input;

	count = 0;
	
	if (argc == 1)
	{
		argc = ft_count_size(argv[1], ' ');
		
		argv = ft_split(argv[0], ' ');
	}
	printf("%s\n",argv[0]);
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);
	printf("%s\n",argv[3]);
	printf("%s\n",argv[4]);
	printf("%s\n",argv[5]);
	printf("%d\n",argc);
	
	input = ft_calloc(sizeof(int), argc);
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
	return (input);
}
