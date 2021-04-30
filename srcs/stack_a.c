/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:13:23 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:14:17 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	t_ps_init(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	return (*ps);
}

int		size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int		empty(t_stack *stack)
{
	return (size(stack) == 0);
}

void	push(t_stack **stack, int value)
{
	t_stack *new;

	if (!stack)
		return ;
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error();
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

int		pop(t_stack **stack)
{
	int		value;
	t_stack	*tmp;

	if (!stack || !(*stack))
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	value = tmp->value;
	free(tmp);
	return (value);
}
