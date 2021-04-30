/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:13:43 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:16:14 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	int max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	min(t_stack *stack)
{
	int min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	gmax(t_ps *ps)
{
	int max_a;
	int max_b;

	if (size(ps->a) == 0)
		return (max(ps->b));
	if (size(ps->b) == 0)
		return (max(ps->a));
	max_a = max(ps->a);
	max_b = max(ps->b);
	return (max_a > max_b ? max_a : max_b);
}

int	gmin(t_ps *ps)
{
	int min_a;
	int min_b;

	if (size(ps->a) == 0)
		return (min(ps->b));
	if (size(ps->b) == 0)
		return (min(ps->a));
	min_a = min(ps->a);
	min_b = min(ps->b);
	return (min_a < min_b ? min_a : min_b);
}
