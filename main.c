#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	printf("Entrada KO.");	
	exit(0);
}

void	ft_all_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			ft_error();
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
			ft_error();
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
			ft_error();
		count++;
	}
	free(result);
	return (1);
}

void	ft_check_argv(int argc, char **argv)
{
	int	count;
	int	nbr;
	int	*result;

	result = malloc(argc * sizeof(int));
	count = 0;
	while (count < argc - 1)
	{
		nbr = ft_atoi(argv[count + 1]);
		if (nbr == 0)
			ft_all_zero(argv[count + 1]);
		else
		{
			ft_duplicate_nbr(result, nbr, argc - 1);
			result[count] = nbr;
		}
		count++;
	}
	result[count] = '\0';
	ft_result_zero(result, argc - 1);
}

int	main(int argc, char **argv)
{
	ft_check_argv(argc, argv);
	printf("Entrada OK.");
	return (0);
}