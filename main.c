#include "push_swap.h"
#include <stdio.h>

void	ft_error(int *result)
{
	printf("Entrada KO.");	
	free (result);
	exit(0);
}

void	ft_all_zero(char *str, int *result)
{
	while (*str)
	{
		if (*str != '0')
			ft_error(result);
		str++;
	}
}

void	ft_duplicate_nbr(int *result, int nbr, int len)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return ;
	while (count < len)
	{
		if (result[count] == nbr)
			ft_error(result);
		count++;
	}
}

int	ft_result_zero(int *result, int len)
{
	int	count;
	int	trigger;

	trigger = 0;
	count = 0;
	while (count < len)
	{
		
		if (result[count] == 0)
			trigger++;
		if (trigger == 2)
			ft_error(result);
		
		
		count++;
	}
	return (1);
}

int	*ft_check_argv(int argc, char **argv, int *result)
{
	int	count;
	int	nbr;
	
	count = 0;
	while (count < argc)
	{
		nbr = ft_atoi(argv[count + 1]);
		if (nbr == 0)
			ft_all_zero(argv[count + 1], result);
		ft_duplicate_nbr(result, nbr, argc);
		result[count] = nbr;
		count++;
	}
	ft_result_zero(result, argc);
	return (result);
}

int * ft_order(int argc, int *order)
{
	int aux;
	int x;
	int y;

	x = 0;
	while (x < argc)
	{
		y = x;
		while (y < argc)
		{
			if (order[y] < order[x])
			{
				aux = order[y];
				order[y] = order[x];
				order[x] = aux;
			}
			y++;
		}
		x++;
	}
	return (order);
}

int * ft_index(int argc, int *result, int *order, int *index)
{
	int aux;
	int x;
	int y;

	x = 0;
	while (x < argc)
	{
		y = 0;
		while (y < argc)
		{
			if (order[x] == result[y])
				index[x] = y;
			y++;
		}
		x++;
	}
	return (order);
}

int	main(int argc, char **argv)
{
	int	*result;
	int	*order;
	int	*index;
	int count;

	argc -= 1; 
	result = malloc(argc * sizeof(int));
	if (!result)
		return (0);
	order = malloc(argc * sizeof(int));
	if (!order)
		return (0);

	index = malloc(argc * sizeof(int));
	if (!index)
		return (0);

	ft_check_argv(argc, argv, result);

	count = 0;
	while (count < argc)
	{
		order[count] = result[count];
		index[count] = 0;
		count++;
	}
	ft_order(argc, order);	
	ft_index(argc, result, order, index);

	count = 0;
	while (count < argc)
	{
		printf("%d\n", index[count]);
		count++;
	}
	printf("A");
	printf("Entrada OK.");
	return (0);
}