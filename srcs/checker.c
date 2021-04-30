/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:08:37 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:22:22 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_operation(t_ps *ps, char *buf, int *nl)
{
	if (ft_strncmp(buf, "sa", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		sa(ps, 0);
	else if (ft_strncmp(buf, "sb", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		sb(ps, 0);
	else if (ft_strncmp(buf, "ss", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		ss(ps, 0);
	else if (ft_strncmp(buf, "pa", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		pa(ps, 0);
	else if (ft_strncmp(buf, "pb", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		pb(ps, 0);
	else if (ft_strncmp(buf, "ra", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		ra(ps, 0);
	else if (ft_strncmp(buf, "rb", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		rb(ps, 0);
	else if (ft_strncmp(buf, "rr", 2) == 0 && buf[2] == '\n' && (*nl = 3))
		rr(ps, 0);
	else if (ft_strncmp(buf, "rra", 3) == 0 && buf[3] == '\n' && (*nl = 4))
		rra(ps, 0);
	else if (ft_strncmp(buf, "rrb", 3) == 0 && buf[3] == '\n' && (*nl = 4))
		rrb(ps, 0);
	else if (ft_strncmp(buf, "rrr", 3) == 0 && buf[3] == '\n' && (*nl = 4))
		rrr(ps, 0);
	else
		error();
}

static void	execute_instructions(t_ps *ps)
{
	ssize_t	ret;
	ssize_t	done;
	int		new_line;
	char	buf[100000];

	ft_bzero(&buf, sizeof(buf));
	done = 0;
	while ((ret = read(0, &buf[done], 100000)))
		done += ret;
	done = 0;
	while (buf[done])
	{
		exec_operation(ps, &buf[done], &new_line);
		done += new_line;
	}
}

int			main(int ac, char **av)
{
	t_ps ps;

	args(--ac, &av[1], &ps);
	execute_instructions(&ps);
	if (ascending_sorting(ps.a) && empty(ps.b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stacks(&ps);
	exit(EXIT_SUCCESS);
	return (0);
}
