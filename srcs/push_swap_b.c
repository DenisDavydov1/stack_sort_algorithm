/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:43:24 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/18 08:52:07 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** How many rotations cost value to get to the top (r_ 1, rr_ 0)
*/

int			rots_to_top(t_stack *s, int val, int *dir)
{
	int up;
	int down;

	up = 0;
	while (s && s->value != val)
	{
		up++;
		s = s->next;
	}
	down = 0;
	while (s)
	{
		down++;
		s = s->next;
	}
	*dir = up < down ? 1 : 0;
	return (up < down ? up : down);
}

static int	val_to_insert(t_stack *s, int val)
{
	int ret;

	ret = max(s);
	if (val > max(s) || val < min(s))
		return (min(s));
	else
	{
		while (s)
		{
			if (val < s->value && s->value < ret)
				ret = s->value;
			s = s->next;
		}
	}
	return (ret);
}

static int	get_opt_elem_val(t_stack *s, int mv[])
{
	int i;
	int min_mv;
	int min_val;

	if (!s)
		return (0);
	i = 0;
	min_mv = 10000;
	min_val = s->value;
	while (s)
	{
		if (mv[i] < min_mv)
		{
			min_mv = mv[i];
			min_val = s->value;
		}
		i++;
		s = s->next;
	}
	return (min_val);
}

int			get_opt_elem(t_ps *ps)
{
	int		i;
	int		mv[1000];
	t_stack	*b;
	int		da;
	int		db;

	ft_bzero(&mv, sizeof(mv));
	b = ps->b;
	i = 0;
	while (b)
	{
		mv[i] = rots_to_top(ps->b, b->value, &db) + rots_to_top(ps->a,
			val_to_insert(ps->a, b->value), &da) + 1;
		if (da == db)
			mv[i] -= min_of(rots_to_top(ps->b, b->value, &db),
				rots_to_top(ps->a, val_to_insert(ps->a, b->value), &da));
		i++;
		b = b->next;
	}
	return (get_opt_elem_val(ps->b, mv));
}

void		move_elem(t_ps *ps, int val)
{
	int da;
	int db;
	int rota;
	int rotb;

	rota = rots_to_top(ps->a, val_to_insert(ps->a, val), &da);
	rotb = rots_to_top(ps->b, val, &db);
	while (da == db && rota > 0 && rotb > 0)
	{
		da ? rr(ps, 1) : rrr(ps, 1);
		rota--;
		rotb--;
	}
	while (rota > 0 && rota--)
		da ? ra(ps, 1) : rra(ps, 1);
	while (rotb > 0 && rotb--)
		db ? rb(ps, 1) : rrb(ps, 1);
	pa(ps, 1);
}
