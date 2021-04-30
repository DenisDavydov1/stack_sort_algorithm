/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:10:53 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/19 13:42:47 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s_(t_stack **stack)
{
	t_stack *second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
	return (1);
}

void		sa(t_ps *ps, int wr)
{
	if (size(ps->a) < 2)
		return ;
	wr ? write(1, "sa\n", 3) : (void)0;
	s_(&ps->a);
	ps->f.hl[0] = top(ps->a);
	ps->f.hl[1] = ps->a->next->value;
	ps->f.len = 2;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		sb(t_ps *ps, int wr)
{
	if (size(ps->b) < 2)
		return ;
	wr ? write(1, "sb\n", 3) : (void)0;
	s_(&ps->b);
	ps->f.hl[0] = top(ps->b);
	ps->f.hl[1] = ps->b->next->value;
	ps->f.len = 2;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		ss(t_ps *ps, int wr)
{
	if (size(ps->a) < 2 && size(ps->b) < 2)
		return ;
	wr ? write(1, "ss\n", 3) : (void)0;
	s_(&ps->a);
	s_(&ps->b);
	ps->f.hl[0] = top(ps->a);
	ps->f.hl[1] = ps->a && ps->a->next ? ps->a->next->value : 0;
	ps->f.hl[size(ps->a) >= 2 ? 2 : 0] = top(ps->b);
	ps->f.hl[size(ps->a) >= 2 ? 3 : 1] = ps->b && ps->b->next ?
		ps->b->next->value : 0;
	ps->f.len = size(ps->a) >= 2 && size(ps->b) >= 2 ? 4 : 2;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}
