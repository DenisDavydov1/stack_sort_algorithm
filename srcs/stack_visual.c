/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:33:26 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:17:07 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		highlight(t_ps *ps, int val)
{
	int i;

	i = -1;
	while (++i < ps->f.len)
		if (val == ps->f.hl[i])
			return (1);
	return (0);
}

void	print_stack(t_ps *ps, t_stack *s)
{
	char *str;

	while (s)
	{
		if (ps->f.a && s->next && s->value > s->next->value)
			write(1, "\e[48;5;196m", 11);
		else if (ps->f.a)
			write(1, "\e[48;5;112m\e[38;5;232m", 22);
		if (!(str = ft_itoa(s->value)))
			error();
		if (ps->f.c && highlight(ps, s->value))
			write(1, "\e[38;5;125m", 11);
		write(1, str, ft_strlen(str));
		write(1, " ", 1);
		write(1, "\e[0m", 4);
		free(str);
		s = s->next;
	}
	write(1, "\n", 1);
}

void	print_stacks(t_ps *ps)
{
	char *msg;

	msg = "  a: ";
	write(1, msg, ft_strlen(msg));
	print_stack(ps, ps->a);
	msg = "  b: ";
	write(1, msg, ft_strlen(msg));
	print_stack(ps, ps->b);
	ps->f.len = 0;
	ft_sleep(ps->f.m);
	ps->f.m ? write(1, "\x1B[2J\x1B[H", 7) : (void)0;
}

void	pr_line(t_ps *ps, t_stack *s)
{
	char	*str;
	int		vol;
	int		sp;
	int		range;

	str = NULL;
	s && s->next && s->value > s->next->value ? write(1, "\e[48;5;196m", 11) :
		write(1, "\e[48;5;112m\e[38;5;232m", 22);
	if (s && !(str = ft_itoa(s->value)))
		error();
	range = gmax(ps) - gmin(ps) == 0 ? 1 : gmax(ps) - gmin(ps);
	vol = s ? (s->value - gmin(ps)) * 25 / range - ft_strlen(str) : 0;
	vol = vol < 0 ? 0 : vol;
	sp = s ? 26 - vol - ft_strlen(str) : 26;
	s ? write(1, str, ft_strlen(str)) : (void)0;
	while (vol > 0 && vol--)
		write(1, " ", 1);
	write(1, "\e[0m", 4);
	while (sp--)
		write(1, " ", 1);
	free(str);
}

void	print_sort(t_ps *ps)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = size(ps->a) > size(ps->b) ? size(ps->a) : size(ps->b);
	a = ps->a;
	b = ps->b;
	write(1, "a:                        b:                       \n", 52);
	while (i--)
	{
		pr_line(ps, a);
		pr_line(ps, b);
		write(1, "\n", 1);
		a = a ? a->next : a;
		b = b ? b->next : b;
	}
	ft_sleep(ps->f.m);
	write(1, "\x1B[2J\x1B[H", 7);
}
