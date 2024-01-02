/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:26:59 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/15 09:39:14 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_digit(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *arg)
{
	long	num;

	num = ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	is_unique(char **args, int i)
{
	int		j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(args[i]);

	j = i;
	while (args[++j])
	{
		len2 = ft_strlen(args[j]);
		if (len1 == len2 && !ft_strncmp(args[j], args[i], len1))
			return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 1)
	{
			ft_putstr_fd("Error\n", 1);
			return (0);
	};
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (!is_digit(args[i]) || !is_int(args[i]) || !is_unique(args, i))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		};
		i++;
	}
	return (1);
}
