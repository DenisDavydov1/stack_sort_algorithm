/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:14:24 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/18 08:47:21 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	clear_stacks(t_ps *ps)
{
	clear_stack(ps->a);
	clear_stack(ps->b);
	ps->a = NULL;
	ps->b = NULL;
}

int		ascending_sorting(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		has_duplicates(t_stack *stack)
{
	t_stack *ptr;

	while (stack)
	{
		ptr = stack->next;
		while (ptr)
		{
			if (stack->value == ptr->value)
				return (1);
			ptr = ptr->next;
		}
		stack = stack->next;
	}
	return (0);
}

t_stack	*get_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
