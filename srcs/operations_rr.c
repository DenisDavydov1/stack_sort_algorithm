/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:10:19 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/19 13:44:11 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rr_(t_stack **stack)
{
	t_stack *ptr;

	if (!stack || size(*stack) < 2)
		return (0);
	ptr = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = *stack;
	*stack = ptr->next;
	ptr->next = NULL;
	return (1);
}

void		rra(t_ps *ps, int wr)
{
	if (size(ps->a) < 2)
		return ;
	wr ? write(1, "rra\n", 4) : (void)0;
	rr_(&ps->a);
	ps->f.hl[0] = top(ps->a);
	ps->f.len = 1;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		rrb(t_ps *ps, int wr)
{
	if (size(ps->b) < 2)
		return ;
	wr ? write(1, "rrb\n", 4) : (void)0;
	rr_(&ps->b);
	ps->f.hl[0] = top(ps->b);
	ps->f.len = 1;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		rrr(t_ps *ps, int wr)
{
	if (size(ps->a) < 2 && size(ps->b) < 2)
		return ;
	wr ? write(1, "rrr\n", 4) : (void)0;
	rr_(&ps->a);
	rr_(&ps->b);
	ps->f.hl[0] = top(ps->a);
	ps->f.hl[size(ps->a) >= 2 ? 1 : 0] = top(ps->b);
	ps->f.len = size(ps->a) >= 2 && size(ps->b) >= 2 ? 2 : 1;
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}
