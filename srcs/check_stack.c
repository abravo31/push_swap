/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:12:46 by abravo            #+#    #+#             */
/*   Updated: 2022/09/17 19:33:21 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	av_is_nbr(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1])
		i++;
	while (is_digit(s[i]) && s[i])
		i++;
	if (!is_digit(s[i]) && s[i])
		return (0);
	return (1);
}

static int	not_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_stack(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av_is_nbr(av[i]))
			return (0);
		i++;
	}
	if (!not_duplicate(av))
		return (0);
	return (1);
}

/*int main (int ac, char **av)
{
	if (ac > 1)
	{
		if (check_stack(av))
			printf("ok");
		else 
			printf("pas bon");
	}
	else
		printf("pas bon");
	return 0;
}*/
