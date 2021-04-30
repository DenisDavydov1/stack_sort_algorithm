/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:09:42 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/19 13:38:39 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	r_(t_stack **stack)
{
	t_stack *ptr;

	if (!stack || size(*stack) < 2)
		return (0);
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *stack;
	*stack = (*stack)->next;
	ptr->next->next = NULL;
	return (1);
}

void		ra(t_ps *ps, int wr)
{
	if (size(ps->a) < 2)
		return ;
	wr ? write(1, "ra\n", 3) : (void)0;
	ps->f.hl[0] = top(ps->a);
	ps->f.len = 1;
	r_(&ps->a);
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		rb(t_ps *ps, int wr)
{
	if (size(ps->b) < 2)
		return ;
	wr ? write(1, "rb\n", 3) : (void)0;
	ps->f.hl[0] = top(ps->b);
	ps->f.len = 1;
	r_(&ps->b);
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}

void		rr(t_ps *ps, int wr)
{
	if (size(ps->a) < 2 && size(ps->b) < 2)
		return ;
	wr ? write(1, "rr\n", 3) : (void)0;
	ps->f.hl[0] = top(ps->a);
	ps->f.hl[size(ps->a) >= 2 ? 1 : 0] = top(ps->b);
	ps->f.len = size(ps->a) >= 2 && size(ps->b) >= 2 ? 2 : 1;
	r_(&ps->a);
	r_(&ps->b);
	wr && ps->f.s ? print_sort(ps) : (void)0;
	wr && ps->f.v && !ps->f.s ? print_stacks(ps) : (void)0;
}
