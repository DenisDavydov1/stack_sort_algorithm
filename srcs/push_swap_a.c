/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:43:18 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/18 08:50:03 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ps *ps)
{
	if (ascending_sorting(ps->a))
		return ;
	if (size(ps->a) == 2)
	{
		sa(ps, 1);
		return ;
	}
	if (top(ps->a) == max(ps->a))
		ra(ps, 1);
	if (ps->a && ps->a->next && ps->a->next->value == max(ps->a))
		rra(ps, 1);
	if (ps->a && ps->a->next && top(ps->a) > ps->a->next->value)
		sa(ps, 1);
}

static void	sort_five(t_ps *ps)
{
	if (ascending_sorting(ps->a))
		return ;
	while (size(ps->b) < 2)
	{
		if (top(ps->a) == gmax(ps) || top(ps->a) == gmin(ps))
			pb(ps, 1);
		else
			ra(ps, 1);
	}
	sort_three(ps);
	pa(ps, 1);
	pa(ps, 1);
	if (top(ps->a) != max(ps->a))
		sa(ps, 1);
	ra(ps, 1);
}

static void	push_b(t_ps *ps)
{
	int md;

	md = mid(ps->a);
	while (size(ps->a) > 2)
	{
		if (top(ps->a) != gmax(ps) && top(ps->a) != gmin(ps))
		{
			pb(ps, 1);
			if (top(ps->b) > md)
				rb(ps, 1);
		}
		else
			ra(ps, 1);
	}
	if (ps->a && ps->a->next && top(ps->a) < ps->a->next->value)
		sa(ps, 1);
	pa(ps, 1);
}

static void	sort(t_ps *ps)
{
	int dir;
	int rot;

	if (ascending_sorting(ps->a))
		return ;
	push_b(ps);
	while (size(ps->b) > 0)
		move_elem(ps, get_opt_elem(ps));
	rot = rots_to_top(ps->a, min(ps->a), &dir);
	while (rot--)
		dir ? ra(ps, 1) : rra(ps, 1);
}

int			main(int ac, char **av)
{
	t_ps ps;

	args_ps(--ac, ++av, &ps);
	if (size(ps.a) <= 3)
		sort_three(&ps);
	else if (size(ps.a) <= 5)
		sort_five(&ps);
	else
		sort(&ps);
	clear_stacks(&ps);
	exit(EXIT_SUCCESS);
	return (0);
}
