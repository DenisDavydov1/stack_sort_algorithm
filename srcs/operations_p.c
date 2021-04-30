/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:09:14 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/18 08:46:59 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	p_(t_stack **stack_from, t_stack **stack_to)
{
	if (empty(*stack_from))
		return (0);
	push(stack_to, pop(stack_from));
	return (1);
}

void		pa(t_ps *ps, int wr)
{
	if (empty(ps->b))
		return ;
	wr ? write(1, "pa\n", 3) : (void)0;
	p_(&ps->b, &ps->a);
	ps->f.hl[0] = top(ps->a);
	ps->f.len = 1;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		pb(t_ps *ps, int wr)
{
	if (empty(ps->a))
		return ;
	wr ? write(1, "pb\n", 3) : (void)0;
	p_(&ps->a, &ps->b);
	ps->f.hl[0] = top(ps->b);
	ps->f.len = 1;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}
