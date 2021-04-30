/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:36:39 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:19:45 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_of(int a, int b)
{
	return (a < b ? a : b);
}

int		is_int(char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	if (*str == 0)
		return (0);
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}

int		ft_atoi_of(char *s, int *overflow)
{
	int res;
	int add;
	int sign;

	res = 0;
	sign = 1;
	if (*s == '+' || (*s == '-' && (sign = -1)))
		s++;
	while (ft_isdigit(*s))
	{
		add = *s++ - '0';
		if (sign > 0)
		{
			if ((res > (INT_MAX - add) / 10) && (*overflow = 1))
				return (1);
			res = res * 10 + add;
		}
		else
		{
			if ((res < (INT_MIN + add) / 10) && (*overflow = 1))
				return (1);
			res = res * 10 - add;
		}
	}
	return (res);
}

void	ft_sleep(int sec)
{
	int i;

	while (sec--)
	{
		i = 0;
		while (i < 10000000 - sec)
		{
			i++;
		}
	}
}
