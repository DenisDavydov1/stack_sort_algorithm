/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:14:58 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:20:39 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}

int	get_next(t_stack *stack, int val)
{
	int next;

	next = max(stack);
	while (stack)
	{
		if (stack->value > val && stack->value < next)
			next = stack->value;
		stack = stack->next;
	}
	return (next);
}

int	mid(t_stack *stack)
{
	int s;
	int mid;

	if (!stack)
		return (0);
	mid = min(stack);
	s = size(stack) / 2;
	while (s--)
		mid = get_next(stack, mid);
	return (mid);
}
